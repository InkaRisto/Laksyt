#include <string>
#include <iostream>
#include <tuple>
#include <random>
#include <vector>

using namespace std;

class Auto{
private:
	//Auton ominaisuudet
	string _rekkari;
	int _nopeus_max;
	int _nopeus_nyt;
	int _matka;

public:
	Auto(const string& rekisteri, int top) {
		//Alustaja, joka asettaa ominaisuuksista kaksi ensin mainittua parametreina saatuihin arvoihin
		_rekkari = rekisteri;
		_nopeus_max = top;
		_nopeus_nyt = 0;
		_matka = 0;
	}

	tuple<string, int, int, int> V‰lit‰_tiedot() const {
		return { _rekkari, _nopeus_max, _nopeus_nyt, _matka };
	}

	/*int Tulosta_tiedot() {
		cout << "Rekisteritunnus: " << _rekkari << "\n";
		cout << "Huippunopeus: " << _nopeus_max << "\n";
		cout << "T‰m‰nhetkinen nopeus: " << _nopeus_nyt << "\n";
		cout << "Kuljettu matka: " << _matka << "\n";

		return 0;
	} */

	int Kiihdyt‰(int muutos) {
		//kiihdyt‰-j‰senfunktio, joka saa parametrinaan nopeuden muutoksen (km/h)
		if (_nopeus_nyt + muutos > 0){
			_nopeus_nyt = _nopeus_nyt + muutos;
		}

		if (_nopeus_nyt + muutos > _nopeus_max) {
			_nopeus_nyt = _nopeus_max;
		}

		if (_nopeus_nyt + muutos < 0){
			_nopeus_nyt = 0;
		}
		return 0;
	}

	int Kulje(int aika) {
		//kasvattaa kuljettua matkaa sen verran kuin auto on tasaisella vauhdilla annetussa tuntim‰‰r‰ss‰ edennyt
		int vauhti = _nopeus_nyt;
		int kuljettu = _nopeus_nyt * aika;
		_matka = _matka + kuljettu;
		return 0;
	}
	};
int get_random_number(int low, int high) {
	random_device seed; //Random seed
	uniform_int_distribution<int> distribution(low, high);
	mt19937 gen(seed()); //Seed the endine
	int random_number = distribution(gen); //Generate from parameters given
	return random_number;
}

int main() {
	//luot uuden auton (rekisteritunnus ABC-123, huippunopeus 142 km/h). 
	vector<Auto> autot;
	for (int i = 1; i <= 10; ++i) {
		string rekisteri = "ABC-" + to_string(i);
		int huippunopeus = get_random_number(100, 200);
		autot.push_back(Auto(rekisteri, huippunopeus));
	}

	while (true) {
		for (Auto& a : autot) {
			int vauhti = get_random_number(-10, 15);
			a.Kiihdyt‰(vauhti);
			a.Kulje(1);
			tuple<string, int, int, int> tiedot = a.V‰lit‰_tiedot();

			if (get<3>(tiedot) >= 10000) {
				// Race is over, print results
				cout << "Kisa ohi! Lopputulos:\n";
				for (const Auto& alus : autot) {
					tuple<string, int, int, int> tiedot_alus = alus.V‰lit‰_tiedot();
					cout << "Rekisteritunnus: " << get<0>(tiedot_alus) << "| Huippunopeus: " << get<1>(tiedot_alus)
						<< "| Tamanhetkinen nopeus: " << get<2>(tiedot_alus) << "| Kuljettu matka: " << get<3>(tiedot_alus) << "\n";
				}
				return 0; // End the program
			}

		}



	}
		
	/*
	a1.Kiihdyt‰(30);
	a1.Kulje(1);
	a1.Kiihdyt‰(70);
	a1.Kulje(1.5);
	a1.Kiihdyt‰(50);
	a1.Kulje(2);
	a1.Kiihdyt‰(-200);
	a1.Kulje(0.5);

	tuple<string, int, int, int> tiedot = a1.V‰lit‰_tiedot();

	// Tulosta p‰‰ohjelmassa sen j‰lkeen luodun auton kaikki ominaisuudet
	cout << "Rekisteritunnus: " << get<0>(tiedot) << "\n";
	cout << "Huippunopeus: " << get<1>(tiedot) << "\n";
	cout << "Tamanhetkinen nopeus: " << get<2>(tiedot) << "\n";
	cout << "Kuljettu matka: " << get<3>(tiedot) << "\n";

	*/

	return 0;
}