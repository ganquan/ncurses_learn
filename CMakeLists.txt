# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(ncurses-learn)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(day0 ${SRC_ROOT}/day0.cpp)
target_link_libraries(day0 ncurses panel menu form)
