#include <stdlib.h>
#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main() {
	int lkm;
	cout << "Kuinka monta lukua tallennetaan? ";
	cin >> lkm;
	int* taulukko_ptr = varaa_taulukko(lkm);
	vector<int> taulukko(lkm); //Luodaan ennalta tuntemattoman kokoinen taulukko (vektoriolio)
	lue_arvot(taulukko_ptr, taulukko);
	kaanna(taulukko_ptr, taulukko);
	tulosta_arvot(taulukko_ptr, taulukko);

	delete[] taulukko_ptr;
}
