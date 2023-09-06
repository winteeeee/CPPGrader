#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class CppGrader {
private:
    ofstream &출력_스트림;
    void 코드_출력(const string& 경로);
    void 채점_프롬프트_출력(const vector<string> &소스코드들);
public:
    CppGrader(ofstream& 출력_스트림);
    void 채점(const vector<string> &소스코드, const string &정답파일, const string &출력파일명);
};
