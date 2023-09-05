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
    ofstream 출력_스트림;
    pair<vector<vector<string>>, vector<vector<string>>> 테스트케이스_로드();

public:
    GraderApp(const string& 채점파일명);
    ~GraderApp();
    void 실행();
};