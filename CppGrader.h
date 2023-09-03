#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CppGrader {
private:
    ofstream 출력_스트림;
    void 코드_출력(const string& 경로);
public:
    CppGrader(const string& 경로);
    ~CppGrader();
    void 채점(const vector<string>& 소스코드);
    void 출력_스트림_쓰기(const string& 문자열);
};
