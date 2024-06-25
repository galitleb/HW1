cmake_minimum_required(VERSION 3.27)
project(MATAM_HW1)

set(CMAKE_CXX_STANDARD 17)

add_executable(MATAM_HW1 main.cpp
        Transaction.h
        BlockChain.h
        Transaction.cpp
        Utilities.h
        BlockChain.cpp
        Utilities.cpp)
