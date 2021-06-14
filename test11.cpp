#include <iostream>
#include <string>

class Fruit {
private:
	std::string _name;
	std::string _color;
public:
	Fruit(std::string, std::string);
	std::string getName();
	std::string getColor();
};

class Apple : public Fruit {
public:
	Apple(std::string name="apple", std::string color="red");
};

class Banana : public Fruit {
public:
	Banana();
};

class GrannySmith : public Apple {
public:
	GrannySmith();
};

Fruit::Fruit(std::string name, std::string color) : _name(name), _color(color) {}

std::string Fruit::getColor() {
	return _color;
}

std::string Fruit::getName() {
	return _name;
}

Apple::Apple(std::string name, std::string color) : Fruit(name, color) {}

Banana::Banana() : Fruit("banana", "yellow") {}

GrannySmith::GrannySmith() : Apple("Granny Smith apple","green") {}

int main()
{
	Apple a("apple" ,"red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	return 0;
}
