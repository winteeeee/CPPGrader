#pragma once

#include <vector>
#include <string>

class Problem {
private:
    std::string 문제;
    int 테스트케이스_개수;
    std::vector<std::string> 입력파일들;
    std::vector<std::string> 정답파일들;
    std::vector<std::string> 메인_경로들;
    std::vector<std::string> 명령행인수들;

public:
    Problem(const std::string 문제, int 테스트케이스_개수, const std::vector<std::string> 입력파일들, const std::vector<std::string> 정답파일들, const std::vector<std::string> 메인_경로들, const std::vector<std::string> 명령행인수들);
    const std::string &get문제() const;
    void set문제(const std::string &문제);
    const std::vector<std::string> &get입력파일들() const;
    void set입력파일들(const std::vector<std::string> &입력파일들);
    const std::vector<std::string> &get정답파일들() const;
    void set정답파일들(const std::vector<std::string> &정답파일들);
    const std::vector<std::string> &get명령행인수들() const;
    void set명령행인수들(const std::vector<std::string> &명령행인수들);
    int get테스트케이스_개수() const;
    void set테스트케이스_개수(int 테스트케이스_개수);
    const std::vector<std::string> &get메인_경로들() const;
    void set메인_경로들(const std::vector<std::string> &메인_경로들);
};