cmake_minimum_required(VERSION 3.20)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

project(lesson5)

add_subdirectory("D:\\libpqxx-7.9.0\\" pqxx-build)

add_executable(lesson5 main.cpp)

target_compile_features(lesson5 PRIVATE cxx_std_17)

target_link_libraries(lesson5 pqxx)