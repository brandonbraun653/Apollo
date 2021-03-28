# block size and number of blocks to write / read
# total size must be smaller than the size of the PDK-USBDEV drive. 
# It is currently 16MB. So if blocksize is 1MB, we can only write 15 blocks

BLOCKSIZE=100K
COUNT=150

echo
echo This tool measures the read/write throughput of a USB thumb drive
echo which in this case is the USB Dev MSC PDK-USBDEV USB drive 
echo Assuming the drive is already mounted
echo Syntax: 
echo "         usb_dev_msc_perf.sh [<blocksize> <count>]"
echo


if [ -d  /media/$USER/PDK-USBDEV ]; then
    cd /media/$USER/PDK-USBDEV
    pwd
else
    echo PDK-USBDEV drive is not found. Exit now
    exit
fi

# usb_dev_msc_perf.sh [<blocksize> <count>]
if [ -n "$1" ]; then
    if [ -n "$2" ]; then
        export BLOCKSIZE="$1"
        export COUNT="$2"
    else
        echo Both block size and count parameters must be provided. Using default
    fi
fi


echo writing and reading $COUNT blocks of $BLOCKSIZE bytes
echo USB write perf
#write a file to disk. Makesure fdatasynch is used
sudo dd if=/dev/zero of=./testfile bs=$BLOCKSIZE count=$COUNT conv=fdatasync 

echo
echo USB read perf
# clear cache before reading the file back.
sudo sh -c "sync && echo 3 > /proc/sys/vm/drop_caches"

#delay a bit because the system performance seems to take a hit for a bit after the above command is executed.
sleep 1

# read the file to measure the performance
dd if=./testfile of=/dev/null bs=$BLOCKSIZE
rm ./testfile

echo done
echo

