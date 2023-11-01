#include <iostream>
#include <limits>
using namespace std;

int tarkista_limit(int numero) {
	//Couldn't get try-catch to work
	int maximum;
	maximum = numeric_limits<int>::max();
		if (numero == maximum) {
			return 1;
		}
		return 0;
	}
