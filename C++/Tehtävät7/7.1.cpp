#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
	vector<T> arr;

public:
	void push(const T& item) {
		arr.push_back(item);
	}

	T pop() {
		T item = arr.back();
		arr.pop_back();
		return item;
	}

	int size() {
		int index = 0;
		for (auto i : arr) {
			index++;
		}
		return index;
	}
};

template <typename T>
T SmallestToLargest(const T& array) {
	T arr = array;
	vector<T> reorganized;
	
	for (i : arr) {
		if (i < get<i + 1>(arr)) {
			arr.push_front(i);
		}
	}


}

int main() {
	Stack<int> intStack;
	Stack<double> dblStack;
	Stack<string> strStack;

	intStack.push(2);
	intStack.push(23);
	intStack.push(3);

	dblStack.push(3.4);
	dblStack.push(2.0);
	
	strStack.push("Well");
	strStack.push("Lwt's");
	strStack.push("See");

	cout << "IntStack size: " << intStack.size() << endl;
	intStack.pop();
	cout << "IntStack size: " << intStack.size() << endl;

	strStack.pop();
	cout << "StrStack size: " << strStack.size() << endl;

	cout << "DblStack size: " << dblStack.size() << endl;

	return 0;
}