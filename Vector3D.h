//
// Created by hp on 07/12/2018.
//

#ifndef CPPTEST_VECTOR3D_H
#define CPPTEST_VECTOR3D_H
#define VECTOR_ELEM_NUM 3

class Vector3D {
    private:
    double _elements[VECTOR_ELEM_NUM];

    public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(double data[VECTOR_ELEM_NUM]);
    Vector3D(const Vector3D &vector3d);
    double norm() const;
    double distance(const Vector3D &vector3D) const;
    const double * getElements() const;
    operator std::string() const;
    friend Vector3D operator+(const Vector3D& vector13D, const Vector3D& vector23D);
    friend Vector3D operator-(const Vector3D& vector13D, const Vector3D& vector23D);
    friend Vector3D operator-(const Vector3D& vector13D);
    friend Vector3D operator*(const Vector3D& vector13D, double number);
    friend Vector3D operator*(double number, const Vector3D& vector13D);
    friend Vector3D operator/(const Vector3D& vector13D, double number);
    friend double operator|(const Vector3D& vector13D, const Vector3D& vector23D);
    friend double operator*(const Vector3D& vector13D, const Vector3D& vector23D);
    friend double operator^(const Vector3D& vector13D, const Vector3D& vector23D);
    friend std::istream& operator>>(std::istream& input, Vector3D &vector3D);
    friend std::ostream& operator<<(std::ostream& os, Vector3D vector3D);

    double& operator[]( int index);
    double operator[]( int index) const;
    Vector3D& operator=(const Vector3D& vector3D);
    Vector3D operator+=(const Vector3D& vector3D);
    Vector3D operator-=(const Vector3D& vector3D);
    Vector3D operator+=(double number);
    Vector3D operator-=(double number);
    Vector3D operator*=(double number);
    Vector3D operator/=(double number);

    void setElements(const Vector3D &vector3D);
    void setElements(double x, double y, double z);

    ~Vector3D();
};


#endif //CPPTEST_VECTOR3D_H
