#include <iostream>
#include "limit.h"
using namespace std;

int pelataan(){
	int luku;
		cout << "\nPelataan Kiinalaista Numeropelia! \nAnna luku:";
		cin >> luku;
		if (luku == 0) {
			return 0;
		}
		if (tarkista_limit(luku)) {
			cout << "Tasapeli!\n";
			return 1;
		}
		cout << "Voitin! Minun lukuni oli: " << luku + 1 << endl;
		return luku;
}


int main() {
	while (true) {
		int luku;
		luku = pelataan();
		
		if (luku == 0) {
			break;
		}
	}
}