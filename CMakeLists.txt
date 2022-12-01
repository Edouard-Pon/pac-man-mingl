cmake_minimum_required(VERSION 3.23)
project(pacman_mingl)

file(GLOB_RECURSE LIB_HEADERS libs/*)
file(GLOB_RECURSE SRC src/*)

add_executable(pacman_mingl ${LIB_HEADERS} ${SRC})

target_include_directories(pacman_mingl PUBLIC libs)
target_include_directories(pacman_mingl PUBLIC src)
target_link_directories(pacman_mingl PUBLIC .)

target_link_libraries(pacman_mingl GL)
target_link_libraries(pacman_mingl GLU)
target_link_libraries(pacman_mingl glut)
target_link_libraries(pacman_mingl MinGL)
