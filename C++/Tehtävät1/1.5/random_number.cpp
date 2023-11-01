#include <iostream>
#include <random>
#include <tuple>

using namespace std;

tuple<int, int, int> get_random_number() {
	random_device seed; //Random seed
	int low, high;
	cout << "Anna pelille alin ja ylin arvo: ";
	cin >> low;
	cin >> high;
	uniform_int_distribution<int> distribution(low, high);
	mt19937 gen(seed()); //Seed the endine
	int random_number = distribution(gen); //Generate from parameters given
	return make_tuple(random_number, low, high);
}