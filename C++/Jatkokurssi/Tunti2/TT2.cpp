#include <thread>
#include <mutex>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <future>

using namespace std;


float acc = 0.0f;

//To store modifications for testing
float added = 0.0f;
float removed = 0.0f;

mutex mtx;

void manage(int operations, bool isDeposit) {
	for (int i = 0; i < operations; i++) {
		float amt = static_cast<float>(rand() % 100);

		cout << "Amount gotten: \n" << amt << endl;

		lock_guard<mutex> lock(mtx);
		if (isDeposit) {
			added += amt;
			acc += amt;
		}
		else {
			removed += amt;
			acc -= amt;
		}

		cout << "Balance: \n" << acc << endl;

	}
}

int main() {
	srand(static_cast<unsigned>(time(0)));
	int operations = 100;

	//Two threads
	auto add = async(manage, operations, true);
	auto take = async(manage, operations, false);

	cout << "Final balance: " << acc << endl;

	//To check accuracy
	cout << "Calc results: " << added - removed << endl;

	return 0;
}
