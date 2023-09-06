#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include "CppCompiler.h"
#include "util.h"
using namespace std;
namespace fs = filesystem;

class GraderApp {
private:
    ofstream 출력_스트림;
    pair<vector<vector<string>>, vector<vector<string>>> 테스트케이스_로드();
    bool 소스코드_존재(const string& 파일);
    void 메인_복사();

public:
    GraderApp(const string& 채점파일명);
    ~GraderApp();
    void 실행();
};