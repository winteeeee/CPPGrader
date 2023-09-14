#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <filesystem>
#include "../etc/TestCase.h"
#include "../executor/CppExecutor.h"
namespace fs = std::filesystem;

class CppCompiler {
private:
    std::ofstream& 출력_스트림;
    CppExecutor 실행기;
    enum 컴파일_옵션 {
        일반 = 0,
        각각_컴파일 = 1,
    };
    void 실행기_작동(const std::string &디렉토리_경로,
                     const std::string &임시_파일명,
                     const std::string &명령어,
                     const TestCase &테스트케이스들,
                     const std::vector<std::string> &목표_소스코드) const;

    int 테케_인덱스_찾기(const std::string &디렉토리_경로,
                         const std::vector<std::string> &소스코드들,
                         const std::vector<TestCase> &테스트케이스들,
                         const int &옵션) const;

public:
    CppCompiler(std::ofstream& 출력_스트림);
    void 컴파일(const std::string &디렉토리_경로,
                const std::string &학생_정보,
                const std::vector<std::string> &소스코드들,
                const std::vector<TestCase> &테스트케이스들,
                const int &옵션) const;
};
