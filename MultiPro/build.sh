#! /bin/sh
cd Send
g++ -std=c++11 main.cpp -o send -lrt
cd ../Receive
g++ -std=c++11 main.cpp -o receive -lrt