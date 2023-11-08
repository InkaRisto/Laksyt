#include <iostream>

using namespace std;

int* taulukko;
int koko = 0;

int* varaa_taulukko(int n) {
	return new int[n];
}

void lue_arvot(int* ptr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Anna tallennettava arvo: ";
		cin >> ptr[i];
	}
}

void kaanna(int* t, int n) {
	for (int i = 0; i < n / 2; i++) {
		int temp = t[i];
		t[i] = t[n - i - 1];
		t[n - i - 1] = temp;
	}
}

void tulosta_arvot(const int* t, int n) {
	cout << "Antamasi arvot lopusta alkuun:";
	for (int i = 0; i < n; i++) {
		cout << t[i] << " ";
	}
}

int main() {
	cout << "Kuinka monta lukua tallennetaan? ";
	cin >> koko;
	taulukko = varaa_taulukko(koko);
	
	lue_arvot(taulukko, koko);
	kaanna(taulukko, koko);
	tulosta_arvot(taulukko, koko);

	delete[] taulukko;
}