#include "CppExecutor.h"

CppExecutor::CppExecutor() : 채점기() {}

void CppExecutor::실행(const string& 입력파일_경로, const string& 정답파일_경로) {
    cout << "실행 중..." << endl;
    string 명령어 = ".\\output < " + 입력파일_경로 + " > " + "output.out";
    system(명령어.c_str());
    채점기.채점(정답파일_경로);
}