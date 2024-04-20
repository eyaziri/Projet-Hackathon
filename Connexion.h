#ifndef CONNEXION_H
#define CONNEXION_H
#include <string>
#include <iostream>

template<typename U>
class Connexion {
protected:
    U DateDeParticipation;

public:
    Connexion(U date = U()) : DateDeParticipation(date) {}
    virtual ~Connexion() {}

    friend std::ostream& operator<< (std::ostream& out, const Connexion<U>& c) {
        out << "\nLa date de participation est: \n" << c.DateDeParticipation << std::endl;
        return out;
    }

    friend std::istream& operator>> (std::istream& in, Connexion<U>& c) {
        std::cout << "\nDonner la date de participation:\n";
        in >> c.DateDeParticipation;
        return in;
    }
    friend std::ostream& operator<< (std::ostream& out, const Connexion<U>* c) {
        out << c->DateDeParticipation ;
        return out;
    }

    friend std::istream& operator>> (std::istream& in, Connexion<U>* c) {
        in >> c->DateDeParticipation;
        return in;
    }

    void setDate(U d) {
        DateDeParticipation = d;
    }
};

#endif // CONNEXION_H
