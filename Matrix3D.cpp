//

#include "Matrix3D.h"
Matrix3D::Matrix3D() : Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0){
}

Matrix3D::Matrix3D(double number) : Matrix3D(number, 0, 0, 0, number, 0, 0, 0, number) {
}


Matrix3D::Matrix3D(double num1, double num2, double num3, double num4, double num5, double num6, double num7,
                   double num8, double num9) {
    this->elements[0] = Vector3D(num1, num2, num3);
    this->elements[0] = Vector3D(num4, num5, num6);
    this->elements[0] = Vector3D(num8, num8, num9);
}


Matrix3D::Matrix3D(double *listNumbers) : Matrix3D(listNumbers[0], listNumbers[1], listNumbers[2], listNumbers[3],
                                                   listNumbers[4], listNumbers[5], listNumbers[6], listNumbers[7],
                                                   listNumbers[8]) {
}


Matrix3D::Matrix3D(double **matrixNumbers)  : Matrix3D(matrixNumbers[0][0], matrixNumbers[0][1], matrixNumbers[0][2],
                                                       matrixNumbers[1][0], matrixNumbers[1][1], matrixNumbers[1][2],
                                                       matrixNumbers[2][0], matrixNumbers[2][1], matrixNumbers[2][2]){
}

Matrix3D::Matrix3D(Vector3D vector1, Vector3D vector2, Vector3D vector3) {
    this->elements[0] = Vector3D(vector1);
    this->elements[1] = Vector3D(vector2);
    this->elements[2] = Vector3D(vector3);
}

Matrix3D::Matrix3D(const Matrix3D &matrix3D) {
    this->elements[0] = Vector3D(matrix3D[0]);
    this->elements[0] = Vector3D(matrix3D[1]);
    this->elements[0] = Vector3D(matrix3D[2]);
}


const Vector3D *Matrix3D::getElements() const {
    return this->elements;
}

Matrix3D operator+(const Matrix3D &matrix3D, const Matrix3D &matrix3D1) {
    return Matrix3D();
}

Matrix3D operator-(const Matrix3D &matrix3D, const Matrix3D &matrix3D1) {
    return Matrix3D();
}

Matrix3D operator*(const Matrix3D &matrix3D, Vector3D vector3D) {
    return Matrix3D();
}

Matrix3D &Matrix3D::operator=(const Matrix3D &matrix3D) {
    return nullptr;
}

Matrix3D Matrix3D::operator+=(const Matrix3D &matrix3d) {
    return Matrix3D();
}

Matrix3D Matrix3D::operator-=(const Matrix3D &matrix3d) {
    return Matrix3D();
}

Matrix3D Matrix3D::operator*=(const Matrix3D &matrix3d) {
    return Matrix3D();
}

Matrix3D Matrix3D::operator*=(double num) {
    return Matrix3D();
}

Matrix3D Matrix3D::operator/=(double num) {
    return Matrix3D();
}

std::istream &operator>>(std::istream &input, Matrix3D &matrix3D) {
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream &os, Matrix3D matrix3D) {
    return <#initializer#>;
}

Vector3D &Matrix3D::operator[](int index) {
    return <#initializer#>;
}

Vector3D Matrix3D::operator[](int index) const {
    return Vector3D();
}

Vector3D Matrix3D::row(short index) {
    return Vector3D();
}

Vector3D Matrix3D::column(short index) {
    return Vector3D();
}

double Matrix3D::trace() {
    return 0;
}

double Matrix3D::determinant() {
    return 0;
}
