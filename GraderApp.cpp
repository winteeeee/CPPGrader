#include "GraderApp.h"

vector<string> GraderApp::테스트케이스_로드() {
    vector<string> 테스트케이스들;

    for (const fs::directory_entry &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        string 경로 = 엔트리.path().string();

        if (경로.find(".in") != string::npos) {
            테스트케이스들.push_back(경로);
        }
    }

    return 테스트케이스들;
}

void GraderApp::실행() {
    int 옵션;
    cout << "컴파일 옵션(0 : 일반, 1 : 각각 컴파일) : ";
    cin >> 옵션;

    vector<string> 소스코드들;
    vector<string> 테스트케이스들 = 테스트케이스_로드();
    auto 컴파일러 = CppCompiler(소스코드들, 테스트케이스들);
    string 현재_디렉토리;

    for (const fs::directory_entry &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory()) {
            if (!소스코드들.empty()) {
                컴파일러.컴파일(현재_디렉토리, 옵션);
            }
            현재_디렉토리 = 엔트리.path().string();
        } else {
            string 파일명 = 엔트리.path().filename().string();
            if (파일명.find(".cpp") != string::npos) {
                소스코드들.push_back("\"" + 파일명 + "\"");
            } else if (파일명.find(".in") != string::npos) {
                테스트케이스들.push_back(엔트리.path().string());
            }
        }
    }
    컴파일러.컴파일(현재_디렉토리, 옵션);
}
