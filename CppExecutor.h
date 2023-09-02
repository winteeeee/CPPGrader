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
    CppExecutor();
    void 실행(const string& 입력파일_경로, const string& 정답파일_경로);
};