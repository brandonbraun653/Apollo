include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

add_subdirectory(src)


gen_intf_lib_variants(
  TARGET
    apollo_core

  INTF_LIBRARIES


  EXPORT_DIR
    "${PROJECT_BINARY_DIR}/Apollo"
)
