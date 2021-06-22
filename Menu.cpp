#include"Nag³ówek.h"

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

void Menu::MyKonto(User person, vector< pair<User, vector<Przedmiot*>>>& issued)
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
		////oddac;
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