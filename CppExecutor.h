#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "CppGrader.h"
using namespace std;

class CppExecutor {
private:
    CppGrader 채점기;
public:
    CppExecutor(ofstream& 출력_스트림);
    void 실행(const string& 입력파일_경로, const string& 학생_정보, const vector<string>& 소스코드들);
};