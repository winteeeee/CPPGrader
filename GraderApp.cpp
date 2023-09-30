#include "GraderApp.h"
using namespace std;

void GraderApp::압축_해제(const string &압축파일명) const {
    string 원래_경로 = fs::current_path().string();

    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        const auto &경로 = 엔트리.path().string();
        if (경로.find(".zip") != string::npos) {
            auto [디렉토리_경로, 파일명] = util::디렉토리_파일_경로_분리(경로);
            util::파일명_변경(디렉토리_경로, 파일명, 압축파일명);
            util::압축_해제(디렉토리_경로, 압축파일명);
        }
    }

    chdir(원래_경로.c_str());
}

GraderApp::GraderApp(const string &채점파일명) : 출력_스트림(채점파일명, ios::app) {}
GraderApp::~GraderApp() {
    출력_스트림.close();
}

void GraderApp::실행() {
    util::아스키_아트_출력();
    vector<string> 소스코드들;
    string 루트_디렉토리 = fs::current_path().string();
    string 현재_디렉토리;
    string 디렉토리명;
    string 현재_학생;
    string 인수;

    압축_해제("codes.zip");
    auto 문제들 = util::컨픽_읽기();
    CppCompiler 컴파일러(출력_스트림, 루트_디렉토리);

    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory()) {
            if (!소스코드들.empty()) {
                컴파일러.컴파일(현재_디렉토리,
                                현재_학생,
                                소스코드들,
                                문제들);
                소스코드들.clear();
            }

            현재_디렉토리 = 엔트리.path().string();
            디렉토리명 = 엔트리.path().filename().string();
            if (디렉토리명.find('_') != string::npos && 디렉토리명 != "__MACOSX") {
                출력_스트림 << endl << '[' << 디렉토리명 << ']' << endl;
                현재_학생 = 디렉토리명;
            }
        } else {
            string 파일명 = 엔트리.path().filename().string();
            if (util::소스코드_존재(파일명) && 현재_디렉토리.find('_') != string::npos && 현재_디렉토리 != "__MACOSX") {
                소스코드들.push_back(파일명);
            }
        }
    }

    if (!소스코드들.empty() && 현재_학생.find('_') != string::npos) {
        컴파일러.컴파일(현재_디렉토리,
                        현재_학생,
                        소스코드들,
                        문제들);
        소스코드들.clear();
    }

    system("pause");
}
