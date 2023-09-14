#include "EachCompiler.h"
using namespace std;

int EachCompiler::테케_인덱스_찾기(const vector<string> &소스코드들, const vector<TestCase> &테스트케이스들) const {
    for (int i = 0; i < 테스트케이스들.size(); i++) {
        if (소스코드들[0].find(테스트케이스들[i].get문제()) != string::npos) {
            return i;
        }
    }
    
    return -1;
}

EachCompiler::EachCompiler(ofstream &출력_스트림) : CppCompiler(출력_스트림) {}

void EachCompiler::컴파일(const string &디렉토리_경로, const string &학생_정보, const vector<string> &소스코드들,
                       const vector<TestCase> &테스트케이스들) const {
    string 임시_파일명 = "output.txt";
    string 명령어;


    util::느리게_출력("\n[Target Student : " + 학생_정보 + "]\n");
    chdir(디렉토리_경로.c_str());

    for (const auto &소스코드 : 소스코드들) {
        vector<string> 임시_벡터 = {소스코드};
        if (소스코드.find(".cpp") != string::npos) {
            명령어 = "g++ " + 소스코드 + " -o output";
        }

        auto 인덱스 = 테케_인덱스_찾기(임시_벡터, 테스트케이스들);
        if (인덱스 != -1) {
            출력_스트림 << 테스트케이스들[인덱스].get문제() << " : ";
            실행기_작동(디렉토리_경로, 임시_파일명, 명령어, 테스트케이스들[인덱스], 임시_벡터);
            출력_스트림 << endl;
        }
    }
}