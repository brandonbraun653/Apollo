include("${COMMON_TOOL_ROOT}/cmake/utility/embedded.cmake")

# ====================================================
# Export the project's root path
# ====================================================
set(APOLLO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "")
set(ApolloExportDir "${PROJECT_BINARY_DIR}/Apollo")

# ====================================================
# Project Library
# ====================================================
add_subdirectory(src)

# ====================================================
# Interface Library
# ====================================================
gen_intf_lib(
  TARGET
    apollo_intf_inc
  INTF_INCLUDES
    "${APOLLO_ROOT}/.."
    "${APOLLO_ROOT}/include"
  EXPORT_DIR
    ${ApolloExportDir}
)
