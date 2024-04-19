#include "Connexion.h"
#include <iostream>

template<class T>
Connexion<T>::Connexion(T date) : DateDeParticipation(date) {}

template<class T>
Connexion<T>::~Connexion() {}

template<class T>
void Connexion<T>::ajouterDateDeParticipation() {
    std::cout << "Donner la nouvelle date de participation : ";
    std::cin >> DateDeParticipation;
}
template<class T>
std::ostream& operator<< (std::ostream& out, const Connexion<std::string>& c) {
    out << "Date de participation: " << c.DateDeParticipation;
    return out;
}

template class Connexion<std::string>;
template class Connexion<int>;
