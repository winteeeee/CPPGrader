#include "TestCase.h"
using namespace std;

TestCase::TestCase(const string 문제, const vector<string> 입력파일들, const vector<string> 정답파일들, const vector<string> 명령행인수들) :
        문제(문제), 입력파일들(입력파일들), 정답파일들(정답파일들), 명령행인수들(명령행인수들) {}

const vector<string> &TestCase::get입력파일들() const {
    return 입력파일들;
}

void TestCase::set입력파일들(const vector<string> &입력파일들) {
    TestCase::입력파일들 = 입력파일들;
}

const string &TestCase::get문제() const {
    return 문제;
}

void TestCase::set문제(const string &문제) {
    TestCase::문제 = 문제;
}

const vector<string> &TestCase::get정답파일들() const {
    return 정답파일들;
}

void TestCase::set정답파일들(const vector<string> &정답파일들) {
    TestCase::정답파일들 = 정답파일들;
}

const vector<string> &TestCase::get명령행인수들() const {
    return 명령행인수들;
}

void TestCase::set명령행인수들(const vector<string> &명령행인수들) {
    TestCase::명령행인수들 = 명령행인수들;
}
