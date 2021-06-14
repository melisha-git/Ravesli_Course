#include <iostream>
#include <string>

class Creature {
protected:
	std::string _name;
	char _symbol;
	int _hp;
	int _damage;
	int _money;
public:
	Creature(std::string name="ogre", char sym='k', int hp=50, int damage=15, int money=10);
	std::string getName() { return _name; }
	char getSymbol() { return _symbol; }
	int getHealth() { return _hp; }
	int getDamage() { return _damage; }
	int getGold() { return _money; }
	void reduceHealth(int damage) { _hp-= damage; }
	bool isDead() { return (_hp <= 0); }
	void addGold(int money) { _money+=money; }
};

Creature::Creature(std::string name, char sym, int hp, int damage, int money)
	: _name(name), _symbol(sym), _hp(hp), _damage(damage), _money(money) {}

class Player : public Creature {
private:
	int8_t _level;
public:
	Player(std::string);
	void levelUp() { _level+= 1; _damage+=1; }
	int8_t getLevel() { return _level; }
	bool hasWon() { return ( _level >= 20); }
};

Player::Player(std::string name) : Creature::Creature(name, '@', 10, 1, 0) {
	_level = 1;
}

class Monster : public Creature {
private:
	typedef struct s_monsterData {
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	} MonsterData;
	static MonsterData monsterData[];
public:
	enum Type {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	Monster(Type);
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES] {
		{ "dragon", 'D', 20, 4, 100 },
		{ "orc", 'o', 4, 2, 25 },
		{ "slime", 's', 1, 1, 10 }
};

Monster::Monster(Type type)
	: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {}

std::string whatName() {
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	return name;
}

int main()
{
	Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
}