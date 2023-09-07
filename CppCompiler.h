#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <filesystem>
#include "CppExecutor.h"
using namespace std;
namespace fs = filesystem;

class CppCompiler {
private:
    ofstream& 출력_스트림;
    vector<string> &소스코드들;
    CppExecutor 실행기;
    enum 컴파일_옵션 {
        일반 = 1,
        각각_컴파일 = 2,
    };

public:
    CppCompiler(vector <string> &소스코드들, ofstream& 출력_스트림);
    void 컴파일(const string &디렉토리_경로,
                const string &학생_정보,
                const vector<string> &입력파일들,
                const vector<string> &정답파일들,
                const int &옵션,
                const string& 명령행_인수);
};
