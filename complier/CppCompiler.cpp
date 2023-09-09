#include "CppCompiler.h"

CppCompiler::CppCompiler(vector <string> &소스코드들, ofstream& 출력_스트림)
: 출력_스트림(출력_스트림), 소스코드들(소스코드들), 실행기(출력_스트림) {}

void CppCompiler::컴파일(const string &디렉토리_경로,
                         const string &학생_정보,
                         const vector<string> &입력파일들,
                         const vector<string> &정답파일들,
                         const int &옵션,
                         const string& 명령행_인수) const {
    util::느리게_출력("\n[Target Student : " + 학생_정보 + "]\n");
    chdir(디렉토리_경로.c_str());

    if (옵션 == CppCompiler::컴파일_옵션::일반) {
        string 명령어 = "g++ ";
        for (const string &소스코드: 소스코드들) {
            if (소스코드.find(".cpp") != string::npos) {
                명령어 += (소스코드 + " ");
            }
        }
        명령어 += " -o output";

        util::느리게_출력("Compiling...\n");
        int 컴파일_결과 = system(명령어.c_str());
        if (!컴파일_결과) {
            for (const auto& 입력파일_경로 : 입력파일들) {
                const auto& 정답파일_경로 = 정답파일들[&입력파일_경로 - &입력파일들[0]];
                실행기.실행(입력파일_경로, 정답파일_경로, 디렉토리_경로, "output.txt", 소스코드들, 명령행_인수);
            }
            fs::remove("output.exe");
        }
    } else if (옵션 == CppCompiler::컴파일_옵션::각각_컴파일) {
        for (const auto &소스코드 : 소스코드들) {
            if (소스코드.find(".cpp") != string::npos) {
                vector<string> 임시_벡터 = {소스코드};

                string 명령어 = "g++ " + 소스코드 + " -o output";
                util::느리게_출력("Compiling...\n");
                cout << endl;
                int 컴파일_결과 = system(명령어.c_str());
                if (!컴파일_결과) {
                    for (const auto &입력파일_경로: 입력파일들) {
                        const auto &정답파일_경로 = 정답파일들[&입력파일_경로 - &입력파일들[0]];
                        실행기.실행(입력파일_경로, 정답파일_경로, 디렉토리_경로, "output.txt", 임시_벡터, 명령행_인수);
                    }
                    fs::remove("output.exe");
                }
            }
        }
    } else {
        util::느리게_출력("[Error : Wrong Option]");
    }
    소스코드들.clear();
}
