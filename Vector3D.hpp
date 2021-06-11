#ifndef RAVESLI_COURSE_VECTOR3D_HPP
#define RAVESLI_COURSE_VECTOR3D_HPP
#include "Point3D.hpp"
class Point3D;

class Vector3D {
private:
	double m_x, m_y, m_z;
public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
	void print();
	friend void Point3D::moveByVector(const Vector3D &v);
};

#endif //RAVESLI_COURSE_VECTOR3D_HPP
