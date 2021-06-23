#include"Nag³ówek.h"

User::User(int id, string name, string email, string haslo)
	:IdUser(id), name(name), email(email), haslo(haslo) {};

int User::getID()
{
	return IdUser;
}
string User::getName()
{
	return name;
}
string User::getEmail()
{
	return email;
}
string User::getHaslo()
{
	return haslo;
}

User& User::setID(int id)
{
	this->IdUser = id;
	return *this;
}
User& User::setName(string name)
{
	this->name = name;
	return *this;
}
User& User::setEmail(string email)
{
	this->email = email;
	return *this;
}

User& User::setHaslo(string haslo)
{
	this->haslo = haslo;
	return *this;
}

bool User::CheckEmail(string email, vector<User*> lista)
{
	for (auto i:lista)
	{
		if (email == i->getEmail())
			return false;                  //  email is  in the base
	}
	return true;							//email free, 
}
bool User::CheckHaslo(string haslo,string email,vector<User*> lista)
{
	for (auto i : lista)
	{
		if (email == i->getEmail())
		{
			if (i->getHaslo() == haslo)
			{
				return true;
			}
		}
	}
	return false;
}
istream& operator>>(istream& s, User &u)
{	string tmp;
	s >> u.IdUser >>u.name>>tmp >> u.email >> u.haslo;
	u.name = u.name +" "+tmp;
	return s;
}
ostream& operator<<(ostream& s, const User& u)
{
	
	s << u.IdUser << " " << u.name << " " << u.email << " " << u.haslo;
	return s;
}



bool Konto::MyBooks(User person,vector< pair<User,vector<Przedmiot*>>> &issued) //ok
{
	
	cout << "\t\tMoje wypozyczone " << endl;
	

	for (auto i:issued)
	{
		if (i.first.getID() == person.getID())
		{   
			if (i.second.size() == 0)
			{
				cout << "Brak!";
				return 0;
			}
			for (auto l : i.second)
			{
				l->Show();
			}
			return 1;
		}
		
	}
	cout << "Brak!"<<endl;
	return 0;

}
void Konto::Issue(User* person, Przedmiot* book, vector< pair<User,vector<Przedmiot*>>> &issued, vector<Przedmiot*> &books) //ok
{
	
	vector<Przedmiot*> issue;
	pair<User, vector<Przedmiot*>> conection{*person,issue};
	char check='n';
	for (auto &l : issued)
	{
		if (l.first.getID() == person->getID())
		{	
			book->setAvailable(0);
			l.second.push_back(book);
			check = 'b';
			break;
		}
	}
	if (check == 'n')
	{
		book->setAvailable(0);
		conection.second.push_back(book);
		issued.push_back(conection);
	}
	for (auto &i:books)
	{
		if ((book->Id()) == (i->Id()))
		{
			i->setAvailable(0);
			break;
		}
	}

}

void Konto::Delete(int person, baza& issued, vector<User*>& users) //ok
{
	int cnt=0;										//error if for(int i=0;
	
	for (auto l : issued)
	{
		if (l.first.getID() == person)
		{			
			if (l.second.size() != 0)
			{
				cout << "Uzytkownik ma nie oddane ksiazki, nie mozna usunac !!!"<<endl;
				cout << "Wcisnij klawisz by wyjsc";
				if (cin.get())
				{
					return;
				}
				
			}
			issued.erase(issued.begin() + cnt);
		}
	}
		cnt = 0;
	for (auto i:users)
	{
		
		if (i->getID() == person)
		{
			users.erase(users.begin() + cnt);
			break;
		}
		cnt++;
	}

	
	

	
}
void Konto::Modify(User& person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>& users) //ok
{
	int option, id = 0;
	string name, email, password,surname;
	vector<Przedmiot*> tmp;
	
	cout << "Modyfikacja konta,zmiana: "<<endl;
	cout << "1.Imienia i nazwiska" << endl << "2.Email'a" << endl << "3.Hasla" << endl << "4.IdUzytkownika" << endl;
	cin >> option;
	
	switch (option)
	{
	case 1:
	{
		cout << "Podaj nowe imie i nazwisko: ";
		cin >> name;
		cin >> surname;
		person.setName(name+" "+surname);
		break;
	}
	case 2:
	{
		cout << "Podaj nowy email: ";
		cin >> email;
		person.setEmail(email);
		break;
	}
	case 3:
	{
		cout << "Podaj nowe haslo: ";
		cin >> password;
		person.setHaslo(password);
		break;
	}
	case 4:
	{
		cout << "Podaj nowe IdUzytkownika: ";
		cin >> id;
		int early = person.getID();
		for (auto &i:users)
		{
			if (i->getID() == early)
			{
				person.setID(id);
				i = &person;
				break;
			}
			
		}
		for (auto &i : issued) {
			if (i.first.getID() == early)
			{
				person.setID(id);
				i.first = person;
				break;
			}
		}

		break;
	}
	default:
		break;
	}

	
	if (id == 0)
	{
		for (auto &i: users)
		{
			if (i->getID() == person.getID())
			{
				i = &person;
				
				break;
			}
			
		}
		for (auto &i : issued)
		{
			if (i.first.getID() == person.getID())
			{
				i.first = person;
				break;
			}
		}
	}

}

User Konto::Add(vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>& users) //ok
{
	system("cls");
	int id;

	User* newUser = new User;

	string name,surname, email, haslo;
	cout << "\t\tNowy uzytkownik" << endl << "Imie i nazwisko: ";
	cin >> name>> surname;
	name = name + " " + surname;
	
	cout << "Email: ";
	cin >> email;
	while (newUser->CheckEmail(email, users) == false)
	{
		cout << "Taki email juz istnieje, podaj jeszcze raz: ";
		cin >> email;
	}
	cout << "Haslo: ";
	cin >> haslo;
	
	id = IdMaker(LastId(users));						
	newUser = new User(id, name, email, haslo);
	pair<User, vector<Przedmiot*>> para;
	vector<Przedmiot*> v = {};
	para = make_pair(*newUser, v);
	issued.push_back(para);
	users.push_back(newUser);

	Konto nowy(id, name, email, haslo);
	return *newUser;
}
bool Konto::Oddaj(User* person,Przedmiot*p, baza& issued, vector<Przedmiot*>& books) //ok
{
	for (auto& i : books)
	{
		if (p->Id() == i->Id())
		{
			i->setAvailable(1);
			break;
		}

	}
	for (auto& l : issued)
	{
		if (l.first.getID() == person->getID())
		{
			p->setAvailable(1);
			for (int m=0 ; m<l.second.size() ; m++)
			{
				if (l.second[m]->Id() == p->Id())
				{
					l.second.erase(l.second.begin() + m);
					return 1;
				}
			}
			
		}
	}
	return 0;

}

bool Konto::Books(User person, baza issued)
{
	cout << "\t\tMoje wypozyczone " << endl;

	for (auto i : issued)
	{
		if (i.first.getID() == person.getID())
		{
			if (i.second.size() == 0)
			{
				return 0;

			}
			for (auto l : i.second)
			{
				if (l->Id()[0] == 'K')
				{
					l->Show();
				}
				
			}
			return 1;
		}

	}
	
	return 0;
}

bool Konto::Gry(User person, baza issued)
{
	cout << "\t\tMoje wypozyczone " << endl;

	for (auto i : issued)
	{
		if (i.first.getID() == person.getID())
		{
			if (i.second.size() == 0)
			{
				return 0;

			}
			for (auto l : i.second)
			{
				if (l->Id()[0] == 'G')
				{
					l->Show();
				}

			}
			return 1;
		}

	}
	return 0;
}

bool Konto::DVD(User person, baza issued)
{
	cout << "\t\tMoje wypozyczone " << endl;

	for (auto i : issued)
	{
		if (i.first.getID() == person.getID())
		{
			if (i.second.size() == 0)
			{
				return 0;

			}
			for (auto l : i.second)
			{
				if (l->Id()[0] == 'D')
				{
					l->Show();
				}

			}
			return 1;
		}

	}
	return 0;
	
}

bool Konto::CD(User person, baza issued)
{
	cout << "\t\tMoje wypozyczone " << endl;
	
	for (auto i : issued)
	{
		if (i.first.getID() == person.getID())
		{
			if (i.second.size() == 0)
			{
				return 0;
				
			}
			for (auto l : i.second)
			{
				if (l->Id()[0] == 'C')
				{
					l->Show();
				}

			}
			return 1;
		}

	}
	return 0;
	
}


int IdMaker(int latest)
{
	return ++latest;
}
int LastId(vector<User*>& users)
{
	int max = -1;
	for (auto i:users)
	{
		if (i->getID() > max)
			max = i->getID();
	}
	return max;
}