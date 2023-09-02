#include "CppCompiler.h"

CppCompiler::CppCompiler(vector <string> &소스코드들, vector <string> &입력파일들, vector<string> &정답파일들)
: 소스코드들(소스코드들), 입력파일들(입력파일들), 정답파일들(정답파일들), 실행기() {}

void CppCompiler::컴파일(const string &디렉토리_경로, const int &옵션) {
    cout << "현재 작업 디렉토리 : " << 디렉토리_경로 << endl;
    cout << "컴파일 중..." << endl;
    chdir(디렉토리_경로.c_str());
    if (옵션 == CppCompiler::컴파일_옵션::일반) {
//        string 명령어 = "g++ ";
//        for (const string &소스코드: 소스코드들) {
//            명령어 += (소스코드 + " ");
//        }
//        명령어 += " -o output";
//        cout << 디렉토리_경로 << " : " << 명령어 << endl;
//
//        int 컴파일_결과 = system(명령어.c_str());
//        if (!컴파일_결과) {
//            실행기.실행("임시");
//        } else {
//            cout << "컴파일 실패" << endl;
//        }
    } else if (옵션 == CppCompiler::컴파일_옵션::각각컴파일) {
        for (int 인덱스 = 0; 인덱스 < 소스코드들.size(); 인덱스++) {
            const string& 소스코드 = 소스코드들[인덱스];
            const string& 입력파일_경로 = 입력파일들[인덱스];
            const string& 정답파일_경로 = 정답파일들[인덱스];

            string 명령어 = "g++ " + 소스코드 + " -o output";
            int 컴파일_결과 = system(명령어.c_str());
            if (!컴파일_결과) {
                실행기.실행(입력파일_경로, 정답파일_경로);
            } else {
                cout << "컴파일 실패" << endl;
            }
        }
    }

    소스코드들.clear();
}
