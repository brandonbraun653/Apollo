
/* SPECIFY THE SYSTEM MEMORY MAP */
SECTIONS
{
    PRU0_REV1_IMEM : {
        pru_imem0_rev1_start = .;
        KEEP(*(PRU0_REV1_IMEM))
        pru_imem0_rev1_end = .;
    }
    PRU0_REV1_DMEM : {
        pru_dmem0_rev1_start = .;
        KEEP (*(PRU0_REV1_DMEM))
        pru_dmem0_rev1_end = .;
    }
    PRU0_REV1_EXT : {
        KEEP (*(PRU0_REV1_EXT))
    }
    PRU1_REV1_IMEM : {
        pru_imem1_rev1_start = .;
        KEEP (*(PRU1_REV1_IMEM))
        pru_imem1_rev1_end = .;
    }
    PRU1_REV1_DMEM : {
        pru_dmem1_rev1_start = .;
        KEEP (*(PRU1_REV1_DMEM))
        pru_dmem1_rev1_end = .;
    }
    PRU1_REV1_EXT : {
        KEEP (*(PRU1_REV1_EXT))
    }
}


