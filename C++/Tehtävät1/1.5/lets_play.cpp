#include <iostream>

using namespace std;

int lets_play(int goal, int low, int high) {
	cout << "\nArvaa luku (" << low << "-" << high << "): " << endl;
	int guess;
	cin >> guess;
	if (low <= guess && high >= guess) {
		if (guess > goal) {
			cout << "Liian suuri!\n";
			return 1;
		}
		if (guess < goal) {
			cout << "Liian pieni\n";
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		cout << "Pysy antamissasi arvoissa!\n";
	}
}