cmake_minimum_required(VERSION 3.26)
project(CPPGrader)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(CPPGrader main.cpp
        complier/CppCompiler.cpp
        complier/CppCompiler.h
        executor/CppExecutor.cpp
        executor/CppExecutor.h
        GraderApp.cpp
        GraderApp.h
        grader/CppGrader.cpp
        grader/CppGrader.h
        etc/util.cpp
        etc/util.h
        etc/TestCase.cpp
        etc/TestCase.h
)
