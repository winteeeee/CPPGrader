#include "CppExecutor.h"

CppExecutor::CppExecutor() : 채점기("채점결과.txt") {}

void CppExecutor::실행(const string& 입력파일_경로, const string& 학생_정보, const vector<string>& 소스코드들) {
    cout << 학생_정보 << "의 ";
    for (const string& 소스코드 : 소스코드들) {
        cout << 소스코드 << " ";
    }
    cout << 입력파일_경로 << endl;

    string 명령어 = ".\\output";
    if (입력파일_경로.find("수동") == string::npos) {
        명령어 += (" < " + 입력파일_경로);
        system(명령어.c_str());
    } else {
        system(명령어.c_str());
    }
    채점기.채점(소스코드들);
}

void CppExecutor::출력_스트림_쓰기(const string &학생_정보) {
    채점기.출력_스트림_쓰기(학생_정보);
}