cmake_minimum_required(VERSION 3.14)
include(FetchContent)

project(zaitsev_m_v)
set(CMAKE_CXX_STANDARD 20)

include_directories(prj.lab prj.thirdparty)

add_subdirectory(prj.lab)
add_subdirectory(prj.thirdparty)