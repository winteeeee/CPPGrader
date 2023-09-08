#include "GraderApp.h"

pair<vector<vector<string>>, vector<vector<string>>> GraderApp::테스트케이스_로드() const {
    vector<vector<string>> 입력파일들;
    vector<vector<string>> 정답파일들;

    vector<string> 입력파일;
    vector<string> 정답파일;
    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory() && !입력파일.empty()) {
            입력파일들.push_back(입력파일);
            정답파일들.push_back(정답파일);
            입력파일.clear();
            정답파일.clear();
        }

        string 경로 = 엔트리.path().string();
        if (경로.find(".in") != string::npos) {
            입력파일.push_back(경로);
        } else if (경로.find(".out") != string::npos) {
            정답파일.push_back(경로);
        }
    }

    if (!입력파일.empty()) {
        입력파일들.push_back(입력파일);
        정답파일들.push_back(정답파일);
    }

    return {입력파일들, 정답파일들};
}

void GraderApp::메인_복사() const {
    string 메인_이름;
    string 목표_폴더;

    while (메인_이름 != "1" && 목표_폴더 != "1") {
        cout << "Please enter the name of the main file to copy (enter 1 for exit) : ";
        cin.ignore();
        getline(cin, 메인_이름);
        cout << "Please enter the path of the target folder (enter 1 for exit) : ";
        cin >> 목표_폴더;

        if (메인_이름 != "1" && 목표_폴더 != "1") {
            fs::path 디렉토리_경로;

            for (const auto &엔트리: fs::recursive_directory_iterator(fs::current_path())) {
                if (엔트리.is_directory()) {
                    디렉토리_경로 = 엔트리.path();
                } else {
                    string 파일 = 엔트리.path().filename().string();
                    if (util::소스코드_존재(파일) && 디렉토리_경로.filename().string() == 목표_폴더) {
                        CopyFile(메인_이름.c_str(), (디렉토리_경로.string() + "/" + 메인_이름).c_str(), false);
                    }
                }
            }
        }
    }
}

vector<string> GraderApp::명령행_인수_로드() const {
    vector<string> 인수들;

    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        string 경로 = 엔트리.path().string();
        if (경로.find(".argv") != string::npos) {
            인수들.push_back(경로);
        }
    }

    return 인수들;
}

void GraderApp::아스키_아트_출력() const {
    cout << " _____                 _____                   _              _ " << endl;
    cout << "/  __ \\   _      _    |  __ \\                 | |            | |" << endl;
    cout << "| /  \\/ _| |_  _| |_  | |  \\/ _ __   __ _   __| |  ___  _ __ | |" << endl;
    cout << "| |    |_   _||_   _| | | __ | '__| / _` | / _` | / _ \\| '__|| |" << endl;
    cout << "| \\__/\\  |_|    |_|   | |_\\ \\| |   | (_| || (_| ||  __/| |   |_|" << endl;
    cout << " \\____/                \\____/|_|    \\__,_| \\__,_| \\___||_|   (_)" << endl;
}

int GraderApp::컴파일_옵션_선택() const {
    //TODO 콘솔 출력파트 개선 https://geundung.dev/15
    int 옵션_인덱스 = 0;
    bool 선택됨 = false;

    while (!선택됨) {
        system("cls");
        아스키_아트_출력();
        cout << "Select compilation options" << endl;
        for (int i = 0; i < 2; i++) {
            if (i == 옵션_인덱스) {
                cout << " -> ";
            }

            if (i == 0) {
                cout << "Default" << endl;
            } else if (i == 1) {
                cout << "Compile each" << endl;
            }
        }

        int 입력 = _getch();
        util::방향키_제어(입력, 2, 옵션_인덱스, 선택됨);
    }

    return (옵션_인덱스 + 1);
}

int GraderApp::메인_옵션_선택() const {
    int 옵션_인덱스 = 0;
    bool 선택됨 = false;

    while (!선택됨) {
        system("cls");
        아스키_아트_출력();
        cout << "Do you want to copy the main?" << endl;
        for (int i = 0; i < 2; i++) {
            if (i == 옵션_인덱스) {
                cout << " -> ";
            }

            if (i == 0) {
                cout << "No" << endl;
            } else if (i == 1) {
                cout << "Yes" << endl;
            }
        }

        int 입력 = _getch();
        util::방향키_제어(입력, 2, 옵션_인덱스, 선택됨);
    }

    return (옵션_인덱스 + 1);
}

GraderApp::GraderApp(const string &채점파일명) : 출력_스트림(채점파일명) {}
GraderApp::~GraderApp() {
    출력_스트림.close();
}

void GraderApp::실행() {
    int 컴파일_옵션 = 컴파일_옵션_선택();
    int 메인_옵션 = 메인_옵션_선택();
    if (메인_옵션 == 2) {
        메인_복사();
    }

    vector<string> 소스코드들;
    unsigned long long 인덱스 = 0;
    auto [입력파일들, 정답파일들] = 테스트케이스_로드();
    auto 명령행_인수들 = 명령행_인수_로드();
    auto 컴파일러 = CppCompiler(소스코드들, 출력_스트림);
    string 현재_디렉토리;
    string 현재_학생;
    string 인수;

    출력_스트림 << "===================================";
    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory()) {
            if (!소스코드들.empty()) {
                if (!명령행_인수들.empty()) {
                    인수 = 명령행_인수들[인덱스];
                }

                컴파일러.컴파일(현재_디렉토리,
                                현재_학생,
                                입력파일들[인덱스],
                                정답파일들[인덱스],
                                컴파일_옵션,
                                인수);
                인덱스 = (인덱스 + 1) % 입력파일들.size();
            }

            현재_디렉토리 = 엔트리.path().string();
            string 디렉토리명 = 엔트리.path().filename().string();

            if (디렉토리명.find('_') != string::npos) {
                출력_스트림 << endl << '[' << 디렉토리명 << ']' << endl;
                현재_학생 = 디렉토리명;
            }
        } else {
            string 파일명 = 엔트리.path().filename().string();
            if (util::소스코드_존재(파일명)) {
                소스코드들.push_back(util::큰따옴표_래핑(파일명));
            }
        }
    }

    if (!소스코드들.empty()) {
        if (!명령행_인수들.empty()) {
            인수 = 명령행_인수들[인덱스];
        }

        컴파일러.컴파일(현재_디렉토리,
                        현재_학생,
                        입력파일들[인덱스],
                        정답파일들[인덱스],
                        컴파일_옵션,
                        인수);
    }
    출력_스트림 << endl << "===================================";
}
