#include "Adresse.h"
using namespace std ;

Adresse::Adresse(int code , string adresse)
{
    this->codePostal = code ;
    this->adresse = adresse ;
}

Adresse::~Adresse()
{
}
ostream& operator<< (ostream& out , const Adresse& a)
{
    out << "\nadresse est : " << a.adresse ;
    out<<"\nLe code postal est :\n "<<a.codePostal;
    return out;

}
istream& operator>> (istream& in ,  Adresse& a)
{
    cout << "\nentrer l'adresse domicile : \n" ;
    in>> a.adresse ;
    cout<<"\nEntrer le code postal :\n ";
    in>>a.codePostal;
    return in;
}
ostream& operator<< (ostream& out , const Adresse* a)
{
    out << "\nadresse est : " << a->adresse ;
    out<<"\nLe code postal est :\n "<<a->codePostal;
    return out;
}
istream& operator>> (istream& in ,  Adresse* a)
{
     cout << "\nentrer l'adresse domicile : \n" ;
    in>> a->adresse ;
    cout<<"\nEntrer le code postal :\n ";
    in>>a->codePostal;
    return in;
}
