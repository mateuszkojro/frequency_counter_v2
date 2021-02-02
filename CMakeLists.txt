cmake_minimum_required(VERSION 3.17)
project(frequency_counter_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(frequency_counter_v2 main.cpp FreqCounter.cpp FreqCounter.h Csv.cpp Csv.h)