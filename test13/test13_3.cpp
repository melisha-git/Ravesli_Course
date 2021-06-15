#include <string>
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

template<typename T>
class StringValuePair : public Pair<std::string, T> {
public:
	StringValuePair(std::string const&, T const &);
};

template<typename T>
StringValuePair<T>::StringValuePair(const std::string &str, const T &y) : Pair<std::string, T>(str, y) {}

int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}