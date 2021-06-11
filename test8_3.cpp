#include <iostream>
#include <string>

class Monster {
public:
	enum MonsterType {
		Dragon = 0,
		Goblin = 1,
		Ogre = 2,
		Orc = 3,
		Skeleton = 4,
		Troll = 5,
		Vampire = 6,
		Zombie = 7,
		MAX_MONSTER_TYPES = 8
	};
	Monster(MonsterType const &, std::string const &, const int &);
	void print();
	std::string getTypeString();
private:
	MonsterType _type;
	std::string _name;
	int _hp;
};

Monster::Monster(const MonsterType &type, const std::string &name, const int &hp)
	: _type(type), _name(name), _hp(hp) {}

std::string Monster::getTypeString() {
	switch (_type) {
		case Orc:
			return "orc";
		case Dragon:
			return "dragon";
		case Goblin:
			return "goblin";
		case Ogre:
			return "orge";
		case Skeleton:
			return "skeleton";
		case Troll:
			return "troll";
		case Vampire:
			return "vampire";
		case Zombie:
			return "zombie";
		default:
			break ;
	}
	return "undefined";
}

void Monster::print() {
	std::cout << _name << " is the " << this->getTypeString() << " that has " << _hp << " health points." << std::endl;
}

class MonsterGenerator {
public:
	static Monster generateMonster() {
		static std::string s_name[] = {"Jack", "Bob", "Jimmy", "Job", "Steve", "Alice"};
		Monster::MonsterType type = Monster::MonsterType(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		return Monster(type, s_name[getRandomNumber(0, 5)], getRandomNumber(1, 100));
	}

	static int getRandomNumber(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};

int main() {
	srand(static_cast<unsigned int>(time(0)));
	rand();
	Monster jack = MonsterGenerator::generateMonster();
	jack.print();
	return 0;
}
