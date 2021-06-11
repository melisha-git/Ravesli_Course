#include <iostream>
#include <chrono>

const int g_arrayElements = 10000;

class Timer {
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> _beg;
public:
	Timer() : _beg(clock_t::now()) {}

	void reset() {
		_beg = clock_t::now();
	}
	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - _beg).count();
	}
};

int main() {
	Timer t;
	std::cout << t.elapsed();
	return 0;
}