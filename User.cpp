#include"Nag��wek.h"

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

istream& operator>>(istream& s, User &u)
{
	s >> u.IdUser >> u.name >> u.email >> u.haslo;
	return s;
}
ostream& operator<<(ostream& s, const User& u)
{
	s << u.IdUser << " " << u.name << " " << u.email << " " << u.haslo;
	return s;
}



void Konto::MyBooks(User person,vector< pair<User,vector<Przedmiot*>>> &issued)
{
	
	cout << "Moje wypozyczone: " << endl;
	
	for (auto i:issued)
	{
		if (i.first.getID() == person.getID())
		{
			for (auto l : i.second)
			{
				l->Show();
			}
		}
		
	}

}
void Konto::Issue(User* person, Przedmiot* book, vector< pair<User,vector<Przedmiot*>>> &issued, vector<Przedmiot*>& books)
{
	for (auto l : issued)
	{
		if (l.first.getID() == person->getID())
		{
			l.second.push_back(book);
		}
	}
	
	for (auto i:books)
	{
		if ((book->Id()) == (i->Id()))
		{
			i->setAvailable(0);
			break;
		}
	}

}

void Konto::Delete(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>& users)
{
	int cnt=0;										//error if for(int i=0;
	for (auto i:users)
	{
		
		if (i->getID() == person.getID())
		{
			users.erase(users.begin() + cnt);
			break;
		}
		cnt++;
	}
	cnt = 0;
	for (auto l : issued)
	{
		if (l.first.getID() == person.getID())
		{
			issued.erase(issued.begin() + cnt);
		}
	}

	
}
//void Konto::Modify(User& person, map<User, vector<Przedmiot*>>& issued, vector<User*>& users)
//{
//	int option, id = 0;
//	string name, email, password;
//	vector<Przedmiot*> tmp;
//	tmp = issued[person];
//	cout << "Modyfikacja konta,zmiana: ";
//	cout << "1.Imienia i nazwiska" << endl << "2.Email'a" << endl << "3.Hasla" << endl << "4.IdUzytkownika" << endl;
//	cin >> option;
//	issued.erase(person);
//	switch (option)
//	{
//	case 1:
//	{
//		cout << "Podaj nowe imie i nazwisko: ";
//		cin >> name;
//		person.setName(name);
//		break;
//	}
//	case 2:
//	{
//		cout << "Podaj nowy email: ";
//		cin >> email;
//		person.setEmail(email);
//		break;
//	}
//	case 3:
//	{
//		cout << "Podaj nowe haslo: ";
//		cin >> password;
//		person.setHaslo(password);
//		break;
//	}
//	case 4:
//	{
//		cout << "Podaj nowe IdUzytkownika: ";
//		cin >> id;
//		User buf = person;
//		buf.setID(id);
//		int cnt = 0;
//		for (auto i:users)
//		{
//			if (i->getID() == person.getID())
//			{
//				users.erase(users.begin() + cnt);
//				break;
//			}
//			cnt++;
//		}
//		users.push_back(&buf);
//		break;
//	}
//	}
//
//	issued[person] = tmp;
//	int cnt = 0;
//	if (id != 0)
//	{
//		for (auto i: users)
//		{
//			if (i->getID() == person.getID())
//			{
//				users.erase(users.begin() + cnt);
//				users.push_back(&person);
//				break;
//			}
//			cnt++;
//		}
//	}
//}

void Konto::Add(vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>& users)
{
	int id;

	User* newUser = new User;

	string name,surname, email, haslo;
	cout << "Nowy uzytkownik" << endl << "Imie i nazwisko: ";
	cin >> name;
	
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

	
}
int IdMaker(int latest)
{
	return latest++;
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