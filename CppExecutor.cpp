#include "CppExecutor.h"

CppExecutor::CppExecutor(ofstream &출력_스트림) : 채점기(출력_스트림) {}

void CppExecutor::실행(const string &입력파일_경로,
                       const string &정답파일_경로,
                       const string &디렉토리_경로,
                       const string &출력파일명,
                       const vector<string> &소스코드들) {
    cout << endl << "=======================================================================================" << endl;
    cout << "실행 디렉토리 : " << 디렉토리_경로 << endl << "소스코드 : ";
    for (const string& 소스코드 : 소스코드들) {
        cout << 소스코드 << " ";
    }
    cout << endl << "테스트케이스 : " << 입력파일_경로 << endl;

    string 명령어 = ".\\output";
    if (입력파일_경로.find("수동") == string::npos) {
        명령어 += (" < " + ("\"" + 입력파일_경로 + "\"") + " > " + 출력파일명);
        system(명령어.c_str());
    } else {
        system(명령어.c_str());
    }
    cout << "=======================================================================================" << endl;
    채점기.채점(소스코드들, 정답파일_경로, 출력파일명);
}

