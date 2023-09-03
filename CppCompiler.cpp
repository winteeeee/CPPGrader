#include "CppCompiler.h"

CppCompiler::CppCompiler(vector <string> &소스코드들, vector <string> &입력파일들)
: 소스코드들(소스코드들), 입력파일들(입력파일들), 실행기() {}

void CppCompiler::컴파일(const string &디렉토리_경로, const int &옵션) {
    cout << "현재 작업 디렉토리 : " << 디렉토리_경로 << endl;
    chdir(디렉토리_경로.c_str());
    실행기.출력_스트림_쓰기('[' + 디렉토리_경로 + ']');

    if (옵션 == CppCompiler::컴파일_옵션::일반) {
        for (const string& 입력파일_경로 : 입력파일들) {
            string 명령어 = "g++ ";
            for (const string &소스코드: 소스코드들) {
                명령어 += (소스코드 + " ");
            }
            명령어 += " -o output";

            cout << "컴파일 중..." << endl;
            cout << 명령어 << endl;
            int 컴파일_결과 = system(명령어.c_str());
            if (!컴파일_결과) {
                실행기.실행(입력파일_경로, 디렉토리_경로, 소스코드들);
            } else {
                cout << "컴파일 실패" << endl;
            }
        }
    } else if (옵션 == CppCompiler::컴파일_옵션::각각_컴파일) {
        for (int 인덱스 = 0; 인덱스 < 소스코드들.size(); 인덱스++) {
            const string& 소스코드 = 소스코드들[인덱스];
            const string& 입력파일_경로 = 입력파일들[인덱스];

            string 명령어 = "g++ " + 소스코드 + " -o output";
            cout << "컴파일 중..." << endl;
            int 컴파일_결과 = system(명령어.c_str());
            if (!컴파일_결과) {
                실행기.실행(입력파일_경로, 디렉토리_경로, 소스코드들);
            } else {
                cout << "컴파일 실패" << endl;
            }
        }
    }

    실행기.출력_스트림_쓰기("\n");
    소스코드들.clear();
}
