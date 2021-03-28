;   ============================================================================
;   @n   (C) Copyright 2018, Texas Instruments, Inc.
;
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions
;   are met:
;
;     Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;
;     Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the
;     distribution.
;
;     Neither the name of Texas Instruments Incorporated nor the names of
;     its contributors may be used to endorse or promote products derived
;     from this software without specific prior written permission.
;
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE,
;   DATA, OR PROFITS;  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;******************************************************************************


  .global CSL_c7xIntEvtRegister
CSL_c7xIntEvtRegister:
 ; set an interrupt in the event vector table
 ; A4 - Vector Table address
 ; A5 - Event to register
 ; A6 - Pointer to function to register
  MVK32     .L1 0xC00               , A3 ; event vector table is 0x400 past evt
  || MV     .S1 A5                  , D1
  ADDD      .L1 A3      , A4        , D0
  STD       .D1 A6                  ,*D0[D1]
  || RET    .B1


  .global CSL_c7xIntEvtUnregister
CSL_c7xIntEvtUnregister:
  ; remove an interrupt from the event vector table
  ; A4 - Vector Table address
  ; A5 - Event to unregister
  MVK32     .L1 0xC00               , A3 ; event vector table is 0x400 past evt
  || MV     .S1 A5                  , D1
  ADDD      .L1 A3      , A4        , D0
  ST0KD     .D1                      *D0[D1]
  || RET    .B1


  .global CSL_c7xIntEvtEnable
CSL_c7xIntEvtEnable:
  ; enable all events
  MVK64     .L1 0x1                 , A4
  REVT      .S1 A4
  || RET    .B1

  .global CSL_c7xIntEvtDisable
CSL_c7xIntEvtDisable:
  ; disable all events
  MVK64     .L1 0x1                 , A4
  DEVT      .S1 A4
  || RET    .B1

  .global CSL_c7xIntSystemEnable
CSL_c7xIntSystemEnable:
  ; enable a specific event in the EER
  ; A4 - event to enable
  MVK32     .S1 1                   , A0
  SHLD      .L1 A0       , A4       , A0
  MVC       .S1 A0                  , EESET
  || RET    .B1

  .global CSL_c7xIntSystemDisable
CSL_c7xIntSystemDisable:
  ; disable a specific event in the EER
  ; A4 - event to disable
  MVK32     .S1 1                   , A0
  SHLD      .L1 A0       , A4       , A0
  MVC       .S1 A0                  , EECLR
  || RET    .B1

  .global CSL_c7xIntEvtPrioritySet
CSL_c7xIntEvtPrioritySet:
  ; sets the priority for an event and returns the curent
  ; A4 - event number
  ; A5 - new priority
  MVCI       .S1 EPRI    , A4       , A6
  || SHLD    .L1 A5      , 5        , A5
  MVCI       .S1 A5      , EPRI     , A4
  || SHRD    .L1 A6      , 5        , A4
  || RET     .B1
