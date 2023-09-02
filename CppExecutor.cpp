#include "CppExecutor.h"

void CppExecutor::실행(const string& 테스트케이스_경로) {
    string 명령어 = ".\\output < " + 테스트케이스_경로;
    system(명령어.c_str());
}