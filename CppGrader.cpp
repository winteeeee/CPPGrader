#include "CppGrader.h"

void CppGrader::코드_출력(const std::string &경로) {
    ifstream 입력_스트림(경로);
    cout << endl << " ===== " << 경로 << " ===== " << endl;
    if (입력_스트림.is_open()) {
        string 줄;

        while (getline(입력_스트림, 줄)) {
            cout << 줄 << endl;
        }
    } else {
        cout << "코드 출력 실패" << endl;
    }
    cout << '\n';
}

CppGrader::CppGrader(ofstream& 출력_스트림) : 출력_스트림(출력_스트림) {}

CppGrader::~CppGrader() {
    출력_스트림.close();
}

void CppGrader::채점(const vector<string>& 소스코드들) {
    string 명령;
    bool 탈출_불가 = true;

    while (탈출_불가) {
        cout << endl << "채점 [y, n, c, ?] : ";
        cin >> 명령;

        if (명령 == "y") {
            출력_스트림 << "O ";
            탈출_불가 = false;
        } else if (명령 == "n") {
            출력_스트림 << "X ";
            탈출_불가 = false;
        } else if (명령 == "c") {
            for (string 소스코드 : 소스코드들) {
                소스코드.replace(0, 1, "");
                소스코드.replace(소스코드.length() - 1, 1, "");
                코드_출력(소스코드);
            }
        } else if (명령 == "?") {
            cout << "y - 정답" << endl;
            cout << "n - 오답" << endl;
            cout << "c - 코드 보기" << endl;
            cout << "? - 도움말 표시" << endl;
        } else {
            cout << "잘못된 명령어" << endl;
        }
    }
}
