;/*****************************************************************************
; *  Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2008   
; *  
; *  Use of this software is controlled by the terms and conditions found in the
; *  license agreement under which this software has been supplied.             
; *****************************************************************************/

;/** @file _csl_intcIsrDispatch.asm
; *
; *  @date 12th June, 2004
; *  @author Ruchika Kharwar
; */
    .global CSL_intcNmiDummy
    .def CSL_intcNmiDummy
    .sect  ".text:csl_section:intc"
CSL_intcNmiDummy:
    b nrp
    nop 5    
        
