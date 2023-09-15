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
                파일명 += 절대_경로[인덱스];
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