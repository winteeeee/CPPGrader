#pragma once
#include <vector>
#include <string>
using namespace std;

class TestCase {
private:
    vector<string> 입력파일들;
    vector<string> 정답파일들;
    vector<string> 명령행인수들;

public:
    TestCase(const vector<string> 입력파일들, const vector<string> 정답파일들, const vector<string> 명령행인수들);
    const vector<string> &get입력파일들() const;
    void set입력파일들(const vector<string> &입력파일들);
    const vector<string> &get정답파일들() const;
    void set정답파일들(const vector<string> &정답파일들);
    const vector<string> &get명령행인수들() const;
    void set명령행인수들(const vector<string> &명령행인수들);
};