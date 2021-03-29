include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

gen_static_lib_variants(
  TARGET
    apollo_freertos_hooks
  SOURCES
    freertos_hooks_prj.cpp
  PRV_LIBRARIES
    aurora_intf_inc
    chimera_intf_inc
  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Apollo"
)
