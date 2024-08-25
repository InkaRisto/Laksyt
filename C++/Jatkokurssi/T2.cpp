#include <thread>
#include <mutex>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


float acc = 0.0f;

//To store modifications for testing
float added = 0.0f;
float removed = 0.0f;

mutex mtx;

void manage(int operations, bool isDeposit) {
	for (int i = 0; i < operations; i++) {
		float amt = static_cast<float>(rand() % 100);
		
		cout << "Amount gotten: " << amt << endl;

		lock_guard<mutex> lock(mtx);
		if (isDeposit) {
			added += amt;
			acc += amt;
		}
		else {
			removed += amt;
			acc -= amt;
		}

		cout << "Balance: " << acc << endl;

	}
}

int main() {
	srand(static_cast<unsigned>(time(0)));
	int operations = 10000;
	
	//Two threads
	thread add(manage, operations, true);
	thread take(manage, operations, false);
	
	cout << "Threads done" << endl;


	add.join();
	take.join();

	cout << "Final balance: " << acc << endl;
	
	//To check accuracy
	cout << "Calc results: " << added - removed << endl;

	return 0;
}
