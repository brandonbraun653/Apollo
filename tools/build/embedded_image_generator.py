# ************************************************************************************************
#   File Name:
#       embedded_image_generator.py
#
#   Description:
#       Utility suite for generation of executable images of a variety of formats for the
#       AM3358.
#
#   2020-2021 | Brandon Braun | brandonbraun653@gmail.com
# ************************************************************************************************

from enum import Enum
from typing import Dict
from pathlib import Path
from argparse import ArgumentParser


class MLOTarget(Enum):
    SD_RAW = 0
    SPI = 1
    UART = 2


class MLOGen:
    """ Generates an image suitable for loading by the TI Boot ROM """
    TARGETS = [MLOTarget.UART, MLOTarget.SPI, MLOTarget.SD_RAW]

    OCM_RAM_START_ADDRESS = 0x402F0400

    def __init__(self):
        pass

    @staticmethod
    def mmc_raw_table_of_contents() -> bytes:
        pass


class ROMGen:
    """ Generates an image that can be read by the MLO for execution """
    pass





def parse_arguments() -> Dict:
    # --------------------------------------------------------
    # Add arguments
    # --------------------------------------------------------
    parser = ArgumentParser()
    parser.add_argument('-f', '--file', action="store", required=True,
                        help="Path to the binary file to be parsed")
    parser.add_argument('-a', '--address', action="store", required=True,
                        help="Address at which the image should be loaded to")

    # --------------------------------------------------------
    # Sanitize input arguments
    # --------------------------------------------------------
    args = parser.parse_known_args()[0]
    rslt = {}

    # Parse the file path
    pth = Path(args.file)
    if not pth.exists():
        raise ValueError("File {} does not exist".format(str(pth)))
    rslt['file'] = pth

    # Parse the start address
    rslt['address'] = int(args.address, 16)

    return rslt


def get_binary_size(filename: Path):
    return filename.stat().st_size


def create_ti_binary(original_file: Path, load_address: int):
    # --------------------------------------------------------
    # Create the new output file name
    # --------------------------------------------------------
    new_filename = original_file.stem + '_ti_boot_image.bin'
    base_folder = original_file.parent
    new_path = Path(base_folder, new_filename)

    # --------------------------------------------------------
    # Grab the size of the original file
    # --------------------------------------------------------
    img_size = get_binary_size(original_file)

    # --------------------------------------------------------
    # Dump the header information and original binary to file.
    # This must be in big endian format per TRM 26.1.8.6.3
    # --------------------------------------------------------
    with new_path.open(mode='wb') as newbin:
        size_bytes = img_size.to_bytes(4, byteorder='big')
        load_bytes = load_address.to_bytes(4, byteorder='big')
        newbin.write(size_bytes)
        newbin.write(load_bytes)

        # Read the little endian formatted binary and convert to big endian
        with original_file.open('rb') as fp:
            idx = 0
            while idx < img_size:
                word = fp.read(4)
                newbin.write(word[::-1])
                idx += 4

        # Fill the rest of the flash chip with zeros
        my_flash_chip_sz = 1048576
        newbin_data_size = 8 + img_size
        flash_size = my_flash_chip_sz - newbin_data_size
        pad = bytes([0xff]*flash_size)
        newbin.write(pad)

    # --------------------------------------------------------
    # Dump a rom layout file used with flashrom utility
    # --------------------------------------------------------
    layout_file = Path(base_folder, 'rom.layout')
    with layout_file.open(mode='w') as layout:
        layout.write('0x00:{} normal'.format(hex(newbin_data_size)))


if __name__ == '__main__':
    args = parse_arguments()
    create_ti_binary(args['file'], args['address'])
