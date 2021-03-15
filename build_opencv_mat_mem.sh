#!/bin/bash
g++ ./opencv_mat_to_mem.cpp -o ./opencv_mat_to_mem -O3 `pkg-config opencv --libs --cflags` -std=c++11 
g++ ./opencv_mat_from_mem.cpp -o ./opencv_mat_from_mem -O3  `pkg-config opencv --libs --cflags` -std=c++11
