#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <windows.h>
#include "CppCompiler.h"
#include "util.h"
using namespace std;
namespace fs = filesystem;

class GraderApp {
private:
    ofstream 출력_스트림;
    pair<vector<vector<string>>, vector<vector<string>>> 테스트케이스_로드() const;
    void 메인_복사() const;
    vector<string> 명령행_인수_로드() const;

public:
    GraderApp(const string& 채점파일명);
    ~GraderApp();
    void 실행();
};