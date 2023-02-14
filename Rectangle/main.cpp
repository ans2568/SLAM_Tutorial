#include "rectangle.hpp"

using namespace cv;
using namespace std;

int main()
{
    int width, weight;
    width = 100;
    weight = 150;
    auto rect = Rectangle(width, weight);
    auto size = rect.getSize();

    cout << "size : " + size << endl;
}
