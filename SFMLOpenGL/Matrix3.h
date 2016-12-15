#pragma once
#define _USE_MATH_DEFINES
#include<math.h>
#include"Vector3.h"


class Matrix3
{
private:
	 double m_A11;
	 double m_A12;
	 double m_A13;
	 double m_A21;
	 double m_A22;
	 double m_A23;
	 double m_A31;
	 double m_A32;
	 double m_A33;

	 

public:
	Matrix3();
	Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);
	Matrix3(double A11,
		double A12,
		double A13,
		double A21,
		double A22,
		double A23,
		double A31,
		double A32,
		double A33);
	Vector3 operator*(Vector3 V1);
	Matrix3 operator+(Matrix3 M2);
	Matrix3 operator-(Matrix3 M2);
	Matrix3 operator*(double x);
	Matrix3 operator*(Matrix3 M2);
	Matrix3 Transpose(Matrix3 M1);
	double Determinant();
	Vector3 Row(int i);
	Vector3 Column(int i);
	Matrix3 Inverse();
	Matrix3 Rotation(int angle);
	Matrix3 Translate(int dx, int dy);
	Matrix3 Scale(float dx, float dy);
	Matrix3 RotationX(float angle);
	Matrix3 RotationY(float angle);
	Matrix3 RotationZ(float angle);
	Matrix3 Scale3D(float dx);


};