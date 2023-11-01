#include <iostream>
#include <tuple>
#include "functions.h"

using namespace std;

int main() {
	int comnumber;
	int guesses;
	int low;
	int high;
	tuple<int, int, int> game_rules = get_random_number();
	guesses = 1;

	low = get<1>(game_rules);
	high = get<2>(game_rules);
	comnumber = get<0>(game_rules);
	while (lets_play(comnumber, low, high)) {
		guesses += 1;
	}
	cout << "Oikein! Teit " << guesses << " arvausta." << endl;
}