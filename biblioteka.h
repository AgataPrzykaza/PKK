#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
using namespace std;

/*struct rzecz
{
	string tytul;
	string autor;
	int rok;
	string gatunek;
};
*/


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

	virtual void Add(vector<Przedmiot*> &lista)=0;
	virtual void Delete(vector<Przedmiot*>& lista)=0;
	virtual void Modify(Przedmiot* &book)=0;
	virtual void Show()=0;

	//virtual friend istream& operator>>(istream& s, Przedmiot* &k);
	//virtual friend ostream& operator<<(ostream& s, Przedmiot* &k);

};


class Ksiazka : public Przedmiot
{
	string genre;

public:
	Ksiazka(string, string, string, int, string, bool);
	Ksiazka() :Przedmiot(),genre("") {};
	string Genre();
	//Ksiazka& setGenre();
	void Show();
	void Add(vector<Przedmiot*> &lista);
	void Delete(vector<Przedmiot*> &lista);
	void Modify(Przedmiot* &book);
	
	// friend istream& operator>>(istream& s, Przedmiot*  &k);
	 //friend ostream& operator<<(ostream& s, const Przedmiot* &k);

	
};
/*class CD :public Przedmiot
{
	string genre;
public:
	void Show();


	void Add();
	void Delete();
	void Modify();
	void Wypozycz();
	void Oddaj();
	friend istream& operator>>(istream& s, CD& cd);
	friend ostream& operator<<(ostream& s, const CD& cd);
};
*/
/*class Gry : public Przedmiot
{
public:
	void Show();


	void Add();
	void Delete();
	void Modify();
	friend istream& operator>>(istream& s, Gry& g);
	friend ostream& operator<<(ostream& s, const Gry& g);
};

class DVD_CD : public Przedmiot
{
	string genre;
public:
	void Show();
	void Add();
	void Delete();
	void Modify();

	friend istream& operator>>(istream& s, DVD_CD& g);
	friend ostream& operator<<(ostream& s, const DVD_CD& g);
};
*/
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

	friend istream& operator>>(istream& s, User& u);
	friend ostream& operator<<(ostream& s, const User& u);
};
class Konto :public User
{
public:
	Konto(int id, string name, string email, string haslo) :User(id, name, email, haslo) {};
	Konto() :User(0, "", "", "") {};
	void MyBooks(User person,map<User,vector<Przedmiot*>> issued);
	void Issue(User person, Przedmiot* book, map<User, vector<Przedmiot*>> &issued,vector<Przedmiot*> &);
	//void Admin();
	void Modify(User &person, map<User, vector<Przedmiot*>> &issued, vector<User*>&);
	void Delete(User person, map<User, vector<Przedmiot*>> &issued,vector<User*>&);
	void Add(map<User*, vector<Przedmiot*>> &issued, vector<User*>&);
};
/*class baza
{
	void UsunUzytkownika(int id);
	void DodajUzytkownia();
};
*/
/*class menu
{
public:
	void login();
	void rejestracja();
	void exitLogin();
	void exitMenu();
	void search();
};
*/
/*class Search
{
public:

	int SearchTitle(string);
	int SearchAutor(string);
	int SearchYear(int);
	int SearchGenre(string);
	void Show(list<Przedmiot*>);
	void ShowNew();
};
*/
int IdMaker(int&);
int LastId(vector<User*>& users);