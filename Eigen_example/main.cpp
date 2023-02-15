#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
    Matrix3d mat3d_1, mat3d_2, matIdentity, matZero;
    mat3d_1 << 123, 321, 456, 654, 789, 987, 135, 531, 999;
    std::cout << "3x3 matrix Initialization(mat3d)" << std::endl
              << mat3d_1 << std::endl
              << std::endl;

    matIdentity = Matrix3d::Identity();
    std::cout << "3x3 Identity matrix" << std::endl
              << matIdentity << std::endl
              << std::endl;

    matZero = Matrix3d::Zero();
    std::cout << "3x3 Zero matrix " << std::endl
              << matZero << std::endl
              << std::endl;

    mat3d_2 = mat3d_1 + matIdentity;
    std::cout << "mat3d와 단위행렬의 합" << std::endl
              << mat3d_2 << std::endl
              << std::endl;

    mat3d_2 = mat3d_1 * matIdentity;
    std::cout << "mat3d와 단위행렬의 곱" << std::endl
              << mat3d_2 << std::endl
              << std::endl;

    mat3d_2 = mat3d_1.transpose();
    std::cout << "mat3d의 transpose" << std::endl
              << mat3d_2 << std::endl
              << std::endl;

    mat3d_2 = mat3d_1.inverse();
    std::cout << "mat3d의 inverse" << std::endl
              << mat3d_2 << std::endl;
}