cmake_minimum_required(VERSION 3.0)
project(space-cadet VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB cmakes ${CMAKE_SOURCE_DIR}/cmake/*.cmake)
FOREACH(cmake ${cmakes})
    INCLUDE(${cmake})
ENDFOREACH(cmake)

find_package(maguey REQUIRED)

include_directories(${MAGUEY_INCLUDE_DIRS}
                    include/)

add_subdirectory(src)

# Resources copy
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
