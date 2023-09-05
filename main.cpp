#include "GraderApp.h"
#define 정수형 int
#define 메인 main
#define 자동 auto
#define 반환 return
#define 채점앱 GraderApp

정수형 메인() {
    자동 앱 = 채점앱("채점결과.txt");
    앱.실행();
    //TODO 임시 파일들 삭제하도록 수정
    //TODO 코드 출력 시 .h과 .hpp 파일도 같이 출력할 수 있도록 수정
    //TODO 메인 파일 지정 기능 추가

    반환 0;
}
