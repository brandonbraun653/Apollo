# **********************************************************************************************************************
#   FileName:
#       templates.py
#
#   Description:
#
#
#   4/16/21 | Brandon Braun | brandonbraun653@gmail.com
# **********************************************************************************************************************

from typing import List
from enum import auto, IntEnum


class AccessType(IntEnum):
    READ = auto()


class BitEnum:
    """ Models values that a bitfield can assume """
    def __init__(self):
        self.description = ''
        self.id = ''
        self.token = ''
        self.value = ''


class BitField:
    """ Models a bit field inside a register """

    def __init__(self):
        self.parent_register = Register()
        self.description = ''
        self.start_bit = 0
        self.end_bit = 0
        self.width = 0
        self.id = ''
        self.rw_access = ''
        self.values = []    # type: List[BitEnum]


class Register:
    """ Models a register inside a module """
    def __init__(self):
        self.parent_module = Module()
        self.acronym = ''
        self.description = ''
        self.id = ''
        self.offset = ''
        self.width = ''
        self.bits = []  # type: List[BitField]


class Module:
    """
    Describes a module in Sitara processors. This is essentially a collection of registers
    that perform some function, like SPI, UART, I2C, etc.
    """

    def __init__(self):
        self.description = ''
        self.id = ''
        self.xml_file = ''
        self.base_address = 0
        self.end_address = 0
        self.size = 0
        self.access_width = 0
        self.registers = []  # type: List[Register]
