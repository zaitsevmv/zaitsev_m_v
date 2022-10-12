add_library(queuep queuep.cpp queuep.h)

add_executable(queuep_test queuep_test.cpp)
target_link_libraries(queuep_test queuep)
