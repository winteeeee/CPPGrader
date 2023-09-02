cmake_minimum_required(VERSION 3.26)
project(CPPGrader)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(CPPGrader main.cpp
        CppCompiler.cpp
        CppCompiler.h
        CppExecutor.cpp
        CppExecutor.h
        GraderApp.cpp
        GraderApp.h
        CppGrader.cpp
        CppGrader.h
)
