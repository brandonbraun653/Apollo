**************************************************************************
*	CPTS Timestamp Comparison Example 
*	---------------------------------
*
*	(C) Copyright 2015, Texas Instruments, Inc.
*
*	Use of this software is controlled by the terms and conditions found 
*	in the license agreement under which this software has been supplied.
***************************************************************************

The CPTS Timestamp Compare example demonstrates the use of CPTS CSL APIs
to trigger the CPTS Timestamp Compare events, generate TS_COMP output pluses
and/or adjust the phase of TS_COMP output clock with NUDGE.

This example performs the following tasks:
1. Configure and enable the CPTS module
2. Measure the CPTS clock rate
3. Program CPTS in non-toggle mode, generate 4000 TS_COMP output pulses per second
   for 10 seconds
4. Program CPTS in toggle mode, generate TS_COMP output clocks with pre-determined 
   Nudge values for 10 seconds   
    
Check the release notes for prerequisites, version information and steps on how to 
run examples

-------------------------
Execute Project
-------------------------

1. Execute using CCS
    
Launch the CCS Debugger and go to the Debug Perspective.

To execute the project ensure the following is done:-
    a) System reset (applicable for EVM under NO_BOOT mode only)
    b) Run EVM specific GEL scripts (applicable for EVM under NO_BOOT mode only)
    b) Load Program
    c) Once the project is loaded; Run to execute it.
    
2. Result

The application will output to the console its status progress and declare pass/fail.

    
    
    
    
