#include "TestCase.h"

TestCase::TestCase(const vector<string> 입력파일들, const vector<string> 정답파일들, const vector<string> 명령행인수들) :
        입력파일들(입력파일들), 정답파일들(정답파일들), 명령행인수들(명령행인수들) {}

const vector<string> &TestCase::get입력파일들() const {
    return 입력파일들;
}

void TestCase::set입력파일들(const vector<string> &입력파일들) {
    TestCase::입력파일들 = 입력파일들;
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
