
--retain="*(PRU0*)"
--retain="*(PRU1*)"


/* SPECIFY THE SYSTEM MEMORY MAP */
SECTIONS
{
    PRU0_REV2_IMEM : {
        pru_imem0_rev2_start = .;
        *(PRU0_REV2_IMEM)
        pru_imem0_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV2_DMEM : {
        pru_dmem0_rev2_start = .;
        *(PRU0_REV2_DMEM)
        pru_dmem0_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV2_EXT : {
        *(PRU0_REV2_EXT)
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV2_IMEM : {
        pru_imem1_rev2_start = .;
        *(PRU1_REV2_IMEM)
        pru_imem1_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV2_DMEM : {
        pru_dmem1_rev2_start = .;
        *(PRU1_REV2_DMEM)
        pru_dmem1_rev2_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV2_EXT : {
        *(PRU1_REV2_EXT)
    } > APP_CACHED_DATA_BLK1_MEM
}




