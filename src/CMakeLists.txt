add_subdirectory(${PROJECT_NAME})
#add_subdirectory(bin)

if(${PROJECT_NAME}_ENABLE_TESTS)
    add_subdirectory(test)
endif()

