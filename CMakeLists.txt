cmake_minimum_required(VERSION 3.16)        # cmake 최상단에 들어가는 문구로 cmake의 최소 버전을 입력
project(app)                                # project 이름을 적는 칸으로 있는걸 추천

find_package(OpenCV REQUIRED)               # OpenCV 라이브러리를 자동으로 찾아주는 함수로 REQUIRED를 붙임으로써 없을 경우 빌드 안됨

if(OpenCV_FOUND)
    message("OpenCV를 찾았습니다!")
else()
    message("OpenCV가 없네요!")
endif()

add_executable(app hello.cpp)               # 실행할 이름을 가장 처음 매개변수에 입력 add_executable(이름.out {나머지 소스파일들})
target_link_libraries(app ${OpenCV_LIBS})   # find_package()로 찾은 라이브러리를 링크해주는 명령어로 실행 파일 이름이 가장 처음에 들어간 후 링크가 필요한 라이브러리들을 넣는다.