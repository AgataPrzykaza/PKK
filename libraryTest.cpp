
#include <iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<Windows.h>
#include"Nagłówek.h"

using namespace std;

typedef vector< pair<User, vector<Przedmiot*>>> baza;

vector<User*> PeopleGet(const string& fileName);
void PeopleSave(const string& exitFile, vector<User*> users);
void PrzedmiotSave(const string& exitFile, vector<Przedmiot*>books);
void PokaNowe(vector<Przedmiot*> books)
{
    system("cls");
    cout << "\t\tNowo dodane!!\n";
    string s;
    for (int i = books.size()-1;i>books.size()-7; i--)
    {
       
        books[i]->Show();
    }
}
void PrzedmiotPeopleSave(baza zbior, const string& exitFile);
vector<Przedmiot*> PrzedmiotGet(const string& fileName);
baza PrzedmiotPeopleGet(const string& fileName);
void Panel2(User u, baza& issued, vector<User*>& members, vector<Przedmiot*> book);

User Panel1(baza& issued, vector<User*>& members, vector<Przedmiot*> books)
{
    system("cls");
    Menu ja;
    cout << "\t\t BIBLIOTEKA\n";
    cout << "1.Zaloguj sie\n";
    cout << "2.Zarejestruj sie\n";
    cout << "3.Wyszukiwanie(tylko do wyswietlenia)\n";
    int o;
    cin >> o;
    if (o == 1)
    {
        return ja.Login(members);

    }
    if (o == 2)
    {
        return ja.Register(members, issued);
    }
    if (o == 3)
    {
        ja.Search(books);
        User u(0, "", "", "");
        return u;
    }
    else
    {
        cout << " :( Nie ma takiej opcji\n";
        User u(0, "", "", "");
        return u;
    }

}

//baza Relacje(const string& fileName)
//{
//    ifstream plik(fileName);
//
//    string s;
//    string id;
//    baza zbior;
//
//
//    if (plik.good())
//    {
//
//        while (getline(plik, s))
//        {
//            
//            stringstream ss(s);
//            ss >> id;
//
//            if()
//           
//
//        }
//    }
//
//    plik.close();
//
//}

int main()
{
    baza zbior;
    vector<Przedmiot*> ksiaz=PrzedmiotGet("przedmioty.txt");
    vector<User*> u = PeopleGet("users.txt");
    //User j(91, "kot na plot", "ko@.pl", "ko");
    //pair<User, vector<Przedmiot*>> cos{ *u[0],{ksiaz[0],ksiaz[2]} };
    //pair<User, vector<Przedmiot*>> cos2{ *u[1],{ksiaz[1],ksiaz[3]} };
   /* zbior.push_back(cos);
    zbior.push_back(cos2);
    Konto ja;
    ja.Issue(u[4], ksiaz[3], zbior, ksiaz);
    ja.MyBooks(*u[4], zbior);
    ja.Modify(*u[4], zbior, u);
    cout << *u[4];
    cout << zbior[zbior.size() - 1].first;*/

   zbior = PrzedmiotPeopleGet("save.txt");
   

    User kolo = Panel1(zbior,u, ksiaz);
    Panel2(kolo, zbior, u, ksiaz);
    PrzedmiotPeopleSave(zbior, "save.txt");
    PrzedmiotSave("przedmioty.txt", ksiaz);
    PeopleSave("users.txt", u);
   
   
   //Program(zbior, u, ksiaz);
   //Panel1(zbior,u);
  // system("cls");

  // PrzedmiotSave("book.txt", ksiaz);
   /*Konto ja;
   ja.Oddaj(u[1], ksiaz[3], zbior, ksiaz);
   cout << zbior[1].second.size();
   ;*/

  /*  DVD d;
    d.Add(ksiaz);
    ksiaz[ksiaz.size() - 1]->Show();
   Przedmiot* nowy=ksiaz[ksiaz.size() - 1];
   cout << *dynamic_cast<DVD*>(nowy);*/
   // ksiaz[ksiaz.size() - 1]->Show();
    ///*Ksiazka k;
    //k.Add(ksiaz);*/

    //User n = zbior[0].first;
    //Menu m;
    //m.MyKonto(n, zbior);
   //Panel2(kolo, zbior, u, ksiaz);
   /* PeopleSave("users.txt", u);
    PrzedmiotSave("book.txt", ksiaz);
    PrzedmiotPeopleSave(zbior, "buff.txt");*/
    //PrzedmiotSave("buff.txt", ksiaz);
    //PrzedmiotPeopleSave(zbior, "buff2.txt");
    //zbior= PrzedmiotPeopleGet("save.txt");
    //ksiaz = PrzedmiotGet("przedmioty.txt");
   // pair<User, vector<Przedmiot*>> p{*u[0],ksiaz};
    
    //zbior.push_back(p);
    
    
   // PrzedmiotPeopleSave(zbior, "save.txt");

    
}

void Panel2(User u,baza& issued, vector<User*>& members, vector<Przedmiot*> book)
{
    int o;
    Menu m;
    system("cls");
    cout << "\t\t ZALOGOWANY\n";
    cout << "1.Ksiazki\n2.Gry\n3.Multimedia\n4.Administracja\n5.Moje Konto\n";
    cout << "6.Wyjdz";
    cin >> o;
    if (o == 1)
    {
        m.Books(u, issued, book);
        cout << endl << "enter-wyjscie";
        if(cin.get())
        Panel2(u,issued, members, book);
    }
    if (o == 2)
    {
        m.Games(u, issued, book);
        cout << endl << "enter-wyjscie";
        if (cin.get())
        Panel2(u, issued, members, book);
    }
    if (o == 3)
    {
        m.Multimedia(u, issued, book);
        cout << endl << "enter-wyjscie";
        if (cin.get())
        Panel2(u, issued, members, book);
    }
    if (o == 4)
    {
        if (u.getID() < 15 && u.getID() > 0)
        {
            m.Admin(issued, book, members);
            cout << endl << "enter-wyjscie";
            cin.get();
            if (cin.get())
            Panel2(u, issued, members, book);
            
        }
        else
        {
            cout << "Nie jestes administartorem!!" << endl;
            cout << endl << "enter-wyjscie";
            Sleep(1000);
            if (cin.get())
            Panel2(u, issued, members, book);
        }
    }
    if(o==5)
    {
        m.MyKonto(u, issued, book);
        cout << endl << "enter-wyjscie";
        if (cin.get())
        Panel2(u, issued, members, book);
    }
    if (o == 6)
    {
        
       
       Panel2(Panel1(issued, members, book), issued, members, book);
    }
    else
    {
        return;
    }

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
        
        plik << k << endl;

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
                /*if ( s.find("D")!=string::npos)
                {
                      DVD d=zbior[i].second[l];
                      plik<<d;

                }*/
                /*if ( s.find("C")!=string::npos)
               {
                     CD d=zbior[i].second[l];
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
                /*if (z[0]=='D')
                {
                    DVD* d = new DVD;
                stringstream ss(s);
                ss1 >>*d;
                zbior.push_back(d);   

                }*/
                /*if (z[0] == 'C')
                {
                   CD* d = new CD;
                    stringstream ss(s);
                    ss1 >> *d;
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
    string s,g;
    string z;
    vector<Przedmiot*> zbior{};
    User man;
    baza tabela;
    if (plik.good())
    {
        getline(plik, g);
        stringstream person(g);
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
                    
                    ss1 >> *k;
                    zbior.push_back(k);

                }
                else
                {
                    /*if (z[0]=='G')
                    {
                         Gra* g = new Gra;
                        
                    ss1 >>*g;
                    zbior.push_back(g);

                    }*/
                    /*if ( z[0]=='D')
                    {
                        DVD* d = new DVD;
                    
                    ss1 >>*d;
                    zbior.push_back(d);

                    }
                    if ( z[0]=='C')
                    {
                        CD* d = new CD;

                    ss1 >>*d;
                    zbior.push_back(d);

                    }
                    if(z*/
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




//void Program(baza& issued, vector<User*>& members, vector<Przedmiot*> book)
//{   User u=Panel1(issued, members, book);
//   Panel2(u, issued, members, book);
//     
//        
//    
//   
//}