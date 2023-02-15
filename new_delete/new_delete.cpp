#include <iostream>

using namespace std;

int main()
{
    int* p = new int;       // new로 동적메모리를 힙에 생성
    *p = 100;
    cout << *p << endl;

    delete p;               // delete로 동적메모리를 힙에서 제거
}