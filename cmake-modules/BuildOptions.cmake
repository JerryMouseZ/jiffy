include(CMakeDependentOption)

# Components to build
option(BUILD_TESTS "Build with unittests" ON)
CMAKE_DEPENDENT_OPTION(USE_SYSTEM_CATCH "Use system catch library" OFF "BUILD_TESTS" OFF)
option(USE_SYSTEM_THRIFT "Use system thrift library" OFF)
option(USE_SYSTEM_LIBCUCKOO "Use system libcuckoo library" OFF)
option(GENERATE_THRIFT "Generate thrift files" OFF)

message(STATUS "----------------------------------------------------------")
message(STATUS "${PROJECT_NAME} version:                       ${PROJECT_VERSION}")
message(STATUS "Build configuration Summary")
message(STATUS "  Build with unit tests:                  ${BUILD_TESTS}")
message(STATUS "    Use system catch library:             ${USE_SYSTEM_CATCH}")
message(STATUS "  Use system thrift library:              ${USE_SYSTEM_THRIFT}")
message(STATUS "  Use system libcuckoo library:           ${USE_SYSTEM_LIBCUCKOO}")
message(STATUS "  Generate thrift files:                  ${GENERATE_THRIFT}")
message(STATUS "----------------------------------------------------------")
