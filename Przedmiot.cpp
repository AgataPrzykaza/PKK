#include"Nag³ówek.h"

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
	this->title = title;
	return *this;
}
Przedmiot& Przedmiot::setAutor(string autor)
{
	this->autor = autor;
	return *this;
}
Przedmiot& Przedmiot::setYear(int year)
{
	this->year = year;
	return *this;
}

Przedmiot& Przedmiot::setAvailable(bool available)
{
	this->available = available;
	return *this;
}
