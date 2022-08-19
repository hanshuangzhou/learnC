#! /bin/sh
cd Send
g++ -std=c++11 ../Proto/event.pb.cc main.cpp -o send -lprotobuf -lpthread -lrt

cd ../Receive
g++ -std=c++11 ../Proto/event.pb.cc main.cpp -o receive -lprotobuf -lpthread -lrt

#-lrt To use mq_open mq_send mq_receive API when link
#-lprotobuf -lpthread To use proto when link.if no -lpthread, when run, error occurs
