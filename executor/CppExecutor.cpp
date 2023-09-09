#include "CppExecutor.h"

CppExecutor::CppExecutor(ofstream &출력_스트림) : 채점기(출력_스트림) {}

void CppExecutor::실행(const string &입력파일_경로,
                       const string &정답파일_경로,
                       const string &디렉토리_경로,
                       const string &출력파일명,
                       const vector<string> &소스코드들,
                       const string &명령행_인수) const {
    util::느리게_출력("\n=======================================================================================\n", 1);
    string 디렉토리_소스코드_문자열 = "Executing on : " + 디렉토리_경로 + "\nSource Code : ";
    for (const string& 소스코드 : 소스코드들) {
        디렉토리_소스코드_문자열 += (소스코드 + " ");
    }
    util::느리게_출력(디렉토리_소스코드_문자열, 5);
    util::느리게_출력("\nTestCase : " + 입력파일_경로, 5);
    if (!명령행_인수.empty()) {
        util::느리게_출력("\nArguments : " + 명령행_인수, 5);
    }
    util::느리게_출력("\n=======================================================================================\n", 1);

    string 명령어 = ".\\output " + util::큰따옴표_래핑(명령행_인수);
    if (입력파일_경로.find("console") == string::npos) {
        명령어 += (" < " + util::큰따옴표_래핑(입력파일_경로) + " > " + 출력파일명);
        system(명령어.c_str());
    } else {
        system(명령어.c_str());
    }
    채점기.채점(소스코드들, 정답파일_경로, 출력파일명);
    fs::remove(출력파일명);
}

