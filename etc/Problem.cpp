#include "Problem.h"
using namespace std;

Problem::Problem(const std::string 문제, int 테스트케이스_개수, const std::vector<std::string> 입력파일들, const std::vector<std::string> 정답파일들, const std::vector<std::string> 메인_경로들, const std::vector<std::string> 명령행인수들) :
        문제(문제), 테스트케이스_개수(테스트케이스_개수), 입력파일들(입력파일들), 정답파일들(정답파일들), 메인_경로들(메인_경로들), 명령행인수들(명령행인수들) {}

const string &Problem::get문제() const {
    return 문제;
}

void Problem::set문제(const string &문제) {
    Problem::문제 = 문제;
}

const vector<std::string> &Problem::get입력파일들() const {
    return 입력파일들;
}

void Problem::set입력파일들(const vector<std::string> &입력파일들) {
    Problem::입력파일들 = 입력파일들;
}

const vector<std::string> &Problem::get정답파일들() const {
    return 정답파일들;
}

void Problem::set정답파일들(const vector<std::string> &정답파일들) {
    Problem::정답파일들 = 정답파일들;
}

const vector<std::string> &Problem::get명령행인수들() const {
    return 명령행인수들;
}

void Problem::set명령행인수들(const vector<std::string> &명령행인수들) {
    Problem::명령행인수들 = 명령행인수들;
}

int Problem::get테스트케이스_개수() const {
    return 테스트케이스_개수;
}

void Problem::set테스트케이스_개수(int 테스트케이스_개수) {
    Problem::테스트케이스_개수 = 테스트케이스_개수;
}

const vector<std::string> &Problem::get메인_경로들() const {
    return 메인_경로들;
}

void Problem::set메인_경로들(const vector<std::string> &메인_경로들) {
    Problem::메인_경로들 = 메인_경로들;
}




