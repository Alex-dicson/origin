cmake_minimum_required(VERSION 3.22)
project(race_dll)
set(SOURCE_DLL tv.cpp tv.h 
air_tv.cpp air_tv.h 
ground_tv.cpp ground_tv.h 
boots.cpp boots.h 
broom.cpp broom.h 
camel.cpp camel.h 
camel_fast.cpp camel_fast.h 
carpet.cpp carpet.h 
centaur.cpp centaur.h 
eagle.cpp eagle.h
macros.h)
add_library(race_dll SHARED ${SOURCE_DLL})
target_compile_definitions(race_dll PRIVATE LIB_EXPORTS)