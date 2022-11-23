add_library(c_queue_p c_queue_p.cpp queue_p.cpp c_queue_p.h queue_p.hpp)
add_executable(c_queue_p_test c_queue_p_test.c)

target_link_libraries(c_queue_p_test c_queue_p)