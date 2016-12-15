#pragma once
#include<iostream>
#include<string>

class Vector3 {

private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vector3();
	Vector3(double x1, double y1, double z1);
	Vector3(float x1, float y1, float z1);
    const double GetX();
	const double GetY();
	const double GetZ();
	float GetXf();
	float GetYf();
	float GetZf();
	double Length();
	double LengthSquared();
	void Normalise();
	Vector3 operator+(Vector3 V2);
	Vector3 operator-(Vector3 V2);
	Vector3 operator*(Vector3 V2);
	double ConvertToDouble();
	Vector3 operator*(double k);
	Vector3 Negate();
	std::string ToString();


};