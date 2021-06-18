#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
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
	virtual void Delete(vector<Przedmiot*>& lista) = 0;
	virtual void Modify(Przedmiot*& book) = 0;
	virtual void Show() = 0;

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
	void Delete(vector<Przedmiot*>& lista);
	void Modify(Przedmiot*& book);

	friend istream& operator>>(istream& s, Ksiazka &k);
	friend ostream& operator<<(ostream& s, Ksiazka &k);


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

	friend istream& operator>>(istream& s, User & u);
	friend ostream& operator<<(ostream& s, const User &u);
};

class Konto :public User
{
public:
	Konto(int id, string name, string email, string haslo) :User(id, name, email, haslo) {};
	Konto() :User(0, "", "", "") {};
	void MyBooks(User person, vector< pair<User, vector<Przedmiot*>>>& issued);
	void Issue(User *person, Przedmiot* book, vector< pair<User, vector<Przedmiot*>>>& issued, vector<Przedmiot*>&);
	//void Admin();
	void Modify(User& person, map<User, vector<Przedmiot*>>& issued, vector<User*>&);
	void Delete(User person, vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>&);
	void Add(vector< pair<User, vector<Przedmiot*>>>& issued, vector<User*>&);
};

int IdMaker(int);
int LastId(vector<User*>& users);