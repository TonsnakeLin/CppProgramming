CXX=g++

all: main.cc
	g++ main.cc ./thread/thread.cc ./misc/assert.cc -o main -g -std=c++17 -lpthread
