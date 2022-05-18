# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(ncurses-learn)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(snake 
    ${SRC_ROOT}/main.cpp 
    ${SRC_ROOT}/board.cpp 
    ${SRC_ROOT}/engine.cpp)

target_link_libraries(snake ncurses)
