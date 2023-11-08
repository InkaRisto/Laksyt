#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int* varaa_taulukko(int n) {
	return new int[n];
}

void lue_arvot(int* ptr, const vector<int>& n) {
	for (int i = 0; i < n.size(); i++) {
		cout << "Anna tallennettava arvo: ";
		cin >> ptr[i];
	}
}

void kaanna(int* t, const vector<int>& n) {
	int len = n.size();
	for (int i = 0; i < len / 2; i++) {
		int temp = t[i];
		t[i] = t[len - i - 1];
		t[len - i - 1] = temp;
	}
}

void tulosta_arvot(const int* t, const vector<int>& n) {
	cout << "Antamasi arvot lopusta alkuun: ";
	for (int i = 0; i < n.size(); i++) {
		cout << t[i] << " ";
	}
}
