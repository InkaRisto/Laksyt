#include <vector>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

long long sum = 0;

mutex calc_lock;


void Calculate(const vector<int>& values, int start, int end) {
	//Calculates vector portions
	long local_sum = 0;
	for (int i = start; i < end; i++) {
		local_sum += values[i];
	}
	calc_lock.lock();
	sum += local_sum;
	calc_lock.unlock();
}

int main() {
	//Vector to store inputted values
	vector<int> values = {2,9,19,92,22,5,19,95,14,3,19,86,2,4,19,86}; //496
	
	int portion_size = values.size() / 3;

	thread calc1(Calculate, cref(values), 0, portion_size);
	thread calc2(Calculate, cref(values), portion_size, portion_size*2);
	thread calc3(Calculate, cref(values),  portion_size * 2, values.size());

	calc1.join();
	calc2.join();
	calc3.join();

	cout << "Sum: " << sum << endl;

	return 0;
}