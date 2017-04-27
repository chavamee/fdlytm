add_executable(fdlytm
    Categories.cpp
    Entries.cpp
    main.cpp
    )

target_link_libraries(fdlytm
    ${CPR_LIBRARIES}
    ${NCF_LIBRARIES}
    curl)

include_directories(
    ${CPR_INCLUDE_DIRS}
    ${FDLYPP_INCLUDE_DIRS}
    ${JSON_INCLUDE_DIRS}
    ${NCF_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/inc)
