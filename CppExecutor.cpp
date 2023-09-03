#include "CppExecutor.h"

CppExecutor::CppExecutor() : 채점기("채점결과.txt") {}

void CppExecutor::실행(const string& 입력파일_경로, const string& 학생_정보, const string& 소스코드) {
    cout << 학생_정보 << "의 " << 소스코드 << endl;
    string 명령어 = ".\\output < " + 입력파일_경로;
    system(명령어.c_str());
    채점기.채점(소스코드);
    //TODO 입력파일 경로가 vector로 들어가야함. (여러 입력 파일이 들어올 수 있음)
}

void CppExecutor::출력_스트림_쓰기(const string &학생_정보) {
    채점기.출력_스트림_쓰기(학생_정보);
}