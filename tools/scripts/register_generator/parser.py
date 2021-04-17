# **********************************************************************************************************************
#   FileName:
#       parser.py
#
#   Description:
#       Parses XML register definition files for information
#
#   4/16/21 | Brandon Braun | brandonbraun653@gmail.com
# **********************************************************************************************************************

from templates import *
from typing import Dict, List
from pathlib import Path
from pyutils.path import find_parent_path
import xml.etree.ElementTree as et

root_path = find_parent_path(Path.cwd(), "Apollo")
dev_dir = Path(root_path, 'lib', 'sitara_device_support_1.5.1', 'common', 'targetdb', 'devices')
mod_dir = Path(root_path, 'lib', 'sitara_device_support_1.5.1', 'common', 'targetdb', 'Modules', 'am335x')


def get_module_files() -> Dict[str, Path]:
    """
    Looks up paths to the AM335x device module definition files
    Returns:
        Dictionary of {module_name: module_path}
    """
    files = mod_dir.glob('*.xml')
    return {pth.stem.lower(): pth for pth in files}


def create_module_objects() -> List[Module]:
    """
    Parses all known module definitions and creates intermediary objects
    that can be used as source data for C++ file generation.

    Returns:
        List of all modules created
    """
    module_list = []

    # ---------------------------------------------------------
    # First parse the high level device file to get a sense of
    # the type and number of peripherals.
    # ---------------------------------------------------------
    dev_xml = Path(dev_dir, 'AM3358.xml')
    assert(dev_xml.exists())

    device_tree = et.parse(str(dev_xml))

    # Navigate down to the high level peripheral definitions
    for item in device_tree.iter(tag='instance'):
        # Each peripheral module definition is characterized by an 'href' tag
        href = item.get('href')
        if not href or 'Modules/am335x' not in href:
            continue

        # Start populating various attributes about this module
        mod = Module()
        mod.id = item.get('id')
        mod.description = item.get('description')
        mod.xml_file = item.get('xml').strip('.xml').lower()
        mod.base_address = item.get('baseaddr')
        mod.end_address = item.get('endaddr')
        mod.size = item.get('size')
        mod.access_width = item.get('accessnumbytes')

        module_list.append(mod)

    # Register definitions for each module type
    mod_defs = get_module_files()

    # Go through each module and fill out its template based on the module definitions
    for module in module_list:
        if module.xml_file not in mod_defs.keys():
            continue

        # Locate the definition file for the module's registers
        def_path = mod_defs[module.xml_file]
        register_tree = et.parse(def_path)

        # Describes all registers present in the module
        for register in register_tree.iter(tag='register'):
            reg = Register()
            reg.parent_module = module
            reg.acronym = register.get('acronym')
            reg.description = register.get('description')
            reg.id = register.get('id')
            reg.offset = register.get('offset')
            reg.width = register.get('width')

            module.registers.append(reg)

            # Create all bit fields that may exist in the register
            for bitfield in register.iter(tag='bitfield'):
                bf = BitField()
                bf.parent_register = reg
                bf.id = bitfield.get('id')
                bf.description = bitfield.get('description')
                bf.start_bit = bitfield.get('begin')
                bf.end_bit = bitfield.get('end')
                bf.rw_access = bitfield.get('rwaccess')
                bf.width = bitfield.get('width')
                reg.bits.append(bf)

                # Create all possible values the bitfield may hold
                for bit_enum in bitfield.iter(tag='bitenum'):
                    be = BitEnum()
                    be.id = bit_enum.get('id')
                    be.token = bit_enum.get('token')
                    be.value = bit_enum.get('value')
                    be.description = bit_enum.get('description')

                    bf.values.append(be)

    return module_list
