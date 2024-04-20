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
    friend std::ostream& operator<< (std::ostream& out, const Connexion<U>& c);
    template<typename U>
    friend std::istream& operator>> (std::istream& in, Connexion<U>& c);
    void setDate(T d)
    {
        DateDeParticipation=d;
    }
};

#endif // CONNEXION_H
