#pragma once
#include <string>
using namespace std;

class util {
public:
    static string 큰따옴표_래핑(const string& 경로);
    static bool 소스코드_존재(const string& 파일);
    static string 슬래시_변환(const string& 문자열);
};