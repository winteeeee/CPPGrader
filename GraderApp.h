#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <windows.h>
#include "complier/CppCompiler.h"
#include "etc/util.h"
#include <conio.h>
using namespace std;
namespace fs = filesystem;

class GraderApp {
private:
    ofstream 출력_스트림;
    pair<vector<vector<string>>, vector<vector<string>>> 테스트케이스_로드() const;
    void 메인_복사() const;
    vector<string> 명령행_인수_로드() const;
    void 아스키_아트_출력() const;
    int 컴파일_옵션_선택() const;
    int 메인_옵션_선택() const;
    void 압축_해제() const;

public:
    GraderApp(const string& 채점파일명);
    ~GraderApp();
    void 실행();
};