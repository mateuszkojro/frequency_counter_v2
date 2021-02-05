cmake_minimum_required(VERSION 3.17)
project(frequency_counter_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        frequency_counter_v2
        main.cpp
        FreqCounter.cpp
        FreqCounter.h
        Csv.cpp
        Csv.h
        BarChart.cpp
        BarChart.h
        ./ppm/helpers.h
        ./ppm/helpers.cpp
        ./ppm/obraz.h
        ./ppm/obraz.cpp
        ./ppm/pixel.h
        ./ppm/pixelRGB.h
        ./ppm/ppm.h
        ./ppm/ppm.cpp
        ./ppm/ppm_parser.h
        ./ppm/ppm_parser.cpp
        ./ppm/state_machine.h
        ./ppm/states.h
)