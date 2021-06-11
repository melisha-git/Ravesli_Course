#ifndef RAVESLI_COURSE_POINT3D_HPP
#define RAVESLI_COURSE_POINT3D_HPP

#include <iostream>

class Vector3D;

class Point3D {
private:
	double m_x, m_y, m_z;
public:
	Point3D(double x = 0.0, double y = 0.0, double z = 0.0);
	void print();
	void moveByVector(const Vector3D &v);
};

#endif //RAVESLI_COURSE_POINT3D_HPP
