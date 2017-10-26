#!/bin/sh

g++ -D_GNU_SOURCE -D_REENTRANT -Wall -g -std=c++11 -I/usr/local/include -L. -lsejson -o test test.cc

