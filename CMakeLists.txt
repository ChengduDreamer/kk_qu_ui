﻿cmake_minimum_required(VERSION 3.1.0)

# 使用kkquui库的时候， 提前设置 QT_ROOT, 如果没有设置QT_ROOT ，将使用qt.cmake中的值
#
#

if(NOT DEFINED QT_ROOT)
	include(qt.cmake)
	set(CMAKE_PREFIX_PATH ${QT_ROOT}/lib/cmake)
endif()

project(kkquui VERSION 1.0.1)

include(InstallRequiredSystemLibraries)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#if(MSVC)
#	add_compile_options($<IF:$<CONFIG:Debug>,/MTd,/MT>)
#	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/bigobj>")
#endif()

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")  # /MD or /MDd
endif()

add_definitions(-DUNICODE -D_UNICODE -DWIN32_LEAN_AND_MEAN)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Svg REQUIRED)

if(${CMAKE_SIZEOF_VOID_P} STREQUAL "4")
	set(PLATFORM_WIN64 FALSE)
else()
	set(PLATFORM_WIN64 TRUE)
endif()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(UILIB_SOURCES
	src/yk_icon_button.cpp 
	src/yk_progress_bar.cpp 
	src/yk_button.cpp
	src/yk_line_edit.cpp
	src/yk_label.cpp
)


include_directories(		
	${CMAKE_BINARY_DIR}
)

link_directories(
)

add_library(${PROJECT_NAME} STATIC ${UILIB_SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Svg)

add_subdirectory(exmaple)


