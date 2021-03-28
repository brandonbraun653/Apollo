LIB_USB_OPT=`pkg-config --libs --cflags libusb-1.0`

all:
	gcc usb_dev_bulk_test.c -o bulk_test $(LIB_USB_OPT) 
