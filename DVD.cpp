#include"Nag³ówek.h"

DVD::DVD(string id, string title, string autor, int year, string genre, bool dostepny)
	: Przedmiot(id, title, autor, year, dostepny), genre(genre) {};

string DVD::Genre()
{
	return genre;
}

void DVD::Show() //ok
{
	cout << "DVD - ";
	cout << this->Id() << ": " << " " << this->Title() << "  " << " " << this->Autor() << " " << endl;
	cout << "      Rok wydania: " << this->Year() << " Gatunek: " << genre << " |";
	if (this->Available() == 1)
		cout << "Dostepne!" << endl;
	else
		cout << "Niedostepne!" << endl;
}

void DVD::Add(vector<Przedmiot*>& lista)	//ok
{
	string title, autor, genre, id;
	int year;

	cout << "Podaj dane DVD " << endl;
	cout << "tytul, cudzyslowach: ";
	//cin >> title;
	getline(cin, title);
	getline(cin, title);
	cout << "autor: ";
	getline(cin, autor);
	//cin >> autor;
	cout << "id:";
	cin >> id;
	cout << "rok wydania: ";
	cin >> year;
	cout << "gatunek: ";
	cin >> genre;
	Przedmiot* book = new DVD(id, title, autor, year, genre, 1);

	lista.push_back(book);
}

bool DVD::Delete(string bookId, vector<Przedmiot*>& lista) //ok
{
	/*string id;
	cout << "Podaj id ksiazki do usuniecia ";
	cin >> id;*/

	for (int i = 0; i < lista.size(); i++)
	{

		if (lista[i]->Id() == bookId)
		{
			if (lista[i]->Available() == 0)
			{
				cout << "DVD jest wypozyczone nie mozna usunac!!";
				return 0;

			}
			lista.erase(lista.begin() + i);
			return 1;
		}

	}
}

void DVD::Modify(Przedmiot*& book)//ok 
{
	DVD* k = dynamic_cast<DVD*> (book);
	int option, l;
	string s;
	cout << "Zmienic: " << endl;
	cout << "1.Id " << endl << "2.Tytul" << endl << "3.Autor" << endl << "4.Rok wydania"
		<< endl << "5.Gatunek" << endl << "6.Dostepnosc" << endl;
	cin >> option;
	switch (option)
	{
	case 1:
	{	cout << "Podaj nowy ID DVD:";
	cin >> s;
	k->setID(s);
	break;

	}
	case 2:
	{	string dod;
	cout << "Podaj nowy tytul DVD:" << endl;
	cin >> s;
	while (s[s.size() - 1] != '"')
	{
		cin >> dod;
		s = s += " " + dod;
	}
	k->setTitle(s);
	break;
	}
	case 3:
	{	string dod;
	cout << "Podaj nowego autora DVD:";
	cin >> s;
	/*while (s[s.size() - 1] != ',')
	{
		cin >> dod;
		s = s += " " + dod;
	}*/
	//getline(cin, s);
	k->setAutor(s);
	break;
	}
	case 4:
	{
		cout << "Podaj nowy rok wydania DVD:";
		cin >> l;
		k->setYear(l);
		break;
	}
	case 5:
	{
		cout << "Podaj nowy gatunek DVD:";
		cin >> s;
		k->genre = s;
		break;
	}
	case 6:
	{cout << "Ustaw dostepnosc DVD: " << endl;
	cout << "1.Niedostepne" << endl << "2.Dostepne";
	cin >> l;
	k->setAvailable(l - 1);
	break;
	}
	default:
		break;
	}
	book = k;
}
string DVD::Gatunek()
{
	return genre;
}
istream& operator>>(istream& s, DVD& d)
{

	string id, title, autor, genre, dane;
	int year;
	bool available;

	s >> id;
	s >> title;
	while (title[title.size() - 1] != '"')
	{
		s >> dane;
		title = title + " " + dane;

	}
	s >> autor;
	/*while (autor[autor.size()- 1] != ',')
	{
		s >> dane;
		autor = autor +" "+dane;
	}*/
	s >> year >> genre >> available;
	d.setID(id); d.setTitle(title); d.setAutor(autor); d.setYear(year); d.genre = genre;
	d.setAvailable(available);
	return s;
}

ostream& operator<<(ostream& s, DVD& d)//ok
{
	s << d.Id() << " " << d.Title() << " " <<d.Autor() << " " << d.Year() << " " <<
		d.Genre() << " " << d.Available();
	return s;
}
