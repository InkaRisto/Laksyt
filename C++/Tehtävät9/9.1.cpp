#include <iostream>

using namespace std;

int main() {
	int alloSize = 100000;
	int* alloed = nullptr;

	//try {
	//	while (true) {
	//		alloed = new int[alloSize];
	//		cout << "Currently allocated: " << alloSize * sizeof(int) << endl;
	//		alloSize += 100000;

	//	}

	//}
	//catch (bad_alloc& err) {
	//	cout << "Failed to allocate memory. Error: " << err.what() << endl;
	//	cout << "Successfully allocated: " << alloSize;

	//}

	while (true) {
		alloed = static_cast<int*>(malloc(alloSize));
		cout << "Currently allocated: " << alloSize << endl;
		if (alloSize > 0) {
			alloSize += 100000;
		}
		else {
			break;
		}
	}

	cout << "Failed to allocate memory." << endl;
	cout << "Successfully allocated: " << alloSize;
	free(alloed);
	
	delete[] alloed;
	
	return 0;

}