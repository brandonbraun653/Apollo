
/* SPECIFY THE SYSTEM MEMORY MAP */
SECTIONS
{
    PRU0_REV1_IMEM : {
        pru_imem0_rev1_start = .;
        KEEP(*(PRU0_REV1_IMEM))
        pru_imem0_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV1_DMEM : {
        pru_dmem0_rev1_start = .;
        KEEP (*(PRU0_REV1_DMEM))
        pru_dmem0_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU0_REV1_EXT : {
        KEEP (*(PRU0_REV1_EXT))
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV1_IMEM : {
        pru_imem1_rev1_start = .;
        KEEP (*(PRU1_REV1_IMEM))
        pru_imem1_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV1_DMEM : {
        pru_dmem1_rev1_start = .;
        KEEP (*(PRU1_REV1_DMEM))
        pru_dmem1_rev1_end = .;
    } > APP_CACHED_DATA_BLK1_MEM
    PRU1_REV1_EXT : {
        KEEP (*(PRU1_REV1_EXT))
    } > APP_CACHED_DATA_BLK1_MEM
}


