#include "CppCompiler.h"
using namespace std;

void CppCompiler::실행기_작동(const string &디렉토리_경로,
                              const string &임시_파일명,
                              const string &명령어,
                              const TestCase &테스트케이스들,
                              const vector<string> &목표_소스코드) const {
    const vector<string> 입력파일들 = 테스트케이스들.get입력파일들();
    const vector<string> 정답파일들 = 테스트케이스들.get정답파일들();
    const vector<string> 명령행_인수들 = 테스트케이스들.get명령행인수들();

    util::느리게_출력("Compiling...\n");
    int 컴파일_결과 = system(명령어.c_str());
    if (!컴파일_결과) {
        for (const auto &입력파일_경로 : 입력파일들) {
            const auto &정답파일_경로 = 정답파일들[&입력파일_경로 - &입력파일들[0]];
            if (!명령행_인수들.empty()) {
                const auto &명령행_인수 = 명령행_인수들[&입력파일_경로 - &입력파일들[0]];
                실행기.실행(입력파일_경로, 정답파일_경로, 디렉토리_경로, 임시_파일명, 목표_소스코드, 명령행_인수);
            } else {
                실행기.실행(입력파일_경로, 정답파일_경로, 디렉토리_경로, 임시_파일명, 목표_소스코드);
            }
        }
        fs::remove("output.exe");
    }
}

CppCompiler::CppCompiler(ofstream& 출력_스트림)
: 출력_스트림(출력_스트림), 실행기(출력_스트림) {}

void CppCompiler::컴파일(const string &디렉토리_경로,
                         const string &학생_정보,
                         const vector<string> &소스코드들,
                         const vector<TestCase> &테스트케이스들,
                         const int &옵션,
                         const int &인덱스) const {
    string 임시_파일명 = "output.txt";
    string 명령어;


    util::느리게_출력("\n[Target Student : " + 학생_정보 + "]\n");
    chdir(디렉토리_경로.c_str());
    if (옵션 == CppCompiler::컴파일_옵션::일반) {
        명령어 = "g++ ";
        for (const string &소스코드: 소스코드들) {
            if (소스코드.find(".cpp") != string::npos) {
                명령어 += (소스코드 + " ");
            }
        }
        명령어 += " -o output";
        실행기_작동(디렉토리_경로, 임시_파일명, 명령어, 테스트케이스들[인덱스], 소스코드들);
    } else if (옵션 == CppCompiler::컴파일_옵션::각각_컴파일) {
        int 내부_인덱스 = 0;
        for (const auto &소스코드 : 소스코드들) {
            vector<string> 임시_벡터 = {소스코드};
            if (소스코드.find(".cpp") != string::npos) {
                명령어 = "g++ " + 소스코드 + " -o output";
            }
            실행기_작동(디렉토리_경로, 임시_파일명, 명령어, 테스트케이스들[내부_인덱스], 임시_벡터);
            내부_인덱스++;
        }

        for (; 내부_인덱스 < 테스트케이스들.size(); 내부_인덱스++) {
            for (int i = 0; i < 테스트케이스들[내부_인덱스].get입력파일들().size(); i++) {
                출력_스트림 << "X ";
            }
        }
    }
}
