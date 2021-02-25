# -----------------------------------------------------------------------------
# Builds the standard project MLO for the AM335x
#
# Configure Command:
#   cmake -DTOOLCHAIN=arm-none-eabi -DCMAKE_BUILD_TYPE=Debug --configure ../
#   cmake -DTOOLCHAIN=gcc -DCMAKE_BUILD_TYPE=Debug --configure ../
#
# Build Command:
#   cmake --build . --target ApolloMLO.elf
# -----------------------------------------------------------------------------
include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

project(ApolloMLO VERSION 1.0 LANGUAGES C CXX ASM)

gen_static_lib_variants(
  TARGET
    apollo_mlo_lib
  SOURCES
    boot_entry.cpp
    boot_handlers.cpp
    stack_guard.cpp
  PRV_LIBRARIES
    apollo_intf_inc
    aurora_intf_inc
    chimera_intf_inc
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Apollo/mlo"
)

add_executable(${PROJECT_NAME}.elf boot_am335x.s )

target_link_options(${PROJECT_NAME}.elf PRIVATE "-T${APOLLO_ROOT}/src/boot/mlo/mlo_ocm_ram.ld")
target_link_options(${PROJECT_NAME}.elf PRIVATE "-Wl,-Map=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.map")
target_link_libraries(${PROJECT_NAME}.elf PRIVATE

  # Sources
  apollo_mlo_lib

  # Header Includes
  apollo_intf_inc
  aurora_intf_inc
  chimera_intf_inc

  # Target Build Properties
  prj_device_target
  prj_build_target
  )

# Create led_on.bin & led_on.lst
add_elf2bin_dependency(${PROJECT_NAME})
add_bin2lst_dependency(${PROJECT_NAME})

# High level target to build everything
add_custom_target(${PROJECT_NAME} DEPENDS ${PROJECT_NAME}.lst)
