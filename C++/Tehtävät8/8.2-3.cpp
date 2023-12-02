#include <vector>
#include <string>

using namespace std;

//Pelaajahahmo
class Hahmo {
private:
	string _nimi;
	int _level;
	int _hp;
	int _gold;

public:
	Hahmo()
	{}

	Hahmo(const string& nimi, int level, int hp, int gold) : _nimi(nimi), _level(level), _hp(hp), _gold(gold)
	{}
};

class Vihollistyyppi {
public:
	int _alku_hp;
	int _alku_hyokvoima;
	int _alku_puolvoima;

	Vihollistyyppi(int hp, int atk, int def) : _alku_hp(hp), _alku_hyokvoima(atk), _alku_puolvoima(def)
	{}
};

class Vihollinen {
private:
	Vihollistyyppi _tyyppi;
	int _hp;

public:
	Vihollinen(Vihollistyyppi tyyppi, int hp) : _tyyppi(tyyppi), _hp(hp)
	{}
};

class Objekti {
private:
	string _nimi;
	Hahmo* _omistaja;

public:
	Objekti(const string& nimi, Hahmo* hahmo) : _nimi(nimi), _omistaja(hahmo)
	{}

};

class Taisteluvaruste : public Objekti {
private:
	int _hyokvoima;
	int _puolvoima;

public:
	Taisteluvaruste(const string& nimi, Hahmo* omistaja, int atk, int def) : Objekti(nimi, omistaja), _hyokvoima(atk), _puolvoima(def)
	{}
};

class MuuObjekti : public Objekti {
private:
	int _vaikutus_hp;
	int _vaikutus_gold;

public:
	MuuObjekti(const string& nimi, Hahmo* omistaja, int buff_hp, int buff_gold) : Objekti(nimi, omistaja), _vaikutus_hp(buff_hp), _vaikutus_gold(buff_gold)
	{}
};

//Maastotyyppi
class Maasto {
public: 
	float _liikvaikeus;
	float _taistvaikeus;

	Maasto()
	{}

	Maasto(float lvaikeus, float tvaikeus) : _liikvaikeus(lvaikeus), _taistvaikeus(tvaikeus)
	{}
};

//Maastoruutu
class Tile {
public:
	Maasto _maastotyyppi;
	int _x;
	int _y;
	Hahmo* _pelaaja;
	vector<Objekti> _objektit; //0...*
	vector<Vihollinen> _vihut; //0...*

	Tile() 
	{}
};

//Karttapohja
class Kartta {
public:
	static vector<Tile> _tilet;

	void KokoaKartta(unsigned rivit, unsigned sarakkeet, const string& pohja) {
		unsigned riveja = rivit;
		unsigned sarakkeita = sarakkeet;
		string karttapohja = pohja;
		int y = 0;
		Maasto tie, metsa, vuoristo;

		for (char t : karttapohja) {
			for (int i = 0; i < sarakkeita; i++) {
				char tunnus = karttapohja[i];

				//Tallennettavat tiedot per tile
				Maasto maasto;
				int x = i;				
				Hahmo* pelaaja = nullptr;


				switch (tunnus) {
				case 'T':
					maasto = tie;
					break;
				case 'V':
					maasto = vuoristo;
					break;
				case 'M':
					maasto = metsa;
					break;
				}

				Tile tile;
				tile._maastotyyppi = maasto;
				tile._pelaaja = pelaaja;
				tile._x = x;
				tile._y = y;

				_tilet.push_back(tile);
				
			}
			y++;
			if (y < riveja) {
				//Pitää saada toistamaan yllä oleva for-loop [saraketta] symboolista eteenpäin
				KokoaKartta(rivit, sarakkeet, pohja);
			}
		}

	}
};

int main() {
	Maasto tie(0, 10);
	Maasto metsa(10, 8);
	Maasto vuoristo(20, 15);
	vector<Tile> tilet = Kartta::_tilet;

	Kartta kartta;
	kartta.KokoaKartta(3, 4, "TTTTVVTMVMTM");

	Hahmo hilfred("Hilfred", 1, 70, 0);

	Hahmo* pelaaja = new Hahmo(hilfred);
	tilet[0]._pelaaja = pelaaja;

	Vihollistyyppi orkki(20, 5, 5);
	Vihollinen orkki1(orkki, orkki._alku_hp);
	Vihollinen orkki2(orkki, orkki._alku_hp);
		
	tilet[7]._vihut.push_back(orkki1);
	tilet[6]._vihut.push_back(orkki2);

	Vihollistyyppi peikko(50, 15, 10);
	Vihollinen peikko1(peikko, peikko._alku_hp);

	tilet[5]._vihut.push_back(peikko1);

	Taisteluvaruste miekka("miekka", pelaaja, 12, 4);

	MuuObjekti sormus("sormus", nullptr, 15, 5);
	MuuObjekti rohto("rohto", nullptr, 25, 0);
	Taisteluvaruste haarniska("haarniska", nullptr, 0, 12);

	tilet[6]._objektit.push_back(sormus);
	tilet[10]._objektit.push_back(rohto);
	tilet[4]._objektit.push_back(haarniska);

	return 0;
}