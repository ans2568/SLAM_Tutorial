#include <iostream>

typedef int* ip;

int main()
{
    ip a = new int;
    ip b = a;

    delete a;   // a의 정보가 삭제

    delete b;   // a의 정보가 삭제되었는데 또 삭제하려고 시도함으로써 에러 발생
}