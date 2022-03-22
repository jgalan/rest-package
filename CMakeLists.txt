# Setup the project
project(restPackage)

cmake_minimum_required(VERSION 3.13)

message("===============  ${PROJECT_NAME}  ==============")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake ${CMAKE_MODULE_PATH})

# Find ROOT
find_package(ROOT REQUIRED COMPONENTS RIO Geom)
execute_process(COMMAND root-config --cflags OUTPUT_VARIABLE ROOT_CFLAGS)
string(STRIP ${ROOT_CFLAGS} ROOT_CFLAGS)
message(STATUS "Found ROOT version: ${ROOT_VERSION} with compilation flags: ${ROOT_CFLAGS} and libraries: ${ROOT_LIBRARIES}")

# Find REST
if (NOT DEFINED REST_PATH)
    if (DEFINED ENV{REST_PATH})
        set(REST_PATH $ENV{REST_PATH})
	else ()
        message(FATAL_ERROR "ERROR ::: REST_PATH must be defined as an environment variable and point to REST install directory")
        return()
    endif ()
endif ()

if (NOT DEFINED rest_include_dirs)
    set(rest_include_dirs ${REST_PATH}/include)
endif ()

if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${REST_PATH})
endif ()

message(STATUS "Using REST_PATH: ${REST_PATH}")
message(STATUS "Using rest_include_dirs: ${rest_include_dirs}")
message(STATUS "Package ${PROJECT_NAME} will be installed in ${CMAKE_INSTALL_PREFIX}")

if (NOT CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS " -std=c++1y")
endif ()

# Set include and lib
set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include ${ROOT_INCLUDE_DIRS} ${rest_include_dirs})


execute_process(COMMAND rest-config --libs OUTPUT_VARIABLE REST_LIBS)
set(LINK_LIBRARIES ${ROOT_LIBRARIES} ${REST_LIBS})
message(STATUS "Link libraries: ${LINK_LIBRARIES}")
string(STRIP "${LINK_LIBRARIES}" LINK_LIBRARIES)

###### UNCOMMENT this if you want to add additional code at src/ inc/ directories
##file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cxx)
##file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)
##########

add_executable(${PROJECT_NAME} restPackage.cxx ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${INCLUDE_DIRS})

# Copy scripts to the build directory
## Enable this if you create an examples directory
# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples/
#        DESTINATION ./examples/restPackage/
#        COMPONENT install
#        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/mac
        DESTINATION macros
        COMPONENT install
        )

# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
install(TARGETS ${PROJECT_NAME} DESTINATION .)

