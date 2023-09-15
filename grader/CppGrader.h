#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <filesystem>
#include "../etc/util.h"
namespace fs = std::filesystem;

class CppGrader {
private:
    std::ofstream &출력_스트림;
    void 파일_내용_출력(const std::string &경로) const;
    void 채점_프롬프트_출력(const std::vector<std::string> &소스코드들, const std::string &정답파일, const std::string &출력파일명) const;
public:
    CppGrader(std::ofstream& 출력_스트림);
    void 채점(const std::vector<std::string> &소스코드, const std::string &정답파일, const std::string &출력파일명) const;
};
