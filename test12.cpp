#include <iostream>
#include <ostream>
#include <vector>

class Point {
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;
public:
	Point(int x, int y, int z)
			: m_x(x), m_y(y), m_z(z) {}

	friend std::ostream& operator<<(std::ostream &out, const Point &p) {
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Share { //A - потому что абстрактный
public:
	virtual std::ostream &print(std::ostream &) const = 0;
	friend std::ostream &operator<<(std::ostream &out, Share &other) {
		return other.print(out);
	}
	virtual ~Share() {}
};

class Triangle : public Share {
private:
	Point _p_one;
	Point _p_two;
	Point _p_three;
public:
	virtual std::ostream &print(std::ostream &out) const override {
		out << "Triangle(" << _p_one << ", " << _p_two << ", " << _p_three << ")";
		return out;
	}
	Triangle(Point const p_one, Point const p_two, Point const p_three) : _p_one(p_one), _p_two(p_two), _p_three(p_three) {}
	virtual ~Triangle() {}
};

class Circle : public Share {
private:
	Point _p;
	int16_t _radius;
public:
	virtual std::ostream &print(std::ostream &out) const override {
		out << "Circle(" << _p << ", radius " << _radius << ")";
		return out;
	}
	Circle(Point const p, int8_t const rad) : _p(p), _radius(rad) {}
	virtual ~Circle() {}
	int16_t getRadius() { return _radius; }
};

/*
 * 2c
 */

int16_t getLargestRadius(std::vector<Share *> &v) {
	int16_t largest = 0;
	for (int i = 0; v[i]; i++) {
		if (Circle *c = dynamic_cast<Circle *>(v[i])) {
			if (largest < c->getRadius())
				largest = c->getRadius();
		}
	}
	return largest;
}

int main() {
	std::vector<Share *> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 11));

	// Вывод элементов вектора v здесь

	for (int i = 0; v[i]; i++) {
		std::cout << *v[i] << std::endl;
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

	// Удаление элементов вектора v здесь
	for (int i = 0; v[i]; i++) {
		delete v[i];
	}
}

/*
 * 2b
 */

//int main() {
//	Circle c(Point(1, 2, 3), 7);
//	std::cout << c << '\n';
//
//	Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
//	std::cout << t << '\n';
//
//	return 0;
//}