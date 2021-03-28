#!/usr/bin/env python

## @package  DecodeProfileDump
#
#
#  @file     decodeProfileDump.py
#
#  @brief    This is the script used for profile post-processing.
#
#  For more information, see:
#  - @subpage profCCS
#  - @subpage profDSS
#
#  ## Usage ##
#
#  Applications that are included in a profiling session must  set these
#  compiler flags for the desired platform:
#    - ARM: `-finstrument-functions -gdwarf-3 -g`
#    - DSP: `--entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g`
#    - M4: `--entry_parm=address --exit_hook=ti_utils_exit --exit_parm=address --entry_hook=ti_utils_entry -g`
#
#  For best results, ensure that the optimization levels are consistent between
#  the library and the project (typically -O3, or optimization level 3).
#
# Dependencies required:
#            * elftools (http://github.com/eliben/pyelftools/)
#            * tabulate (http://bitbucket.org/astanin/python-tabulate/)
#            * xlsxwriter (https://github.com/jmcnamara/XlsxWriter/)
#            * readelf.py included in the same directory as the script
#
# Usage:     python decodeProfileDump.py [log] [Function] ... [-v verbose]
#            [-t breakdown totals] [-x print Excel] [-h print histogram]
#            [-off N instrumentation offset of N cycles] [-csv print CSV]
#
# Known Issues:
#            * Functions with more than one entry point may not always map
#              correctly with their symbols
#
# Copyright (c) 2015, Texas Instruments Incorporated. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#    * Redistributions of source code must retain the above copyright
#        notice, this list of conditions and the following disclaimer.
#
#    * Redistributions in binary form must reproduce the above copyright
#        notice, this list of conditions and the following disclaimer in the
#        documentation and/or other materials provided with the distribution.
#
#    * Neither the name of Texas Instruments Incorporated nor the names of
#        its contributors may be used to endorse or promote products derived
#        from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
## @defgroup pdk_profiling_postprocessing PDK Post-Processing Script
## @ingroup pdk_profiling_tool
## @{

from collections import namedtuple
from collections import deque
from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection
from elftools.common.py3compat import maxint, bytes2str
from elftools.dwarf.descriptions import describe_form_class
from tabulate import tabulate
from operator import attrgetter
from sys import argv
import xlsxwriter
import subprocess
import copy
import csv
import os
import re

def readerror():
    print("Usage: python "+argv[0]+"[log] [optional: func] [-v verbose] [-t breakdown totals] [-x print Excel] [-csv print CSV] [-h print histogram] [-off N instrumentation offset]")
    exit()

# Custom Parameters: Parameters used in the script that can be altered for
# different uses, applications, or localizations
arguments = argv[1:]
should_log = "-v" in arguments
separate_callsite = "-t" in arguments
print_excel = "-x" in arguments
print_csv = "-csv" in arguments
should_print_hist = "-h" in arguments
instrumentation_entry_offset = 0
instrumentation_exit_offset = 0
# Manual Instrumentation Offset: Use this sparingly and only if the value
# calculated by the instrumentation hooks themselves is wrong or missing
has_offset = "-off" in arguments
instrumentation_entry_offset = 0
instrumentation_exit_offset = 0
if has_offset:
    try:
        instrumentation_entry_offset = int(arguments.pop(arguments.index("-off")+1))
        instrumentation_exit_offset = int(arguments.pop(arguments.index("-off")+2))
    except ValueError:
        readerror()
flags = [x for x in arguments if re.search('-',x)]
files = [x for x in arguments if (x not in flags and x != "" and x != " ")]

overall_label = "[overall]"
enter_keyword = "ENTER"
exit_keyword = "EXIT "
xlfilename = "report"
log_delimiter = "\n"
main_func_name = "main"
histogram_bins = 10
executable = None
if separate_callsite:
    headers = [
        "FUNCTION","REFERENCED BY", "TOTAL CYCLES (inc)", "TOTAL CYCLES (exc)",
        "AVG CYCLES (inc)","AVG CYCLES(exc)", "TOTAL CALLS", "ITER"]
else:
    headers = [
        "FUNCTION", "TOTAL CYCLES (inc)", "TOTAL CYCLES (exc)", "AVG CYCLES (inc)",
        "AVG CYCLES (exc)", "TOTAL CALLS", "ITER"]
histogramlabel = "Histogram"
binlabels = ["Low","High","Bin Size","Notes"]
devicelabels = ["Unknown Device","ARM","DSP","M4"]

# Boilerplate Functions: Used for simple operations throughout the script:
# * Returning the first element in a list that matches a query
def first(iterable):
        for element in iterable:
            return element
        return None
# * Returning a list of subarrays, or "chunks," iterable based on a given size
def chunks(array, size):
    # Note: This is an iterable; seen throughout this script and is a standard
    # Python syntax. Don't be afraid of iterables! They're fairly simple:
    #      objects of desired attr... with value...  in the array...
    return (array[pos:pos + size] for pos in xrange(0, len(array), size))
    #       subarrays for every...    index... in sequence... 0,1*size,2*size...
    #      ...then returned as a list
    #    You can think of iterables as a "for" loop that compares a given
    #    attribute and assembles an array of objects with that attribute. The
    #    attribute can be a comparison, but in this case, is used as the lower
    #    and upper bounds of a subarray
# * Parsing an input list into an array, using a predefined delimitor
def split(input):
    txt = str(input)
    parsed_logs = txt.split(log_delimiter)
    return parsed_logs

FuncNode = namedtuple('FuncNode',['lowpc','highpc','namestring'],verbose=False)
## @brief Build Function List
#
# Creates a lookup table from the given DWARF symbol
# table, based on the assembly addresses of each function
# Note: For both functions, named tuples are used instead of objects. Although
#        they are functionally the same, tuples hold values in a static context,
#        in Python, resulting in a faster access and search time
def parse_dwarf(dwarfinfo):
    if should_log:
        print("")
        print("Building DWARF lookup table...")
    templist = []
    for CU in dwarfinfo.iter_CUs():
        for DIE in CU.iter_DIEs():
            try:
                # Using each DIE (Debugging Information Entry), the lower and
                # upper bounds of a function (subprogram) are recorded. This
                # takes into account entries that may only have a length instead
                # of an upper-bound attribute
                if DIE.tag == 'DW_TAG_subprogram':
                    lowpc = DIE.attributes['DW_AT_low_pc'].value
                    highpc_attr = DIE.attributes['DW_AT_high_pc']
                    highpc_attr_class = describe_form_class(highpc_attr.form)
                    if highpc_attr_class == 'address':
                        highpc = highpc_attr.value
                    elif highpc_attr_class == 'constant':
                        highpc = lowpc + highpc_attr.value
                    else:
                        highpc = 0
                    namestring = bytes2str(DIE.attributes['DW_AT_name'].value)
                    if lowpc > 0:
                        templist.append(
                            FuncNode(
                                lowpc = lowpc, highpc = highpc,
                                namestring = namestring))
            except KeyError:
                continue
    if should_log:
        for temp in templist:
            print(temp.namestring+": "+str(temp.lowpc)+"/"+str(temp.highpc))
    return sorted(templist, key=lambda x: x.lowpc)
## @brief Secondary Build Function List
# Creates a secondary function list based on the
# symbol table in actual executable itself, as some symbols seem to be lost or
# ignored in the DWARF table, possibly due to function pointers
def parse_exec(elf_executable):
    dump_command = "python "+os.path.dirname(os.path.realpath(__file__))+"/readelf.py -s "+elf_executable
    if should_log:
        print("")
        print("Building secondary lookup table from elf dump...")
        print (dump_command)
    process = subprocess.Popen(dump_command, shell=True, stdout=subprocess.PIPE)
    output = process.stdout.read()
    symbols = output.split("\n")
    templist = []
    for symbol in symbols:
        func_params = symbol.split()
        if len(func_params) == 8 and func_params[3] == 'FUNC':
            lowpc = int(func_params[1],16)
            highpc = lowpc + int(func_params[2])
            namestring = str(func_params[7])
            templist.append(
                FuncNode(
                    lowpc = lowpc, highpc = highpc, namestring = namestring))
    if should_log:
        for temp in templist:
            print(temp.namestring+": "+str(temp.lowpc)+":"+str(temp.highpc))
    return sorted(templist, key=lambda x: x.lowpc)

## @brief Binary Search
# Used for quick lookup of a given address from a given lookup table
def binsearch(address, sym_dw_list):
    first = 0
    last = len(sym_dw_list) - 1
    while first <= last:
        mid = (first + last)/2
        if sym_dw_list[mid].lowpc <= address < sym_dw_list[mid].highpc:
            return sym_dw_list[mid].namestring
        if sym_dw_list[mid].lowpc > address:
            last = mid-1
        else:
            first = mid+1
    return None

## @brief Function Name Lookup
# Resolves the function name of the hex assembly address
# provided in the lookup tables. Note: If the function is not found in the
# symbol table generated from the DWARF table, the secondary table is searched
# as well. There is currently an issue with the pyelftools library in processing
# certain functions or function pointers
def lookup_funcname(addresshex, sym_dw_list, sym_ex_list):
    if addresshex == None or addresshex == overall_label or addresshex == '':
        return None
    address = addresshex
    namestring = binsearch(address, sym_dw_list)
    if namestring == None:
        namestring = binsearch(address, sym_ex_list)
    if namestring != None:
        return namestring
    else:
        if should_log:
            print("Could not resolve "+str(addresshex)+". Check your ELF file for consistency")
        return str(addresshex)

## @brief Outprint Logs
# Prints each entry of the log passed into the script with
# entry/exit labels, each function's resolved name, and timestamp
def print_logs(logs, sym_dw_list, sym_ex_list):
    print("")
    print("Resolving logs of "+executable+"...")
    for chunk in chunks(logs, 4):
        if chunk[0] != '':
            is_enter = int(chunk[0], 16)
            fn_addr = int(chunk[1],16)
            ref_addr = int(chunk[2],16)
            timestamp = chunk[3]
            if is_enter == 1:
                fn_name = lookup_funcname(fn_addr, sym_dw_list, sym_ex_list)
                print(enter_keyword+" "+fn_name+" "+timestamp)
            elif is_enter == 0:
                fn_name = lookup_funcname(fn_addr, sym_dw_list, sym_ex_list)
                print(exit_keyword+" "+fn_name+" "+timestamp)
            # The first quartet of the log is the exec information, consisting
            #    of the device type, instrumentation time offset, and potentially
            #    more information in future iterations
            elif is_enter == 2:
                # Uses the localized device descriptions above for logging
                arch_type = fn_addr
                if arch_type == 1 or arch_type == 2 or arch_type == 3:
                    device = devicelabels[arch_type]
                else:
                    device = devicelabels[0]
                print(device+" Log with time offset "+timestamp)

## @brief Expand Timestamp
# Utilizes the fact log entry timestamps are increasing 32-bit
# unsigned integers, tracking each timestamp's overflow to expand it to 64-bit
last_clock = 0
high_clock = 0
def expand_timestamp(low_clock):
    global high_clock
    global last_clock
    if (last_clock & 2147483648) and not (low_clock & 2147483648):
        high_clock += 1
    last_clock = low_clock
    new_clock = (high_clock << 32) | low_clock
    return new_clock

## @brief Increment Object
# Stores total measurements counted during processing to be
# printed once processing is complete
class PrintNode(object):
        def __init__(
                self, fn_name, ref_addr, cycles_inc,cycles_exc, calls_inc,
                calls_exc, count):
            self.fn_name = fn_name
            self.ref_addr = ref_addr
            self.cycles_inc = cycles_inc
            self.cycles_exc = cycles_exc
            self.calls_inc = calls_inc
            self.calls_exc = calls_exc
            self.iter = count
            self.histogram = []
def increment_obj(print_list,tempexc,tempinc,should_append_overall):
    if should_append_overall:
        # Note that if the user opts to separate logs by callsite, this function
        #    is called again to maintain another printnode object of the total
        #    measurements
        increment_obj(print_list,tempexc,tempinc,False)
        tempobj = first(temp for temp in print_list if (
            temp.fn_name == tempinc.fn_name and
            temp.ref_addr == tempinc.ref_addr))
    else:
        tempobj = first(temp for temp in print_list if (
            temp.fn_name == tempinc.fn_name and
            temp.ref_addr == overall_label))
    if tempobj != None:
        tempindex = print_list.index(tempobj)
        print_list[tempindex].cycles_exc += tempexc.time
        print_list[tempindex].cycles_inc += tempinc.time
        print_list[tempindex].calls_exc = tempexc.iter
        print_list[tempindex].calls_inc = tempinc.iter
        print_list[tempindex].iter += 1
    else:
        if should_append_overall:
            print_list.append(
                PrintNode(
                    tempexc.fn_name, tempexc.ref_addr, tempinc.time,
                    tempexc.time, tempinc.iter, tempexc.iter, 1))
        else:
            if separate_callsite:
                tempobj1 = first(temp for temp in print_list if (
                    temp.fn_name == tempinc.fn_name and
                    temp.ref_addr != tempinc.ref_addr))
                if tempobj1 != None:
                    tempobj1 = copy.copy(tempobj1)
                    tempobj1.ref_addr = overall_label
                    print_list.append(tempobj1)
                    increment_obj(print_list,tempexc,tempinc,False)
            else:
                print_list.append(
                    PrintNode(
                        tempexc.fn_name, overall_label, tempinc.time,
                        tempexc.time, tempinc.iter, tempexc.iter, 1))

## @brief Exit Log
# Handles "exit" log entries, calculating the time elapsed by each
# function and the total cycles required. Note:
#    * The inclusive time elapsed by a function is added to the timestamp of
#      the top function of the exclusive stack so that the time taken by the
#      inclusive function is not included in the exclusive function
def log_exit(log_list,print_list,timestamp,stack_exc,stack_inc,instrumentation_entry_offset,instrumentation_exit_offset):
    tempinc = stack_inc.pop()
    tempexc = stack_exc.pop()
    tempinc.time = timestamp-tempinc.time+instrumentation_exit_offset
    tempexc.time = timestamp-tempexc.time-instrumentation_entry_offset
    if len(stack_exc) != 0:
        stack_inc[len(stack_inc)-1].iter += tempinc.iter
        stack_exc[len(stack_exc)-1].time += tempinc.time
    tempstring = "    "*(len(stack_inc)+1)+str(tempinc.time)+" cycles, at "+str(tempinc.iter)+" fn calls inc"+"\n"+"    "*(len(stack_inc)+1)+str(tempexc.time)+" cycles, at "+str(tempexc.iter)+" fn calls exc"+"\n"+"    "*len(stack_inc)+"}" # + "  " + str(timestamp)
    if should_log:
        print(tempstring)
    increment_obj(print_list,tempexc,tempinc,separate_callsite)
    log_list.append(tempexc)
    if len(stack_inc) == 0:
        return tempstring, tempinc.time, 1
    else:
        return tempstring, 0, 0        

## @brief Process Logs
# Iterates through each log entry and processes entry/exit pairs
#    to calculate time elapsed, total calls, and iterations while resolving the
#    name of each function for the final printout. Note:
#    * "Calls" are defined as instrumented function calls that are made by a
#      given function
#    * "Cycles" are the total number of processor ticks elapsed by the function
#    * "Iterations" are the number of references, or times the single function
#      is called
class LogNode(object):
    def __init__(self, fn_addr, fn_name, ref_addr, time, count):
        self.fn_addr = fn_addr
        self.fn_name = fn_name
        self.ref_addr = ref_addr
        self.time = time
        self.iter = count
def process_logs(arch_list,logs,sym_dw_list, sym_ex_list):
    arch_list_size = len(arch_list)
    log_list = []
    print_list = []
    out_buffer = ""
    if should_log:
        print("")
        print("Counting iterations of "+executable+":")
    stack_inc = deque([])
    stack_exc = deque([])
    task_stack_dict_inc = {}
    task_stack_dict_exc = {}
    task_timestamp_dict_inc = {}
    task_timestamp_dict_exc = {}
    task_timestamp_dict_idle = {}
    task_timestamp_cycle_inc = {}
    last_timestamp = 0
    idle_time_flag = 0
    cycle_count_inc = 0
    cycle_count_inc1 = 0
    cycle_count_idle = 0
    cycle_count_idle1 = 0
    cycle_count_offset = 0
    # this factor decides if clock for core and timer is different.
    divide_factor = 1
    for chunk in chunks(logs, 4):
        if chunk[0] != '':
            # Break each chunk, or log, into its individual attributes. Note
            # that each value is in hex
            is_enter = int(chunk[0], 16)
            fn_addr = int(chunk[1], 16)
            ref_addr = int(chunk[2], 16)
            timestamp = (expand_timestamp(int(chunk[3], 16)) / divide_factor)
            if is_enter == 1:
                fn_name = lookup_funcname(fn_addr, sym_dw_list, sym_ex_list)
                if separate_callsite:
                    cs_name = lookup_funcname(ref_addr, sym_dw_list, sym_ex_list)
                else:
                    cs_name = ref_addr
                if len(stack_inc) != 0:
                    stack_inc[len(stack_inc)-1].iter += 1
                    stack_exc[len(stack_exc)-1].iter += 1
                # Used for debugging and for logging output:
                tempstring = "    "*len(stack_inc)+str(fn_name)+" {    " # + str(fn_addr) + "  " + str(timestamp)
                out_buffer += tempstring+"\n"
                if should_log:
                    print(tempstring)
                # Programs compiled with GCC have an extra "call_site" attribute
                # that records the function that called the function currently
                # being instrumented. If this information is not provided,
                # likely because the program used the TI compiler, the address
                # of the last function on the stack is used instead
                if ref_addr == 0:
                    tempinc = LogNode(fn_addr,fn_name,"",timestamp,0)
                    tempexc = LogNode(fn_addr,fn_name,"",timestamp,0)
                    if len(stack_inc) != 0:
                        tempinc.ref_addr = stack_inc[len(stack_inc)-1].fn_name
                        tempexc.ref_addr = stack_inc[len(stack_exc)-1].fn_name
                else:
                    tempinc = LogNode(fn_addr,fn_name,cs_name,timestamp,0)
                    tempexc = LogNode(fn_addr,fn_name,cs_name,timestamp,0)
                stack_inc.append(tempinc)
                stack_exc.append(tempexc)
                if idle_time_flag != 0:
                    cycle_count_idle = cycle_count_idle + timestamp - last_timestamp
                    idle_time_flag = 0
            elif is_enter == 0:
                fn_name = lookup_funcname(fn_addr, sym_dw_list, sym_ex_list)
                # The exit log is matched to the entry hook to ensure that no
                # functions are unaccounted for. This can become problematic
                # so the last function on the stack is removed before proceeding
                if fn_addr == stack_inc[len(stack_inc)-1].fn_addr:
                    tempstring, temp_count, idle_time_flag = log_exit(log_list,print_list,timestamp,stack_exc,stack_inc,instrumentation_entry_offset,instrumentation_exit_offset)
                    cycle_count_inc = cycle_count_inc + temp_count
                    cycle_count_offset += instrumentation_exit_offset+instrumentation_entry_offset
                    out_buffer += tempstring+"\n"
                    if idle_time_flag != 0:
                        last_timestamp = timestamp
                else:
                    print("Inconsistency error. Function exit \""+stack_inc[len(stack_inc)-1].fn_name+"\" does not match function begin \""+fn_name+"\" on stack")
                    stack_inc.pop()
                    stack_exc.pop()
            elif is_enter == 2:
                # The first log generated by the programming hooks contains
                # the processor type and the measured instrumentation offset
                if fn_addr == 1:
                    arch_list.append("ARM")
                    divide_factor = 1
                elif fn_addr == 2:
                    arch_list.append("DSP")
                    divide_factor = 1
                elif fn_addr == 3:
                    arch_list.append("M4")
                    # timer clock for m4 is running at twice the speed of processor speed i.e. 40 Mhz
                    divide_factor = 2
                else:
                    arch_list.append("UNKNOWN")
                if ref_addr == 1:
                    # the first timestamp has already been taken so need to divide it specially
                    # for the next case, it will be divided by the required factor automatically
                    # as divide factor has been set correct value.
                    instrumentation_entry_offset = timestamp/divide_factor
                else:
                    instrumentation_exit_offset = timestamp
            elif is_enter == 3:
                # The task switch log generated for handling the case of context 
                # switch, so the inconsistancy between entry/exit hooks can be matched
                if ref_addr == 0:
                    task_stack_dict_inc[fn_addr] = stack_inc
                    task_stack_dict_exc[fn_addr] = stack_exc
                    task_timestamp_dict_inc[fn_addr] = timestamp
                    task_timestamp_dict_exc[fn_addr] = timestamp
                    task_timestamp_dict_idle[fn_addr] = cycle_count_idle
                    task_timestamp_cycle_inc[fn_addr] = cycle_count_inc
                else:
                    if idle_time_flag != 0:
                        cycle_count_idle = cycle_count_idle + timestamp - last_timestamp
                        idle_time_flag = 0                        
                    if (ref_addr in task_stack_dict_inc) and (ref_addr in task_stack_dict_exc):
                        task_stack_dict_inc[ref_addr] = stack_inc
                        task_stack_dict_exc[ref_addr] = stack_exc
                        task_timestamp_dict_inc[ref_addr] = timestamp
                        task_timestamp_dict_exc[ref_addr] = timestamp
                        task_timestamp_dict_idle[ref_addr] = cycle_count_idle
                        task_timestamp_cycle_inc[ref_addr] = cycle_count_inc
                        stack_inc = deque([])
                        stack_exc = deque([])

                        if fn_addr in task_stack_dict_inc:
                            stack_inc1 = task_stack_dict_inc[fn_addr]
                            stack_exc1 = task_stack_dict_exc[fn_addr]
                            old_timestamp = task_timestamp_dict_inc[fn_addr]
                            cycle_count_idle = task_timestamp_dict_idle[fn_addr]
                            cycle_count_inc = task_timestamp_cycle_inc[fn_addr]
                            while True:
                                try:
                                    tempLog = stack_inc1.popleft()
                                    tempLog.time = tempLog.time + timestamp - old_timestamp
                                    stack_inc.append(tempLog) 
                                except IndexError:
                                    break
                            while True:
                                try:
                                    tempLog = stack_exc1.popleft()
                                    tempLog.time = tempLog.time + timestamp - old_timestamp
                                    stack_exc.append(tempLog) 
                                except IndexError:
                                    break  
                            if len(stack_inc) == 0:
                                idle_time_flag = 1
                                last_timestamp = timestamp                
                        else:
                            idle_time_flag = 1
                            last_timestamp = timestamp
                            cycle_count_idle = 0
                            cycle_count_inc = 0

                        task_stack_dict_inc[fn_addr] = deque([])
                        task_stack_dict_exc[fn_addr] = deque([])
                        task_timestamp_dict_idle[fn_addr] = 0    
                        task_timestamp_cycle_inc[fn_addr] = 0
                    else:
                        print("Inconsistency error. Current task is not in the task list")
                    
    # Note: For consistency, the remaining enter entries that have not been
    #    matched with an exit entry are counted for consistency. This is because
    #    some functions, such as main, may never reach an entry hook at runtime
    if len(stack_inc) != 0:
        if should_log:
            print("Parsing remaining function calls that are missing exit hooks:")
        while not len(stack_inc) == 0:
            tempstring, temp_count, idle_time_flag = log_exit(log_list,print_list,timestamp,stack_exc,stack_inc,instrumentation_entry_offset,instrumentation_exit_offset)
            cycle_count_inc = cycle_count_inc + temp_count
            cycle_count_offset += instrumentation_exit_offset+instrumentation_entry_offset
            out_buffer += tempstring+"\n"
    cycle_count_inc1 = cycle_count_inc1 + cycle_count_inc
    cycle_count_idle1 = cycle_count_idle1 + cycle_count_idle
    for stck in task_stack_dict_inc:
        stack_inc = task_stack_dict_inc[stck]
        stack_exc = task_stack_dict_exc[stck]
        cycle_count_idle = task_timestamp_dict_idle[stck]
        cycle_count_inc = task_timestamp_cycle_inc[stck]
        if len(stack_inc) != 0:
            timestamp = task_timestamp_dict_exc[stck]
            if should_log:
                print("Parsing remaining function calls that are missing exit hooks:")
            while not len(stack_inc) == 0:
                tempstring, temp_count, idle_time_flag = log_exit(log_list,print_list,timestamp,stack_exc,stack_inc,instrumentation_entry_offset,instrumentation_exit_offset)
                cycle_count_inc = cycle_count_inc + temp_count
                cycle_count_offset += instrumentation_exit_offset+instrumentation_entry_offset
                out_buffer += tempstring+"\n"
        cycle_count_inc1 = cycle_count_inc1 + cycle_count_inc
        cycle_count_idle1 = cycle_count_idle1 + cycle_count_idle
    cycle_count_inc1 = cycle_count_inc1 ++ cycle_count_idle1
    print_list.append(PrintNode("Idle cycle", overall_label, cycle_count_idle1,
                                cycle_count_idle1, 0, 0, 1))
    if len(print_list) == 0:
        print("No parsable logs found. Check enter and exit keywords and/or whether the program has the correct format.")
        exit()
    if len(arch_list) == arch_list_size:
        arch_list.append("UNKNOWN")
    return print_list,log_list,out_buffer,cycle_count_inc1,cycle_count_offset

## @brief Get Dwarf
# Reads the ELF and DWARF information of the given executable
def get_dwarf(func):
    if should_log:
        print("")
        print("Reading ELF from "+func+"...")
    if func[0:2] == "./":
        func = func[2:]
    with open(func, 'rb') as stream:
        elffile = ELFFile(stream)
        section = elffile.get_section_by_name('.symtab')
        if not section:
            print("No Symbol Table found in ELF. Perhaps you didn't include the function instrumentation flag(s) when compiling?")
        elif not elffile.has_dwarf_info():
            print("No DWARF info found in ELF. Perhaps you didn't include -g when compiling?")
        else:
            dwarfinfo = elffile.get_dwarf_info()
            return dwarfinfo
    return None

## @brief Verify Values
# Verifies the values of the processing function by:
#    * Comparing the sum of all exclusive time values with the total
#      (inclusive) time value of main, the lowest-level function
def verify_values(print_list,cycle_count_inc,cycle_count_offset):
    if should_log:
        print("Sanity-checking values...")
    excsum = 0
    for obj in print_list:
        if separate_callsite and obj.ref_addr != overall_label:
            excsum += obj.cycles_exc
        elif not separate_callsite:
            excsum += obj.cycles_exc
    
    excsum += cycle_count_offset
    if should_log:
        print("No of offset cycle :"+str(cycle_count_offset))

    if excsum == cycle_count_inc:
        if should_log:
            print("Exclusive cycle count matches total cycle count")
            print("exclusive cycle count      "+str(excsum))
            print("inclusive cycle count      "+str(cycle_count_inc))
        return True
    else:
        print("Exclusive cycle count does NOT match total cycle count. Check input for inconsistency")
        print("exclusive cycle count      "+str(excsum))
        print("inclusive cycle count      "+str(cycle_count_inc))
        return True

## @brief Tabulate Table
# Organizes the total values into sorted lists that will be
#    printed to the terminal, a text file, and to a .xlsx file, should the user
#    choose to do so. The main goal of this function is to merge each node
#    generated from each executable by function to be printed
def tabulate_table(arch_list,print_list_cols):
    tab_out_list = []
    if should_log:
        print("")
        print("Final Report of "+executable+":")
    i = 0
    for print_list in print_list_cols:
        if separate_callsite:
            sorted_print_list = sorted(print_list, key=lambda obj: (
                obj.cycles_exc/obj.iter,obj.ref_addr == overall_label,obj.fn_name))
        else:
            sorted_print_list = sorted(print_list, key=lambda obj: (obj.cycles_exc/obj.iter))
        # Since the tabulate library uses a list of lists to form its table
        # structure, the data set is filled as if it were a table traversing
        # left, then down. As such, empty cells also need to be accounted for
        # E.g. Example List: [[elem1, elem2],["",elem3],[elem4, elem5, elem6]]
        #       Example Table:    attr1    attr2    attr3
        #                        -----    -----    -----
        #                        elem1    elem2    elem3
        #                        elem4    elem5    elem6
        for obj in sorted_print_list:
            if separate_callsite:
                funcitem = first(temp for temp in tab_out_list if (temp.fn_name == obj.fn_name and temp.ref_addr == obj.ref_addr))
            else:
                funcitem = first(temp for temp in tab_out_list if temp.fn_name == obj.fn_name)
            if funcitem == None:
                funcitem = PrintNode(obj.fn_name,obj.ref_addr,[""]*i + [obj.cycles_inc],[""]*i + [obj.cycles_exc],[""]*i + [obj.calls_inc],[""]*i + [obj.calls_exc],[0]*i + [obj.iter])
                tab_out_list.append(funcitem)
            else:
                funcitem.cycles_inc.append(obj.cycles_inc)
                funcitem.cycles_exc.append(obj.cycles_exc)
                funcitem.calls_inc.append(obj.calls_inc)
                funcitem.calls_exc.append(obj.calls_exc)
                funcitem.iter.append(obj.iter)
        # For programs that are missing the functions that are in another, empty
        # Entries are added to the columns for consistency (see above)
        for otherobj in [obj for obj in tab_out_list if len(obj.cycles_inc) == i]:
            otherobj.cycles_inc.append("")
            otherobj.cycles_exc.append("")
            otherobj.calls_inc.append("")
            otherobj.calls_exc.append("")
            otherobj.iter.append(0)
        i += 1
    headerlist = [headers.pop(0)]
    if separate_callsite:
        # If the user opts to separate the function logs by call site, another
        # column is added to distinguish one from another from the overall log
        # of that function
        headerlist.append(headers.pop(0))
    preheader_size = len(headerlist)
    for i in range(0,len(headers)):
        # This is also a standard Python syntax: multiplying strings. This
        # operator simply appends copies of the string passed, in this case,
        # the table headers to represent each processor type
        headerlist.extend([headers[i]]*(len(print_list_cols)))
    for i in range(0,len(print_list_cols)*len(headers)):
        j = i+preheader_size
        headerlist[j]+=" "+arch_list[i%len(print_list_cols)]
    return tab_out_list,headerlist

## @brief Print Final
# Uses the tabulated data list to create the final output table
def print_final(tab_out_list,headerlist,parity,out_buffer,num_print_tries):
    tabulated_list = []
    # Checks if the filename specified already exists, to prevent overwriting
    # data. If so, the name is incremented
    if (os.path.isfile(xlfilename+".txt")):
        num_print_tries += 1
        while os.path.isfile(xlfilename+str(num_print_tries)+".txt"):
            num_print_tries += 1
    # The code below simply converts the merged print nodes into lists that
    # can be processed by the tabulate library
    for merged_node in tab_out_list:
        temp = [merged_node.fn_name] #Initialize an array with the first element
        if separate_callsite:
            temp.append(merged_node.ref_addr)
        # Append the Total Cycles (inc)
        temp.extend(merged_node.cycles_inc)
        # Append the Total Cycles (exc)
        for i in range(0,len(merged_node.iter)):
            if merged_node.cycles_exc[i] < 0:
                # appending 0 in the situation where time interval is too small to benchmark
                temp.extend("0")
            else:
                temp.extend(merged_node.cycles_exc)
        # Append the Average Cycles (inc)
        for i in range(0,len(merged_node.iter)):
            if merged_node.iter[i] != 0:
                temp.append(merged_node.cycles_inc[i]/merged_node.iter[i])
            else:
                temp.append("")
        # Append the Average Cycles (exc)
        for i in range(0,len(merged_node.iter)):
            if merged_node.iter[i] != 0:
                if merged_node.cycles_exc[i] < 0:
                    temp.append("0")
                else:
                    temp.append(merged_node.cycles_exc[i]/merged_node.iter[i])
            else:
                temp.append("")
        # Append the Total Calls
        temp.extend(merged_node.calls_exc)
        # Append the Iterations
        temp.extend(merged_node.iter)
        # Added space for safety when printing (consistent array lengths)
        temp.append("")
        # Append the function histogram
        temp.extend(merged_node.histogram)
        tabulated_list.append(temp)

    text_table = tabulate(tabulated_list, headerlist, tablefmt="simple")
    print(text_table)
    if print_excel:
        if should_log:
            print("Writing to Excel...")
        if num_print_tries == 0:
            workbook = xlsxwriter.Workbook(xlfilename+".xlsx")
        else:
            workbook = xlsxwriter.Workbook(xlfilename+str(num_print_tries)+".xlsx")
        worksheet = workbook.add_worksheet()
        # Formats the text, such that:
        #    * Column headers (first row) are bold and frozen
        #    * Function names (first column) are bold and frozen
        header_format = workbook.add_format(
            {'bold': True, 'align': 'center', 'valign': 'vcenter'})
        header_format.set_text_wrap()
        worksheet.freeze_panes(1, 1)
        #    * Attribute columns are 20 spaces wide
        #    * Histogram columns are 10 spaces wide
        #    * Notes column and beyond are 150 spaces wide
        for i, col in enumerate(headerlist):
            worksheet.write(0,i,col,header_format)
            worksheet.set_column(i,i,20)
            if (i > (parity*7)):
                worksheet.set_column(i,i,10)
            if (i > (parity*7)+histogram_bins+4):
                worksheet.set_column(i,i,150)
        #    * Function column is 35 spaces wide
        worksheet.set_column(0,0,35)
        #    * All attribute columns are colored by parity for easy-viewing.
        #      There will likely be no more than four executables compared in
        #      a given report, but in case there are, more colors can be added
        for i, l in enumerate(tabulated_list):
            for j, col in enumerate(l):
                if (j < parity*7+1):
                    if (j == 0):
                        text_format = workbook.add_format({'bold':True})
                    elif (j%parity == 0):
                        text_format = workbook.add_format({'color':'blue'})
                    elif (j%parity == 1):
                        text_format = workbook.add_format({'color':'black'})
                    elif (j%parity == 2):
                        text_format = workbook.add_format({'color':'green'})
                    elif (j%parity == 3):
                        text_format = workbook.add_format({'color':'purple'})
                else:
                    text_format = workbook.add_format({'bold':False,'color':'black'})
                worksheet.write(i+1,j,col,text_format)
        try:
            # XLSXWriter will attempt to write to the filename assigned above,
            # in the same directory as the script. If the filename is already
            # taken and cannot be overwritten, a number is appended to the
            # filename
            workbook.close()
        except IOError:
            print("Could not write to file. Close any open instances of the report file and try again.")
            exit()
    if print_csv:
        if num_print_tries == 0:
            csvNameString = xlfilename+".csv"
        else:
            csvNameString = xlfilename+str(num_print_tries)+".csv"
        with open(csvNameString, 'wb') as csvfile:
            csvwriter = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
            csvwriter.writerow(headerlist)
            for csvrow in tabulated_list:
                csvwriter.writerow(csvrow)
    if num_print_tries == 0:
        reportfile = open(xlfilename+".txt", 'w')
    else:
        reportfile = open(xlfilename+str(num_print_tries)+".txt",'w')
    reportfile.write(text_table+"\n"*2+out_buffer)
    reportfile.close()

## @brief Resolve File
# Similar to the resolve function name function above, but instead
# searches for the file and line number of the reference provided
def resolve_file(dwarfinfo, addresshex):
    address = addresshex
    for CU in dwarfinfo.iter_CUs():
        lineprog = dwarfinfo.line_program_for_CU(CU)
        prevstate = None
        for entry in lineprog.get_entries():
            if entry.state is None or entry.state.end_sequence:
                continue
            if prevstate and prevstate.address <= address < entry.state.address:
                filename = lineprog['file_entry'][prevstate.file - 1].name
                line = prevstate.line
                return filename, line
            prevstate = entry.state
    return None, None

## @brief Tabulate Histogram
# Uses the list values to create a histogram with the bin
# count specified above
def tabulate_histogram(printlist,log_pr_list,dwarfinfo,sym_dw_list,sym_ex_list):
    parse_logs_combined = [j for i in log_pr_list for j in i]
    if should_log:
        print("")
        print("Building Histogram...")
    for printitem in printlist:
        if printitem.iter[0] > 1:
            # For every Print Node (function) a histogram is built if it has
            # more than one reference in the log. This is used to determine the
            # normalized scale and if there are any abnormally inefficient
            # references
            if separate_callsite and printitem.ref_addr != overall_label:
                func_sublist = [func for func in parse_logs_combined if (func.fn_name ==
                    printitem.fn_name and func.ref_addr == printitem.ref_addr)]
            else:
                func_sublist = [func for func in parse_logs_combined if func.fn_name ==
                    printitem.fn_name]
            maxvalue = max(obj.time for obj in func_sublist)
            minvalue = min(obj.time for obj in func_sublist)
            mintemp = minvalue
            binsize = ((maxvalue-minvalue)/(histogram_bins-1))
            frequencylist = []
            bin_idx = 0
            # The bucket frequency values are appended to the frequency list in
            # the same manner they were populated in the tabulate function
            if binsize > 0:
                while bin_idx < histogram_bins-1:
                    frequencylist.append(0)
                    for obj in func_sublist:
                        if minvalue <= obj.time < (minvalue + binsize):
                            frequencylist[bin_idx] += 1
                    bin_idx += 1
                    minvalue += binsize
                frequencylist.append(0)
                for obj in func_sublist:
                    if minvalue <= obj.time <= maxvalue:
                        frequencylist[bin_idx] += 1
            else:
                for i in range(0,histogram_bins):
                    frequencylist.append("")
            # Append the min, max, and bin size values
            frequencylist.append(mintemp)
            frequencylist.append(maxvalue)
            frequencylist.append(binsize)
            # The outlier function (if there is one) is then resolved and added
            # to the notes section of the report for debugging
            if binsize > 0:
                if dwarfinfo != None:
                    bigfunc = max(func_sublist, key=attrgetter('time'))
                    i = 0
                    for parse_logs in log_pr_list:
                        if bigfunc in parse_logs:
                            break
                        i += 1
                    filename, line = resolve_file(dwarfinfo[i],bigfunc.fn_addr)
                    if frequencylist[0] > sum(frequencylist[1:histogram_bins-1]):
                        outliermsg = "High outlier function \""+bigfunc.fn_name+"\" "
                        if bigfunc.ref_addr != None:
                            outliermsg = outliermsg+"was referenced by \""+str(bigfunc.ref_addr)+"\" "
                        if filename != None:
                            outliermsg = outliermsg+"in "+filename+" "
                            if line != None:
                                outliermsg = outliermsg+": "+str(line)+" "
                        frequencylist.append(outliermsg)
            printitem.histogram = frequencylist

# Program Main
merged_list = [] # Merged lognodes for printing
sym_dw_list = [] # Symbols processed from the DWARF symbol information
sym_ex_list = [] # Symbols processed from the executable, itself
log_pr_list = [] # Separate lognodes for processing histogram
dtable_list = [] # List of DWARF symbol tables used for processing and resolution
out_buffer = ""  # String buffer used to output the trace information and
                 #    messages to the report text document
arch_list = []     # Architecture list used to coordinate the architecture labels
                 #    in the output files
if len(files) == 0:
    readerror()
while len(files) > 0:
    # Pops files off of the file list to be processed
    dump_file = files.pop(0)
    if len(files) == 2:
        should_print_hist = True
    executable = files.pop(0)
    parse_logs = split(open(dump_file).read())
    if os.path.isfile(executable) and os.access(executable, os.R_OK):
        dinfo = get_dwarf(executable)
        # In case the user adds the files in the wrong parity, the two files are
        #    reversed to try again
        if dinfo == None:
            dinfo = get_dwarf(dump_file)
            executable=dump_file
        if dinfo != None:
            dtable_list.append(dinfo)
            sym_dw_list.append(parse_dwarf(dinfo))
            sym_ex_list.append(parse_exec(executable))
        else:
            readerror()
    # Determine whether the first entry in the log file is the memory headers,
    #    which must be removed for processing
    try:
        header = int(parse_logs[0])
    except ValueError:
        header = None
    if header != 0 and header != 1:
        parse_logs.pop(0)

    # For debugging purposes, verbose mode prints each log entry with its
    #    resolved name and entry/exit
    if should_log:
        print_logs(
            parse_logs,sym_dw_list[len(sym_dw_list)-1],
            sym_ex_list[len(sym_ex_list)-1])

    # Processes logs into:
    #    * Print List: used to tabulate the final table for output
    #    * Log List: used for tabulating the histogram
    #    * Output Buffer: used to output trace information in the final report
    # Output is then verified before appended to the final output lists
    if len(sym_dw_list) == 0:
        print("Found Zero.")

    printlist,log_list,tempout_buffer,cycle_count_inc,cycle_count_offset = process_logs(arch_list,parse_logs,
        sym_dw_list[len(sym_dw_list)-1],sym_ex_list[len(sym_ex_list)-1])

    if verify_values(printlist,cycle_count_inc,cycle_count_offset):
        merged_list.append(printlist)
        log_pr_list.append(log_list)
        out_buffer+=arch_list[len(arch_list)-1]+":\n"+tempout_buffer+"\n"*2

if len(merged_list) > 0:
    tabulated_list,headerlist = tabulate_table(arch_list,merged_list)
    if should_print_hist:
        # Histogram headers are added so that they appear in the table
        headerlist.append(histogramlabel)
        for i in range(0,histogram_bins):
            headerlist.append("Bin "+str(i))
        headerlist.extend(binlabels)
        tabulate_histogram(
            tabulated_list,log_pr_list,dtable_list,sym_dw_list,sym_ex_list)
    else:
        headerlist.append("")
    print_final(tabulated_list,headerlist,len(merged_list),out_buffer,0)

if should_log:
    print("Complete.")
## @}
