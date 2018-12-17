//

#include "Matrix3D.h"
Matrix3D::Matrix3D() : Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0){
}

Matrix3D::Matrix3D(double number) : Matrix3D(number, 0, 0, 0, number, 0, 0, 0, number) {
}


Matrix3D::Matrix3D(double num1, double num2, double num3, double num4, double num5, double num6, double num7,
                   double num8, double num9) {
    this->elements[0] = new Vector3D(num1, num2, num3);
    this->elements[1] = new Vector3D(num4, num5, num6);
    this->elements[2] = new Vector3D(num7, num8, num9);
}
//
////
Matrix3D::Matrix3D(double *listNumbers) : Matrix3D(listNumbers[0], listNumbers[1], listNumbers[2], listNumbers[3],
                                                   listNumbers[4], listNumbers[5], listNumbers[6], listNumbers[7],
                                                   listNumbers[8]) {
}


Matrix3D::Matrix3D(double **matrixNumbers)  : Matrix3D(matrixNumbers[0][0], matrixNumbers[0][1], matrixNumbers[0][2],
                                                       matrixNumbers[1][0], matrixNumbers[1][1], matrixNumbers[1][2],
                                                       matrixNumbers[2][0], matrixNumbers[2][1], matrixNumbers[2][2]){
}

Matrix3D::Matrix3D(Vector3D vector1, Vector3D vector2, Vector3D vector3) {
    this->elements[0] = new Vector3D(vector1);
    this->elements[1] = new Vector3D(vector2);
    this->elements[2] = new Vector3D(vector3);
}

Matrix3D::Matrix3D(const Matrix3D &matrix3D) {
    this->elements[0] = new Vector3D(matrix3D[0]);
    this->elements[1] = new Vector3D(matrix3D[1]);
    this->elements[2] = new Vector3D(matrix3D[2]);
}


Vector3D *const* Matrix3D::getElements() const {
    return this->elements;
}

Matrix3D operator+(const Matrix3D &matrix3D, const Matrix3D &matrix3D1) {
    Vector3D v1 = Vector3D(matrix3D[0] + matrix3D1[0]);
    Vector3D v2 = Vector3D(matrix3D[1] + matrix3D1[1]);
    Vector3D v3 = Vector3D(matrix3D[2] + matrix3D1[2]);
    return Matrix3D(v1, v2, v3);
}

Matrix3D operator-(const Matrix3D &matrix3D, const Matrix3D &matrix3D1) {
    Vector3D v1 = Vector3D(matrix3D[0] - matrix3D1[0]);
    Vector3D v2 = Vector3D(matrix3D[1] - matrix3D1[1]);
    Vector3D v3 = Vector3D(matrix3D[2] - matrix3D1[2]);
    return Matrix3D(v1, v2, v3);
}

Vector3D operator*(const Matrix3D &matrix3D, Vector3D vector3D) {
    return Vector3D(matrix3D[0] * vector3D, matrix3D[1] * vector3D,
            matrix3D[2] * vector3D);
}

Matrix3D &Matrix3D::operator=(const Matrix3D &matrix3D) {
    return *this;
}

Matrix3D Matrix3D::operator+=(const Matrix3D &matrix3d) {
    Matrix3D m1 = Matrix3D((*this) + matrix3d);
    delete elements[0];
    delete elements[1];
    delete elements[2];
    elements[0] = new Vector3D(m1[0]);
    elements[1] = new Vector3D(m1[1]);
    elements[2] = new Vector3D(m1[2]);
    return *this;
}

Matrix3D Matrix3D::operator-=(const Matrix3D &matrix3d) {
    Matrix3D m1 = Matrix3D((*this) - matrix3d);
    delete elements[0];
    delete elements[1];
    delete elements[2];
    elements[0] = new Vector3D(m1[0]);
    elements[1] = new Vector3D(m1[1]);
    elements[2] = new Vector3D(m1[2]);
    return *this;
}
//
Matrix3D Matrix3D::operator*=(const Matrix3D &matrix3d) {
    Matrix3D m = Matrix3D(matrix3d * (*this)[0], matrix3d * (*this)[1], matrix3d * (*this)[2]);
    delete elements[0];
    delete elements[1];
    delete elements[2];
    elements[0] = new Vector3D(m[0]);
    elements[1] = new Vector3D(m[1]);
    elements[2] = new Vector3D(m[2]);
    return *this;
}

Matrix3D Matrix3D::operator*=(double num) {
    Vector3D v1 = Vector3D(*(elements[0]) * num);
    Vector3D v2 = Vector3D(*(elements[1]) * num);
    Vector3D v3 = Vector3D(*(elements[2]) * num);
    delete elements[0];
    delete elements[1];
    delete elements[2];
    elements[0] = new Vector3D(v1);
    elements[1] = new Vector3D(v2);
    elements[2] = new Vector3D(v3);
    return *this;
}

Matrix3D Matrix3D::operator/=(double num) {
    Vector3D v1 = Vector3D(*(elements[0]) / num);
    Vector3D v2 = Vector3D(*(elements[1]) / num);
    Vector3D v3 = Vector3D(*(elements[2]) / num);
    delete elements[0];
    delete elements[1];
    delete elements[2];
    elements[0] = new Vector3D(v1);
    elements[1] = new Vector3D(v2);
    elements[2] = new Vector3D(v3);
    return *this;
}

std::istream &operator>>(std::istream &input, Matrix3D &matrix3D) {
    input >> matrix3D[0] >> matrix3D[1] >> matrix3D[2];
    return input;
}

std::ostream &operator<<(std::ostream &os, Matrix3D matrix3D) {
    os << matrix3D[0] << "\n"<< matrix3D[1] <<
       "\n" << matrix3D[2];
    return os;
}



Vector3D& Matrix3D::operator[](int index) {
    return *(elements[index]);
}

Vector3D Matrix3D::operator[](int index) const {
    return *(elements[index]);
}

Vector3D Matrix3D::row(short index) {
    return Vector3D((*this)[index]);
}

Vector3D Matrix3D::column(short index) const {
    return Vector3D((*this)[0][index], (*this)[1][index], (*this)[2][index]);
}

double Matrix3D::trace() {
    return (*elements[0])[0] + (*elements[1])[1] + (*elements[2])[2];
}

double Matrix3D::determinant() {
    return (*this)[0][0] * ((*this)[1][1]*(*this)[2][2] - (*this)[1][2]*(*this)[2][1])
    - (*this)[0][1] * ((*this)[1][0]*(*this)[2][2] - (*this)[1][2]*(*this)[2][0])
            +(*this)[0][2] * ((*this)[1][0]*(*this)[2][1] - (*this)[1][1]*(*this)[2][0]);
}



