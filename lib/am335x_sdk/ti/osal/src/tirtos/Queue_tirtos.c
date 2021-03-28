/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== HwiP_tirtos.c ========
 */

#include <ti/osal/osal.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/osal/src/tirtos/tirtos_config.h>
/*!
 *  @brief  Function to construct the queue
 *
 *  @param  structPtr  Pointer to the structure containing the queue element
 *
 *  @param  queue parameters
 *
 */
void Osal_Queue_construct(void * structPtr, const void * params)
{
    Queue_construct((Queue_Struct*)structPtr, (Queue_Params *) params);
}
/*!
 *  @brief  Function to return the queue handle from the structure
 *
 *  @param  structPtr  Pointer to the structure containing the queue element
 *
 */
Osal_Queue_Handle Osal_Queue_handle(void *structPtr)
{
    return((Osal_Queue_Handle)Queue_handle((Queue_Struct *)structPtr));
}
/*!
 *  @brief  Function to empty the queue
 *
 *  @param  handle   The queue handle
 *
 */
bool Osal_Queue_empty(Osal_Queue_Handle handle)
{
  bool ret;
  if(Queue_empty(Queue_handle((Queue_Struct *)handle)) == TRUE)
  {
     ret = (bool)true;
  } 
  else
  {
      ret = (bool)false;  
  }
  return (ret);
}
/*!
 *  @brief  Function to return the element at the front of the queue
 *
 *  @param  handle   The queue handle
 *
 */
void * Osal_Queue_get(Osal_Queue_Handle handle)
{
return Queue_get(Queue_handle((Queue_Struct *)handle));

}
/*!
 *  @brief  Function to return the element at the front of the queue
 *
 *  @param  handle   The queue handle
 *
 *  @param  elem      The queue element
 */
void Osal_Queue_put(Osal_Queue_Handle handle,Osal_Queue_Elem *ptr)
{
    Queue_put(Queue_handle((Queue_Struct *)handle),(Queue_Elem *)ptr);
}


