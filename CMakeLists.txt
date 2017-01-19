cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Kandinsky)
project(${PROJECT_NAME})

set (${PROJECT_NAME}_MAJOR_VERSION 0)
set (${PROJECT_NAME}_MINOR_VERSION 1)
set (${PROJECT_NAME}_PATCH_VERSION 0)
set(${PROJECT_NAME}_VERSION
    ${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}.${${PROJECT_NAME}_PATCH_VERSION})
# This is used when configuring files
# (this way we have a variable which is not dependent on the project name)
set(PROJECT_VERSION ${${PROJECT_NAME}_VERSION})

option(${PROJECT_NAME}_ENABLE_TESTS "Enable tests" ON)
if(${PROJECT_NAME}_ENABLE_TESTS)
    enable_testing()
endif()

# Project setup (basic flags, variables, cmake function...)
set(CUPID_VERSION "dd25cff83567503ee7c43bda5ac44f30a307e2ba")
if(EXISTS "${CMAKE_SOURCE_DIR}/cupid/src/SetUpProject.cmake")
    include("${CMAKE_SOURCE_DIR}/cupid/src/SetUpProject.cmake")
elseif(NOT EXISTS "${CMAKE_BINARY_DIR}/cupid/src/SetUpProject.cmake")
    message(STATUS "Downloading cupid...")
    file(DOWNLOAD https://github.com/lgpasquale/cupid/archive/${CUPID_VERSION}.zip
        "${CMAKE_BINARY_DIR}/cupid.zip")
    execute_process(COMMAND "${CMAKE_COMMAND}" -E tar xf cupid.zip
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
    execute_process(COMMAND "${CMAKE_COMMAND}" -E rename "cupid-${CUPID_VERSION}" "cupid"
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
    include("${CMAKE_BINARY_DIR}/cupid/src/SetUpProject.cmake")
endif()
#include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/src/SetUpProject.cmake)

#================================
# Dependencies
#================================
#add_project_dependency(Eigen3)

install_project_dependencies()
find_project_dependencies()

message(STATUS "${PROJECT_NAME}_DEPENDENCIES_INCLUDE_DIRS = ${${PROJECT_NAME}_DEPENDENCIES_INCLUDE_DIRS}")
message(STATUS "${PROJECT_NAME}_DEPENDENCIES_LIBRARY_DIRS = ${${PROJECT_NAME}_DEPENDENCIES_LIBRARY_DIRS}")
message(STATUS "${PROJECT_NAME}_DEPENDENCIES_LIBRARIES = ${${PROJECT_NAME}_DEPENDENCIES_LIBRARIES}")
message(STATUS "${PROJECT_NAME}_DEPENDENCIES_PROVIDING_USE_FILES = ${${PROJECT_NAME}_DEPENDENCIES_PROVIDING_USE_FILES}")

include_directories(SYSTEM ${${PROJECT_NAME}_DEPENDENCIES_INCLUDE_DIRS})

link_directories(${${PROJECT_NAME}_DEPENDENCIES_LIBRARY_DIRS})

set(LIBRARIES
    ${${PROJECT_NAME}_DEPENDENCIES_LIBRARIES}
    CACHE INTERNAL "")

#================================
# Flags
#================================
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2 -std=c++11")

    # Set specific flags for the three different build types (Release, debug and Profile)
    set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-D_GLIBCXX_DEBUG -DDEBUG -g -O0")
    set(CMAKE_CXX_FLAGS_PROFILE "-pg")
    set(CMAKE_CXX_FLAGS_CODECOVERAGE "-g -O0 --coverage")

    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        message(STATUS "Compiling with flags:\n  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Compiling with flags:\n  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Profile")
        message(STATUS "Compiling with flags:\n  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_PROFILE}")
    elseif(CMAKE_BUILD_TYPE STREQUAL "CodeCoverage")
        include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CodeCoverage.cmake)
        message(STATUS "Compiling with flags:\n  ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_CODECOVERAGE}")
        setup_target_for_coverage(${PROJECT_NAME}_coverage ${CMAKE_CTEST_COMMAND} coverage)
    endif()
endif()

if(MSVC)
    # Enable openmp
    #set(CMAKE_CXX_FLAGS_RELEASE "/openmp /GL")
    #set(CMAKE_INSTALL_OPENMP_LIBRARIES ON) # used by InstallRequiredSystemLibraries to install VCOMP*.dll
endif()

#================================
# Subdirectories
#================================
# Directories in which to look for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(doc)

#================================
# Installation
#================================
if(WIN32)
    # Licence file
    #set(CPACK_RESOURCE_FILE_LICENSE "")
    # Vendor
    set(CPACK_PACKAGE_VENDOR "Vendor")
    # Disable the component based installer
    set(CPACK_MONOLITHIC_INSTALL ON)
    # Pairs of executable and displayed name to show in the start menu
    set(CPACK_PACKAGE_EXECUTABLES "main;Launch ${PROJECT_NAME}")
    # Disable request for administrator privileges (none|user|highest|admin)
    #set(CPACK_NSIS_DEFINES "${CPACK_NSIS_DEFINES}\nRequestExecutionLevel user")
endif()
include(${CUPID_DIR}/src/InstallProject.cmake)

