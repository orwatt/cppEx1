//
// Created by hp on 08/12/2018.
//

#ifndef CPPTEST_MATRIX3D_H
#define CPPTEST_MATRIX3D_H
#define MATRIX_ELEM_NUM 3

#include <iostream>
#include <math.h>
#include "Vector3D.h"


class Matrix3D {
    public:
    Matrix3D();
    Matrix3D(double number);
    Matrix3D(double num1, double num2, double num3, double num4, double num5, double num6, double num7, double num8,
             double num9);
    Matrix3D(double *listNumbers);
    Matrix3D(double **matrixNumbers);
    Matrix3D(Vector3D vector1, Vector3D vector2, Vector3D vector3);
    Matrix3D(const Matrix3D &matrix3D);
    const Vector3D* getElements() const ;


    friend Matrix3D operator+(const Matrix3D& matrix3D, const Matrix3D& matrix3D1);
    friend Matrix3D operator-(const Matrix3D& matrix3D, const Matrix3D& matrix3D1);
    friend Matrix3D operator*(const Matrix3D& matrix3D, Vector3D vector3D);

    friend std::istream& operator>>(std::istream& input, Matrix3D &matrix3D);
    friend std::ostream& operator<<(std::ostream& os, Matrix3D matrix3D);

    Matrix3D& operator=(const Matrix3D& matrix3D);
    Matrix3D operator+=(const Matrix3D& matrix3d);
    Matrix3D operator-=(const Matrix3D& matrix3d);
    Matrix3D operator*=(const Matrix3D& matrix3d);
    Matrix3D operator*=(double num);
    Matrix3D operator/=(double num);

    Vector3D& operator[]( int index);
    Vector3D operator[]( int index) const;

    Vector3D row(short index);
    Vector3D column(short index);
    double trace();
    double determinant();

    private:
        Vector3D elements[MATRIX_ELEM_NUM];
};


#endif //CPPTEST_MATRIX3D_H
