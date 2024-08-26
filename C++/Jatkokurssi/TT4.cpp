#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Functor {
	public:
		int operator()(int val, int change) {
			return val = val <= change ? 0 : val - change;
		}
};
int damage(int dmg, int& hp) {
	return hp = hp <= dmg ? 0 : hp - dmg;
}
auto spell_effect(vector<int>& HPs, int dmg) {
	//c. lambda function
	for_each(HPs.begin(), HPs.end(), [dmg](int& hp) {hp = hp <= 100 ? 0 : hp - dmg; });

	//d. named lambda
	auto dmg_calc = [dmg](int& hp) {hp = hp <= 100 ? 0 : hp - dmg; };
	for_each(HPs.begin(), HPs.end(), dmg_calc);

	//a. call separate function
	for (int& hp : HPs) {
		hp = damage(dmg, hp);
	}

	//Functor
	Functor enemy;
	for (int& hp : HPs) {
		hp = enemy(hp, dmg);
	}
}

int main() {
	vector<int> enemiesHP = { 200, 100, 500, 400, 50 };
	bool success = true;
	int dmg = 100;

	spell_effect(ref(enemiesHP), dmg);
		
	cout << "Enemy HPs after 4 attacks: " << endl;
	for (int hp : enemiesHP) {
		cout << hp << " ";
	}

	//Sort vector L > S
	return 0;
}