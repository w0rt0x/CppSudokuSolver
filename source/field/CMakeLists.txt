# Creating Libs with Header Interface
add_library(Subfield STATIC subfield.cpp)
target_include_directories(Subfield INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Field STATIC field.cpp)
target_link_libraries(Field PRIVATE Subfield)
target_include_directories(Field INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if(Verbose)
  set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
  set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
  target_compile_options(Field PRIVATE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
  )
endif()