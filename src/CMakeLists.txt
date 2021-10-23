target_include_directories(${PROJECT_NAME} PUBLIC includes)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRCS)

target_sources(${PROJECT_NAME} PUBLIC ${SRCS})
