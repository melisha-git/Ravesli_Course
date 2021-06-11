#include <iostream>
#include <cmath>

class Point {
private:
	double m_a;
	double m_b;
public:
	Point(double a = 0.0, double b = 0.0);
	void print();
	friend  double distanceFrom(const Point &, const Point &);
	double distanceTo(const Point &);
};

Point::Point(double a, double b) : m_a(a), m_b(b) {}

void Point::print() {
	std::cout << "Point(" << m_a << ", " << m_b << ")" << std::endl;
}

double distanceFrom(const Point &copy, const Point &other) {
	return sqrt((copy.m_a - other.m_a) * (copy.m_a - other.m_a) + (copy.m_b - other.m_b) * (copy.m_b - other.m_b));
}

double Point::distanceTo(const Point &other) {
	return sqrt((this->m_a - other.m_a) * (this->m_a - other.m_a) + (this->m_b - other.m_b) * (this->m_b - other.m_b));
}

/*
 * main Для 1.a задания
 *

	int main() {
		Point first;
		Point second(2.0, 5.0);
		first.print();
		second.print();
		return 0;
	}
 */

/*
 * main для 1.b задания
	int main() {
		Point first;
		Point second(2.0, 5.0);
		first.print();
		second.print();
		std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
		return 0;
	}
*/

int main() {
	Point first;
	Point second(2.0, 5.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
	return 0;
}