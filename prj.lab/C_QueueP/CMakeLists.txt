add_library(c_queue_p queue_p.hpp queue_p.cpp c_queue_p.h c_queue_p.cpp)
add_executable(c_queue_p_test c_queue_p_test.c)

target_link_libraries(c_queue_p_test c_queue_p)