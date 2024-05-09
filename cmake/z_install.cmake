
########################################################################################################################
# Install module                                                                                                       #
########################################################################################################################

# local debug
set(CMAKE_INSTALL_PREFIX "./")
# Release Code
# set(CMAKE_INSTALL_PREFIX "/")

message(STATUS "The default installation path is ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Please use \"make install DESTDIR=./PATH\" to set install path")

# test install
install(TARGETS
    ${test_name} DESTINATION ${PROJECT_NAME}/bin
    )

if (generate_lib STREQUAL "ON")
    # include install
    install(FILES # /
        ${CMAKE_SOURCE_DIR}/src/she_log.h # source head
        DESTINATION # to
        ${PROJECT_NAME}/include # target dir
        )
    install(FILES # /common
            ${CMAKE_SOURCE_DIR}/src/common/log_info.h
            ${CMAKE_SOURCE_DIR}/src/common/make_unique.h
            ${CMAKE_SOURCE_DIR}/src/common/time.h
            DESTINATION # to
            ${PROJECT_NAME}/include/common # target dir
    )
    install(FILES # /filter
            ${CMAKE_SOURCE_DIR}/src/filter/log_level.h
            DESTINATION # to
            ${PROJECT_NAME}/include/filter # target dir
    )
    install(FILES # /format
            ${CMAKE_SOURCE_DIR}/src/format/log_format.h
            DESTINATION # to
            ${PROJECT_NAME}/include/format # target dir
    )
    install(FILES # /logger
            ${CMAKE_SOURCE_DIR}/src/logger/log_channel.h
            ${CMAKE_SOURCE_DIR}/src/logger/logger.h
            DESTINATION # to
            ${PROJECT_NAME}/include/logger # target dir
    )
    install(FILES # /output
            ${CMAKE_SOURCE_DIR}/src/output/output.h
            ${CMAKE_SOURCE_DIR}/src/output/log_dest.h
            DESTINATION # to
            ${PROJECT_NAME}/include/output # target dir
    )
    install(FILES # /output/console
            ${CMAKE_SOURCE_DIR}/src/output/console/console.h
            DESTINATION # to
            ${PROJECT_NAME}/include/output/console # target dir
    )
    install(FILES # /output/local_file
            ${CMAKE_SOURCE_DIR}/src/output/local_file/local_file.h
            DESTINATION # to
            ${PROJECT_NAME}/include/output/local_file # target dir
    )
    install(FILES # /output/local_file/file_ops
            ${CMAKE_SOURCE_DIR}/src/output/local_file/file_ops/file.h
            ${CMAKE_SOURCE_DIR}/src/output/local_file/file_ops/seek.h
            ${CMAKE_SOURCE_DIR}/src/output/local_file/file_ops/write.h
            DESTINATION # to
            ${PROJECT_NAME}/include/output/local_file/file_ops # target dir
    )
    # lib install
    install(TARGETS
        ${library_static_name} ${library_dynamic_name}
        DESTINATION ${PROJECT_NAME}/lib
        )
    # cmake install
    install(FILES
            ${CMAKE_SOURCE_DIR}/cmake/${project_name}-config.cmake
            DESTINATION ${PROJECT_NAME}/cmake
            )
endif ()


