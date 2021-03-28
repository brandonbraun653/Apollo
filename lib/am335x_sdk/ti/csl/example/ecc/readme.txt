Overview
--------
This example provides details of ECC tests on a given core.
See the program flow see comments for for the appropriate core.

In general the ECC tests are performed by purposefully inserting the single or double errors

Directory structure
-------------------

ecc_test_app/
├── ecc_common.h
├── ecc_emif.c --> EMIF ecc routines
├── ecc_emif.h --> EMIF ecc header file ( Memory region configured with ECC enabled defined here)
├── ecc_ocmc.c --> OCMC ecc routines
├── ecc_ocmc.h --> OCMC ecc header file ( Memory region configured with ECC enabled defined here)
├── lnk_dsp.cmd --> DSP linker cmd file
├── main.c --> Main file for A15 core
├── main_c66x.c --> Main file for c66x core
├── main_ipu.c --> Main file for ipu core
├── main_a53.c --> Main file for A53 core
├── ecc_msmc.c --> MSMC ecc routines for A53
├── esm_app.c --> AM65xx ESM routines
└── makefile 
