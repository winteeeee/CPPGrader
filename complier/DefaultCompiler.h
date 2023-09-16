#pragma once

#include "CppCompiler.h"

class DefaultCompiler : public CppCompiler {
private:
    int 테케_인덱스_찾기(const std::string &디렉토리_경로,
                         const std::vector<TestCase> &테스트케이스들) const;

public:
    DefaultCompiler(std::ofstream& 출력_스트림);
    void 컴파일(const std::string &디렉토리_경로,
                const std::string &학생_정보,
                const std::vector<std::string> &소스코드들,
                const std::vector<TestCase> &테스트케이스들) const;
};

