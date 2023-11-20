#include <string>

using namespace std;

class Villager {
private:
	string _name;
	string _job;
	int _age;
	Villager* _relationship;

public:
	Villager() : _name(""), _job(""), _age()
	{}

	Villager(const string& name, const string& job, int age, Villager* relation = nullptr) {
		_name = name;
		_job = job;
		_age = age;
		_relationship = new Villager;
	}

	~Villager() {
		delete _relationship;
	}

	Villager(const Villager& original) {
		_name = original._name;
		_job = original._job;
		_age = original._age;

		//Pointer to avoid pointing to the same address as the original:
		_relationship = new Villager(*(original._relationship));

	}

	Villager& operator= (const Villager& rhs) //"right-hand side"
	{
		//Making sure no unintended memoryleak is left behind:
		if (_relationship) delete _relationship;
		_relationship = new Villager(*(rhs._relationship));

		_name = rhs._name;
		_job = rhs._job;
		_age = rhs._age;	

		return *this;
	}
};


int main() {
	Villager jukka("Jukka", "leader", 52);
	Villager pilvi("Pilvi", "farmer", 32, &jukka);

	pilvi = jukka;

	Villager arno("Arno", "smith", 22, &jukka);
	Villager jaana(arno);

	//a:
	//Villager jukka("Jukka", "leader", 52);
	//Villager pilvi("Pilvi", "farmer", 32, &jukka);

	//pilvi = jukka; // Mita tapahtuu? Tämä: Unhandled exception thrown: read access violation. **this** was 0xFFFFFFFFFFFFFFA7. Villager-olioiden luominen onnistui ongelmitta.

	//b:
	//Villager jukka("Jukka", "leader", 52);
	//Villager pilvi(jukka); // Mita tapahtuu? Tämä: Exception thrown: read access violation. **this** was 0xFFFFFFFFFFFFFFA7. Virheilmoitus samassa kohdassa, dekonstructoria luodessa.

	return 0;

}
