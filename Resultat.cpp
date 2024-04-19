#include "Resultat.h"
#include "Juge.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

Resultat::Resultat() {
    Juge* q = new Juge();
    jury.push_back(q);
}

Resultat::~Resultat() {
    for (int i = 0; i < jury.size(); i++) {
        delete jury[i];
    }
    jury.clear();
}

std::ostream& operator<<(std::ostream& out, const Resultat& r) {
    for (int i = 0; i < r.jury.size(); i++) {
        out << (*(r.jury[i]));
    }
    return out;
}

std::istream& operator>>(std::istream& in, Resultat& r) {
    for (int i = 0; i < r.jury.size(); i++) {
        in >> *(r.jury[i]);
    }
    return in;
}

Resultat& Resultat::operator =(const Resultat& r) {
    if (this != &r) {
        for (int i = 0; i < jury.size(); i++) {
            delete jury[i];
        }
        jury.clear();
        for (int i = 0; i < r.jury.size(); i++) {
            Juge* q = new Juge(*r.jury[i]);
            jury.push_back(q);
        }
    }
    return *this;
}

void Resultat::trierJugeParProjetCroissant() {
    std::sort(jury.begin(), jury.end(), Juge::comparerJugesParScore);
}
