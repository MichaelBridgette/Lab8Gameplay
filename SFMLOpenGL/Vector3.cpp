#include"Vector3.h"
#include<math.h>
//Vector3();
//Vector3(double x1, double y1, double z1);
//double Length();
//double LengthSquared();
//void Normalise();
//Vector3 operator+(Vector3 V2);
//Vector3 operator-(Vector3 V2);
//Vector3 operator*(Vector3 V2);
//Vector3 operator*(double k);
//double Negate();

Vector3::Vector3() {
	m_x = 0;
	m_y = 0;
	m_z = 0;
}
Vector3::Vector3(double x1, double y1, double z1)
{
	m_x = x1;
	m_y = y1;
	m_z = z1;
}
Vector3::Vector3(float x1, float y1, float z1)
{
	m_x = x1;
	m_y = y1;
	m_z = z1;
}

double Vector3::Length()
{
	return (double) sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

double Vector3::LengthSquared()
{
	return (m_x*m_x + m_y*m_y + m_z*m_z);
}

const double Vector3::GetX()
{
	return m_x;
}

const double Vector3::GetY()
{
	return m_y;
}

const double Vector3::GetZ()
{
	return m_z;
}

 float Vector3::GetXf()
{
	return (float)m_x;
}

 float Vector3::GetYf()
{
	return (float)m_y;
}

 float Vector3::GetZf()
{
	return (float)m_z;
}

void Vector3::Normalise()
{
	if (Vector3::Length() > 0)
	{
		double magnit = Vector3::Length();
		m_x /= magnit;
		m_y /= magnit;
		m_z /= magnit;
	}
}
Vector3 Vector3::operator+(Vector3 V2)
{
	return Vector3(m_x+V2.m_x , m_y+V2.m_y, m_z+ V2.m_z);
}

Vector3 Vector3::operator-(Vector3 V2)
{
	return Vector3(m_x - V2.m_x, m_y - V2.m_y, m_z - V2.m_z);
}

Vector3 Vector3::operator*(Vector3 V2)
{
	return Vector3(m_x* V2.m_x, m_y*V2.m_y, m_z*V2.m_z);
}

Vector3  Vector3::operator*(double k)
{
	return Vector3(m_x*k, m_y*k, m_z*k);
}

Vector3 Vector3::Negate()
{
	return Vector3(-m_x, -m_y, -m_z);
}

std::string Vector3::ToString()
{
	return "(" + std::to_string(m_x) + " , " + std::to_string(m_y) + " , " + std::to_string(m_z)+")";

}

double Vector3::ConvertToDouble()
{
	return (m_x + m_y + m_z);
}