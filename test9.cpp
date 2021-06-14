#include <iostream>
#include <ostream>



class Average {
private:
	int32_t _result;
	int8_t _count;
public:
	Average();
	Average &operator+=(int);

	friend std::ostream &operator<<(std::ostream &, Average const &);
};

Average::Average() : _result(0), _count(0) {}

std::ostream &operator<<(std::ostream &out, Average const &other) {
	out << other._result / other._count;
	return out;
}

Average &Average::operator+=(int val) {
	this->_result += val;
	this->_count++;
	return *this;
}

void test2ex() {
	Average avg;
	avg += 5;
	std::cout << avg << '\n';
	avg += 9;
	std::cout << avg << '\n';
	avg += 19;
	std::cout << avg << '\n';
	avg += -9;
	std::cout << avg << '\n';
	(avg += 7) += 11;
	std::cout << avg << '\n';
	Average copy = avg;
	std::cout << copy << '\n';
}

class IntArray {
private:
	int *_array;
	int _max_index;
public:
	IntArray(unsigned int);
	IntArray(const std::initializer_list<int> &list);
	~IntArray();
	int &operator[](int);
	friend std::ostream &operator<<(std::ostream &, IntArray const &);
	IntArray &operator=(IntArray const &);
	int getLength() { return _max_index;}
};

IntArray& IntArray::operator=(IntArray const &other) {
	delete [] this->_array;
	this->_array = new int [other._max_index + 1];
	this->_max_index = other._max_index;
	for (int i = 0; i <= this->_max_index; i++) {
		this->_array[i] = other._array[i];
	}
	return *this;
}

IntArray::IntArray(const std::initializer_list<int> &list) : IntArray(list.size()) {
	int i = 0;
	for (auto &element : list) {
		_array[i] = element;
		++i;
	}
}

IntArray::IntArray(unsigned int val) : _max_index(val - 1) {
	_array = new int [val];
}

IntArray::~IntArray() {
	delete [] _array;
}

int & IntArray::operator[](int index) {
	assert(index >= 0 && index <= this->_max_index);
	return _array[index];
}

std::ostream &operator<<(std::ostream &out, IntArray const &other) {
	for (int i = 0; i <= other._max_index; i++) {
		out << other._array[i] << " ";
	}
	return out;
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 8;
	a[6] = 9;
	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';
	return 0;
}
