#include "CppCompiler.h"

#include <utility>
using namespace std;

int CppCompiler::문제_인덱스_찾기(int 옵션, const std::string &디렉토리_경로, const std::vector<std::string> &소스코드들, const std::vector<Problem> &문제들) const {
    if (옵션 == 0) {
        for (int i = 0; i < 문제들.size(); i++) {
            if (디렉토리_경로.find(문제들[i].get문제()) != string::npos) {
                return i;
            }
        }
    } else if (옵션 == 1) {
        for (int i = 0; i < 문제들.size(); i++) {
            if (소스코드들[0].find(문제들[i].get문제()) != string::npos) {
                return i;
            }
        }
    }
    return -1;
}

void CppCompiler::실행기_작동(int 옵션,
                              const string &디렉토리_경로,
                              const string &임시_파일명,
                              const Problem &문제,
                              const vector<string> &목표_소스코드) const {
    const vector<string> &메인_경로 = 문제.get메인_경로들();
    const vector<string> &입력파일들 = 문제.get입력파일들();
    const vector<string> &정답파일들 = 문제.get정답파일들();
    const vector<string> &명령행_인수들 = 문제.get명령행인수들();

    for (int i = 0; i < 문제.get테스트케이스_개수(); i++) {
        string 명령어;
        if (!옵션) {
            명령어 = "g++ ";
            for (const string &소스코드: 목표_소스코드) {
                if (소스코드.find(".cpp") != string::npos) {
                    명령어 += (소스코드 + " ");
                }
            }

            if (!메인_경로.empty()) {
                auto [temp, 메인] = util::디렉토리_파일_경로_분리(메인_경로[i]);
                명령어 += (메인 + " ");
            }
            명령어 += " -o output";

            util::느리게_출력("Compiling...\n");
            int 컴파일_결과 = system(명령어.c_str());
            if (!컴파일_결과) {
                실행기.실행(입력파일들[i], 정답파일들[i], 디렉토리_경로, 임시_파일명, 목표_소스코드, 명령행_인수들[i]);
                fs::remove("output.exe");
            }
        } else {
            for (const auto &소스코드 : 목표_소스코드) {
                if (소스코드.find(문제.get문제()) != string::npos) {
                    vector<string> 임시_벡터 = {소스코드};
                    if (메인_경로[0].empty()) {
                        명령어 = "g++ " + 소스코드 + " -o output";
                    } else {
                        auto [temp, 메인] = util::디렉토리_파일_경로_분리(메인_경로[i]);
                        명령어 = "g++ " + 메인 + " -o output";
                    }

                    util::느리게_출력("Compiling...\n");
                    int 컴파일_결과 = system(명령어.c_str());
                    if (!컴파일_결과) {
                        실행기.실행(입력파일들[i], 정답파일들[i], 디렉토리_경로, 임시_파일명, 임시_벡터, 명령행_인수들[i]);
                        fs::remove("output.exe");
                    }
                }
            }
        }
    }
}

CppCompiler::CppCompiler(std::ofstream& 출력_스트림, const std::string &루트_디렉토리)
: 출력_스트림(출력_스트림), 루트_디렉토리(루트_디렉토리), 실행기(출력_스트림, 루트_디렉토리) {}

void CppCompiler::컴파일(const std::string &디렉토리_경로, const std::string &학생_정보, const std::vector<std::string> &소스코드들,
                      const std::vector<Problem> &문제들) const {
    int 컴파일_옵션 = 1;
    for (const auto& 소스코드 : 소스코드들) {
        if (소스코드.find(".h") != string::npos) {
            컴파일_옵션 = 0;
            break;
        }
    }

    string 임시_파일명 = "output.txt";
    util::느리게_출력("\n[Target Student : " + 학생_정보 + "]\n");
    chdir(디렉토리_경로.c_str());

    if (!컴파일_옵션) {
        auto 인덱스 = 문제_인덱스_찾기(컴파일_옵션, 디렉토리_경로, 소스코드들, 문제들);
        for (const auto& 메인_경로 : 문제들[인덱스].get메인_경로들()) {
            string 현재_경로 = fs::current_path().string();
            chdir(루트_디렉토리.c_str());
            util::파일_복사(메인_경로, 디렉토리_경로);
            chdir(현재_경로.c_str());
        }

        출력_스트림 << 문제들[인덱스].get문제() << " : ";
        실행기_작동(컴파일_옵션, 디렉토리_경로, 임시_파일명, 문제들[인덱스], 소스코드들);
        출력_스트림 << endl;

        for (const auto& 메인_경로 : 문제들[인덱스].get메인_경로들()) {
            auto [temp, 파일명] = util::디렉토리_파일_경로_분리(메인_경로);
            fs::remove(파일명);
        }
    } else {
        int 인덱스 = 0;
        for (const auto &문제 : 문제들) {
            if (인덱스 >= 소스코드들.size()) {
                break;
            }

            for (const auto& 메인_경로 : 문제.get메인_경로들()) {
                string 현재_경로 = fs::current_path().string();
                chdir(루트_디렉토리.c_str());
                util::파일_복사(메인_경로, 디렉토리_경로);
                chdir(현재_경로.c_str());
            }

            출력_스트림 << 문제.get문제() << " : ";
            실행기_작동(컴파일_옵션, 디렉토리_경로, 임시_파일명, 문제, 소스코드들);
            출력_스트림 << endl;

            for (const auto& 메인_경로 : 문제들[인덱스].get메인_경로들()) {
                auto [temp, 파일명] = util::디렉토리_파일_경로_분리(메인_경로);
                fs::remove(파일명);
            }

            인덱스++;
        }
    }
}