#include <iostream>
#include <memory>
#include <vector>

class A
{
    int* data;

    public:
    A() {
        std::cout << "자원 획득!" << std::endl;
        data = new int[100];
    }

    void something() { std::cout << "일반 포인터와 동일하게 사용!" << std::endl;}


    void do_sth(int a) {
        std::cout << "do Something" << std::endl;
        data[0] = a;
    }

    ~A() {
        std::cout << "자원 해제!" << std::endl;
        delete[] data;
    }
};

void do_something(A* pa) {pa->do_sth(3);}

int main()
{
    std::unique_ptr<A> pa(new A());
    std::cout << "pa.get() : " << pa.get() << std::endl;                                          // unique_ptr의 get()은 주소를 가져오는 메서드
    do_something(pa.get());


    auto pb = std::make_unique<A>();
    std::cout << "make_unique를 이용한 unique_ptr 생성 pb.get() : " << pb.get() << std::endl;        // make_unique는 unique_ptr을 생성함과 동시에 클래스에 대한 생성자를 바로 사용할 수 있게 만들어줌

    std::vector<std::unique_ptr<A>> vec;
    auto pc = std::make_unique<A>();
    // vec.push_back(pc);                                                                         // unique_ptr에는 복사 생성자가 없기 때문에 컴파일 에러 발생
    vec.push_back(std::move(pc));                                                                 // push_back으로 진행 시 std::move를 이용해 소유권 이전
    vec.emplace_back(new A());                                                                    // emplace_back()을 사용하면 생성자를 그대로 넣기 때문에 vector에 넣을 수 있음

}