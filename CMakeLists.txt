#cmake versions
cmake_minimum_required(VERSION 2.8)
 
PROJECT (pgremotecore)

set (sfup_VERSION_MAJOR 0)
set (sfup_VERSION_MINOR 1)
set (sfup_VERSION_PATCH 1)

option(BUILD_NETUTIL_SERVER "Build netutil" ON)
option(BUILD_STREAMUTIL_SERVER "Build streamutil" ON)
option(BUILD_STREAMSDK_SERVER "Build streamsdk" ON)
option(BUILD_TYPE_DEBUG "Build debug" ON)

if(BUILD_TYPE_DEBUG)
    SET(CMAKE_BUILD_TYPE "Debug")
else()
    SET(CMAKE_BUILD_TYPE "Release")
endif()

IF (WIN32)
	MESSAGE(STATUS "windows platform")
	#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS_DEBUG} -Wl,--rpath=./lib/ -m64 -Wall -o0 -g -ggdb -pthread -std=c++11 -fPIC")
ELSEIF (APPLE)
	MESSAGE(STATUS "apple platform")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS_DEBUG} -Wl,--rpath=./lib/ -m64 -Wall -o0 -g -ggdb -pthread -std=c++11 -fPIC")
ELSEIF (UNIX)
	MESSAGE(STATUS "unix platform")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS_DEBUG} -Wl,--rpath=./lib/ -m64 -Wall -o0 -g -ggdb -pthread -std=c++11 -fPIC")
ENDIF ()

aux_source_directory(${PROJECT_SOURCE_DIR}/netutil/src/ NETUTIL_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/streamutil/src/ STREAMUTIL_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/streamutil/src/ STREAMSDK_SRC_LIST)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)
INCLUDE_DIRECTORIES(
					${PROJECT_SOURCE_DIR}/third_party/log4z/src/ 
		    		${PROJECT_SOURCE_DIR}/netutil/src/ 
                    ${PROJECT_SOURCE_DIR}/third_party/websocketpp/
                    ${PROJECT_SOURCE_DIR}/third_party/libuv/include/
		    )
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib  /usr/local/lib)
add_definitions(-D_TTS_)
add_definitions(-g)
ADD_SUBDIRECTORY(netutil)
#ADD_SUBDIRECTORY(third_party/asio)
ADD_SUBDIRECTORY(third_party/libzmq)
#ADD_SUBDIRECTORY(third_party/jsoncpp)
#ADD_SUBDIRECTORY(third_party/libuv)

add_library(netutil SHARED ${NETUTIL_SRC_LIST})
add_library(streamutil SHARED ${STREAMUTIL_SRC_LIST})
add_library(streamsdk SHARED ${STREAMSDK_SRC_LIST})

TARGET_LINK_LIBRARIES(netutil log4z boost_system ssl crypto)
TARGET_LINK_LIBRARIES(streamutil)
TARGET_LINK_LIBRARIES(streamsdk netutil streamutil log4z boost_system ssl crypto jsoncpp_lib)