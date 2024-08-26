#include <execution>
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

template <typename ExecutionPolicy>
void increase(ExecutionPolicy policy, vector<int>& group) {
	//Start time of testing timer
	const auto start = chrono::steady_clock::now();

	for_each(policy, group.begin(), group.end(), [](int& i) { i++; });

	const auto finish = chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
	cout << duration << " ms" << "\n";
	}


int main() {
	int n = 15000000;
	vector<int> numbers;
	
	for (int i = 0; i < n; i++) {
		numbers.push_back(i);
	}

	//Increasing the values by one in 3 methods
	increase(execution::seq, ref(numbers)); //fastest on lower amounts; slowest on large ones
	increase(execution::par, ref(numbers)); //slowest
	increase(execution::par_unseq, ref(numbers)); //quite equal with par


}