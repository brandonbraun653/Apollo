#/*
# *  Copyright (c) Texas Instruments Incorporated 2018
# * 
# *  Redistribution and use in source and binary forms, with or without 
# *  modification, are permitted provided that the following conditions 
# *  are met:
# *
# *    Redistributions of source code must retain the above copyright 
# *    notice, this list of conditions and the following disclaimer.
# *
# *    Redistributions in binary form must reproduce the above copyright
# *    notice, this list of conditions and the following disclaimer in the 
# *    documentation and/or other materials provided with the   
# *    distribution.
# *
# *    Neither the name of Texas Instruments Incorporated nor the names of
# *    its contributors may be used to endorse or promote products derived
# *    from this software without specific prior written permission.
# *
# *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
# *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
# *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
# *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
# *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
# *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
# *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
# *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# *
#*/
#
# @desc USB-DEV-BULK example test. Verifies basic bulk functionality on the EVM
# The test code is based on PyUSB 1.0 or later which can be downloaded from
# https://github.com/pyusb/pyusb,  or "pip install pyusb", 
#
# Before running this test make sure the device has been installed successfully. 
#
# For Linux systems also make sure there is a rule with the appropriate mode 
# (SUBSYSTEM=="usb", ATTR{idVendor}=="<your Vendor ID>", \ 
# ATTR{idProduct}=="<your product ID>", MODE="666")
# in one of the files located at /etc/udev/rules.d/ An example bulk_udev.rules 
# is also supplied.  Copy it to /etc/udev/rules.d and run service udev restart 
# before running the bulk demo
#

requires = ['usb']

import usb.core
import usb.util
import string
import re
import time
import sys
import random

#
# this is our bulk USB vid:pid
# WARNING: Currently all EVMs running same USB example will have same 
# Vendor ID and product ID 
#
vendor_id = 0x1cbe
product_id = 0x0003
num_ascii_strings = 100
packet_size = 512
    
bulk_buffer_size=packet_size
single_packet = False

write_throughput_test_length=1024*1024*10
read_throughput_test_length=1024*1024*10

def doing_usb_bulk_echo_test():
    global ep, ep2
    test_string = string.ascii_letters*num_ascii_strings

    received_string = ''


    # tell the USB device that we will do a demo
    ep.write("DEMO")

    # delay a bit since the USB bulk client will be printing some messages on 
    # the UART console before it actually starts listening to the USB host. 
    # if we don't the device will response with a lot of NAKs
    time.sleep(0.1);

    # write the data
    if (single_packet == False):
        print ('\nSending test string of length {} bytes... in chunk of {} bytes'.format(len(test_string),bulk_buffer_size ))
    else:
        print('\nSending and expecting only 1 packet\n')
        
    start_time=time.time()

    if (single_packet == False):
        for substring in re.findall('.{1,%d}'%bulk_buffer_size, test_string):
            ep.write(substring)
            # read data
            for letter in ep2.read(len(substring)):
                received_string+= chr(letter)
    else:
        t_substring = ""
        for i in range (0,1):
            substring = test_string[:packet_size]
            t_substring += substring
            ep.write(substring)
            # read data
            for letter in ep2.read(len(substring)):
                received_string+= chr(letter)

    ep.write("ENDDEMO")

    end_time=time.time()
    total_time = end_time - start_time

    #we do both sending and receiving during this test. Times 2 for the data rate
    data_rate = 2*((len(string.ascii_letters))*num_ascii_strings)/total_time

    print ('Received string of length {} bytes'.format(len(received_string)))

    if (single_packet == False):
        if test_string == received_string.swapcase():
            test_pass = True
        else:
            test_pass = False
    else:
        if t_substring == received_string.swapcase():
            test_pass = True
        else:
            test_pass = False

    if test_pass:
        print('Received string matched sent string with letters case swapped\n')
        print('Write and receive took:  {} seconds\n'.format(total_time))
        print('data rate (both read and write): {} Bytes per second\n'.format(data_rate))
        print('Please note this tool is not intended to measure throughput\n'.format(data_rate))
        print ('\nTest passes!\n')
    else:
        print('Received string did not match with sent string with letters case swapped\n')
        print ('\nTest fails!\n')




def doing_usb_bulk_write_throughput_test(): 
    global ep, ep2

    # tell the device that we are about to do a write throughput test
    cmd_string = 'WRITE_THROUGHPUT='
    cmd_string = cmd_string + str(write_throughput_test_length) + ';'

    print ("\nStarting write throughput test with " + str(write_throughput_test_length) + " bytes\n")

    test_string = ''
    for i in range(write_throughput_test_length):
        test_string += random.choice(string.ascii_letters)

    ep.write(cmd_string)

    # delay a bit since the USB bulk client will be printing some messages on 
    # the UART console before it actually starts listening to the USB host. 
    # if we don't the device will response with a lot of NAKs
    time.sleep(0.1);

    start_time=time.time()

    for substring in re.findall('.{1,%d}'%bulk_buffer_size, test_string):
        ep.write(substring)

    end_time=time.time()
    total_time = end_time - start_time
    data_rate = write_throughput_test_length/1024/1024/total_time

    print('Write TP test took: {} seconds'.format(total_time))
    print('Write data rate   : {} MB/s'.format(data_rate))




def doing_usb_bulk_read_throughput_test(): 
    global ep, ep2

    # starting read-throughput test
    # tell the device that we are about to do a read throughput test
    cmd_string = 'READ_THROUGHPUT='
    cmd_string = cmd_string + str(read_throughput_test_length) + ';'

    print ("\nStarting read throughput test with " + str(read_throughput_test_length) + " bytes\n")

    ep.write(cmd_string)

    # delay a bit since the USB bulk client will be printing some messages on 
    # the UART console before it actually starts listening to the USB host. 
    # if we don't the device will response with a lot of NAKs
    time.sleep(0.1);

    received_string = ''

    start_time=time.time()

    #for letter in ep2.read(read_throughput_test_length):
    #    received_string+= chr(letter)

    # breaking the receving into multiple 512 byte packets works fine.
    for i in range(read_throughput_test_length/bulk_buffer_size):
        for letter in ep2.read(bulk_buffer_size):
            received_string+= chr(letter)

    #for i in range(read_throughput_test_length/bulk_buffer_size/2):
    #    for letter in ep2.read(bulk_buffer_size*2):
    #        received_string+= chr(letter)

    end_time=time.time()

    print ("received " + str(len(received_string)) + " bytes")

    total_time = end_time - start_time
    data_rate = len(received_string)/1024/1024/total_time

    print('Read TP test took : {} seconds'.format(total_time))
    print('Read data rate    : {} MB/s\n'.format(data_rate))






print ('\nUSB generic bulk host application')
print ('Send string to usb bulk device and wait for reverse case string echo back')
print ('and check to make sure the returned data is matched with what we expect\n')
print ('{} [single] to send 1 packet\n'.format(sys.argv[0]))

if ((len(sys.argv)>1) and (str(sys.argv[1]) == 'single')):
    single_packet = True
    

try:
    
    #find our USB bulk device.
    dev = usb.core.find(idVendor=vendor_id, 
                        idProduct=product_id)
   
    if dev is not None:
        print ('\nFound device with following usb info:')
        print ('Bus:        ', dev.bus)
        print ('Address:    ', dev.address)
        print ('Vendor Id:  ', format(dev.idVendor, '#06x'))
        print ('Product Id: ', format(dev.idProduct, '#06x'))
    else:
        print ('USB %04x:%04x device is not found\n'%(vendor_id,product_id))
        exit()


    # get an endpoint instance
    cfg = dev.get_active_configuration()

except Exception as e:
    print ("%r"%e ,('\n\nBefore running this test:\n' +
                   '1) Make sure the device has been installed successfully.\n' + 
                   '2)For Linux systems also make sure there is a rule with ' +
                   'the appropriate mode, i.e\n \'SUBSYSTEM=="usb", ' + 
                   'ATTR{idVendor}=="%04x", ATTR{idProduct}=="%04x", ' + 
                   'MODE="666"\', \nin one of the files located at ' + 
                   "/etc/udev/rules.d/\n")%(vendor_id,product_id))
    raise e

# cfg index is a tuple of two values with interface index and
# alternate setting index.
interface_number = cfg[(0,0)].bInterfaceNumber

intf = usb.util.find_descriptor(
    cfg, bInterfaceNumber = interface_number,
    bAlternateSetting = interface_number
)

ep = usb.util.find_descriptor(
    intf,
    # match the first OUT endpoint
    custom_match = \
    lambda e: \
        usb.util.endpoint_direction(e.bEndpointAddress) == \
        usb.util.ENDPOINT_OUT
)

ep2 = usb.util.find_descriptor(
    intf,
    # match the first IN endpoint
    custom_match = \
    lambda e: \
        usb.util.endpoint_direction(e.bEndpointAddress) == \
        usb.util.ENDPOINT_IN
)

if ep == None:
    raise 'Unable to find OUT endpoint in device'
    
if ep2 == None:
    raise 'Unable to find IN endpoint in device'




# delay a bit so that the USB bulk device can finish printing any UART printf it might be doing
# this is the case when we just finish a test earlier and start another test immediately.
# The reason is UART prints on the device can take a bit and cause the USB host to time out.
time.sleep(0.1);
doing_usb_bulk_echo_test()

# USB device will do a printf after the above test has completed. 
time.sleep(0.1);

# starting writing throughput test
doing_usb_bulk_write_throughput_test()

# USB device will do a printf after the above test has completed.
time.sleep(0.1);
doing_usb_bulk_read_throughput_test()

#end
