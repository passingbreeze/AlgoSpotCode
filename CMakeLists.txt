cmake_minimum_required(VERSION 3.14)
project(AlgoSpotCode)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

link_libraries(tbb)
link_directories(/usr/local/lib /home/hongjeongmin/coding/tool/tbb-tbb_2020/build/linux_intel64_gcc_cc8.3.0_libc2.27_kernel4.15.0_release)
add_executable(algowithcs weird.c)
