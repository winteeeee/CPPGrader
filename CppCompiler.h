#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "CppExecutor.h"
using namespace std;

class CppCompiler {
private:
    vector<string>& 소스코드들;
    vector<string>& 입력파일들;
    CppExecutor 실행기;
    enum 컴파일_옵션 {
        일반 = 0,
        각각_컴파일 = 1,
    };

public:
    CppCompiler(vector <string> &소스코드들, vector <string> &입력파일들);
    void 컴파일(const string &디렉토리_경로, const int &옵션);
};
