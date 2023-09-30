#include "util.h"
using namespace std;

string util::큰따옴표_래핑(const string &경로) {
    if (경로.empty()) {
        return 경로;
    }

    return ("\"" + 경로 + "\"");
}

bool util::소스코드_존재(const string &파일) {
    return (파일.find(".cpp") != string::npos ||
           파일.find(".h") != string::npos ||
           파일.find(".h++") != string::npos ||
           파일.find(".hpp") != string::npos) && (파일.find("._") == string::npos);
}

int util::키보드_제어_콘솔_출력(vector<string> &출력_문자열, int 옵션_시작_인덱스) {
    int 옵션_인덱스 = 0;
    bool 선택됨 = false;

    for (const auto &현재_문자열 : 출력_문자열) {
        느리게_출력(현재_문자열);
        cout << endl;
    }
    느리게_출력("Selected Option : " + 출력_문자열[옵션_시작_인덱스 + 옵션_인덱스] + "\n");

    while (!선택됨) {
        int 입력 = _getch();
        방향키_제어(입력, 출력_문자열.size() - 옵션_시작_인덱스 - 1, 옵션_인덱스, 선택됨);
        if (입력 == 방향키_위 || 입력 == 방향키_아래) {
            느리게_출력("Selected Option : " + 출력_문자열[옵션_시작_인덱스 + 옵션_인덱스] + "\n");
        }
    }

    return 옵션_인덱스;
}

void util::방향키_제어(int 입력, int 인덱스_최댓값, int &인덱스, bool &종료_플래그) {
    if (입력 == 방향키_위) {
        인덱스--;
        if (인덱스 < 0) {
            인덱스 = 인덱스_최댓값;
        }
    } else if (입력 == 방향키_아래) {
        인덱스++;
        if (인덱스 > 인덱스_최댓값) {
            인덱스 = 0;
        }
    } else if (입력 == 엔터) {
        종료_플래그 = true;
    }
}

void util::느리게_출력(const string &문자열, int 딜레이) {
    for (const auto &문자 : 문자열) {
        cout << 문자 << flush;
        Sleep(딜레이);
    }
}

pair<string, string> util::디렉토리_파일_경로_분리(const string &절대_경로) {
    string 디렉토리_경로;
    string 파일명;
    bool 파일명_추출_중 = true;

    for (int 인덱스 = 절대_경로.length(); 인덱스 >= 0; 인덱스--) {
        if (파일명_추출_중) {
            if (절대_경로[인덱스] == '/' || 절대_경로[인덱스] == '\\') {
                파일명_추출_중 = false;
            } else {
                if (절대_경로[인덱스]) {
                    파일명 += 절대_경로[인덱스];
                }
            }
        } else {
            디렉토리_경로 += 절대_경로[인덱스];
        }
    }

    reverse(디렉토리_경로.begin(), 디렉토리_경로.end());
    reverse(파일명.begin(), 파일명.end());
    return {디렉토리_경로, 파일명};
}

void util::압축_해제(const string &디렉토리_경로, const string &파일명) {
    chdir(디렉토리_경로.c_str());
    system(string("unzip -o " + 큰따옴표_래핑(파일명)).c_str());
    filesystem::remove(파일명);
}

void util::아스키_아트_출력() {
    cout << " _____                 _____                   _              _ " << endl;
    cout << "/  __ \\   _      _    |  __ \\                 | |            | |" << endl;
    cout << "| /  \\/ _| |_  _| |_  | |  \\/ _ __   __ _   __| |  ___  _ __ | |" << endl;
    cout << "| |    |_   _||_   _| | | __ | '__| / _` | / _` | / _ \\| '__|| |" << endl;
    cout << "| \\__/\\  |_|    |_|   | |_\\ \\| |   | (_| || (_| ||  __/| |   |_|" << endl;
    cout << " \\____/                \\____/|_|    \\__,_| \\__,_| \\___||_|   (_)" << endl;
}

void util::파일명_변경(const string &디렉토리_경로, const string &이전, const string &이후) {
    rename((디렉토리_경로 + '\\' + 이전).c_str(), (디렉토리_경로 + '\\' + 이후).c_str());
}

vector<Problem> util::컨픽_읽기(char 구분자) {
    vector<Problem> 결과;
    int 개수 = GetPrivateProfileInt("Problem", "size", 0, "./ProblemConfig.ini");
    char 이름[256]; GetPrivateProfileString("Problem", "name", "", 이름, 256, "./ProblemConfig.ini");

    int 이름_인덱스 = 0;
    for (int i = 0; i < 개수; i++) {
        string 현재_이름;
        vector<string> 입력파일들, 출력파일들, 메인들, 명령행_인수들;

        while (이름[이름_인덱스]) {
            if (이름[이름_인덱스] == 구분자) {
                이름_인덱스++;
                break;
            }

            현재_이름 += 이름[이름_인덱스++];
        }

        int 입력_인덱스 = 0;
        int 출력_인덱스 = 0;
        int 메인_인덱스 = 0;
        int 명령행_인덱스 = 0;
        int 문제_개수 = GetPrivateProfileInt(현재_이름.c_str(), "size", 0, "./ProblemConfig.ini");
        char 입력[1024]; GetPrivateProfileString(현재_이름.c_str(), "inputPath", "", 입력, 1024, "./ProblemConfig.ini");
        char 출력[1024]; GetPrivateProfileString(현재_이름.c_str(), "outputPath", "", 출력, 1024, "./ProblemConfig.ini");
        char 메인[1024]; GetPrivateProfileString(현재_이름.c_str(), "mainPath", "", 메인, 1024, "./ProblemConfig.ini");
        char 명령행[1024]; GetPrivateProfileString(현재_이름.c_str(), "argvPath", "", 명령행, 1024, "./ProblemConfig.ini");

        for (int j = 0; j < 문제_개수; j++) {
            string 현재_입력, 현재_출력, 현재_메인, 현재_명령행;

            while (입력[입력_인덱스]) {
                if (입력[입력_인덱스] == 구분자) {
                    입력_인덱스++;
                    break;
                }

                현재_입력 += 입력[입력_인덱스++];
            }

            while (출력[출력_인덱스]) {
                if (출력[출력_인덱스] == 구분자) {
                    출력_인덱스++;
                    break;
                }

                현재_출력 += 출력[출력_인덱스++];
            }

            while (메인[메인_인덱스]) {
                if (메인[메인_인덱스] == 구분자) {
                    메인_인덱스++;
                    break;
                }

                현재_메인 += 메인[메인_인덱스++];
            }

            while (명령행[명령행_인덱스]) {
                if (명령행[명령행_인덱스] == 구분자) {
                    명령행_인덱스++;
                    break;
                }

                현재_명령행 += 명령행[명령행_인덱스++];
            }

            입력파일들.push_back(현재_입력);
            출력파일들.push_back(현재_출력);
            메인들.push_back(현재_메인);
            명령행_인수들.push_back(현재_명령행);
        }
        결과.push_back({현재_이름, 문제_개수, 입력파일들, 출력파일들, 메인들, 명령행_인수들});
    }

    return 결과;
}

void util::파일_복사(const std::string& 대상, const std::string& 목표) {
    auto [temp, 파일명] = 디렉토리_파일_경로_분리(대상);
    cout << 대상 << " to " << 목표 << endl;
    CopyFile(대상.c_str(), (목표 + "/" + 파일명).c_str(), false);
}