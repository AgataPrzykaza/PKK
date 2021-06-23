#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<conio.h>

using namespace std;

class Przedmiot
{
private:
	string id;  //K23909-ksiazka;G8273982-gra
	bool available;
	string title;
	string autor;
	int year;

public:
	Przedmiot();
	Przedmiot(string id, string, string, int, bool available);

	string Title();
	string Autor();
	int Year();
	bool Available();
	string Id();

	Przedmiot& setTitle(string);
	Przedmiot& setAutor(string);
	Przedmiot& setID(string);
	Przedmiot& setAvailable(bool);
	Przedmiot& setYear(int);

	virtual void Add(vector<Przedmiot*>& lista) = 0;
	virtual bool Delete(string bookId,vector<Przedmiot*>& lista) = 0;
	virtual void Modify(Przedmiot*& book) = 0;
	virtual void Show() = 0;
	virtual string Gatunek() = 0;

	//virtual friend istream& operator>>(istream& s, Przedmiot* &k)=0;
	//virtual friend ostream& operator<<(ostream& s, Przedmiot* &k);

};
class Ksiazka : public Przedmiot
{
	string genre;

public:
	Ksiazka(string, string, string, int, string, bool);
	Ksiazka() :Przedmiot(), genre("h") {};
	string Genre();
	//Ksiazka& setGenre();
	void Show();
	void Add(vector<Przedmiot*>& lista);
	bool Delete(string bookId,vector<Przedmiot*>& lista);
	void Modify(Przedmiot* &book);
	string Gatunek();

	friend istream& operator>>(istream& s, Ksiazka &k);
	friend ostream& operator<<(ostream& s, Ksiazka &k);


};

class Gra : public Przedmiot
{
public:
	Gra(string, string, string, int, bool);
	Gra() :Przedmiot() {};

	
	void Show();
	void Add(vector<Przedmiot*>& lista);
	bool Delete(string bookId, vector<Przedmiot*>& lista);
	void Modify(Przedmiot*& book);
	string Gatunek() { return ""; };

	friend istream& operator>>(istream& s, Gra& g);
	friend ostream& operator<<(ostream& s, Gra& g);


};

class DVD : public Przedmiot
{
	string genre;

public:
	DVD(string, string, string, int, string, bool);
	DVD() :Przedmiot(), genre("h") {};
	string Genre();
	//Ksiazka& setGenre();
	void Show();
	void Add(vector<Przedmiot*>& lista);
	bool Delete(string bookId, vector<Przedmiot*>& lista);
	void Modify(Przedmiot*& book);
	string Gatunek();

	friend istream& operator>>(istream& s, DVD& d);
	friend ostream& operator<<(ostream& s, DVD& d);


};
class CD: public Przedmiot
{
	string genre;

public:
	CD(string, string, string, int, string, bool);
	CD() :Przedmiot(), genre("h") {};
	string Genre();
	//Ksiazka& setGenre();
	void Show();
	void Add(vector<Przedmiot*>& lista);
	bool Delete(string bookId, vector<Przedmiot*>& lista);
	void Modify(Przedmiot*& book);
	string Gatunek();

	friend istream& operator>>(istream& s, CD& d);
	friend ostream& operator<<(ostream& s, CD& d);


};
class User
{
private:
	int IdUser;
	string name, email, haslo;
public:
	//int UserId(string email,vector<User*> lista);
	User(int, string, string, string);
	User() :IdUser(0), name(""), email(""), haslo("") {};
	//void Wypozyczone(int id);
	//void ZmianaDanych();
	string getName();
	string getEmail();
	string getHaslo();
	int    getID();
	//void Delete(int id);
	//void Add();

	User& setName(string);
	User& setID(int);
	User& setEmail(string);
	User& setHaslo(string);

	//void CheckHaslo(string, string email);
	bool CheckEmail(string, vector<User*> lista);
	bool CheckHaslo(string haslo, string email, vector<User*> lista);
	
	friend istream& operator>>(istream& s, User & u);
	friend ostream& operator<<(ostream& s, const User &u);
};
typedef vector< pair<User, vector<Przedmiot*>>> baza;
class Konto :public User
{
public:
	Konto(int id, string name, string email, string haslo) :User(id, name, email, haslo) {};
	Konto() :User(0, "", "", "") {};
	bool MyBooks(User person, vector< pair<User, vector<Przedmiot*>>>& issued);
	void Issue(User *person, Przedmiot* book, vector< pair<User, vector<Przedmiot*>>> &issued, vector<Przedmiot*>&);
	//void Admin();
	void Modify(User& person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>&);
	void Delete(int person, baza& issued, vector<User*>&);
	User Add(vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>&);
	bool Oddaj(User* person,Przedmiot* p, baza& issued, vector<Przedmiot*>&);
	bool Books(User person, baza issued);
	bool Gry(User person, baza issued);
	bool DVD(User person, baza issued);
	bool CD(User person, baza issued);
	void Aktual(User& person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>& users);
};

class Menu
{
public:
	Menu() {};
	User Login(vector<User*> members);
	User Register(vector<User*> &members, baza &zbior);
	void Search(vector<Przedmiot*> books);
	void Admin(baza &zbior, vector<Przedmiot*> &books, vector<User*> &members);
	void MyKonto(User &person, vector< pair<User, vector<Przedmiot*>>>& issued,vector<Przedmiot*> &book,vector<User*> &members);
	void Books(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*>& book);
	void Games(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*>& book);
	void Multimedia(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*>& book);
};
class Searching
{
public:
	Searching() {};
	bool SearchByTitle(char,vector<Przedmiot*> books);
	bool SearchByAutor(char z,vector<Przedmiot*> books);
	bool SearchByYear(char z,vector<Przedmiot*> books);
	bool SearchByGenre(char z,vector<Przedmiot*> books);

};
int IdMaker(int);
int LastId(vector<User*>& users);
Przedmiot* getPrzedmiot(string id,vector<Przedmiot*> book);
//User Panel1(baza issued, vector<User*> members,vector<Przedmiot*> books);
//void Panel2(User u,baza& issued, vector<User*>& members, vector<Przedmiot*> books);
//void Program(baza& issued, vector<User*>& members, vector<Przedmiot*> book);
void PokaNowe(vector<Przedmiot*> books);