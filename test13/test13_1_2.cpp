#include <iostream>

template<typename T, typename S>
class Pair {
private:
	T _x;
	S _y;
public:
	Pair(T const &, S const &);
	T first() const;
	S second() const;
};

template<typename T, typename S>
Pair<T, S>::Pair(const T &x, const S &y) : _x(x), _y(y) {}

template<typename T, typename S>
T Pair<T, S>::first() const {
	return _x;
}

template<typename T, typename S>
S Pair<T, S>::second() const {
	return _y;
}

int main()
{
	Pair<int, double> p1(6, 7.8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}