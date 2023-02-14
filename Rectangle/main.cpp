#include "rectangle.hpp"

using namespace cv; // 추후 사용을 위해 남겨둠
using namespace std;

int main()
{
    int width, height;
    width = 100;
    height = 150;
    auto rect = Rectangle(width, height);
    auto size = rect.getSize();

    cout << "size : " + to_string(size) << endl;
}
