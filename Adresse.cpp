#include"Adresse.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


Adresse::Adresse(int code, std::string adr) : codePostal(code), adresse(adr) {}

Adresse::~Adresse() {}

void ajouterAdresse(Adresse& a) {
    std::cout << "Donner votre numero de code postal : \n";
    std::cin >> a.codePostal;

    std::cout << "Donner votre adresse complete : \n";
    std::cin.ignore();
    std::getline(std::cin, a.adresse);
}

std::ostream& operator<<(std::ostream& out, const Adresse& a) {
    out << "\n L'adresse est : \n" << a.adresse << std::endl;
    out << "\nLe code postal est : \n" << a.codePostal << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Adresse& a) {
    std::cout << "\n Entrez votre adresse de domicile: \n";
    std::cin.ignore();
    std::getline(in, a.adresse);

    std::cout << "\n Entrez votre code postal : \n";
    in >> a.codePostal;

    return in;
}
std::ostream& operator<<(std::ostream& out, const Adresse* a)
{
    out << a->codePostal << std::setw(2) << a->adresse << std::setw(2);
    return out ;
}
std::istream& operator>>(std::istream& in, Adresse* a)
{
    in >> a->codePostal ;
    in >> a->adresse ;
    return in ;
}
