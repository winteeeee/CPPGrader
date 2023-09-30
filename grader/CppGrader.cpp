#include "CppGrader.h"
using namespace std;

void CppGrader::파일_내용_출력(const string &경로) const {
    ifstream 입력_스트림(경로);
    util::느리게_출력("\n ===== " + 경로 + " ===== \n");
    if (입력_스트림.is_open()) {
        string 줄;

        while (getline(입력_스트림, 줄)) {
            cout << 줄 << endl;
        }
    } else {
        util::느리게_출력("[Error : print failed]\n");
    }
    cout << '\n';
    입력_스트림.close();
}

void CppGrader::채점_프롬프트_출력(const vector<string> &소스코드들, const string &정답파일, const string &출력파일명) const {
    string 명령;

    while (명령 != "y" && 명령 != "n" && 명령 != "h") {
        util::느리게_출력("\nGrade [y, n, h, d, c, ?] : ");
        cin >> 명령;

        if (명령 == "y") {
            출력_스트림 << "O ";
        } else if (명령 == "n") {
            출력_스트림 << "X ";
        } else if (명령 == "h") {
            출력_스트림 << "△ ";
        } else if (명령 == "d") {
            파일_내용_출력(루트_디렉토리 + "/" + 정답파일);
            파일_내용_출력(출력파일명);
        } else if (명령 == "c") {
            cin.ignore();
            for (int 인덱스 = 0; 인덱스 < 소스코드들.size(); 인덱스++) {
                string 소스코드 = 소스코드들[인덱스];
                파일_내용_출력(소스코드);

                util::느리게_출력("(" + to_string(인덱스 + 1) + "/" + to_string(소스코드들.size()) + ") " + "Enter any input to next");
                getline(cin, 소스코드);
            }
        } else if (명령 == "?") {
            util::느리게_출력("y - perfect point\n");
            util::느리게_출력("n - zero point\n");
            util::느리게_출력("h - half point\n");
            util::느리게_출력("d - diff detail\n");
            util::느리게_출력("c - code print\n");
            util::느리게_출력("? - help print\n");
        } else {
            util::느리게_출력("[Error : Wrong Command]\n");
        }
    }
}

CppGrader::CppGrader(ofstream &출력_스트림, const string &루트_디렉토리) : 출력_스트림(출력_스트림), 루트_디렉토리(루트_디렉토리) {}

void CppGrader::채점(const vector<string> &소스코드들, const string &정답파일, const string &출력파일명) const {
    string 임시_파일명 = "temp.txt";
    string 명령어 = "fc  /w /n " + util::큰따옴표_래핑(출력파일명) + " " + util::큰따옴표_래핑(루트_디렉토리 + "/" + 정답파일) + " > " + 임시_파일명;
    system(명령어.c_str());

    ifstream 입력_스트림(임시_파일명);
    if (입력_스트림.is_open()) {
        string 줄;

        getline(입력_스트림, 줄);
        getline(입력_스트림, 줄);
        if (줄.find("FC: no differences encountered") != string::npos) {
            cout << "********* Same as the .out file *********\n\n";
            출력_스트림 << "O ";
        } else {
            입력_스트림.seekg(0);
            while(getline(입력_스트림, 줄)) {
                cout << 줄 << endl;
            }
            채점_프롬프트_출력(소스코드들, 정답파일, 출력파일명);
        }
    } else {
        util::느리게_출력("[Error : FC command do not execute normally]\n");
    }
    입력_스트림.close();
    fs::remove(임시_파일명);
}