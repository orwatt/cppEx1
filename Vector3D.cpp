//
// Created by hp on 07/12/2018.
//

#include "Vector3D.h"

Vector3D::Vector3D() : Vector3D(0, 0, 0){
    /*
     *
     */
}

Vector3D::Vector3D(double x, double y, double z) {
    /*
     *
     */
    _elements[0] = x;
    _elements[1] = y;
    _elements[2] = z;
}

Vector3D::Vector3D(double data[VECTOR_ELEM_NUM]) : Vector3D(data[0], data[1], data[2]) {
    /*
     *
     */
}

Vector3D::Vector3D(const Vector3D &vector3d) : Vector3D(vector3d.getElements()[0], vector3d.getElements()[1],
        vector3d.getElements()[2]){
    /*
     *
     */
}

const double* Vector3D::getElements() const {
    /*
     *
     */
    return _elements;
}



Vector3D::~Vector3D() {
    /*
     *
     */
}

void Vector3D::setElements(double x, double y, double z) {
    /*
     *
     */
    _elements[0] = x;
    _elements[1] = y;
    _elements[2] = z;
}

Vector3D operator+(const Vector3D& vector13D, const Vector3D& vector23D) {
    /*
     *
     */
    double firstElem = vector13D[0] + vector23D[0];
    double secondElem = vector13D[1] + vector23D[1];
    double thirdElem = vector13D[2] + vector23D[2];
    return Vector3D(firstElem, secondElem, thirdElem);
}

Vector3D operator-(const Vector3D& vector13D, const Vector3D& vector23D) {
    /*
     *
     */
    double firstElem = vector13D[0] - vector23D[0];
    double secondElem = vector13D[1] - vector23D[1];
    double thirdElem = vector13D[2] - vector23D[2];
    return Vector3D(firstElem, secondElem, thirdElem);
}


double Vector3D::dist(const Vector3D &vector3D) const {
    return sqrt((pow(_elements[0] - vector3D[0], 2) + pow(_elements[1] -
    vector3D[1], 2) + pow(_elements[2] - vector3D[2], 2)));
}

double Vector3D::norm() const {
    return dist(Vector3D());
}

Vector3D Vector3D::operator-=(const Vector3D &vector3D) {
    this->setElements(_elements[0] - vector3D[0], _elements[1] - vector3D[1],
                      _elements[2] - vector3D[2]);
    return *this;
}

Vector3D Vector3D::operator+=(const Vector3D &vector3D) {
    this->setElements(_elements[0] + vector3D[0], _elements[1] + vector3D[1],
            _elements[2] + vector3D[2]);
    return *this;
}

void Vector3D::setElements(const Vector3D &vector3D) {
    this->setElements(vector3D[0], vector3D[1], vector3D[2]);
}


Vector3D operator*(const Vector3D &vector13D, double number) {
    return Vector3D(vector13D[0] * number, vector13D[1] * number, vector13D[2] * number);
}

Vector3D Vector3D::operator*=(double number) {
    this->setElements(_elements[0] * number, _elements[1] * number, _elements[2] * number);
    return *this;
}

Vector3D Vector3D::operator/=(double number) {
    return operator*=(1/number);
}


Vector3D operator-(const Vector3D &vector13D) {
    return operator*(vector13D, -1);
}

Vector3D operator/(const Vector3D &vector13D, double number) {
    return operator*(vector13D, 1/number);
}

Vector3D Vector3D::operator+=(double number) {
    return Vector3D();
}

Vector3D Vector3D::operator-=(double number) {
    return Vector3D();
}


Vector3D& Vector3D::operator=(const Vector3D &vector3D) {
    setElements(vector3D);
    return *this;
}

double& Vector3D::operator[](int index) {
    return _elements[index];
}

double Vector3D::operator[](int index) const{
    return _elements[index];
}


Vector3D operator*(double number, const Vector3D &vector13D) {
    return operator*(vector13D, number);
}

double operator|(const Vector3D &vector13D, const Vector3D &vector23D) {
    return vector13D.dist(vector23D);
}

double operator*(const Vector3D &vector13D, const Vector3D &vector23D) {
    return vector13D[0] * vector23D[0] + vector13D[1] * vector23D[1] + vector13D[2] * vector23D[2];
}

double operator^(const Vector3D &vector13D, const Vector3D &vector23D) {
    return acos((vector13D * vector23D)/vector13D.norm() * vector23D.norm());
}

std::ostream &operator<<(std::ostream& os, Vector3D vector3D) {
    os << vector3D[0] << " "<< vector3D[1] <<
       " " << vector3D[2];
    return os;
}

std::istream &operator>>(std::istream &input, Vector3D &vector3D) {
    input >> vector3D[0] >> vector3D[1] >> vector3D[2];
    return input;
}

