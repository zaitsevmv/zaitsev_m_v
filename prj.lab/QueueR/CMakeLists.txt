add_library(queuer queuer.cpp queuer.h)

add_executable(queuer_test queuer_test.cpp)
target_link_libraries(queuer_test queuer)
