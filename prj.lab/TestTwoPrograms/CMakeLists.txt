add_library(twoPrograms first.cpp second.cpp)

add_executable(test_programs test_programs.cpp)
link_libraries(twoPrograms test_programs)