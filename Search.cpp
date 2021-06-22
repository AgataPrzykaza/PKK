#include"Nag³ówek.h"


void Searching::SearchByTitle(vector<Przedmiot*> books)
{
	string s;
	cout << "Szunkanie po tytule" << endl;
	cout << "Podaj tytul w cudzyslowach: ";
	cin >> s;
	bool b = 0;
	for (auto i : books)
	{
		if (i->Title() == s)
		{
			i->Show();
			b = 1;
		}
	}
	if (b == 0)
	{
		cout << "Przkro nam nie ma takiego tytulu w bazie";
	}

}

void Searching::SearchByAutor(vector<Przedmiot*> books)
{
	string s;
	cout << "Szunkanie po autorze" << endl;
	cout << "Podaj autora: ";
	cin >> s;
	bool b = 0;
	for (auto i : books)
	{
		if (i->Autor() == s)
		{
			i->Show();
			b = 1;
		}
	}
	if (b == 0)
	{
		cout << "Przkro nam nie ma takiego autora w bazie";
	}
}

void Searching::SearchByYear(vector<Przedmiot*> books)
{
	int s;
	cout << "Szunkanie po roku wydania" << endl;
	cout << "Podaj rok: ";
	cin >> s;
	bool b = 0;
	for (auto i : books)
	{
		if (i->Year() == s)
		{
			i->Show();
			b = 1;
		}
	}
	if (b == 0)
	{
		cout << "Przkro nam nie ma takich przedmiotow w bazie";
	}
}

void Searching::SearchByGenre(vector<Przedmiot*> books)
{
	string s;
	cout << "Szunkanie po gatunku" << endl;
	cout << "Podaj gatunek: ";
	cin >> s;
	bool b = 0;
	Ksiazka* k;
	for (auto i : books)
	{
		k = dynamic_cast<Ksiazka*>(i);
		if (k->Genre() == s)
		{
			i->Show();
			b = 1;
		}
	}
	if (b == 0)
	{
		cout << "Przkro nam nie ma takiego gatunku w bazie";
	}
}