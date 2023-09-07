#include "util.h"

string util::큰따옴표_래핑(const std::string &경로) {
    return ("\"" + 경로 + "\"");
}

bool util::소스코드_존재(const std::string &파일) {
    return 파일.find(".cpp") != string::npos || 파일.find(".h") != string::npos || 파일.find(".h++") != string::npos;
}

string util::슬래시_변환(const std::string &문자열) {
    string 결과;

    for (auto 문자: 문자열) {
        if (문자 == '\\') {
            문자 = '/';
        }

        결과.push_back(문자);
    }

    return 결과;
}