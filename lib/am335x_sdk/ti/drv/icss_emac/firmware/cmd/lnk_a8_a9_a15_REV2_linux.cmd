
/* SPECIFY THE SYSTEM MEMORY MAP */
SECTIONS
{
    PRU0_REV2_IMEM : {
        pru_imem0_rev2_start = .;
        KEEP(*(PRU0_REV2_IMEM))
        pru_imem0_rev2_end = .;
    }
    PRU0_REV2_DMEM : {
        pru_dmem0_rev2_start = .;
        KEEP (*(PRU0_REV2_DMEM))
        pru_dmem0_rev2_end = .;
    }
    PRU0_REV2_EXT : {
        KEEP (*(PRU0_REV2_EXT))
    }
    PRU1_REV2_IMEM : {
        pru_imem1_rev2_start = .;
        KEEP (*(PRU1_REV2_IMEM))
        pru_imem1_rev2_end = .;
    }
    PRU1_REV2_DMEM : {
        pru_dmem1_rev2_start = .;
        KEEP (*(PRU1_REV2_DMEM))
        pru_dmem1_rev2_end = .;
    }
    PRU1_REV2_EXT : {
        KEEP (*(PRU1_REV2_EXT))
    }
}


