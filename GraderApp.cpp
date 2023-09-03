#include "GraderApp.h"

vector<string> GraderApp::테스트케이스_로드() {
    vector<string> 입력파일들;

    for (const fs::directory_entry &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        string 경로 = 엔트리.path().string();

        if (경로.find(".in") != string::npos) {
            입력파일들.push_back(경로);
        }
    }

    return 입력파일들;
}

void GraderApp::실행() {
    int 옵션;
    cout << "컴파일 옵션(0 : 일반, 1 : 각각 컴파일) : ";
    cin >> 옵션;

    vector<string> 소스코드들;
    auto 입력파일들 = 테스트케이스_로드();
    auto 컴파일러 = CppCompiler(소스코드들, 입력파일들);
    string 현재_디렉토리;

    for (const fs::directory_entry &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory()) {
            if (!소스코드들.empty()) {
                컴파일러.컴파일(현재_디렉토리, 옵션);
            }
            현재_디렉토리 = 엔트리.path().filename().string();
        } else {
            string 파일명 = 엔트리.path().filename().string();
            if (파일명.find(".cpp") != string::npos) {
                소스코드들.push_back("\"" + 파일명 + "\"");
            }
        }
    }

    if (!소스코드들.empty()) {
        컴파일러.컴파일(현재_디렉토리, 옵션);
    }
}
