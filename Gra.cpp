#include"Nag��wek.h"
Gra::Gra(string id, string tytul, string autor, int rok, bool dostep)
	:Przedmiot(id, tytul, autor, rok, dostep) {};
void Gra::Show() //ok
{
	cout << "Gra - ";
	cout << this->Id() << ": " << " " << this->Title() << "  " << " " << this->Autor() << " " << endl;
	cout << "      Rok wydania: " << this->Year() << " |";
	if (this->Available() == 1)
		cout << "Dostepna!" << endl;
	else
		cout << "Niedostepna!" << endl;
}
void Gra::Add(vector<Przedmiot*>& lista)	//ok
{
	string title, autor, id;
	int year;

	cout << "Podaj dane gry " << endl;
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
	Przedmiot* book = new Gra(id, title, autor, year, 1);

	lista.push_back(book);
}

bool Gra::Delete(string bookId, vector<Przedmiot*>& lista) //ok
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
				cout << "Gra jest wypozyczona nie mozna usunac!!";
				return 0;

			}
			lista.erase(lista.begin() + i);
			return 1;
		}

	}
}
void Gra::Modify(Przedmiot*& book) 
{
	Gra* g = dynamic_cast<Gra*> (book);
	int option, l;
	string s;
	cout << "Zmienic: " << endl;
	cout << "1.Id " << endl << "2.Tytul" << endl << "3.Autor" << endl << "4.Rok wydania"
		<< endl << "5.Dostepnosc" << endl ;
	cin >> option;
	switch (option)
	{
	case 1:
	{	cout << "Podaj nowy ID gry:";
	cin >> s;
	g->setID(s);
	break;

	}
	case 2:
	{	string dod;
	cout << "Podaj nowy tytul gry:" << endl;
	cin >> s;
	while (s[s.size() - 1] != '"')
	{
		cin >> dod;
		s = s += " " + dod;
	}
	g->setTitle(s);
	break;
	}
	case 3:
	{	string dod;
	cout << "Podaj nowego autora gry:";
	cin >> s;
	/*while (s[s.size() - 1] != ',')
	{
		cin >> dod;
		s = s += " " + dod;
	}*/
	//getline(cin, s);
	g->setAutor(s);
	break;
	}
	case 4:
	{
		cout << "Podaj nowy rok wydania gry:";
		cin >> l;
		g->setYear(l);
		break;
	}

	case 5:
	{cout << "Ustaw dostepnosc gry: " << endl;
	cout << "1.Niedostepna" << endl << "2.Dostepna";
	cin >> l;
	g->setAvailable(l - 1);
	break;
	}
	default:
		break;
	}
	book = g;
}

istream& operator>>(istream& s, Gra& g) //ok
{

	string id, title, autor, dane;
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
	s >> year >> available;
	g.setID(id); g.setTitle(title); g.setAutor(autor); g.setYear(year); 
	g.setAvailable(available);
	return s;
}

ostream& operator<<(ostream& s, Gra& g)  //ok
{
	s << g.Id() << " " << g.Title() << " " <<g.Autor() << " " << g.Year()<<" " << g.Available();
	return s;
}
