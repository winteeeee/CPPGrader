#pragma once

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <filesystem>

#include "../grader/CppGrader.h"
#include "../etc/util.h"

namespace fs = std::filesystem;

class CppExecutor {
private:
    CppGrader 채점기;
    std::string 루트_디렉토리;
public:
    CppExecutor(std::ofstream& 출력_스트림, const std::string &루트_디렉토리);
    void 실행(const std::string &입력파일_경로,
              const std::string &정답파일_경로,
              const std::string &디렉토리_경로,
              const std::string &출력파일명,
              const std::vector<std::string> &소스코드들,
              const std::string &명령행_인수 = "") const;
};