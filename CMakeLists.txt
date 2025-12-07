cmake_minimum_required(VERSION 3.10)

project(2048game LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

# ===== ОСНОВНАЯ ИГРА =====
file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")
file(GLOB_RECURSE GAME_HEADERS "src/*.hpp")

list(FILTER GAME_SOURCES EXCLUDE REGEX ".*tests/.*")
list(FILTER GAME_HEADERS EXCLUDE REGEX ".*tests/.*")

add_executable(${PROJECT_NAME} ${GAME_SOURCES} ${GAME_HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Gui)

# ===== UNIT-ТЕСТЫ =====
set(TEST_SOURCES
    src/tests/TestGameBoard.cpp
    src/tests/main_tests.cpp
    src/GameBoard.cpp
)

set(TEST_HEADERS
    src/tests/TestGameBoard.hpp
    src/GameBoard.hpp
)

add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE Qt6::Core)
target_include_directories(${PROJECT_NAME}_tests PRIVATE src)

