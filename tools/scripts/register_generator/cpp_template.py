# **********************************************************************************************************************
#   FileName:
#       cpp_template.py
#
#   Description:
#
#
#   4/16/21 | Brandon Braun | brandonbraun653@gmail.com
# **********************************************************************************************************************

from pathlib import Path
from parser import create_module_objects


def file_header(module_name: str) -> str:
    return """
/********************************************************************************
 *  File Name:
 *    reg_{name_lower}.hpp
 *
 *  Description:
 *    AUTO-GENERATED DEFINITIONS: DO NOT EDIT
 *
 *******************************************************************************/

#pragma once
#ifndef APOLLO_REG_DEF_{name_upper}_HPP
#define APOLLO_REG_DEF_{name_upper}_HPP

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/utility>
""".format(name_lower=module_name.lower(), name_upper=module_name.upper())


def file_footer(module_name: str) -> str:
    return """
        
#endif /* !APOLLO_REG_DEF_{name}_HPP */
""".format(name=module_name.upper())


def namespace_start() -> str:
    return """
namespace Apollo::REG
{
"""


def namespace_end() -> str:
    return """
}"""


def generate_module_file_definitions():

    modules = create_module_objects()
    mod = modules[0]

    reg_file_name = Path(Path.cwd(), 'reg_{}.hpp'.format(mod.xml_file))
    with reg_file_name.open(mode='w') as f:
        # Add the header to the file
        f.write(file_header(module_name=mod.xml_file))
        f.write(namespace_start())

        # Fill in register bit field enumerations
        for register in mod.registers:

            for bitfield in register.bits:
                # Bit access class

                for enum in bitfield.values:
                    # constexpr definitions
                    pass

        # Add the footer
        f.write(namespace_end())
        f.write(file_footer(module_name=mod.xml_file))


if __name__ == "__main__":
    generate_module_file_definitions()
