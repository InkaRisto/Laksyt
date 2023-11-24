#include <string>
#include <iostream>

using namespace std;

class Publication {
private:
	string _name;
	
public:
	Publication()
	{}

	Publication(const string& name) : _name(name)
	{}

	virtual void PrintInfo() const {
		cout << "Julkaisun ninmi: " << _name << endl;
	}

};

class Book : public Publication {
private:
	int _pages;
	string _author;

public:
	Book(const string& name, const string& author, int pages) : Publication(name)
	{
		_pages = pages;
		_author = author;
	}

	virtual void PrintInfo() const {
		Publication::PrintInfo();
		cout << "Kirjailija: " << _author << "\nSivuja: " << _pages << endl;

	}
};

class Magazine : public Publication {
private:
	string _editor;

public:
	Magazine(const string& name, const string& editor) : Publication(name) {
		_editor = editor;
	}

	void PrintInfo() const {
		Publication::PrintInfo();
		cout << "Paatoimittaja: " << _editor << endl;
	}
};

int main() {
	Magazine* pub1 = new Magazine("Aku Ankka", "Aki Hyyppa");
	Book* pub2 = new Book("Hytti n.o 6", "Rosa Likson", 200);

	pub1 -> PrintInfo();
	pub2 -> PrintInfo();

	delete pub1;
	delete pub2;

	return 0;
}