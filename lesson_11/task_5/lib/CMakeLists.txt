cmake_minimum_required(VERSION 3.22)
project(figure_dll)
set(SOURCE_DLL equilateral.cpp equilateral.h 
figure.cpp figure.h 
isosceles.cpp isosceles.h 
parallelogram.cpp parallelogram.h 
quadrangle.cpp quadrangle.h 
rectangle.cpp rectangle.h 
rhomb.cpp rhomb.h 
right.cpp right.h 
sqare.cpp sqare.h 
triangle.cpp triangle.h)
add_library(figure_dll SHARED ${SOURCE_DLL})