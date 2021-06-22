#include"Nag��wek.h"

void Menu::Admin(baza zbior,vector<Przedmiot*> &books,vector<User*> members)
{
	
	int option;
	cout << "\t\t Administracja"<<endl;
	cout << "\t\t Wybierz dzialanie"<<endl;
	cout << "1.Usun uzytkownika" << endl << "2.Zmien dane uzytkownika" << endl;
	cout << "3.Dodaj przedmiot" << endl << "4.Usun przedmiot" << endl << "5.Modyfikuj dane przedmiotu"<<endl;
	cout << "6.Wyjdz " << endl;
	cin >> option;
	switch (option)
	{
	case 1:
	{	int id;
		cout << "Podaj id uzytkownika do usuniecia"<<endl;
		cin >> id;
		Konto user;
		int dl = members.size();
		user.Delete(id,zbior, members);
		if (dl == members.size())
		{
			return;
		}
		else {
			cout << "Konto o id:" << id << " zostalo usuniete, nacisnij enter by wyjsc";
			if (cin.get())
			{
				return;
			}
		}
	}
	case 2:
	{					
		int id;
		User osoba;
		cout << "Podaj id uzydkownika ktorego chcesz zmienic dane" << endl;
		cin >> id;
		Konto user;
		for (auto i:members)
		{
			if (i->getID() == id)
			{
				osoba = *i;
				user.Modify(osoba, zbior, members);
				cout << "Zmiana dokonana,nowe dane";
				cout << osoba<<endl;
				cout << "Wcisnij enter by wyjsc";
				if (cin.get())
				{
					return;
				}

				
			}

		}
	}
	case 3:
	{	int o;										//ok
		cout << "Dodaj nowy przedmiot"<<endl;
		cout << "1.Ksiazka" << endl << "2.Gra" <<endl<< "3.DVD" << endl << "4.CD" << endl;
		cin>>o;
		if (o == 1)
		{
			Ksiazka nowa;
			nowa.Add(books);
		}
		if (o == 2)
		{
			//Gra nowa;
			//nowa.Add(books);
		}
		if (o == 3)
		{
			//DVD nowa;
			// nowa.Add(books);
		}
		if (o == 4)
		{
			//CD nowa;
			// nowa.Add(books);
		}
		return;
	}
	case 4:
	{   string s;													//ok
		cout << "Podaj id przedmiotu do usuniecia" << endl;
		cin >> s;
		for (auto i : books)
		{
			if (i->Id() == s)
			{
				if (i->Delete(s, books) == 1)
				{
					cout << "Przedmiot usuniety z bazy !" << endl;
				}
				cout << "Wcisnij enter by wyjsc";
				if (cin.get())
				{
					return;
				}
				
			}
		}
	}
	case 5:
	{	string s;		//ok
		cout << "Podaj id przedmiotu do modyfikacji" << endl;
		cin >> s;
		int bylo=0;
		Przedmiot* tmp=books[0];
		for (int i=0;i<books.size();i++)
		{
			if (books[i]->Id() == s&&books[i]->Available()==1)
			{
				tmp = books[i];
				books.erase(books.begin() + i);
				tmp->Modify(tmp);
				books.push_back(tmp);
				bylo = 1;
				break;
			}
		}
		if (bylo == 1)
		{
			cout << "Nowe dane przedmiotu" << endl;
			tmp->Show();
			cout << "Wcisnij enter by wyjsc";
			if (cin.get())
			{
				return;
			}
		}
		else
		{
			cout << "Przedmiot wypozyczony, poza baza niemozliwy do modyfikacji !"<<endl;
			cout << "Wcisnij enter by wyjsc";
			if (cin.get())
			{
				return;
			}
		}
		
		
		

	}
	case 6:
	{
		return;
	}
	}
}

User Menu::Login(vector<User*> members) //ok
{
	User zalogowany;
	string email, haslo;
	cout << "\t\t Zaloguj sie";
	cout << "Podaj email: ";
	cin >> email;
	while (zalogowany.CheckEmail(email, members) != false)
	{
		cout << "Taki email nie istnieje, podaj jeszcze raz" << endl;
		cin >> email;

	};
	zalogowany.setEmail(email);
	cout << endl << "Podaj haslo: ";
	cin >> haslo;
	while (zalogowany.CheckHaslo(haslo, email, members) == false)
	{
		cout << "Zle haslo.Podaj jeszcze raz" << endl;
		cin >> haslo;
	}
	zalogowany.setHaslo(haslo);
	for (auto i : members)
	{
		if (zalogowany.getEmail() == i->getEmail())
		{
			zalogowany.setID(i->getID());
			zalogowany.setName(i->getName());
		}
	}
	
	return zalogowany;
	
}

Konto Menu::Register(vector<User*> members, baza zbior)//ok
{
	Konto person;
	person=person.Add(zbior, members);
	cout << "Konto utowrzone !!" << endl;
	cout << "Wcisnij klawisz by przejsc dalej";
	if (cin.get())
	{
		return person;
	}
	return person;
}

void Menu::MyKonto(User person, vector< pair<User, vector<Przedmiot*>>>& issued,vector<Przedmiot*> &book)
{
	cout << "\t\t Twoje konto" << endl;
	cout << person;
	cout << endl << "--------------------------------" << endl;
	
	Konto k;
	k.MyBooks(person, issued);
	
	cout << "Czy chcesz oddac jakis przedmiot? T-tak N-nie" << endl;
	char s;
	cin >> s;
	if (s == 'T')
	{
		string id;
		cout << "Podaj id przedmiotu ktory chcesz oddac";
		cin >> id;
		Przedmiot* p = getPrzedmiot(id, book);
		k.Oddaj(&person, p, issued, book);
		cout << "Przedmiot oddany!!!" << endl;
		cout << "Wcisnij enter by wyjsc";
		if (cin.get())
		{
			return;
		}
	}
	if (s == 'N')
	{
		cout << "Wcisnij enter by wyjsc";
		if (cin.get())
		{
			return;
		}
	}
	return;
}

void Menu::Books(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*>& book)
{
	cout << "\t\t Ksiazki" << endl;
	cout << "1.Wyszukaj ksiazke" << endl<<"2.Pokaz moje ksiazki" << endl << "3.Wyjdz" << endl;
	int option;
	cin >> option;
	char k;
	string s;
	if (option == 1)
	{
		Searching szukanie;
		cout << "\t\t WYSZUKIWANIE" << endl;
		cout << "1.Po tytule 2.Po autorze 3.Po roku wydania 4.Po gatunku" << endl;
		cin >> option;
		if (option == 1)
		{
			szukanie.SearchByTitle('K', book);
			cout << "Chcesz wypozyczyc ksiazke T/N ?"<<endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Ksiazka wypozyczona"<<endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}
			

		}
		if (option== 2)
		{
			szukanie.SearchByAutor('K',book);
			cout << "Chcesz wypozyczyc ksiazke T/N ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Ksiazka wypozyczona" << endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}

		}
		if (option == 3)
		{
			szukanie.SearchByYear('K',book);
			cout << "Chcesz wypozyczyc ksiazke T/N ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Ksiazka wypozyczona" << endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}

		}
		if (option == 4)
		{
			szukanie.SearchByGenre('K',book);
			cout << "Chcesz wypozyczyc ksiazke T/N ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Ksiazka wypozyczona" << endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}

		}
	}
	if (option == 2)
	{
		Konto me;
		if (me.Books(person, issued) == 1)
		{
			cout << "Chcesz oddac jakas ksiazke (T/N) ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				cout << "Podaj id ksiazki: ";
				cin >> s;
				me.Oddaj(&person, getPrzedmiot(s, book), issued, book);
				cout << "Ksiazka oddana";
				cout << "Enter by wyjsc";
				if (cin.get())
					return;

			}
		}
		else
		{
			cout << "Brak wypozyczonych ksiazek\n";
			cout << "Enter by wyjsc";
			if (cin.get())
				return;
		}

	}
	if (option == 3)
	{
		return;
	}
	else
	{
		return;
	}

}

void Menu::Games(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*>& book)
{
	cout << "\t\t Gry" << endl;
	cout << "1.Wyszukaj gre" << endl << "2.Pokaz moje gry" << endl << "3.Wyjdz" << endl;
	int option;
	cin >> option;
	char k;
	string s;
	if (option == 1)
	{
		Searching szukanie;
		cout << "\t\t WYSZUKIWANIE" << endl;
		cout << "1.Po tytule 2.Po autorze 3.Po roku wydania" << endl;
		cin >> option;
		if (option == 1)
		{
			szukanie.SearchByTitle('G',book);
			cout << "Chcesz wypozyczyc gre T/N ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Gra wypozyczona" << endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}


		}
		if (option == 2)
		{
			szukanie.SearchByAutor('G',book);
			cout << "Chcesz wypozyczyc gre T/N ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Gra wypozyczona" << endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}

		}
		if (option == 3)
		{
			szukanie.SearchByYear('G',book);
			cout << "Chcesz wypozyczyc gre T/N ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				Konto me;
				cout << "Podaj jej id: ";
				cin >> s;
				me.Issue(&person, getPrzedmiot(s, book), issued, book);
				cout << "Gra wypozyczona" << endl;
				cout << "Enter by wyjsc";
				if (cin.get())
				{
					return;
				}

			}
			if (k == 'N')
			{
				return;
			}

		}
		
	}
	if (option == 2)
	{
		Konto me;
		if (me.Gry(person, issued) == 1)
		{
			cout << "Chcesz oddac jakas gre (T/N) ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				cout << "Podaj id gry: ";
				cin >> s;
				me.Oddaj(&person, getPrzedmiot(s, book), issued, book);
				cout << "Gra oddana";
				cout << "Enter by wyjsc";
				if (cin.get())
					return;

			}
		}
		else
		{
			cout << "Brak wypozyczonych gier\n";
			cout << "Enter by wyjsc";
			if (cin.get())
				return;
		}

	}
	if (option == 3)
	{
		return;
	}
	else
	{
		return;
	}

}

void Menu::Multimedia(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*> &book)
{
	cout << "\t\t Multimedia" << endl;
	cout << "1.Wyszukaj CD lub DVD" << endl << "2.Pokaz moje multimedia" << endl << "3.Wyjdz" << endl;
	int option;
	cin >> option;
	char k;
	string s;
	if (option == 1)
	{
		Searching szukanie;
		cout << "\t\t WYSZUKIWANIE" << endl;
		cout << "1.DVD 2.CD" << endl;
		cin >> option;
		if (option == 1)
		{
			cout << "\t\tDVD\n";
			cout << "1.Po tytule 2.Po autorze 3.Po roku wydania 4.Po gatunku" << endl;
			cin >> option;
			if (option == 1)
			{
				szukanie.SearchByTitle('D', book);
				cout << "Chcesz wypozyczyc multimedia T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczony" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}


			}

			if (option == 2)
			{
				szukanie.SearchByAutor('D', book);
				cout << "Chcesz wypozyczyc dvd T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczony" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}

			}
			if (option == 3)
			{
				szukanie.SearchByYear('D', book);
				cout << "Chcesz wypozyczyc przedmiot T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczony" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}

			}
			if (option == 4)
			{
				szukanie.SearchByGenre('D', book);
				cout << "Chcesz wypozyczyc multimedia T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczona" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}

			}
		}
		if (option == 2)
		{
			cout << "\t\tCD\n";
			cout << "1.Po tytule 2.Po autorze 3.Po roku wydania 4.Po gatunku" << endl;
			cin >> option;
			if (option == 1)
			{
				szukanie.SearchByTitle('C', book);
				cout << "Chcesz wypozyczyc multimedia T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczony" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}


			}

			if (option == 2)
			{
				szukanie.SearchByAutor('C', book);
				cout << "Chcesz wypozyczyc cd T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczony" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}

			}
			if (option == 3)
			{
				szukanie.SearchByYear('C', book);
				cout << "Chcesz wypozyczyc przedmiot T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczony" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}

			}
			if (option == 4)
			{
				szukanie.SearchByGenre('C', book);
				cout << "Chcesz wypozyczyc multimedia T/N ?" << endl;
				cin >> k;
				if (k == 'T')
				{
					Konto me;
					cout << "Podaj jej id: ";
					cin >> s;
					me.Issue(&person, getPrzedmiot(s, book), issued, book);
					cout << "Przedmiot wypozyczona" << endl;
					cout << "Enter by wyjsc";
					if (cin.get())
					{
						return;
					}

				}
				if (k == 'N')
				{
					return;
				}

			}
		}
	}
	if (option == 2)
	{
		Konto me;
		if (me.DVD(person, issued) == 1||me.CD(person,issued)==1)
		{
			cout << "Chcesz oddac jakis przedmiot (T/N) ?" << endl;
			cin >> k;
			if (k == 'T')
			{
				cout << "Podaj id : ";
				cin >> s;
				me.Oddaj(&person, getPrzedmiot(s, book), issued, book);
				cout << "Przedmiot oddany";
				cout << "Enter by wyjsc";
				if (cin.get())
					return;

			}
		}
		else
		{
			cout << "Brak wypozyczonych multimediow\n";
			cout << "Enter by wyjsc";
			if (cin.get())
				return;
		}

	}
	if (option == 3)
	{
		return;
	}
	else
	{
		return;
	}



}

void Menu::Search(vector<Przedmiot*> books)
{
	char z;
	cout << "\t\tWYSZUKIWANIE\n";
	cout << "1.Ksiazek\n" << "2.Gier\n" << "3.DVD\n"<<"4.CD\n";
	cin >> z;
	Searching szukac;
	if (z =='1')
	{
		cout << "1-Tytul,2-Autor,3-Rok,4-Gatunek" << endl;
		cin >> z;
		if (z == '1')
		{
			szukac.SearchByTitle('K',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '2')
		{
			szukac.SearchByAutor('K',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '3')
		{
			szukac.SearchByYear('K',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '4')
		{
			szukac.SearchByGenre('K',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
	}

	if (z == '2')
	{
		cout << "1-Tytul,2-Autor,3-Rok" << endl;
		cin >> z;
		if (z == '1')
		{
			szukac.SearchByTitle('G',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '2')
		{
			szukac.SearchByAutor('G',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '3')
		{
			szukac.SearchByYear('G',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		
	}

	if (z == '3')
	{
		cout << "1-Tytul,2-Autor,3-Rok,4-Gatunek" << endl;
		cin >> z;
		if (z == '1')
		{
			szukac.SearchByTitle('D',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '2')
		{
			szukac.SearchByAutor('D',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '3')
		{
			szukac.SearchByYear('D',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
		if (z == '4')
		{
			szukac.SearchByGenre('D',books);
			cout << "Wyjscie-enter";
			if (cin.get())
				return;
		}
	}
	if (z == 4)
	{
		if (z == '1')
		{
			cout << "1-Tytul,2-Autor,3-Rok,4-Gatunek" << endl;
			cin >> z;
			if (z == '1')
			{
				szukac.SearchByTitle('C', books);
				cout << "Wyjscie-enter";
				if (cin.get())
					return;
			}
			if (z == '2')
			{
				szukac.SearchByAutor('C', books);
				cout << "Wyjscie-enter";
				if (cin.get())
					return;
			}
			if (z == '3')
			{
				szukac.SearchByYear('C', books);
				cout << "Wyjscie-enter";
				if (cin.get())
					return;
			}
			if (z == '4')
			{
				szukac.SearchByGenre('C', books);
				cout << "Wyjscie-enter";
				if (cin.get())
					return;
			}
		}

	}
	else
	{
		return;
	}
}