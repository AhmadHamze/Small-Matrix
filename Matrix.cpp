#include "Matrix.h"


using namespace std;

Matrix2by2::Matrix2by2()
{
    for(short i=0;i<9;i++)
    {
        q[i]=0;
        p[i]=0;
    }
    for(short i=0;i<3;i++)
    {
        for(short j=0;j<3;j++)
            r[i][j]=0;
    }
}
Matrix2by2::~Matrix2by2()
{

}
Matrix2by2::Matrix2by2(float*q)
{
for(short i=0;i<4;i++)
{
    this->q[i]=q[i];
}
}

float*Matrix2by2::setMatrix()
{
   cout<<"Enter the 2 by 2 matrix horizontally\n";
    for(short i=0;i<4;i++)
        cin>>q[i];
        return q;
}
float*Matrix2by2::getMatrix()
{
    for(short i=0;i<2;i++)
        cout<<q[i]<<" ";
    cout<<endl;
    for(short i=2;i<4;i++)
            cout<<q[i]<<" ";
    cout<<endl;
    return q;
}
float*Matrix2by2::invertMatrix()
{
    float tmp=q[0]*q[3]-q[2]*q[1];
    if(tmp!=0)
    {
        p[0]=q[3]/tmp;
        p[1]=-q[1]/tmp;
        p[2]=-q[2]/tmp;
        p[3]=q[0]/tmp;
    }
    else cout<<"The matrix is not invertible\n";
    Matrix2by2 M=p;
    return p;

}
Matrix2by2 Matrix2by2::operator+(Matrix2by2 M)
{
    for(short i=0;i<4;i++)
    {
        p[i]=this->q[i]+M.q[i];
    }
   M=p;
   return M;
}
Matrix2by2 Matrix2by2::operator*(Matrix2by2 M)
{
for(short i=0;i<4;i+=2)
{
    for(short j=0;j<2;j++)
    {
        r[i][j]=this->q[i]*M.q[j]+this->q[i+1]*M.q[j+2];
    }
}
p[0]=r[0][0];p[1]=r[0][1];p[2]=r[2][0];p[3]=r[2][1];
M=p;
return M;
}

Matrix3by3::Matrix3by3()
{
for(short i=0;i<9;i++)
    {
        q[i]=0;
    }
}
Matrix3by3::~Matrix3by3()
{

}
Matrix3by3::Matrix3by3(float*q)
{
    for(short i=0;i<9;i++)
    {
        this->q[i]=q[i];
    }
}
float* Matrix3by3::setMatrix()
{
    cout<<"Enter the 3 by 3 matrix horizontally\n";
    for(short i=0;i<9;i++)
        cin>>q[i];
        return q;
}
float*Matrix3by3::getMatrix()
{
for(short i=0;i<3;i++)
        cout<<q[i]<<" ";
    cout<<endl;
    for(short i=3;i<6;i++)
            cout<<q[i]<<" ";
    cout<<endl;
    for(short i=6;i<9;i++)
        cout<<q[i]<<" ";
    cout<<endl;
        return q;

}
Matrix3by3 Matrix3by3::operator+(Matrix3by3 M)
{
   for(short i=0;i<9;i++)
    {
        p[i]=this->q[i]+M.q[i];
    }
   M=p;
   return M;
}

Matrix3by3 Matrix3by3::operator*(Matrix3by3 M)
{
    for(short i=0,k=0;i<9,k<3;i+=3,k++)
    {
        for(short j=0;j<3;j++)
            r[j][k]=this->q[i]*M.q[j]+this->q[i+1]*M.q[j+3]+this->q[i+2]*M.q[j+6];
    }
    for(short i=0,j=3,k=6;i<3,j<6,k<9;i++,j++,k++)
    {
        p[i]=r[i][0];
        p[j]=r[j-3][1];
        p[k]=r[k-6][2];
    }
M=p;
return M;
}
float* Matrix3by3::invertMatrix()
{
    float det=q[0]*(q[4]*q[8]-q[5]*q[7])-q[1]*(q[3]*q[8]-q[5]*q[6])+q[2]*(q[3]*q[7]-q[4]*q[6]);
    if(det!=0)
    {
        p[0]=(q[4]*q[8]-q[5]*q[7])/det;
        p[3]=(q[5]*q[6]-q[3]*q[8])/det;
        p[6]=(q[3]*q[7]-q[4]*q[6])/det;
        p[1]=(q[2]*q[7]-q[1]*q[8])/det;
        p[4]=(q[0]*q[8]-q[2]*q[6])/det;
        p[7]=(q[1]*q[6]-q[0]*q[7])/det;
        p[2]=(q[1]*q[5]-q[2]*q[4])/det;
        p[5]=(q[2]*q[3]-q[0]*q[5])/det;
        p[8]=(q[0]*q[4]-q[1]*q[3])/det;
        }
    else {
            cout<<"The matrix is not invertible"<<endl;

            }
    Matrix3by3 N=p;
    return p;
}

