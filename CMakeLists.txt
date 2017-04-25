cmake_minimum_required(VERSION 2.8.8)

set(PROJECT_NAME_STR fdlytm)
project(${PROJECT_NAME_STR})

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

add_definitions(-Wall -ansi -Wno-deprecated -pthread)
set (CMAKE_CXX_STANDARD 14)

add_subdirectory(${EXT_PROJECTS_DIR}/fdlypp)
add_subdirectory(${EXT_PROJECTS_DIR}/ncf)

include_directories(${FDLYPP_INCLUDE_DIRS} ${NCF_INCLUDE_DIRS} ${FDLYPP_DEPENDS_INCLUDE_DIRS} "inc")

set(srcs
    src/Categories.cpp
    src/Entries.cpp
    src/main.cpp)

add_executable(fdlytm ${srcs})
add_dependencies(${PROJECT_NAME_STR} ncf fdlypp)
target_link_libraries(${PROJECT_NAME_STR} ${NCF_LIBRARIES_DIR} ${FDLYPP_DEPENDS_LIB_DIRS})
