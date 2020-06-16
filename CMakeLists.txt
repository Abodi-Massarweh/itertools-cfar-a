cmake_minimum_required(VERSION 3.10)

# set the project name
project(itertools-cfar-a)

# add the executable
add_executable(itertools-cfar-a   Test.cpp doctest.h range.cpp range.hpp accumulate.cpp accumulate.hpp filterfalse.cpp filterfalse.hpp compress.cpp compress.hpp)
add_executable(demo  Demo.cpp range.cpp range.hpp accumulate.cpp accumulate.hpp filterfalse.cpp filterfalse.hpp compress.cpp compress.hpp)
# Demo.cpp range.cpp range.hpp accumulate.cpp accumulate.hpp filterfalse.cpp filterfalse.hpp compress.cpp compress.hpp