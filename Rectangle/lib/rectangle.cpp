#include "rectangle.hpp"

using namespace std;

Rectangle::Rectangle(int width, int height) : width_(width), height_(height)
{
    cout << "width : " + width << endl
         << "height : " + height << endl;
}

int Rectangle::getSize() const
{
    return width_ * height_;
}