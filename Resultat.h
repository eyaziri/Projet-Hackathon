#ifndef RESULTAT_H
#define RESULTAT_H

#include "Juge.h"
#include <vector>
#include <iostream>

class Resultat {
protected:
    std::vector<Juge*> jury;

public:
    Resultat();
    virtual ~Resultat();
    friend std::ostream& operator<<(std::ostream&, const Resultat&);
    friend std::istream& operator>>(std::istream&, Resultat&);
    Resultat& operator =(const Resultat&);
    void trierJugeParProjetCroissant();
};

#endif // RESULTAT_H
