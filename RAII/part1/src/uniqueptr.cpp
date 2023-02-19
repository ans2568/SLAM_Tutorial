#include <iostream>
#include <memory>

class A
{
    int* data;

    public:
    A() {
        std::cout << "자원 획득!" << std::endl;
        data = new int[100];
    }

    void something() { std::cout << "일반 포인터와 동일하게 사용!" << std::endl;}

    ~A() {
        std::cout << "자원 해제!" << std::endl;
        delete[] data;
    }
};

void do_something() {
    std::unique_ptr<A> pa(new A());                 // pa라는 unique_ptr이 생성되고 do_something()이 끝날 때 자동으로 소멸자가 호출되면서 A에 대한 소멸자도 함께 호출
    std::cout << "pa : ";
    pa->something();

    // std::unique_ptr<A> pb = pa;                  // unique_ptr은 유일해야하기 때문에 복사생성자는 deprecated 된 함수라 사용 불가

    std::unique_ptr<A> pb = std::move(pa);          // std::move()를 이용해 소유권을 이전하는 것은 가능함
    std::cout << "pb : ";
    pb->something();

    std::cout << "pa : "<< pa.get() << std::endl;   // dangling pointer라고 부르며 소유권이 이전된 포인터를 가리킨다. pa.get()은 0으로 출력
}

int main()
{
    do_something();
}