#include <iostream>

class Fraction {
private:
	int _numerator;
	int _denominator;
	Fraction();
public:
	Fraction(int, int);
	void print();
	int nod(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}
	void reduce();
	friend Fraction operator*(Fraction const&, Fraction const&);
	friend Fraction operator*(Fraction const&, const int &);
	friend Fraction operator*(const int &, Fraction const&);
};

Fraction::Fraction(int num, int den)
	: _numerator(num), _denominator(den)
{
	this->reduce();
}

Fraction::Fraction()
	: Fraction(0, 0) {}

void Fraction::print() {
	std::cout << _numerator << "/" << _denominator << std::endl;
}

void Fraction::reduce() {
	int node = nod(_numerator, _denominator);
	while (node != 1) {
		_numerator /= node;
		_denominator /= node;
		node = nod(_numerator, _denominator);
	}
}

Fraction operator*(Fraction const &copy, Fraction const &other) {
	return (Fraction(copy._numerator * other._numerator, copy._denominator * other._denominator));
}

Fraction operator*(Fraction const&other, const int &val) {
	return (Fraction(other._numerator * val, other._denominator));
}

Fraction operator*(const int &val, Fraction const&other) {
	return (Fraction(other._numerator * val, other._denominator));
}

int main()
{
	Fraction f1(3, 4);
	f1.print();

	Fraction f2(2, 7);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 3;
	f4.print();

	Fraction f5 = 3 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();
}