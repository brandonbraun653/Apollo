/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdint.h>
#include "string.h"
#include "stdio.h"
#include "sbl_sec.h"
#include <stdarg.h>

/* Index for signature verify ROM API */
#ifdef CONFIG_AM33XX
#define API_HAL_KM_VERIFYCERTIFICATESIGNATURE_INDEX (0x0000000C)
#else
#define API_HAL_KM_VERIFYCERTIFICATESIGNATURE_INDEX (0x0000000E)
#endif

#define IS_ALIGNED(x, a)        (((x) & ((typeof(x))(a) - 1)) == 0)

#ifndef SOC_CACHELINE_SIZE
#define SOC_CACHELINE_SIZE                  (128U)
#endif

static uint32_t secure_rom_call_args[5] __aligned(SOC_CACHELINE_SIZE);

/* Wrapper to HS RBL ROM function on AM437x HS for authenticating boot image 
 * Exact action performed depends on the certificate embedded into the image 
 * being boot. Refer to "Sitara AM437x Processors Security" for more detail
 */
uint32_t secure_rom_call(uint32_t service, uint32_t proc_id, uint32_t flag, ...)
{
    int i;
    uint32_t num_args;
    va_list ap;

    va_start(ap, flag);

    num_args = va_arg(ap, uint32_t);

    if (num_args > 4)
        return 1;

    /* Copy args to aligned args structure */
    for (i = 0; i < num_args; i++)
        secure_rom_call_args[i + 1] = va_arg(ap, uint32_t);

    secure_rom_call_args[0] = num_args;

    va_end(ap);

    return omap_smc_sec(service, proc_id, flag, secure_rom_call_args);
}

/* find the image signature */
static uint32_t find_sig_start(char *image, size_t size)
{
    char *image_end = image + size;
    char *sig_start_magic = "CERT_";
    int magic_str_len = strlen(sig_start_magic);
    char *ch;

    while (--image_end > image) {
        if (*image_end == '_') {
            ch = image_end - magic_str_len + 1;
            if (!strncmp(ch, sig_start_magic, magic_str_len))
                return (uint32_t)ch;
        }
    }
    return 0;
}

/* wrapper to secure_boot_verify_image */
uint32_t SBL_authentication(void *addr, uint32_t size)
{
    return secure_boot_verify_image(&addr, &size);
}

/* Verifying boot image 
   Pointers to the location and size of the boot data needed.
*/
int secure_boot_verify_image(void **image, size_t *size)
{
    int result = 1;
    uint32_t cert_addr, sig_addr;
    size_t cert_size;

    cert_addr = (uint32_t)*image;
    sig_addr = find_sig_start((char *)*image, *size);

    if (sig_addr == 0) {
        CONSOLEUtilsPuts("No signature found in image!\n");
        result = 1;
        goto auth_exit;
    }

    *size = sig_addr - cert_addr;   /* Subtract out the signature size */
    cert_size = *size;

    /* Check if image load address is 32-bit aligned */
    if (!IS_ALIGNED(cert_addr, 4)) {
        CONSOLEUtilsPuts("Image is not 4-byte aligned!\n");
        result = 1;
        goto auth_exit;
    }

    /* Image size also should be multiple of 4 */
    if (!IS_ALIGNED(cert_size, 4)) {
        CONSOLEUtilsPuts("Image size is not 4-byte aligned!\n");
        result = 1;
        goto auth_exit;
    }

    /* CONSOLEUtilsPuts("secboot load_addr = %x, size = %d, sig_addr = %x\n", 
                      cert_addr, cert_size, sig_addr);*/

    /* Call ROM HAL API to verify certificate signature */
    result = secure_rom_call(
        API_HAL_KM_VERIFYCERTIFICATESIGNATURE_INDEX, 0, 0,
        4, cert_addr, cert_size, sig_addr, 0xFFFFFFFF);

auth_exit:
    if (result != 0) {
        CONSOLEUtilsPuts("Authentication failed!\n");
        CONSOLEUtilsPuts("Return Value = 0x%08x\n", result);
    }

    return result;
}

