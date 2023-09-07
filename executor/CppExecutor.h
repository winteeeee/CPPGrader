#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include "../grader/CppGrader.h"
#include "../etc/util.h"
using namespace std;
namespace fs = filesystem;

class CppExecutor {
private:
    CppGrader 채점기;
public:
    CppExecutor(ofstream& 출력_스트림);
    void 실행(const string &입력파일_경로,
              const string &정답파일_경로,
              const string &디렉토리_경로,
              const string &출력파일명,
              const vector<string> &소스코드들,
              const string &명령행_인수) const;
};