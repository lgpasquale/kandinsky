# This deletes the variables stored in the cache from previous calls to cmake
set(${PROJECT_NAME}_HEADERS CACHE INTERNAL "Kandinsky.hpp")
set(${PROJECT_NAME}_SOURCES CACHE INTERNAL "")

add_subdirectory(expressions)
add_subdirectory(utils)

install_files_with_directory_structure(${PROJECT_INCLUDE_INSTALL_DIR}/${PROJECT_NAME} ${${PROJECT_NAME}_HEADERS})

