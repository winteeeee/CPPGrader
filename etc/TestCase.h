#pragma once
#include <vector>
#include <string>

class TestCase {
private:
    std::vector<std::string> 입력파일들;
    std::vector<std::string> 정답파일들;
    std::vector<std::string> 명령행인수들;

public:
    TestCase(const std::vector<std::string> 입력파일들, const std::vector<std::string> 정답파일들, const std::vector<std::string> 명령행인수들);
    const std::vector<std::string> &get입력파일들() const;
    void set입력파일들(const std::vector<std::string> &입력파일들);
    const std::vector<std::string> &get정답파일들() const;
    void set정답파일들(const std::vector<std::string> &정답파일들);
    const std::vector<std::string> &get명령행인수들() const;
    void set명령행인수들(const std::vector<std::string> &명령행인수들);
};