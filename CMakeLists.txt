# CMakeLists.txt

cmake_minimum_required(VERSION "3.17")

project(ncurses-learn)

set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_STANDARD 17)

SET(SILENCE_PRAGMA_ONCE_WARN "-Wno-pragma-once-outside-header")
# SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${SILENCE_PRAGMA_ONCE_WARN}")
# SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")


include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(snake 
    ${SRC_ROOT}/main.cpp 
    ${SRC_ROOT}/board.cpp 
    ${SRC_ROOT}/engine.cpp
    ${SRC_ROOT}/apple.cpp
    ${SRC_ROOT}/snake.cpp
    ${SRC_ROOT}/empty.cpp)

target_link_libraries(snake ncurses)


# mkdir Debug
# cd Debug
# cmake -DCMAKE_BUILD_TYPE=Debug ..
# make

# mkdir Release
# cd Release
# cmake -DCMAKE_BUILD_TYPE=Release ..
# make


