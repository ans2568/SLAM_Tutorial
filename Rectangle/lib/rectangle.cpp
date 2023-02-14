#include "rectangle.hpp"

using namespace std;

Rectangle::Rectangle(int width, int height) : width_(width), height_(height)
{
    cout << "생성자 생성" << endl;
    cout << "width : " + to_string(width) << endl;
    cout << "height : " + to_string(height) << endl;
}

int Rectangle::getSize() const
{
    return width_ * height_;
}