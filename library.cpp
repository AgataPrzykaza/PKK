#include "biblioteka.h"

Przedmiot::Przedmiot(string id, string title, string autor, int year, bool available)
	:id(id), title(title), autor(autor), year(year), available(available) {};
Przedmiot::Przedmiot()
	:id(""), title(""), autor(""), year(0), available(0) {};
string Przedmiot::Id()
{
	return id;
}

string Przedmiot::Title()
{
	return title;
}

string Przedmiot::Autor()
{
	return autor;
}

int Przedmiot::Year()
{
	return year;
}
bool Przedmiot::Available()
{
	return available;
}

Przedmiot& Przedmiot::setID(string id)
{
	this->id = id;
	return *this;
}
Przedmiot& Przedmiot::setTitle(string title)
{
	this->title =title;
	return *this;
}
Przedmiot& Przedmiot::setAutor(string autor)
{
	this->autor =autor;
	return *this;
}
Przedmiot& Przedmiot::setYear(int year)
{
	this->year = year;
	return *this;
}

Przedmiot& Przedmiot::setAvailable(bool available)
{
	this->available=available;
	return *this;
}

/***********BOOK*************************/

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
void Ksiazka::Add(vector<Przedmiot*> &lista)
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
	Przedmiot* book = new Ksiazka(id,title,autor,year,genre,1);

	lista.push_back(book);		
}

void Ksiazka::Delete(vector<Przedmiot*> &lista)
{   
	string id;
	cout << "Podaj id ksiazki do usuniecia ";
	cin >> id;
	for (int i = 0; i < lista.size(); i++)
	{
		if (lista[i]->Id() == id)
		{
			lista.erase(lista.begin()+i);
			break;
		}

	}
}
void Ksiazka::Modify(Przedmiot* &book)
{
	Ksiazka* k = dynamic_cast<Ksiazka*> (book);
	int option,l;
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
		cout << "Ustaw dostepnosc ksiazki: "<<endl;
		cout << "1.Niedostepna" << endl << "2.Dostepna";
		cin >> l;
		k->setAvailable(l - 1);
		break;

	}
	book = k;
}

istream& operator>>(istream& s, Przedmiot* &k)
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

ostream& operator<<(ostream& s, Przedmiot* &k)
{
	Ksiazka* book = dynamic_cast<Ksiazka*> (k);
	
	cout<< book->Id() <<" "<<book->Title() <<" "<< book->Autor() <<" "<< book->Year() <<" "<<
		book->Genre() <<" "<< book->Available();
	return s;
}
/***********USER*******************************************************************/
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
	for (int i = 0; i < lista.size(); i++)
	{
		if (email == lista[i]->getEmail())
			return false;                  //  email is  in the base
	}
	return true;							//email free, 
}

istream& operator>>(istream& s, User& u)
{
	cin >> u.IdUser >> u.name >> u.email >> u.haslo;
	return s;
}
ostream& operator<<(ostream& s, const User& u)
{
	cout << u.IdUser << " " << u.name << " " << u.email << " " << u.haslo;
	return s;
}

/***********KONTO****************************************************/
void Konto::MyBooks(User person, map<User, vector<Przedmiot*>> issued)
{
	cout << "Moje wypozyczone: " << endl;
	for (int i = 0; i < issued[person].size(); i++)
	{
		 issued[person][i]->Show();
	}
	
}
void Konto::Issue(User person,Przedmiot* book,map<User, vector<Przedmiot*>> &issued,vector<Przedmiot*> &books)
{
	issued[person].push_back(book);
	for (int i = 0; i < books.size(); i++)
	{
		if (book->Id() == books[i]->Id())
		{
			books[i]->setAvailable(0);
			break;
		}
	}

}
void Konto::Delete(User person, map<User, vector<Przedmiot*>> &issued, vector<User*> &users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getID() == person.getID() )
		{
			users.erase(users.begin() + i);
			break;
		}

	}
	issued.erase(person);
}
void Konto::Modify(User &person, map<User, vector<Przedmiot*>> &issued, vector<User*> &users)
{
	int option,id=0;
	string name, email, password;
	vector<Przedmiot*> tmp;
	tmp = issued[person];
	cout << "Modyfikacja konta,zmiana: ";
	cout << "1.Imienia i nazwiska" << endl << "2.Email'a" << endl << "3.Hasla" << endl << "4.IdUzytkownika" << endl;
	cin >> option;
	issued.erase(person);
	switch (option)
	{
	case 1:
	{
		cout << "Podaj nowe imie i nazwisko: ";
		cin >> name;
		person.setName(name);
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
		User buf = person;
		buf.setID(id);
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getID() == person.getID())
			{
				users.erase(users.begin() + i);
				break;
			}

		}
		users.push_back(&buf);
		break;
	}
	}
	
	issued[person] = tmp;

	if (id != 0)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getID() == person.getID())
			{
				users.erase(users.begin() + i);
				users.push_back(&person);
				break;
			}

		}
	}
}
void Konto::Add(map<User*, vector<Przedmiot*>>& issued, vector<User*>& users)
{
	int id;
	
	User*newUser=new User ;
	
	string name, email, haslo;
	cout << "Nowy uzytkownik" << endl << "Imie i nazwisko: ";
	cin >> name;
	cout << "Email: ";
	cin >> email;
	while (newUser->CheckEmail(email, users) == false)
	{
		cout << "Taki email juz istnieje, podaj jeszcze raz: ";
		cin >> email;
	}
	cout << endl<<"Haslo: ";
	cin >> haslo;
	int last=LastId(users);
	id = IdMaker(last);						// in one line ERRROR!
	newUser= new User(id, name, email, haslo);
	issued[newUser] = {};
	users.push_back(newUser);
	

}






int IdMaker(int &latest)
{
	return latest++;
}
int LastId(vector<User*>& users)
{
	int max=-1;
	for (int i = 0; i < users.size();i++)
	{
		if (users[i]->getID() > max)
			max = users[i]->getID();
	}
	return max;
}