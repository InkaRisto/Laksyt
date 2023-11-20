#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

class Viisari {
private:
	unsigned _arvo;

public:
	//Konstruktori; 0-alustus ei toiminut
	Viisari(unsigned int alustus_arvo) : _arvo(alustus_arvo)
	{}

	void Nayta() {
		printf("%02d", _arvo);
	}

	void Etene(bool tuntiviisari) {
		if (tuntiviisari) {
			_arvo = (_arvo + 1) % 24;
		}

		else {
			_arvo = (_arvo + 1) % 60;
		}
	}
};

class Kello
{
private:
	Viisari* tunnit;
	Viisari* minuutit;
	Viisari* sekunnit;
public:
	// luodaan ja alustetaan viisarit
	Kello(int h, int m, int s) {
		if(h < 24 && m,s < 60 && h,m,s >= 0){
		tunnit = new Viisari(h);
		minuutit = new Viisari(m);
		sekunnit = new Viisari(s);
		}
		else {
			tunnit = 00;
			minuutit = 00;
			sekunnit = 00;
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
		//Haluaisin lisätä tähän myös h,m,s 
		tunnit->Etene(true);
		minuutit->Etene(false);
		sekunnit->Etene(false);
	}
};

int main() {
	Kello rolex(14, 19, 60);
	while (1)
	{
		rolex.kay();
		rolex.nayta();
		std::this_thread::sleep_for(1000ms);// nukkuu yhden sekunnin
	}

	return 0;
}