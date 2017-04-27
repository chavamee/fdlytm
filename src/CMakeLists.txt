add_executable(fdlytm
    main.cpp
    Categories.cpp
    Entries.cpp
    )

target_link_libraries(fdlytm
    ${CPR_LIBRARIES}
    ${NCF_LIBRARIES}
    curl)

include_directories(
    ${FDLYPP_INCLUDE_DIRS}
    ${CPR_INCLUDE_DIRS}
    ${JSON_INCLUDE_DIRS}
    ${NCF_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/inc)
