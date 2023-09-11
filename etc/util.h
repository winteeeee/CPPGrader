#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <unistd.h>
#define 방향키_위 72
#define 방향키_아래 80
#define 엔터 13
using namespace std;

class util {
public:
    static string 큰따옴표_래핑(const string &경로);
    static bool 소스코드_존재(const string &파일);
    static string 슬래시_변환(const string &문자열);
    static int 키보드_제어_콘솔_출력(vector<string> &출력_문자열, int 옵션_시작_인덱스 = 1);
    static void 방향키_제어(int 입력, int 인덱스_최댓값, int &인덱스, bool &종료_플래그);
    static void 느리게_출력(const string &문자열, int 딜레이 = 10);
    static pair<string, string> 디렉토리_파일_경로_분리(const string &절대_경로);
    static void 압축_해제(const string &디렉토리_경로, const string &파일명);
};