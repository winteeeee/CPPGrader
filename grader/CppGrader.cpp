#include "CppGrader.h"

void CppGrader::코드_출력(const string &경로) const {
    ifstream 입력_스트림(경로);
    util::느리게_출력("\n ===== " + 경로 + " ===== \n");
    if (입력_스트림.is_open()) {
        string 줄;

        while (getline(입력_스트림, 줄)) {
            cout << 줄 << endl;
        }
    } else {
        util::느리게_출력("[Error : Code print failed]\n");
    }
    cout << '\n';
    입력_스트림.close();
}

void CppGrader::채점_프롬프트_출력(const vector<string> &소스코드들) const {
    string 명령;
    bool 탈출_불가 = true;

    while (탈출_불가) {
        util::느리게_출력("\nGrade [y, n, c, ?] : ");
        cin >> 명령;

        if (명령 == "y") {
            출력_스트림 << "O ";
            탈출_불가 = false;
        } else if (명령 == "n") {
            출력_스트림 << "X ";
            탈출_불가 = false;
        } else if (명령 == "c") {
            cin.ignore();
            for (int 인덱스 = 0; 인덱스 < 소스코드들.size(); 인덱스++) {
                string 소스코드 = 소스코드들[인덱스];
                소스코드.replace(0, 1, "");
                소스코드.replace(소스코드.length() - 1, 1, "");
                코드_출력(소스코드);

                util::느리게_출력("(" + to_string(인덱스 + 1) + "/" + to_string(소스코드들.size()) + ") " + "Enter any input to next");
                getline(cin, 소스코드);
            }
        } else if (명령 == "?") {
            util::느리게_출력("y - Correct\n");
            util::느리게_출력("n - Wrong\n");
            util::느리게_출력("c - Code print\n");
            util::느리게_출력("? - help print\n");
        } else {
            util::느리게_출력("[Error : Wrong Command]\n");
        }
    }
}

CppGrader::CppGrader(ofstream &출력_스트림) : 출력_스트림(출력_스트림) {}

void CppGrader::채점(const vector<string> &소스코드들, const string &정답파일, const string &출력파일명) const {
    string 명령어 = "fc  /w /n " + util::큰따옴표_래핑(정답파일) + " " + util::큰따옴표_래핑(출력파일명) + " > temp.txt";
    system(명령어.c_str());

    ifstream 입력_스트림("temp.txt");
    if (입력_스트림.is_open()) {
        string 첫줄;
        string 줄;
        bool 정답 = false;

        while (getline(입력_스트림, 줄)) {
            if (첫줄.empty()) {
                첫줄 = 줄;
                continue;
            }

            if (줄.find("FC: no differences encountered") != string::npos) {
                util::느리게_출력("********* Same as the .out file *********\n\n");
                출력_스트림 << "O ";
                정답 = true;
                break;
            }

            if (!첫줄.empty()) {
                cout << 첫줄 << endl;
                첫줄 = "";
            }

            cout << 줄 << endl;
        }

        if (!정답) {
            채점_프롬프트_출력(소스코드들);
        }
    } else {
        util::느리게_출력("[Error : FC command do not execute normally]\n");
    }
    입력_스트림.close();
    fs::remove("temp.txt");
}