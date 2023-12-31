#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

#include "complier/CppCompiler.h"
#include "etc/util.h"
#include "etc/Problem.h"

namespace fs = std::filesystem;

class GraderApp {
private:
    std::ofstream 출력_스트림;
    void 압축_해제(const std::string &압축파일명) const;

public:
    GraderApp(const std::string& 채점파일명);
    ~GraderApp();
    void 실행();
};