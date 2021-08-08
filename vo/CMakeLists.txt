cmake_minimum_required(VERSION 3.10)
project(visual_odom)

message(STATUS ${OpenCV_LIBS})
message(STATUS ${OpenCV_INCLUDE_DIRS})

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(main src/main.cc)
target_link_libraries(main ${OpenCV_LIBS})