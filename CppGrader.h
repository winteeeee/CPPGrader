#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CppGrader {
private:
    ofstream& 출력_스트림;
    void 코드_출력(const string& 경로);
public:
    CppGrader(ofstream& 출력_스트림);
    ~CppGrader();
    void 채점(const vector<string>& 소스코드);
};
