cmake_minimum_required(VERSION 3.23)

project(ascii_media_player)

set(CMAKE_CXX_STANDARD 14)

add_executable(ascii_media_player main.cpp video_loader.cpp video_loader.h screen.cpp screen.h)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ascii_media_player ${OpenCV_LIBS})

find_package(CURSES REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(ascii_media_player ${CURSES_LIBRARIES})

find_package(Boost 1.76.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(ascii_media_player ${Boost_LIBRARIES})

