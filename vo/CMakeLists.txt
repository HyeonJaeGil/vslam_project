cmake_minimum_required(VERSION 3.10)
project(visual_odom)

find_package( OpenCV 
            # PATHS "/home/hj/cpp-cv-project-template/third_party/opencv3.4/install/" 
            REQUIRED 
            # NO_DEFAULT_PATH
)

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(main src/main.cc)
target_link_libraries(main ${OpenCV_LIBS})

add_executable(tutorial src/tutorial.cc)
target_link_libraries(tutorial ${OpenCV_LIBS})

message(STATUS "OpenCV libs are ${OpenCV_LIBS}")
message(STATUS "Opencv include dirs are ${OpenCV_INCLUDE_DIRS}")
