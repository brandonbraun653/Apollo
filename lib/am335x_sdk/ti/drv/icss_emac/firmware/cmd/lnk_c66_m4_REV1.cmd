
--retain="*(PRU0*)"
--retain="*(PRU1*)"


/* SPECIFY THE SYSTEM MEMORY MAP */
SECTIONS
{
    PRU0_REV1_IMEM : {
        pru_imem0_rev1_start = .;
        *(PRU0_REV1_IMEM)
        pru_imem0_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV1_DMEM : {
        pru_dmem0_rev1_start = .;
        *(PRU0_REV1_DMEM)
        pru_dmem0_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV1_EXT : {
        *(PRU0_REV1_EXT)
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV1_IMEM : {
        pru_imem1_rev1_start = .;
        *(PRU1_REV1_IMEM)
        pru_imem1_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV1_DMEM : {
        pru_dmem1_rev1_start = .;
        *(PRU1_REV1_DMEM)
        pru_dmem1_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV1_EXT : {
        *(PRU1_REV1_EXT)
    } > APP_CACHED_DATA_BLK1_MEM
}




