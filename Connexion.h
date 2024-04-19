#ifndef CONNEXION_H
#define CONNEXION_H

#include <string>
#include <iostream>

template<class T>
class Connexion {
protected:
    T DateDeParticipation;

public:
    Connexion(T date = "");
    virtual ~Connexion();
    void ajouterDateDeParticipation();
    template<typename U>
    friend std::ostream& operator<< (std::ostream& out, const Connexion<U>& c); ;
};

#endif // CONNEXION_H
