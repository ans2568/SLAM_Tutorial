#pragma once

#include <string>
#include <iostream>
#include <opencv4/opencv2/core.hpp>

class Rectangle
{
    public:
    Rectangle(int width, int height);

    int getSize() const;

    private:
    int width_, height_;
};