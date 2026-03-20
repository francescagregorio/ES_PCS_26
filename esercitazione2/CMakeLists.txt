cmake_minimum_required(VERSION 3.20) 
project(myproject) 
set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla") 
set(SOURCES ESE2_2.cpp bubblesort.cpp 1_posizionamento_memoria.cpp)

 
add_executable(myproject ESE2_2.cpp)
add_executable (bubble_proj bubblesort.cpp)
add_executable (posiz_memo 1_posizionamento_memoria.cpp)

