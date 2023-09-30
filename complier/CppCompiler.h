#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <filesystem>

#include "../etc/Problem.h"
#include "../executor/CppExecutor.h"

namespace fs = std::filesystem;

class CppCompiler {
private:
    std::ofstream& 출력_스트림;
    std::string 루트_디렉토리;
    CppExecutor 실행기;
    int 문제_인덱스_찾기(int 옵션, const std::string &디렉토리_경로, const std::vector<std::string> &소스코드들, const std::vector<Problem> &문제들) const;
    void 실행기_작동(int 옵션,
                     const std::string &디렉토리_경로,
                     const std::string &임시_파일명,
                     const Problem &문제들,
                     const std::vector<std::string> &목표_소스코드) const;

public:
    CppCompiler(std::ofstream& 출력_스트림, const std::string &루트_디렉토리);
    void 컴파일(const std::string &디렉토리_경로,
                const std::string &학생_정보,
                const std::vector<std::string> &소스코드들,
                const std::vector<Problem> &문제들) const;
};
