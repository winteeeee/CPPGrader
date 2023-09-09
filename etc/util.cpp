#include "util.h"

string util::큰따옴표_래핑(const std::string &경로) {
    if (경로.empty()) {
        return 경로;
    }

    return ("\"" + 경로 + "\"");
}

bool util::소스코드_존재(const std::string &파일) {
    return 파일.find(".cpp") != string::npos || 파일.find(".h") != string::npos || 파일.find(".h++") != string::npos;
}

string util::슬래시_변환(const std::string &문자열) {
    string 결과;

    for (auto 문자: 문자열) {
        if (문자 == '\\') {
            문자 = '/';
        }

        결과.push_back(문자);
    }

    return 결과;
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