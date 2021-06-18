
#include <iostream>
#include<fstream>
#include<sstream>

#include"Nagłówek.h"
using namespace std;
typedef vector< pair<User, vector<Przedmiot*>>> baza;
vector<User*> PeopleGet(const string& fileName);
void PeopleSave(const string& exitFile, vector<User*> users);
void PrzedmiotSave(const string& exitFile, vector<Przedmiot*>books);
void PokaNowe(vector<Przedmiot*> books)
{
    string s;
    for (int i = books.size()-1;i>books.size()-7; i--)
    {
       
        if (s.find("K") != string::npos)
        {
            Ksiazka k = *(dynamic_cast<Ksiazka*>  (books[i]));

            cout << k;
        }
        else
        {
            /*if (s.find("G") != string::npos)
            {
                  Gra g=books[i];
                  cout<<g;

            }*/
            /*if (s.find("C") != string::npos || s.find("D")!=string::npos)
            {
                  DVD_CD d=*(dynamic_cast<DVD_CD*>  (books[i]));
                  cout<<d;

            }*/
        }
    }
}
void PrzedmiotPeopleSave(baza zbior, const string& exitFile);
vector<Przedmiot*> PrzedmiotGet(const string& fileName);
baza PrzedmiotPeopleGet(const string& fileName);

int main()
{
	
    vector<User*> u= PeopleGet("users.txt");
    /*for (int i=0;i<u.size();i++)
    {
        cout << *u[i]<<endl;
    }

    PeopleSave("save.txt", u);
    
    Ksiazka o("K0909", "ws", "qs", 2, "kol", 1);
    Przedmiot* k = new Ksiazka;
    *k = o;
    ksiaz.push_back(k);

    Ksiazka op("K77777", "ws", "qs", 2, "kol", 1);
    Przedmiot* kp = &op;
    ksiaz.push_back(kp);

    
    pair<User, vector<Przedmiot*>> p{*u[0],ksiaz};
    ksiaz.push_back(k);
    pair<User, vector<Przedmiot*>> l{ *u[1],ksiaz };
    
    PrzedmiotSave("save.txt", ksiaz);
    
    zbior.push_back(p);
    zbior.push_back(l);*/

    baza zbior;
    vector<Przedmiot*> ksiaz;
    ksiaz = PrzedmiotGet("przedmioty.txt");
    /*pair<User, vector<Przedmiot*>> lp{ *u[1],ksiaz };
    zbior.push_back(lp);

    PrzedmiotPeopleSave(zbior, "save.txt");*/

    zbior = PrzedmiotPeopleGet("save.txt");

    Ksiazka k;
    k.Add(ksiaz);

    ksiaz[ksiaz.size() - 1]->Show();

    //GETLINE W NAME !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    /*PrzedmiotPeopleSave(zbior, "test.txt");*/
}

vector<User*> PeopleGet(const string& fileName)  // read people file
{
    vector<User*> users;

    ifstream plik(fileName);
    
    string s;

    
   
    if (plik.good())
    {

        while (getline(plik, s))
        {   User* u=new User;
            stringstream ss(s);   
            ss >> *u;
            users.push_back(u);
            
        }
    }
    
    plik.close();

    return users;

}
void PeopleSave(const string& exitFile, vector<User*> users)// save people file
{
    ofstream plik(exitFile);
    for (int i=0;i<users.size();i++)
    {   
        plik << *users[i] << endl;
    }


    plik.close();
}
void PrzedmiotSave(const string& exitFile, vector<Przedmiot*>books)// save przedmiot file
{
    ofstream plik(exitFile);
    for (int i=0;i<books.size();i++)
    {
        Ksiazka k=*(dynamic_cast<Ksiazka*>  (books[i]));
        
        plik << k;

    }
    plik.close();
}
void PrzedmiotPeopleSave(baza zbior, const string& exitFile) // save to base people-issued
{
    ofstream plik(exitFile);
    string s;
    for (int i = 0; i < zbior.size(); i++)
    {
        plik << zbior[i].first <<endl;
        for (int l = 0; l < zbior[i].second.size(); l++)
        {
            s = zbior[i].second[l]->Id();
            if (s.find("K") != string::npos)
            {
                Ksiazka k = *(dynamic_cast<Ksiazka*>  (zbior[i].second[l]));

                plik << k<<endl;
            }
            else
            {
                /*if (s.find("G") != string::npos)
                {   
                      Gra g=zbior[i].second[l];
                      plik<<g;

                }*/
                /*if (s.find("C") != string::npos || s.find("D")!=string::npos)
                {
                      DVD_CD d=zbior[i].second[l];
                      plik<<d;

                }*/
            }

        }
    }
    plik.close();
}


vector<Przedmiot*> PrzedmiotGet(const string& fileName) // read from przedmiot file
{
    fstream plik(fileName);

    string s;
    string z;
    vector<Przedmiot*> zbior{};

    if (plik.good())
    {

        while (getline(plik, s))
        {
            
            stringstream ss(s);
            stringstream ss1(s);

            ss >> z;
            
            if (z[0] == 'K')
            {   
               
                Ksiazka* k = new Ksiazka;
                stringstream ss(s);
                ss1 >>*k;
                zbior.push_back(k);           
                
            }
            else
            {
                /*if (z[0]=='G')
                {
                     Gra* g = new Gra;
                    stringstream ss(s);
                ss1 >>*g;
                zbior.push_back(g);   

                }*/
                /*if (z[0]=='C'||z[0]=='D')
                {
                    DVD_CD* d = new DVD_CD;
                stringstream ss(s);
                ss1 >>*d;
                zbior.push_back(d);   

                }*/
            }


        }
    }

    plik.close();
    return zbior;

}

baza PrzedmiotPeopleGet(const string& exitFile)
{
    ifstream plik(exitFile);
    string s;
    string z;
    vector<Przedmiot*> zbior{};
    User man;
    baza tabela;
    if (plik.good())
    {
        getline(plik, s);
        stringstream person(s);
        person >> man;
        while (getline(plik, s))
        {

            stringstream ss(s);
            stringstream ss1(s);

            ss >> z;
            
            if (z[0] == 'K' || z[0] == 'G' || z[0] == 'D' || z[0] == 'C')
            {


                if (z[0]=='K')
                {

                    Ksiazka* k = new Ksiazka;
                    stringstream ss(s);
                    ss1 >> *k;
                    zbior.push_back(k);

                }
                else
                {
                    /*if (z[0]=='G')
                    {
                         Gra* g = new Gra;
                        stringstream ss(s);
                    ss1 >>*g;
                    zbior.push_back(g);

                    }*/
                    /*if (z[0]=='C' || z[0]=='D')
                    {
                        DVD_CD* d = new DVD_CD;
                    stringstream ss(s);
                    ss1 >>*d;
                    zbior.push_back(d);

                    }*/
                }
            }
            else {
                
                tabela.push_back({ man,zbior });
                zbior={};
                ss1 >> man;
                

            }

        }
        tabela.push_back({ man,zbior });

    }
    plik.close();

    return tabela;


}
