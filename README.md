# Log File Manager (C++)

본 프로젝트는 C++17 기반으로 스마트 포인터를 활용하여
여러 개의 로그 파일을 안전하게 관리하는 Log File Manager를 구현

RAII(Resource Acquisition Is Initialization) 원칙을 기반으로
파일 리소스를 자동 관리하며, 예외 처리를 통해 안정적인 로그 기록을 작성

## 개발 및 실행 환경

- 운영체제: Windows 10 / Windows 11
- 개발 도구: Visual Studio Code
- 컴파일러: g++ (MinGW-w64)
- C++ 표준: C++17

## 설치 및 실행 방법

### 1. 컴파일러 설치
- MinGW-w64 설치
- 설치 후 `bin` 디렉터리를 시스템 PATH에 추가

### 2. 컴파일
```bash
g++ LogFileManager.cpp main.cpp -std=c++17
```
### 3. 실행
```
a.exe
```

## 설계 및 구현 설명
- LogFileManager 클래스는 여러 로그 파일을 동시에 관리한다.
- 파일 스트림은 `std::unique_ptr<std::ofstream>`을 사용하여 관리한다.
- `std::map`을 이용하여 파일 이름과 파일 스트림을 매핑한다.
- 예외 발생 시 `std::runtime_error`를 사용하여 오류를 명확히 전달한다.
### 스마트 포인터 사용 이유
- unique_ptr을 사용하여 파일 스트림의 단일 소유권을 보장
- 파일 닫힘 및 메모리 해제를 자동으로 처리
- 리소스 누수 및 중복 해제 방지
### 예외 안전성
- 파일 열기 실패 시 예외 발생
- 파일 쓰기 실패 시 예외 발생
- 잘못된 파일 접근을 사전에 차단
