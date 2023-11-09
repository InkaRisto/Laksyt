#include <iostream>

using namespace std;

class Solmu {
public:
	int _data;
	Solmu* _next;
};

//Tulostaa kaikki listan arvot
void tulosta_lista(const Solmu* alku) {
	//while(alku) on sama kuin while(alku != nullptr)
	while (alku) {
		cout << alku->_data << "\n";
		alku = alku->_next;
	}
}

//Lisää uuden alkuun, palauttaa uusen alkukohdan
Solmu* lisaa_alkuun(Solmu* alku, int arvo) {
	Solmu* uusi = new Solmu;
	uusi->_data = arvo;
	uusi->_next = alku;
	return uusi;
	
}

//Deletoi kaikki listan solmut
void tuhoa_lista(Solmu* alku) {
	while (alku) {

	}
}

int main() {
	Solmu* s1 = new Solmu;
	Solmu* s2 = new Solmu;
	Solmu* s3 = new Solmu;
	Solmu* s4 = new Solmu;

	s1->_data = 3;
	s2->_data = 10;
	s3->_data = 2;
	s4->_data = 1; //Jos olisi olio itse eikä osoittaja; s4._data = 1;

	s1->_next = s2;
	s2->_next = s3;
	s3->_next = s4;
	s4->_next = nullptr; //tai 0;

	Solmu* head = s1;

	head = lisaa_alkuun(head, 115);
	head = lisaa_alkuun(head, 127);
	head = lisaa_alkuun(head, 132);

	tulosta_lista(head);

	return 0;
}