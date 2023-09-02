#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include "CppCompiler.h"
using namespace std;
namespace fs = filesystem;

class GraderApp {
private:
    pair<vector<string>, vector<string>> 테스트케이스_로드();

public:
    void 실행();
};