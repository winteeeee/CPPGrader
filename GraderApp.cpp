#include "GraderApp.h"

std::vector<TestCase> GraderApp::테스트케이스_로드() const {
    std::string 원래_경로 = fs::current_path().string();
    std::vector<TestCase> 테스트케이스들;

    std::vector<std::string> 입력파일;
    std::vector<std::string> 정답파일;
    std::vector<std::string> 명령행인수;
    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory() && !입력파일.empty()) {
            테스트케이스들.emplace_back(입력파일, 정답파일, 명령행인수);
            입력파일.clear();
            정답파일.clear();
            명령행인수.clear();
        }

        std::string 경로 = 엔트리.path().string();
        if (경로.find(".in") != std::string::npos) {
            입력파일.push_back(경로);
        } else if (경로.find(".out") != std::string::npos) {
            정답파일.push_back(경로);
        } else if (경로.find(".argv") != std::string::npos) {
            명령행인수.push_back(경로);
        }
    }

    if (!입력파일.empty()) {
        테스트케이스들.emplace_back(입력파일, 정답파일, 명령행인수);
    }

    chdir(원래_경로.c_str());
    return 테스트케이스들;
}

void GraderApp::메인_복사() const {
    std::string 메인_이름;
    std::string 목표_폴더;

    while (메인_이름 != "1" && 목표_폴더 != "1") {
        std::cout << "Please enter the name of the main file to copy (enter 1 for exit) : ";
        std::cin.ignore();
        getline(std::cin, 메인_이름);
        std::cout << "Please enter the path of the target folder (enter 1 for exit) : ";
        std::cin >> 목표_폴더;

        if (메인_이름 != "1" && 목표_폴더 != "1") {
            fs::path 디렉토리_경로;

            for (const auto &엔트리: fs::recursive_directory_iterator(fs::current_path())) {
                if (엔트리.is_directory()) {
                    디렉토리_경로 = 엔트리.path();
                } else {
                    std::string 파일 = 엔트리.path().filename().string();
                    if (util::소스코드_존재(파일) && 디렉토리_경로.filename().string() == 목표_폴더) {
                        CopyFile(메인_이름.c_str(), (디렉토리_경로.string() + "/" + 메인_이름).c_str(), false);
                    }
                }
            }
        }
    }
}

void GraderApp::아스키_아트_출력() const {
    std::cout << " _____                 _____                   _              _ " << std::endl;
    std::cout << "/  __ \\   _      _    |  __ \\                 | |            | |" << std::endl;
    std::cout << "| /  \\/ _| |_  _| |_  | |  \\/ _ __   __ _   __| |  ___  _ __ | |" << std::endl;
    std::cout << "| |    |_   _||_   _| | | __ | '__| / _` | / _` | / _ \\| '__|| |" << std::endl;
    std::cout << "| \\__/\\  |_|    |_|   | |_\\ \\| |   | (_| || (_| ||  __/| |   |_|" << std::endl;
    std::cout << " \\____/                \\____/|_|    \\__,_| \\__,_| \\___||_|   (_)" << std::endl;
}

int GraderApp::컴파일_옵션_선택() const {
    std::vector<std::string> 출력_문자열 = {"Select compilation options",
                                  "1. Default",
                                  "2. Compile each"};

    return util::키보드_제어_콘솔_출력(출력_문자열, 1);
}

int GraderApp::메인_옵션_선택() const {
    std::vector<std::string> 출력_문자열 = {"Do you want to copy the main?",
                             "1. No",
                             "2. Yes"};

    return util::키보드_제어_콘솔_출력(출력_문자열, 1);
}

void GraderApp::압축_해제() const {
    std::string 원래_경로 = fs::current_path().string();

    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        const auto &경로 = 엔트리.path().string();
        if (경로.find(".zip") != std::string::npos) {
            auto [디렉토리_경로, 파일명] = util::디렉토리_파일_경로_분리(경로);
            util::압축_해제(디렉토리_경로, 파일명);
        }
    }

    chdir(원래_경로.c_str());
}

GraderApp::GraderApp(const std::string &채점파일명) : 출력_스트림(채점파일명) {}
GraderApp::~GraderApp() {
    출력_스트림.close();
}

void GraderApp::실행() {
    아스키_아트_출력();
    std::cout << "\n=======================================================================================\n";
    int 컴파일_옵션 = 컴파일_옵션_선택();
    std::cout << "=======================================================================================\n";
    int 메인_옵션 = 메인_옵션_선택();
    std::cout << "=======================================================================================\n";
    if (메인_옵션 == 1) {
        메인_복사();
    }

    std::vector<std::string> 소스코드들;
    unsigned long long 인덱스 = 0;
    std::string 현재_디렉토리;
    std::string 현재_학생;
    std::string 인수;

    압축_해제();
    auto 테스트케이스들 = 테스트케이스_로드();
    auto 컴파일러 = CppCompiler(출력_스트림);

    출력_스트림 << "===================================";
    for (const auto &엔트리 : fs::recursive_directory_iterator(fs::current_path())) {
        if (엔트리.is_directory()) {
            if (!소스코드들.empty()) {
                컴파일러.컴파일(현재_디렉토리,
                                현재_학생,
                                소스코드들,
                                테스트케이스들,
                                컴파일_옵션,
                                인덱스);
                소스코드들.clear();
                인덱스 = (인덱스 + 1) % 테스트케이스들.size();
            }

            현재_디렉토리 = 엔트리.path().string();
            std::string 디렉토리명 = 엔트리.path().filename().string();

            if (디렉토리명.find('_') != std::string::npos) {
                출력_스트림 << std::endl << '[' << 디렉토리명 << ']' << std::endl;
                현재_학생 = 디렉토리명;
                인덱스 = 0;
            }
        } else {
            std::string 파일명 = 엔트리.path().filename().string();
            if (util::소스코드_존재(파일명)) {
                소스코드들.push_back(util::큰따옴표_래핑(파일명));
            }
        }
    }

    if (!소스코드들.empty()) {
        컴파일러.컴파일(현재_디렉토리,
                        현재_학생,
                        소스코드들,
                        테스트케이스들,
                        컴파일_옵션,
                        인덱스);
        소스코드들.clear();
    }
    출력_스트림 << std::endl << "===================================";
    system("pause");
}
