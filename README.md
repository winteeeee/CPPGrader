# CPPGrader - C++ 프로그래밍 과제 채점기
## 0. 개발 환경
C++ 17, CLion 환경에서 개발하였음.

## 1. 사전 설정
1. MinGw의 g++을 컴파일러로 콘솔 환경에서 실행하므로 g++의 환경변수 설정이 되어 있어야 한다.
2. 콘솔에서 unzip 명령어를 사용하기 위해 C:\Windows\System32에 같이 배포되어 있는 unzip.exe 파일을 넣어둬야 한다.

## 2. 문제 세팅
압축을 푼 과제 파일 안에 폴더를 하나 만든다.

그 안에 문제별로 폴더를 다시 한 번 더 생성한 후 그 안에 입력파일과 정답파일을 만든다.

입력파일은 .in 확장자를 가져야하며 정답파일은 .out 확장자를 가져야한다. 명령행 인수를 이용하여 파일을 읽어들이는 프로그램의 경우 명령행 인수의 입력으로 사용할 파일의 확장자를 .argv로 지정하여 만들어 둔다.

**입력파일, 정답파일 (필요시) 명령행 인수 프로그램은 모두 같은 수만큼 존재하여야 한다.**

만일 (랜덤 함수와 같은 요소로) 정해진 입력이 들어오면 안되는 경우 입력파일의 파일명 안에 "console"을 포함해둔다.

그 후 ProblemConfig.ini 파일의 내용을 수정해둔다. 기본 구분자는 ,를 사용하고 있으며 구분자 앞 뒤로 공백이 들어가면 안된다.
메인이 필요한 경우 mainPath에 적어두되, 한 번 적었다면 반드시 입력파일 갯수만큼 적어둔다.

## 3. 채점
입력파일의 결과를 임시 파일로 출력한 뒤 정답 파일과 임사 파일의 내용을 windows 콘솔 명령어 fc를 이용하여 다른 점을 비교한다.

파일의 내용이 완벽히 동일한 경우 자동으로 정답 처리되고 다음으로 넘어간다.

정답 파일과 다른 점이 발견될 경우 fc 명령어에 의해 다른 점이 출력되고 채점 프롬프트가 출력된다.

| 옵션 | 설명                          |
|----|-----------------------------|
| y  | 정답으로 채점하고 넘어가기              |
| n  | 오답으로 채점하고 넘어가기              |
| h  | 감점으로 채점하고 넘어가기              |
| d  | 출력 전체 비교                    |
| c  | 코드 보기(.cpp, .h, .h++, .hpp) |
| ?  | 도움말 출력                      |

모든 파일에 대한 채점이 완료되면 result.txt에 채점 결과가 저장된다.
