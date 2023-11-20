#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

class Viisari {
private:
	unsigned _arvo;
	Viisari* _seuraava;

public:
	//Konstruktori; 0-alustus ei toiminut
	Viisari(unsigned int alustus_arvo, Viisari* seuraava = nullptr) : _arvo(alustus_arvo), _seuraava(seuraava)
	{}

	void Nayta() {
		printf("%02d", _arvo);
	}

	void Etene() {
		if(_seuraava){
			_arvo = (_arvo + 1) % 60;
			_seuraava->Etene();
		}
		
		else {
			_arvo = (_arvo + 1) % 24;
		}
	}
};

//Tarkistetaan validi syöttö
int onValilla(int merkki, unsigned a_raja, unsigned y_raja) {
	if (merkki >= a_raja && merkki <= y_raja) {
		return 1;
	}
	return 0;
}

class Kello
{
private:
	Viisari* tunnit;
	Viisari* minuutit;
	Viisari* sekunnit;
public:
	// luodaan ja alustetaan viisarit sekä niiden seuraajat
	Kello(int h, int m, int s) {
		if (onValilla(h, 0, 23) && onValilla(m, 0, 59) && onValilla(s, 0, 59)) {
			tunnit = new Viisari(h);
			minuutit = new Viisari(m, tunnit);
			sekunnit = new Viisari(s, minuutit);
		}
		else {
			tunnit = nullptr;
			minuutit = nullptr;
			sekunnit = nullptr;
			cout << "Virheellinen aika";
		}
	}

	//puretaan viisarit
	~Kello() {
		delete tunnit;
		delete minuutit;
		delete sekunnit;
	}

	void nayta() {
		tunnit->Nayta();
		cout << ":";
		minuutit->Nayta();
		cout << ":";
		sekunnit->Nayta();
		cout << "\n";
	}
	void kay() {
		//Eteneminen sekunneista lähtien
		sekunnit->Etene();
	}
};

int main() {
	Kello rolex(22,45,51);
	while (1)
	{
		rolex.kay();
		rolex.nayta();
		std::this_thread::sleep_for(1000ms);// nukkuu yhden sekunnin
	}

	return 0;
}