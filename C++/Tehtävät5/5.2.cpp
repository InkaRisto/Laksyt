#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

class Viisari {
private:
	unsigned _arvo;
	int _max; //Kiertoon hyödyllinen
	Viisari* _seuraava;


public:
	//Konstruktori; 0-alustus ei toiminut
	Viisari(unsigned int alustus_arvo, int maximi, Viisari* seuraava = nullptr) : _arvo(alustus_arvo), _max(maximi), _seuraava(seuraava)
	{}

	void Nayta() {
		printf("%02d", _arvo);
	}

	void Etene() {			
		_arvo = (_arvo + 1) % _max;

		if(_seuraava){
			_seuraava->Etene();
		}
	}
};

//Tarkistetaan validi syöttö
int onValilla(int merkki, int a_raja, int y_raja) {
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
			tunnit = new Viisari(h, 24);
			minuutit = new Viisari(m, 60, tunnit);
			sekunnit = new Viisari(s, 60, minuutit);
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