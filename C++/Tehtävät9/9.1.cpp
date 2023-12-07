#include <iostream>

using namespace std;

int main() {
	int alloSize = 1000;
	int* alloed = nullptr;

	try {
		while (true) {
			alloed = new int[alloSize];
			cout << "Currently allocated: " << alloSize << endl;
			alloSize = +1000;

		}

	}
	catch (bad_alloc& err) {
		cout << "Failed to allocate memory. Error: " << err.what() << endl;
		cout << "Successfully allocated: " << alloSize;

	}

	delete[] alloed;
	return 0;

}