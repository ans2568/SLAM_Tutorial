#include <iostream>
#include <memory>
#include <vector>
#include <string>

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


int main()
{
    std::shared_ptr<A> p1(new A());
    std::shared_ptr<A> p2(p1);              //shared_ptr은 복사 생성자가 가능
    

    std::vector<std::shared_ptr<A>> vec;

    vec.push_back(p1);
    vec.push_back(vec[0]);
    vec.push_back(vec[1]);

    std::cout << "첫 번째 원소 소멸" << std::endl;
    vec.erase(vec.begin());


    std::cout << "두 번째 원소 소멸" << std::endl;
    vec.erase(vec.begin());

    std::cout << "세 번째 원소 소멸" << std::endl;
    vec.erase(vec.begin());

    std::cout << "프로그램 종료" << std::endl;
}