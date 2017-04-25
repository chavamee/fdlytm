cmake_minimum_required(VERSION 2.8.8)
project(ncf_builder C CXX)
include(ExternalProject)

ExternalProject_Add(ncf
    GIT_REPOSITORY  https://github.com/chavamee/ncframe.git
    CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -DCMAKE_CXX_FLAGS=${MSVC_COMPILER_DEFS}
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    INSTALL_COMMAND ""
    )


ExternalProject_Get_Property(ncf source_dir)
set(NCF_INCLUDE_DIRS ${source_dir}/ncf/inc PARENT_SCOPE)

ExternalProject_Get_Property(ncf binary_dir)
set(NCF_LIBRARIES_DIR ${binary_dir}/lib PARENT_SCOPE)
