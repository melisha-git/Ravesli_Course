#include <ostream>
#include <iostream>

#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator=0, int denominator=1):
			m_numerator(numerator), m_denominator(denominator) {
		reduce();
	}

	static int nod(int a, int b) {
		return b == 0 ? a : nod(b, a % b);
	}

	void reduce()
	{
		int nod = Fraction::nod(m_numerator, m_denominator);
		m_numerator /= nod;
		m_denominator /= nod;
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
	friend std::ostream &operator<<(std::ostream &out, Fraction const &);
	friend std::istream &operator>>(std::istream &in, Fraction &);
	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::istream &operator>>(std::istream &in, Fraction &other) {
	in >> other.m_numerator;
	char c;
	in >> c;
	in >> other.m_denominator;
	return in;
}

std::ostream &operator<<(std::ostream &out, Fraction const &other) {
	out << other.m_numerator << "/" << other.m_denominator;
	return out;
}

int main()
{

	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}