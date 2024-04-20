#include "Connexion.h"
#include <string>
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
template<typename T>
std::ostream& operator<< (std::ostream& out, const Connexion<T>& c) {
    out <<"\nLa date de participation est: \n" << c.DateDeParticipation<<std::endl;
    return out;
}


template<typename T>
std::istream& operator>> (std::istream& in, Connexion<T>& c) {
    std::cout << "\nDonner la date de participation:\n ";
    in>>c.DateDeParticipation;

    return in;
}

template class Connexion<std::string>;
