#include "GraderApp.h"

pair<vector<vector<string>>, vector<vector<string>>> GraderApp::테스트케이스_로드() {
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

GraderApp::GraderApp(const string &채점파일명) : 출력_스트림(채점파일명) {}
GraderApp::~GraderApp() {
    출력_스트림.close();
}

void GraderApp::실행() {
    int 옵션;
    cout << "컴파일 옵션(1 : 일반, 2 : 각각 컴파일) : ";
    cin >> 옵션;

    vector<string> 소스코드들;
    unsigned long long 인덱스 = 0;
    auto [입력파일들, 정답파일들] = 테스트케이스_로드();
    auto 컴파일러 = CppCompiler(소스코드들, 출력_스트림);
    string 현재_디렉토리;
    string 현재_학생;

    출력_스트림 << "===================================";
    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory()) {
            if (!소스코드들.empty()) {
                컴파일러.컴파일(현재_디렉토리, 현재_학생, 입력파일들[인덱스], 정답파일들[인덱스], 옵션);
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
            if (파일명.find(".cpp") != string::npos ||
                파일명.find(".h") != string::npos ||
                파일명.find(".h++") != string::npos) {
                소스코드들.push_back("\"" + 파일명 + "\"");
            }
        }
    }

    if (!소스코드들.empty()) {
        컴파일러.컴파일(현재_디렉토리, 현재_학생, 입력파일들[인덱스], 정답파일들[인덱스], 옵션);
    }
    출력_스트림 << endl << "===================================";
}
