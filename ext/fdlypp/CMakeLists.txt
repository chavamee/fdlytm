cmake_minimum_required(VERSION 2.8.8)
project(fdlypp_fetcher C CXX)
include(ExternalProject)

ExternalProject_Add(fdlypp
    GIT_REPOSITORY  https://github.com/chavamee/fdlypp.git
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    INSTALL_COMMAND ""
    BUILD_COMMAND ""
    )


ExternalProject_Get_Property(fdlypp source_dir)
set(FDLYPP_INCLUDE_DIRS ${source_dir}/src PARENT_SCOPE)

ExternalProject_Get_Property(fdlypp binary_dir)
set(FDLYPP_DEPENDS_INCLUDE_DIRS ${binary_dir}/depends/inc)
set(FDLYPP_DEPENDS_LIB_DIRS ${binary_dir}/depends/lib)
