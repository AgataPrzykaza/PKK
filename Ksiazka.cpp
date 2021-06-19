#include"Nag³ówek.h"

Ksiazka::Ksiazka(string id, string title, string autor, int year, string genre, bool available)
	:Przedmiot(id, title, autor, year, available), genre(genre) {};


string Ksiazka::Genre()
{
	return genre;
}

void Ksiazka::Show() //ok
{
	cout << "Ksiazka - ";
	cout << this->Id() << ": " << " " << this->Title() << "  " <<" "<< this->Autor() <<" "<< endl;
	cout <<"\t" "Rok wydania: " << this->Year() << " Gatunek: " << genre<<" |";
	if (this->Available() == 1)
		cout << "Dostepna!" << endl;
	else
		cout << "Niedostepna!" << endl;
}
void Ksiazka::Add(vector<Przedmiot*>& lista)	//ok
{
	string title, autor, genre, id;
	int year;

	cout << "Podaj dane ksiazki " << endl;
	cout << "tytul: ";
	//cin >> title;
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
void Ksiazka::Modify(Przedmiot* &book)
{
	Ksiazka* k = dynamic_cast<Ksiazka*> (book);
	int option, l;
	string s;
	cout << "Zmienic: " << endl;
	cout << "1.Id " << endl << "2.Tytul" <<endl<< "3.Autor" << endl << "4.Rok wydania"
		<< endl << "5.Gatunek" << endl << "6.Dostepnosc"<<endl;
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
	{	string dod;
		cout << "Podaj nowy tytul ksiazki:"<<endl;
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
		cout << "Podaj nowego autora ksiazki:";
		cin >> s;
		while (s[s.size() - 1] != ',')
		{
			cin >> dod;
			s = s += " " + dod;
		}
		//getline(cin, s);
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

istream& operator>>(istream& s, Ksiazka& k)
{
	
	string id, title, autor, genre,dane;
	int year;
	bool available;

	s >> id;
	s >> title;
	while(title[title.size()-1]!='"')
	{	s >> dane;
		title = title +" "+dane;

	}
	s >> autor;
	/*while (autor[autor.size()- 1] != '"')
	{
		s >> dane;
		autor = autor +" "+dane;
	}*/
	s>> year >> genre >> available;
	k.setID(id); k.setTitle(title); k.setAutor(autor); k.setYear(year); k.genre = genre;
	k.setAvailable(available);
	return s;
}

ostream& operator<<(ostream& s, Ksiazka& k)
{
		s << k.Id() << " " << k.Title() << " " << k.Autor() << " " << k.Year() << " " <<
		k.Genre() << " " << k.Available();
	return s;
}