#ifndef ADRESSE_H
#define ADRESSE_H
#include <string>
#include <iostream>

using namespace std;

class Adresse
{
    private:
        int codePostal;
        string adresse ;
     public:
        Adresse( int = 0  ,string = "");
        virtual ~Adresse();
        friend ostream& operator<< (ostream& out , const Adresse& a);
        friend istream& operator>> (istream& in ,  Adresse& a);
        friend ostream& operator<< (ostream& out , const Adresse* a);
        friend istream& operator>> (istream& in ,  Adresse* a);

};

#endif // ADRESSE_H
