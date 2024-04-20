#ifndef ADRESSE_H
#define ADRESSE_H

#include <iostream>
#include <string>

class Adresse {
    int codePostal;
    std::string adresse;

public:
    Adresse(int code = 0, std::string adr = "");
    virtual ~Adresse();

    friend void ajouterAdresse(Adresse& a);

    friend std::ostream& operator<<(std::ostream& out, const Adresse& a);
    friend std::istream& operator>>(std::istream& in, Adresse& a);
    friend std::ostream& operator<<(std::ostream& out, const Adresse* a);
    friend std::istream& operator>>(std::istream& in, Adresse* a);
};

#endif // ADRESSE_H

