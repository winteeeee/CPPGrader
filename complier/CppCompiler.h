#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <filesystem>
#include "../etc/TestCase.h"
#include "../executor/CppExecutor.h"
using namespace std;
namespace fs = filesystem;

class CppCompiler {
private:
    ofstream& 출력_스트림;
    CppExecutor 실행기;
    enum 컴파일_옵션 {
        일반 = 0,
        각각_컴파일 = 1,
    };
    void 실행기_작동(const string &디렉토리_경로,
                     const string &임시_파일명,
                     const string &명령어,
                     const TestCase &테스트케이스들,
                     const vector<string> &목표_소스코드) const;

public:
    CppCompiler(ofstream& 출력_스트림);
    void 컴파일(const string &디렉토리_경로,
                const string &학생_정보,
                const vector<string> &소스코드들,
                const vector<TestCase> &테스트케이스들,
                const int &옵션,
                const int &인덱스) const;
};
