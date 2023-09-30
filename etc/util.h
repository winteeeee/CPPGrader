#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <unistd.h>
#include <filesystem>

#include "Problem.h"

#define 방향키_위 72
#define 방향키_아래 80
#define 엔터 13

namespace fs = std::filesystem;

class util {
public:
    static std::string 큰따옴표_래핑(const std::string &경로);
    static bool 소스코드_존재(const std::string &파일);
    static int 키보드_제어_콘솔_출력(std::vector<std::string> &출력_문자열, int 옵션_시작_인덱스 = 1);
    static void 방향키_제어(int 입력, int 인덱스_최댓값, int &인덱스, bool &종료_플래그);
    static void 느리게_출력(const std::string &문자열, int 딜레이 = 10);
    static std::pair<std::string, std::string> 디렉토리_파일_경로_분리(const std::string &절대_경로);
    static void 압축_해제(const std::string &디렉토리_경로, const std::string &파일명);
    static void 아스키_아트_출력();
    static void 파일명_변경(const std::string &디렉토리_경로, const std::string &이전, const std::string &이후);
    static std::vector<Problem> 컨픽_읽기(char 구분자=',');
    static void 파일_복사(const std::string& 대상, const std::string& 목표);
};