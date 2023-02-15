cmake_minimum_required(VERSION 3.16)        # cmake 최상단에 들어가는 문구로 cmake의 최소 버전을 입력
project(new_delete)                                # project 이름을 적는 칸으로 있는걸 추천

add_executable(new_delete new_delete.cpp)               # 실행할 이름을 가장 처음 매개변수에 입력 add_executable(이름.out {나머지 소스파일들})