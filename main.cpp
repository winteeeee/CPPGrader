#include "GraderApp.h"
#define 정수형 int
#define 메인 main
#define 자동 auto
#define 반환 return
#define 채점앱 GraderApp

정수형 메인() {
    자동 앱 = 채점앱("채점결과.txt");
    앱.실행();
    //TODO 명령행 인자로 입력 파일 넣는 기능 추가

    반환 0;
}
