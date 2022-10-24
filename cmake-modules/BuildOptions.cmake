include(CMakeDependentOption)

# Components to build
option(BUILD_TESTS "Build with unittests" ON)
option(BUILD_DOC "Build documentation" OFF)
option(BUILD_STORAGE "Build storage service" ON)
option(BUILD_DIRECTORY "Build directory service" ON)
option(BUILD_CPP_CLIENT "Build C++ client" ON)
option(BUILD_PYTHON_CLIENT "Build Python Client" ON)
option(BUILD_JAVA_CLIENT "Build Java Client" ON)
option(BUILD_MEMKIND_SUPPORT "Build support for memkind" ON)
option(BUILD_S3_SUPPORT "Build support for S3 as external store" OFF)
option(USE_SYSTEM_BOOST "Use system boost libraries" ON)
option(USE_SYSTEM_THRIFT "Use system thrift library" ON)
option(USE_SYSTEM_AWSSDK "Use system AWS SDK" ON)
option(USE_SYSTEM_MEMKIND "Use system Memkind" OFF)
option(USE_SYSTEM_JEMALLOC "Use system Jemalloc" ON)
option(USE_SYSTEM_CURL "Use system Curl" ON)
option(USE_SYSTEM_LIBEVENT "Use system libevent" ON)
option(USE_SYSTEM_OPENSSL "Use system OpenSSL" ON)
option(USE_SYSTEM_ZLIB "Use system Zlib" ON)
option(BUILD_BENCHMARKS "Build benchmarks" OFF)
option(GENERATE_THRIFT "Generate thrift files" OFF)

# Exception for Darwin
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(BUILD_MEMKIND_SUPPORT "OFF")
endif()

message(STATUS "----------------------------------------------------------")
message(STATUS "${PROJECT_NAME} version:                            ${PROJECT_VERSION}")
message(STATUS "Build configuration Summary")
message(STATUS "  Build storage service:                  ${BUILD_STORAGE}")
message(STATUS "  Build directory service:                ${BUILD_DIRECTORY}")
message(STATUS "  Build C++ client:                       ${BUILD_CPP_CLIENT}")
message(STATUS "  Build Python client:                    ${BUILD_PYTHON_CLIENT}")
message(STATUS "  Build Java client:                      ${BUILD_JAVA_CLIENT}")
message(STATUS "  Build memkind support:                  ${BUILD_MEMKIND_SUPPORT}")
message(STATUS "  Build S3 support:                       ${BUILD_S3_SUPPORT}")
message(STATUS "  Build benchmarks:                       ${BUILD_BENCHMARKS}")
message(STATUS "  Build unit tests:                       ${BUILD_TESTS}")
message(STATUS "  Build documentation:                    ${BUILD_DOC}")
message(STATUS "  Use system Thrift library:              ${USE_SYSTEM_THRIFT}")
message(STATUS "  Use system AWS SDK:                     ${USE_SYSTEM_AWSSDK}")
message(STATUS "  Use system Jemalloc:                    ${USE_SYSTEM_JEMALLOC}")
message(STATUS "  Use system Memkind:                     ${USE_SYSTEM_MEMKIND}")
message(STATUS "  Use system Curl:                        ${USE_SYSTEM_CURL}")
message(STATUS "  Use system libevent:                    ${USE_SYSTEM_LIBEVENT}")
message(STATUS "  Use system OpenSSL:                     ${USE_SYSTEM_OPENSSL}")
message(STATUS "  Use system Zlib:                        ${USE_SYSTEM_ZLIB}")
message(STATUS "  Generate thrift files:                  ${GENERATE_THRIFT}")
message(STATUS "----------------------------------------------------------")
