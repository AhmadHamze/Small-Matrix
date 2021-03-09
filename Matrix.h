#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
#include <limits>
#include <string.h>

class Matrix2by2
{
protected:
float q[9];
float p[9];
float r[3][3];
public:
    Matrix2by2();
    virtual ~Matrix2by2();
    Matrix2by2(float*);//Convert constructor.
    void setMatrix();
    void getMatrix();
    float* invertMatrix();
    bool isPrintable;
    Matrix2by2 operator+(Matrix2by2);
    Matrix2by2 operator*(Matrix2by2);

} ;

class Matrix3by3:public Matrix2by2
{
public:
    Matrix3by3();
    ~Matrix3by3();
    Matrix3by3(float*);
    float*setMatrix();
    float*getMatrix();
    Matrix3by3 operator+(Matrix3by3);
    Matrix3by3 operator*(Matrix3by3);
    float*invertMatrix();


};



#endif // MATRIX_H_INCLUDED
