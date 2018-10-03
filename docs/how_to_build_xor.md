* Tizen Studio로 기본 환경 구성
  * Tizen Platform Project 생성
  * 소스파일 확장자를 cpp로 변경 후 xor 소스코드 copy & paste
* CMakeLists.txt 수정
  * FILE(GLOB SRCS src/*.c)를 FILE(GLOB SRCS src/*.cpp)로 변경
  * TARGET_LINK_LIBRARIES(Xor tensorflow-lite pthread dl) 추가
* Spec 파일 수정
  * BuildRequires: tensorflow-lite-devel 추가
* Build at Host
  * Ubuntu 16.04에서 빌드
  * gbs build --include-all -A armv7l
* Install xor package to target
  * host에서 빌드하여 생성한 package 파일을 target에 설치
  * mount -o rw,remount /
  * rpm -Uvh org.tizen.Xor-0.0.1-1.armv7l.rpm
     (conflict error 발생 시 --force 옵션 추가: rpm -Uvh org.tizen.Xor-0.0.1-1.armv7l.rpm --force)
* Test
  * xorGate.lite와 같은 경로에서 실행
  * test
    * ![test_xor](./fig/test_xor.png)