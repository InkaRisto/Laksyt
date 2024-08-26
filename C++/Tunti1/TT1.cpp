#include <vector>
#include <thread>
#include <iostream>
#include <mutex>
#include <future>

using namespace std;



long Calculate(const vector<int>& values, int start, int end) {
	//Calculates vector portions
	long local_sum = 0;
	for (int i = start; i < end; i++) {
		local_sum += values[i];
	}
	return local_sum;
}

int main() {
	//Vector to store inputted values
	vector<int> values = { 2,9,19,92,22,5,19,95,14,3,19,86,2,4,19,86 }; //496
	long long sum = 0;

	int portion_size = values.size() / 3;

	auto calc1 = async(Calculate, cref(values), 0, portion_size);
	auto calc2 = async(Calculate, cref(values), portion_size, portion_size * 2);
	auto calc3 = async(Calculate, cref(values), portion_size * 2, values.size());

	sum = calc1.get() + calc2.get() + calc3.get();

	cout << "Sum: " << sum << endl;

	return 0;
}