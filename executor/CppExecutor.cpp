#include "CppExecutor.h"

CppExecutor::CppExecutor(std::ofstream &출력_스트림) : 채점기(출력_스트림) {}

void CppExecutor::실행(const std::string &입력파일_경로,
                       const std::string &정답파일_경로,
                       const std::string &디렉토리_경로,
                       const std::string &출력파일명,
                       const std::vector<std::string> &소스코드들,
                       const std::string &명령행_인수) const {
    std::cout << "\n=======================================================================================\n";
    std::string 디렉토리_소스코드_문자열 = "Executing on : " + 디렉토리_경로 + "\nSource Code : ";
    for (const std::string& 소스코드 : 소스코드들) {
        디렉토리_소스코드_문자열 += (소스코드 + " ");
    }
    std::cout << 디렉토리_소스코드_문자열;
    std::cout << "\nTestCase : " + 입력파일_경로;
    if (!명령행_인수.empty()) {
        std::cout << "\nArguments : " + 명령행_인수;
    }
    std::cout << "\n=======================================================================================\n";

    std::string 명령어 = ".\\output " + util::큰따옴표_래핑(명령행_인수);
    if (입력파일_경로.find("console") == std::string::npos) {
        명령어 += (" < " + util::큰따옴표_래핑(입력파일_경로) + " > " + 출력파일명);
        system(명령어.c_str());
    } else {
        system(명령어.c_str());
    }
    채점기.채점(소스코드들, 정답파일_경로, 출력파일명);
    fs::remove(출력파일명);
}

