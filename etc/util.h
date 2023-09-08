#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#define 방향키_위 72
#define 방향키_아래 80
#define 엔터 13
using namespace std;

class util {
public:
    static string 큰따옴표_래핑(const string& 경로);
    static bool 소스코드_존재(const string& 파일);
    static string 슬래시_변환(const string& 문자열);
    //TODO 콘솔 출력()
    static void 방향키_제어(int 입력, int 인덱스_최댓값, int &인덱스, bool &종료_플래그);
    static void 느리게_출력(const string& 문자열, int 딜레이);
    //TODO 추후에 ostream& 타입으로 변경하여 cout에서 바로 적용가능하게하기
};