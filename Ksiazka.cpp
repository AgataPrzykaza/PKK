#include"Nag��wek.h"

Ksiazka::Ksiazka(string id, string title, string autor, int year, string genre, bool available)
	:Przedmiot(id, title, autor, year, available), genre(genre) {};


string Ksiazka::Genre()
{
	return genre;
}

void Ksiazka::Show()
{
	cout << this->Id() << ": " << "' " << this->Title() << " ' " << this->Autor() << endl;
	cout << "Rok wydania: " << this->Year() << " Gatunek: " << genre << endl;
}
void Ksiazka::Add(vector<Przedmiot*>& lista)
{
	string title, autor, genre, id;
	int year;

	cout << "Podaj dane ksiazki " << endl;
	cout << "tytul: ";
	cin >> title;
	cout << "autor: ";
	cin >> autor;
	cout << "id:";
	cin >> id;
	cout << "rok wydania: ";
	cin >> year;
	cout << "gatunek: ";
	cin >> genre;
	Przedmiot* book = new Ksiazka(id, title, autor, year, genre, 1);

	lista.push_back(book);
}

void Ksiazka::Delete(vector<Przedmiot*>& lista)
{
	string id;
	cout << "Podaj id ksiazki do usuniecia ";
	cin >> id;
	for (int i = 0; i < lista.size(); i++)
	{
		if (lista[i]->Id() == id)
		{
			lista.erase(lista.begin() + i);
			break;
		}

	}
}
void Ksiazka::Modify(Przedmiot*& book)
{
	Ksiazka* k = dynamic_cast<Ksiazka*> (book);
	int option, l;
	string s;
	cout << "Zmienic: " << endl;
	cout << "1.Id " << endl << "2.Tytul" << "3.Autor" << endl << "4.Rok wydania"
		<< endl << "5.Gatunek" << endl << "6.Dostepnosc";
	cin >> option;
	switch (option)
	{
	case 1:
	{	cout << "Podaj nowy ID ksiazki:";
	cin >> s;
	k->setID(s);
	break;

	}
	case 2:
	{
		cout << "Podaj nowy tytul ksiazki:";
		cin >> s;
		k->setTitle(s);
		break;
	}
	case 3:
	{
		cout << "Podaj nowego autora ksiazki:";
		cin >> s;
		k->setAutor(s);
		break;
	}
	case 4:
	{
		cout << "Podaj nowy rok wydania ksiazki:";
		cin >> l;
		k->setYear(l);
		break;
	}
	case 5:
	{
		cout << "Podaj nowy gatunek ksiazki:";
		cin >> s;
		k->genre = s;
		break;
	}
	case 6:
		cout << "Ustaw dostepnosc ksiazki: " << endl;
		cout << "1.Niedostepna" << endl << "2.Dostepna";
		cin >> l;
		k->setAvailable(l - 1);
		break;

	}
	book = k;
}

istream& operator>>(istream& s, Przedmiot*& k)
{
	Ksiazka* book = dynamic_cast<Ksiazka*> (k);
	string id, title, autor, genre;
	int year;
	bool available;
	cin >> id >> title >> autor >> year >> genre >> available;
	book->setID(id); book->setTitle(title); book->setAutor(autor); book->setYear(year);
	book->setAvailable(available);
	return s;
}

ostream& operator<<(ostream& s, Przedmiot*& k)
{
	Ksiazka* book = dynamic_cast<Ksiazka*> (k);

	cout << book->Id() << " " << book->Title() << " " << book->Autor() << " " << book->Year() << " " <<
		book->Genre() << " " << book->Available();
	return s;
}