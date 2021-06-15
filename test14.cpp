#include <iostream>

class Fraction {
private:
	int16_t _x;
	int16_t _y;
public:
	Fraction(int16_t x, int16_t y) : _x(x), _y(y) {
		if (y == 0) {
			throw std::runtime_error("Your fraction has an invalid denominator.");
		}
	}
};

int main() {
	int num, den;
	std::cout << "Enter the numerator: ";
	std::cin >> num;
	std::cout << "Enter the denominator: ";
	std::cin >> den;
	try {
		Fraction f = Fraction(num, den);
	}
	catch (std::runtime_error &r) {
		std::cerr << r.what();
	}
	return 0;
}