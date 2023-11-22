cmake_minimum_required(VERSION 3.22)
project(leaverDLL)
set(SOURCE_DLL leaver.cpp leaver.h)
add_library(leaverDLL SHARED ${SOURCE_DLL})