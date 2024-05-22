
# Setting Standards and defining Project
cmake_minimum_required(VERSION 3.15)
project(SudokuSolver VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(Verbose Off)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Adding executable target
add_executable(SudokuSolver main.cpp)

# Adding Test Folder
add_subdirectory(tests)

# adding QT
#find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Adding Libraries
add_subdirectory(source)
target_link_libraries(SudokuSolver PRIVATE Field Solver) #Qt5::Widgets)