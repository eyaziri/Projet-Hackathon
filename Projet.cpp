#include<vector>
#include "Projet.h"
#include <string>
#include <iostream>

Projet::Projet(std::string titreProjet, std::string description, int technologieAvancee, int idProjet): titreProjet(titreProjet), description(description), technologieAvancee(technologieAvancee), idProjet(idProjet) {}

Projet::~Projet() {}

std::ostream& operator<<(std::ostream& out, const Projet& p) {
    out << "\nLe titre du projet est : \n" << p.titreProjet << std::endl;
    out << "\nLa description du projet est : \n" << p.description << std::endl;
    out << "\nLe nombre de technologie utilise est :\n " << p.technologieAvancee << std::endl;
    out << "\nLe code du projet est : \n" << p.idProjet << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Projet& p) {
    std::cout << "\nDonner le titre du projet : \n";
    in >> p.titreProjet;
    std::cout << "\nDonner la description du projet : \n";
    in >> p.description;
    std::cout << "\nDonner le nombre de technologies utilisees pour le projet : \n";
    in >> p.technologieAvancee;
    std::cout << "\nDonner le code du projet : \n";
    in >> p.idProjet;
    return in;
}
