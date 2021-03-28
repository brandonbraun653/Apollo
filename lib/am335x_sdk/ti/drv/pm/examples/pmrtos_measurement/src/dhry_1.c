/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

/*
#  Copyright (c) 2015-2017 Texas Instruments Incorporated - http://www.ti.com
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#  *  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#
#  *  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
#  *  Neither the name of Texas Instruments Incorporated nor the names of
#     its contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "dhry.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef BIOS_POSIX

/* BIOS6 include */
#include <ti/sysbios/BIOS.h>

/* XDC include */
#include <xdc/runtime/System.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/posix/pthread.h>
#include "ti/board/board.h"
#else
#include <pthread.h>
#include <sys/time.h>
#endif

#ifdef BIOS_POSIX
#ifndef IO_CONSOLE
#include <ti/drv/uart/UART_stdio.h>
#endif
#endif

#ifdef BIOS_POSIX
#if 0
#include <c6x.h>

#define CORE_MHZ 983
static inline uint64_t read_time()
{
    return ((uint64_t)TSCH<<32) | TSCL;
}
#else
#define CORE_MHZ 1000
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
uint64_t read_time()
{
    uint64_t result;
    Types_Timestamp64 ts1;
    Timestamp_get64(&ts1);

    result = ((uint64_t )ts1.hi << 32) | ts1.lo;

    return result;
}
#endif
#endif

/* Global Variables: */
#define MAX_THREADS 32
#define DEFAULT_STACK_SIZE  0x8000

typedef struct {
  int numIterations;
  float results;
  pthread_barrier_t *barrier;
} threadInst_t;
typedef struct {
  threadInst_t threadInst;
  pthread_t    threadId;
} threadData_t;


//extern char     *malloc ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

int DHRY_printf(const char *format, ...)
{
    int retval;
    va_list args;
    va_start(args, format);
    
#ifdef BIOS_POSIX
#ifndef IO_CONSOLE
    {
        char buf[80];
        size_t len = 80;
        retval = System_vsnprintf (buf, len, format, args);
        UART_puts (buf, retval);
    }
#else
    retval = System_vprintf(format, args);
#endif
#else
    retval = vprintf(format, args);
    fflush(stdout);
#endif
    
    va_end(args);
    return retval;
}

/* end of variables for time measurement */
void check (const char *str, int err)
{
  if (err != 0)
  {
    DHRY_printf ("%s: %d: %s\n", str, err, strerror(err));
    exit(1);
  }
}

void *dhryThread (void *arg)
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;
  threadInst_t         *threadInst = (threadInst_t *)arg;

long            Begin_Time,
                End_Time,
                User_Time;
float           Microseconds,
                Dhrystones_Per_Second = -1;
  dhryInstance_t inst;
  int error = 0;
  int err;
/* variables for time measurement: */
#ifdef TIMEOFDAY
  struct timeval Begin_TimeVal, End_TimeVal, Diff_TimeVal;
  float  float_time;
#define Too_Small_Time (2*HZ)
#endif
#ifdef BIOS_POSIX
  uint64_t begin, end;
  #define Too_Small_Time 10 /* MHz */
#endif
#ifdef TIMES
struct tms      time_info;
//extern  int     times ();
                /* see library function "times" */
#define Too_Small_Time (2*HZ)
                /* Measurements should last at least about 2 seconds */
#endif
#ifdef TIME
#ifdef BIOS_POSIX
extern time_t     time(time_t *timer);
#else
extern long     time();
                /* see library function "time"  */
#endif
#define Too_Small_Time 2
                /* Measurements should last at least 2 seconds */
#endif
#ifdef MSC_CLOCK
extern clock_t	clock();
#define Too_Small_Time (2*HZ)
#endif

  /* Initializations */

  inst.Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  inst.Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

  inst.Ptr_Glob->Ptr_Comp                    = inst.Next_Ptr_Glob;
  inst.Ptr_Glob->Discr                       = Ident_1;
  inst.Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  inst.Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (inst.Ptr_Glob->variant.var_1.Str_Comp, 
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  inst.Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */

#ifdef VERBOSE
  DHRY_printf ("\n");
  DHRY_printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  DHRY_printf ("\n");
#endif
#ifdef VERBOSE
  if (Reg)
  {
    DHRY_printf ("Program compiled with 'register' attribute\n");
    DHRY_printf ("\n");
  }
  else
  {
    DHRY_printf ("Program compiled without 'register' attribute\n");
    DHRY_printf ("\n");
  }
#endif
#ifdef VERBOSE
  DHRY_printf ("Please give the number of runs through the benchmark: ");
  {
    int n;
    scanf ("%d", &n);
    Number_Of_Runs = n;
  }
  DHRY_printf ("\n");
#endif
  Number_Of_Runs = threadInst->numIterations;

#ifdef VERBOSE
  DHRY_printf ("Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);
#endif

  /***************/
  /* Start timer */
  /***************/
#ifdef BIOS_POSIX
#ifndef TIME
  begin = read_time();
#endif
#endif
#ifdef TIMEOFDAY
  gettimeofday (&Begin_TimeVal, NULL);
#endif
#ifdef TIMES
  times (&time_info);
  Begin_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
#ifdef BIOS_POSIX
  Begin_Time = time ( (time_t *) 0);
#else
  Begin_Time = time ( (long *) 0);
#endif
#endif
#ifdef MSC_CLOCK
  Begin_Time = clock();
#endif
  if (threadInst->barrier)
  {
    err = pthread_barrier_wait (threadInst->barrier);
    if (err != 0 && err != PTHREAD_BARRIER_SERIAL_THREAD)
    {
      check("pthread_barrier_wait", err);
    }
  }

  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5(&inst);
    Proc_4(&inst);
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    inst.Bool_Glob = ! Func_2 (&inst, Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (&inst, inst.Arr_1_Glob, inst.Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (&inst, inst.Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= inst.Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (&inst, Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (&inst, Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        inst.Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&inst, &Int_1_Loc);
      /* Int_1_Loc == 5 */
#ifdef BIOS_POSIX
#ifndef TIME
    //read_time();
#endif
#endif
  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/
  if (threadInst->barrier) 
  {
    err = pthread_barrier_wait (threadInst->barrier);
    if (err != 0 && err != PTHREAD_BARRIER_SERIAL_THREAD)
    {
      check("pthread_barrier_wait", err);
    }
  }

#ifdef BIOS_POSIX
#ifndef TIME
    end = read_time();
    Begin_Time = (long)(begin/1000000);
    End_Time = (long)(end/1000000);
#endif
#endif
  
#ifdef TIMEOFDAY
  gettimeofday (&End_TimeVal, NULL);
#endif
#ifdef TIMES
  times (&time_info);
  End_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
#ifdef BIOS_POSIX
  End_Time = time ( (time_t *) 0);
#else
  End_Time = time ( (long *) 0);
#endif
#endif
#ifdef MSC_CLOCK
  End_Time = clock();
#endif

#ifdef VERBOSE
  DHRY_printf ("Execution ends\n");
  DHRY_printf ("\n");
  DHRY_printf ("Final values of the variables used in the benchmark:\n");
  DHRY_printf ("\n");
  DHRY_printf ("Int_Glob:            %d\n", inst.Int_Glob);
  DHRY_printf ("        should be:   %d\n", 5);
  DHRY_printf ("Bool_Glob:           %d\n", inst.Bool_Glob);
  DHRY_printf ("        should be:   %d\n", 1);
  DHRY_printf ("Ch_1_Glob:           %c\n", inst.Ch_1_Glob);
  DHRY_printf ("        should be:   %c\n", 'A');
  DHRY_printf ("Ch_2_Glob:           %c\n", inst.Ch_2_Glob);
  DHRY_printf ("        should be:   %c\n", 'B');
  DHRY_printf ("Arr_1_Glob[8]:       %d\n", inst.Arr_1_Glob[8]);
  DHRY_printf ("        should be:   %d\n", 7);
  DHRY_printf ("Arr_2_Glob[8][7]:    %d\n", inst.Arr_2_Glob[8][7]);
  DHRY_printf ("        should be:   Number_Of_Runs + 10\n");
  DHRY_printf ("Ptr_Glob->\n");
  DHRY_printf ("  Ptr_Comp:          %d\n", (int) inst.Ptr_Glob->Ptr_Comp);
  DHRY_printf ("        should be:   (implementation-dependent)\n");
  DHRY_printf ("  Discr:             %d\n", inst.Ptr_Glob->Discr);
  DHRY_printf ("        should be:   %d\n", 0);
  DHRY_printf ("  Enum_Comp:         %d\n", inst.Ptr_Glob->variant.var_1.Enum_Comp);
  DHRY_printf ("        should be:   %d\n", 2);
  DHRY_printf ("  Int_Comp:          %d\n", inst.Ptr_Glob->variant.var_1.Int_Comp);
  DHRY_printf ("        should be:   %d\n", 17);
  DHRY_printf ("  Str_Comp:          %s\n", inst.Ptr_Glob->variant.var_1.Str_Comp);
  DHRY_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  DHRY_printf ("Next_Ptr_Glob->\n");
  DHRY_printf ("  Ptr_Comp:          %d\n", (int) inst.Next_Ptr_Glob->Ptr_Comp);
  DHRY_printf ("        should be:   (implementation-dependent), same as above\n");
  DHRY_printf ("  Discr:             %d\n", inst.Next_Ptr_Glob->Discr);
  DHRY_printf ("        should be:   %d\n", 0);
  DHRY_printf ("  Enum_Comp:         %d\n", inst.Next_Ptr_Glob->variant.var_1.Enum_Comp);
  DHRY_printf ("        should be:   %d\n", 1);
  DHRY_printf ("  Int_Comp:          %d\n", inst.Next_Ptr_Glob->variant.var_1.Int_Comp);
  DHRY_printf ("        should be:   %d\n", 18);
  DHRY_printf ("  Str_Comp:          %s\n",
                                inst.Next_Ptr_Glob->variant.var_1.Str_Comp);
  DHRY_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  DHRY_printf ("Int_1_Loc:           %d\n", Int_1_Loc);
  DHRY_printf ("        should be:   %d\n", 5);
  DHRY_printf ("Int_2_Loc:           %d\n", Int_2_Loc);
  DHRY_printf ("        should be:   %d\n", 13);
  DHRY_printf ("Int_3_Loc:           %d\n", Int_3_Loc);
  DHRY_printf ("        should be:   %d\n", 7);
  DHRY_printf ("Enum_Loc:            %d\n", Enum_Loc);
  DHRY_printf ("        should be:   %d\n", 1);
  DHRY_printf ("Str_1_Loc:           %s\n", Str_1_Loc);
  DHRY_printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  DHRY_printf ("Str_2_Loc:           %s\n", Str_2_Loc);
  DHRY_printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  DHRY_printf ("\n");
#else
  if (inst.Int_Glob != 5) {
    DHRY_printf ("Int_Glob:            %d\n", inst.Int_Glob);
    DHRY_printf ("        should be:   %d\n", 5);
    error = 1;
  }
  if (inst.Bool_Glob != 1) {
    DHRY_printf ("Bool_Glob:           %d\n", inst.Bool_Glob);
    DHRY_printf ("        should be:   %d\n", 1);
    error = 1;
  }
  if (inst.Ch_1_Glob != 'A')
  {
    DHRY_printf ("Ch_1_Glob:           %c\n", inst.Ch_1_Glob);
    DHRY_printf ("        should be:   %c\n", 'A');
    error = 1;
  }
  if (inst.Ch_2_Glob != 'B')
  {
    DHRY_printf ("Ch_2_Glob:           %c\n", inst.Ch_2_Glob);
    DHRY_printf ("        should be:   %c\n", 'B');
    error = 1;
  }
  if (inst.Arr_1_Glob[8] != 7)
  {
    DHRY_printf ("Arr_1_Glob[8]:       %d\n", inst.Arr_1_Glob[8]);
    DHRY_printf ("        should be:   %d\n", 7);
    error = 1;
  }
  if (inst.Arr_2_Glob[8][7] != Number_Of_Runs + 10)
  {
    DHRY_printf ("Arr_2_Glob[8][7]:    %d\n", inst.Arr_2_Glob[8][7]);
    DHRY_printf ("        should be:   Number_Of_Runs + 10\n");
    error = 1;
  }
#ifdef VERBOSE
  DHRY_printf ("Ptr_Glob->\n");
  DHRY_printf ("  Ptr_Comp:          %d\n", (int) Ptr_Glob->Ptr_Comp);
  DHRY_printf ("        should be:   (implementation-dependent)\n");
#endif
  if (inst.Ptr_Glob->Discr != 0)
  {
    DHRY_printf ("  Discr:             %d\n", inst.Ptr_Glob->Discr);
    DHRY_printf ("        should be:   %d\n", 0);
    error = 1;
  }
  if (inst.Ptr_Glob->variant.var_1.Enum_Comp != 2)
  {
    DHRY_printf ("  Enum_Comp:         %d\n", inst.Ptr_Glob->variant.var_1.Enum_Comp);
    DHRY_printf ("        should be:   %d\n", 2);
    error = 1;
  }
  if (inst.Ptr_Glob->variant.var_1.Int_Comp != 17)
  {
    DHRY_printf ("  Int_Comp:          %d\n", inst.Ptr_Glob->variant.var_1.Int_Comp);
    DHRY_printf ("        should be:   %d\n", 17);
    error = 1;
  }
  if (strcmp(inst.Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING") != 0)
  {
    DHRY_printf ("  Str_Comp:          %s\n", inst.Ptr_Glob->variant.var_1.Str_Comp);
    DHRY_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
    error = 1;
  }
#ifdef VERBOSE
  DHRY_printf ("Next_Ptr_Glob->\n");
  DHRY_printf ("  Ptr_Comp:          %d\n", (int) Next_Ptr_Glob->Ptr_Comp);
  DHRY_printf ("        should be:   (implementation-dependent), same as above\n");
#endif
  if (inst.Next_Ptr_Glob->Discr != 0)
  {
    DHRY_printf ("  Discr:             %d\n", inst.Next_Ptr_Glob->Discr);
    DHRY_printf ("        should be:   %d\n", 0);
    error = 1;
  }
  if (inst.Next_Ptr_Glob->variant.var_1.Enum_Comp != 1)
  {
    DHRY_printf ("  Enum_Comp:         %d\n", inst.Next_Ptr_Glob->variant.var_1.Enum_Comp);
    DHRY_printf ("        should be:   %d\n", 1);
    error = 1;
  }
  if (inst.Next_Ptr_Glob->variant.var_1.Int_Comp != 18)
  {
    DHRY_printf ("  Int_Comp:          %d\n", inst.Next_Ptr_Glob->variant.var_1.Int_Comp);
    DHRY_printf ("        should be:   %d\n", 18);
    error = 1;
  }
  if (strcmp (inst.Next_Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING") != 0)
  {
    DHRY_printf ("  Str_Comp:          %s\n",
                                  inst.Next_Ptr_Glob->variant.var_1.Str_Comp);
    DHRY_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
    error = 1;
  }
  if (Int_1_Loc != 5) 
  {
    DHRY_printf ("Int_1_Loc:           %d\n", Int_1_Loc);
    DHRY_printf ("        should be:   %d\n", 5);
    error = 1;
  }
  if (Int_2_Loc != 13)
  {
    DHRY_printf ("Int_2_Loc:           %d\n", Int_2_Loc);
    DHRY_printf ("        should be:   %d\n", 13);
    error = 1;
  }
  if (Int_3_Loc != 7)
  {
    DHRY_printf ("Int_3_Loc:           %d\n", Int_3_Loc);
    DHRY_printf ("        should be:   %d\n", 7);
    error = 1;
  }
  if (Enum_Loc != 1)
  {
    DHRY_printf ("Enum_Loc:            %d\n", Enum_Loc);
    DHRY_printf ("        should be:   %d\n", 1);
    error = 1;
  }
  if (strcmp (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING") != 0)
  {
    DHRY_printf ("Str_1_Loc:           %s\n", Str_1_Loc);
    DHRY_printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
    error = 1;
  }
  if (strcmp (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING") != 0)
  {
    DHRY_printf ("Str_2_Loc:           %s\n", Str_2_Loc);
    DHRY_printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
    error = 1;
  }
#endif

  if (error)
  {
     DHRY_printf("Error found\n");
     exit(1);
  }
  free(inst.Next_Ptr_Glob);
  free(inst.Ptr_Glob);
  User_Time = End_Time - Begin_Time;

  if (User_Time < Too_Small_Time)
  {
#ifdef VERBOSE
    DHRY_printf ("Measured time too small to obtain meaningful results\n");
    DHRY_printf ("Please increase number of runs\n");
    DHRY_printf ("\n");
#endif
  }
  else
  {
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#elif defined(TIMEOFDAY)
    timersub (&End_TimeVal, &Begin_TimeVal, &Diff_TimeVal);
    float_time = ((float)Diff_TimeVal.tv_sec) + ((float)(Diff_TimeVal.tv_usec))/Mic_secs_Per_Second;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) float_time;
#elif defined(BIOS_POSIX)
    {
        float float_time = (float)(end - begin);
        Types_FreqHz timerFreq; /* Timestamp frequency */
        Timestamp_getFreq(&timerFreq);
        float_time /= timerFreq.lo;
#if defined(DEVICE_KEYSTONE)
        float factor = 8.0; /* correct frequency coming from getFreq */
#elif defined(SOC_AM572x)
        float factor = 0.3333;
#else
        float factor = 1;
#endif
        Dhrystones_Per_Second = (float) Number_Of_Runs / (float) float_time * factor;
    }
#else
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;
#endif
#ifdef VERBOSE
    DHRY_printf ("Microseconds for one run through Dhrystone: ");
    DHRY_printf ("%6.1f \n", Microseconds);
    DHRY_printf ("Dhrystones per Second:                      ");
    DHRY_printf ("%6.1f \n", Dhrystones_Per_Second);
    DHRY_printf ("\n");
#endif
  }
  
  threadInst->results = Dhrystones_Per_Second;
  return arg;
}

int thread_create ( void *(start_routine)(void*), void* args, pthread_t *thread)
{
    int max_priority, err;
    pthread_attr_t attr;
    struct sched_param param;

#ifdef BIOS_POSIX
    max_priority = sched_get_priority_max();
    /* sched_get_priority_max should return Task_numPrioritis -1 but returns
     * Task_numPriorities instead.  This is a bug in BIOS */
    max_priority--;
#else
    max_priority = 0;
#endif
    err = pthread_attr_init(&attr);
    if (err) {
        DHRY_printf("pthread_attr_init failed: (%s)\n", strerror(err));
        return err;
    }
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    if (err) {
        DHRY_printf("pthread_attr_setdetachstate failed: (%s)\n", strerror(err));
        return err;
    }
    err = pthread_attr_setstacksize(&attr, DEFAULT_STACK_SIZE);
    if (err) {
        DHRY_printf("pthread_attr_setstacksize failed: (%s)\n", strerror(err));
        return err;
    }
    memset(&param, 0, sizeof(param));
    param.sched_priority = max_priority;
    err = pthread_attr_setschedparam(&attr, &param);
    if (err) {
        DHRY_printf("pthread_attr_setschedparam failed: (%s)\n", strerror(err));
        return err;
    }
    if (err) return err;
    err = pthread_create(thread, &attr, start_routine, args);
    if (err) {
        DHRY_printf("pthread_create failed: (%s)\n", strerror(err));
        return err;
    }
    if (err) return err;
    return 0;
}

void thread_wait (pthread_t *handle)
{
    check ("pthread_join", pthread_join(*handle, NULL));
    return;
}

float spawn (threadData_t *threadData, int iterations, int nThreads)
{
  int i;
  pthread_barrierattr_t battr;
  pthread_barrier_t barrier;
  float results = 0;

  if (nThreads == 0)
  {
    /* Direct run */
    threadData[0].threadInst.numIterations = iterations;
    threadData[0].threadInst.barrier = NULL;
    dhryThread (&threadData[0].threadInst);
    results = threadData[0].threadInst.results;
  }
  else
  {
    check ("pthread_barrierattr_init", pthread_barrierattr_init (&battr));
    check ("pthread_barrier_init", pthread_barrier_init (&barrier, &battr, nThreads));
    for (i = 0; i < nThreads; i++)
    {
      threadData[i].threadInst.numIterations = iterations;
      threadData[i].threadInst.barrier = &barrier;
      check ("thread_create",  thread_create (dhryThread, &threadData[i].threadInst, &threadData[i].threadId));
    }
    for (i = 0; i < nThreads; i++)
    {
      check ("pthread_join", pthread_join(threadData[i].threadId, NULL));
      results += threadData[i].threadInst.results;
    }
    check ("pthread_barrier_destroy", pthread_barrier_destroy (&barrier));
    check ("pthread_barrierattr_destroy", pthread_barrierattr_destroy (&battr));
  }
  return results;
}

/* This variable is used to modify the # of iterations spent during Dhrystone benchmark */
#define ITERATIONS 10000000

void *dhryMainThread(void *arg)
{
  int iterations = ITERATIONS;
  int threads = 1;
  float result, prevResult = 1;
  threadData_t threadData[MAX_THREADS];

  DHRY_printf ("Dhrystone Benchmark, Version 2.1+Thread (Language: C)\n");

  DHRY_printf ("Stage 1: find good iteration count without threads\n");
  do {
    DHRY_printf("Attempting %d iterations\n", iterations);
    result = spawn (threadData, iterations, 0);
    if (result < 0) {
      iterations *= 2;
    }
  } while (result < 0);
  DHRY_printf("dhrystones %d, dmips=%i\n", (int)result, (int)(result/1857));

  DHRY_printf ("Stage 2: find best number of threads\n");
  for (threads = 1; threads <= MAX_THREADS; threads *= 2)
  {
    DHRY_printf ("%d iterations * %d threads\n", iterations, threads);
    result = spawn (threadData, iterations, threads);
    DHRY_printf("dhrystones %d, dmips=%i\n", (int)result, (int)(result/1857));
    if (result/prevResult < 1.2)
    {
      break;
    }
    prevResult = result;
  }

  DHRY_printf("dhrystone benchmark complete\n");
  return(NULL);
}

int dhry_main(void)
{
    int err = dhryMainThread(NULL);
    return (err);
}

Proc_1 (dhryInstance_t *inst, REG Rec_Pointer Ptr_Val_Par)
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;  
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */
  
  structassign (*Ptr_Val_Par->Ptr_Comp, *inst->Ptr_Glob); 
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp 
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (inst, &Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp 
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (inst, Ptr_Val_Par->variant.var_1.Enum_Comp, 
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = inst->Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10, 
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


Proc_2 (dhryInstance_t *inst, One_Fifty *Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

{
  One_Fifty  Int_Loc;  
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (inst->Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - inst->Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


Proc_3 (dhryInstance_t *inst, Rec_Pointer *Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */


{
  if (inst->Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = inst->Ptr_Glob->Ptr_Comp;
  Proc_7 (10, inst->Int_Glob, &inst->Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


Proc_4 (dhryInstance_t *inst) /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = inst->Ch_1_Glob == 'A';
  inst->Bool_Glob = Bool_Loc | inst->Bool_Glob;
  inst->Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 (dhryInstance_t *inst) /* without parameters */
/*******/
    /* executed once */
{
  inst->Ch_1_Glob = 'A';
  inst->Bool_Glob = false;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif

