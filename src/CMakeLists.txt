SET(pwd ${CMAKE_CURRENT_LIST_DIR})

FILE(GLOB src ${pwd}/*.cpp)

add_executable(space-cadet ${src})
message(STATUS "space-cadets added")

target_link_libraries(space-cadet ${MAGUEY_LIBRARIES}
                                  ${stdgl_libraries}
                                  SOIL) # TODO: Find a better solution for SOIL
