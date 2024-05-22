add_library(Solver STATIC solver.cpp)
target_include_directories(Solver INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Giving Field to Solver due to dependency
target_link_libraries(Solver PRIVATE Field)
