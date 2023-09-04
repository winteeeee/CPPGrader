#include "GraderApp.h"

int main() {
    auto 앱 = GraderApp("채점결과.txt");
    앱.실행();
    //TODO 정답 케이스와 비교 후 다를 경우에만 출력하도록 변경
    //TODO 메인 지정 기능 추가

    return 0;
}