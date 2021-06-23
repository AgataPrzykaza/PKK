#include"Nag³ówek.h"


void Searching::SearchByTitle(char z,vector<Przedmiot*> books)
{
	string s;
	cout << "\t\tSzunkanie po tytule" << endl;
	cout << "Podaj tytul w cudzyslowach: ";
	cin >> s;
	bool b = 0;
	for (auto i : books)
	{
		if (i->Title() == s&& i->Available()==1&&z==i->Id()[0])
		{
			i->Show();
			b = 1;
		}
	}
	for (auto i : books)
	{
		if (i->Title() == s && i->Available() == 0 && z == i->Id()[0])
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

void Searching::SearchByAutor(char z,vector<Przedmiot*> books)
{
	string s;
	cout << "\t\tSzunkanie po autorze" << endl;
	cout << "Podaj autora: ";
	cin >> s;
	bool b = 0;
	for (auto i : books)
	{
		if (i->Autor() == s&& i->Available()==1 && z == i->Id()[0])
		{
			i->Show();
			b = 1;
		}
	}
	for (auto i : books)
	{
		if (i->Autor() == s && i->Available() == 0 && z == i->Id()[0])
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

void Searching::SearchByYear(char z,vector<Przedmiot*> books)
{
	int s;
	cout << "\t\tSzunkanie po roku wydania" << endl;
	cout << "Podaj rok: ";
	cin >> s;
	bool b = 0;
	for (auto i : books)
	{
		if (i->Year() == s&&i->Available()==1 && z == i->Id()[0])
		{
			i->Show();
			b = 1;
		}
	}
	for (auto i : books)
	{
		if (i->Year() == s && i->Available() == 0 && z == i->Id()[0])
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

void Searching::SearchByGenre(char z,vector<Przedmiot*> books)
{
	string s;
	cout << "\t\tSzunkanie po gatunku" << endl;
	cout << "Podaj gatunek: ";
	cin >> s;
	bool b = 0;
	Ksiazka* k;
	for (auto i : books)
	{
		k = dynamic_cast<Ksiazka*>(i);
		if (k->Genre() == s&&k->Available()==1 && z == i->Id()[0])
		{
			i->Show();
			b = 1;
		}
	}
	for (auto i : books)
	{
		k = dynamic_cast<Ksiazka*>(i);
		if (k->Genre() == s && k->Available() == 0 && z == i->Id()[0])
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