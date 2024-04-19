#include "Hackathon.h"
#include "Equipe.h"
#include "Resultat.h"
#include "UtilisateurPlatforme.h"
#include "Participant.h"
#include "Juge.h"
#include "Organisateur.h"
#include<vector>
#include <iostream>
#include <string>


std::vector<Equipe*> Hackathon::equipe;
std::vector<Resultat*> Hackathon::resultat;
std::vector<Participant<std::string>*> Hackathon::participant;
std::vector<Organisateur*> Hackathon::organisateur;
std::vector<Juge*> Hackathon::juge;

Hackathon::Hackathon() {

    Equipe* q = new Equipe();
    equipe.push_back(q);

    Resultat* r = new Resultat();
    resultat.push_back(r);

    Participant<std::string>* p = new Participant<std::string>();
    participant.push_back(p);

    Juge* j = new Juge();
    juge.push_back(j);

     Organisateur* o = new Organisateur();
     organisateur.push_back(o);

}

Hackathon::~Hackathon() {
    for (std::vector<Resultat*>::size_type i = 0; i < resultat.size(); i++) {
        delete resultat[i];
    }
    resultat.clear();

    for (std::vector<Equipe*>::size_type p = 0; p < equipe.size(); p++) {
        delete equipe[p];
    }
    equipe.clear();

    for (int j = 0; j < participant.size(); j++) {
        delete participant[j];
    }
    participant.clear();

    for (std::vector<Organisateur*>::size_type j = 0; j < organisateur.size(); j++) {
        delete organisateur[j];
    }
    organisateur.clear();

    for (std::vector<Juge*>::size_type j = 0; j < juge.size(); j++) {
        delete juge[j];
    }
    juge.clear();
}

Hackathon::Hackathon(const Hackathon &h) {
   for (std::vector<Resultat*>::size_type i = 0; i < h.resultat.size(); i++) {
        Resultat* q = new Resultat(*(h.resultat[i]));
        resultat.push_back(q);
    }

    for (std::vector<Equipe*>::size_type p = 0; p < h.equipe.size(); p++) {
        Equipe* e = new Equipe(*(h.equipe[p]));
        equipe.push_back(e);
    }

    for (int j = 0; j < h.participant.size(); j++) {
        Participant<std::string>* p = new Participant<std::string>(*(h.participant[j]));
        participant.push_back(p);
    }

    for (std::vector<Organisateur*>::size_type j = 0; j < h.organisateur.size(); j++) {
        Organisateur* p = new Organisateur(*(h.organisateur[j]));
        organisateur.push_back(p);
    }

    for (std::vector<Juge*>::size_type j = 0; j < h.juge.size(); j++) {
        Juge* p = new Juge(*(h.juge[j]));
        juge.push_back(p);
    }

}

std::ostream& operator<<(std::ostream &out, const Hackathon &h) {
    for (std::vector<Resultat*>::size_type  i = 0; i < h.resultat.size(); i++) {
        out << *(h.resultat[i]) << std::endl;
    }

    for (std::vector<Equipe*>::size_type p = 0; p < h.equipe.size(); p++) {
        out << *(h.equipe[p]) << std::endl;
    }

     for (int j = 0; j < h.participant.size(); j++) {
        out << *(h.participant[j]) << std::endl;
    }

     for (std::vector<Organisateur*>::size_type j = 0; j < h.organisateur.size(); j++) {
        out << *(h.organisateur[j]) << std::endl;
    }

     for (std::vector<Juge*>::size_type j = 0; j < h.juge.size(); j++) {
        out << *(h.juge[j]) << std::endl;
    }
        return out;
}

std::istream& operator>>(std::istream &in, Hackathon &h) {

    Equipe* q = new Equipe();
    in >> *q;
    h.equipe.push_back(q);

    Resultat* r = new Resultat();
    in >> *r;
    h.resultat.push_back(r);

    Participant<std::string>* p = new Participant<std::string>();
    in >> p;
    h.participant.push_back(p);

    Organisateur* o = new Organisateur();
    in >> *o;
    h.organisateur.push_back(o);

    Juge* j = new Juge();
    in >> *j;
    h.juge.push_back(j);

    return in;
}

Hackathon& Hackathon::operator=(const Hackathon &h) {
    if (this != &h) {
        for (std::vector<Equipe*>::size_type i = 0; i < equipe.size(); i++) {
            delete equipe[i];
        }
        equipe.clear();

        for (std::vector<Equipe*>::size_type i = 0; i < h.equipe.size(); i++) {
            Equipe* e = new Equipe(*(h.equipe[i]));
            equipe.push_back(e);
        }

        for (std::vector<Resultat*>::size_type j = 0; j < resultat.size(); j++) {
            delete resultat[j];
        }
        resultat.clear();

        for (std::vector<Resultat*>::size_type j = 0; j < h.resultat.size(); j++) {
            Resultat* r = new Resultat(*(h.resultat[j]));
            resultat.push_back(r);
        }

        for (int p = 0; p < participant.size(); p++) {
            delete participant[p];
        }
        participant.clear();

        for (int i = 0; i < h.participant.size(); i++) {
            Participant<std::string>* p = new Participant<std::string>(*(h.participant[i]));
            participant.push_back(p);
        }


         for (std::vector<Organisateur*>::size_type p = 0; p < organisateur.size(); p++) {
            delete organisateur[p];
        }
        organisateur.clear();

        for (std::vector<Organisateur*>::size_type p = 0; p < h.organisateur.size(); p++) {
            Organisateur* u = new Organisateur(*(h.organisateur[p]));
            organisateur.push_back(u);
        }


         for (std::vector<Juge*>::size_type p = 0; p < juge.size(); p++) {
            delete juge[p];
        }
        juge.clear();

        for (std::vector<Juge*>::size_type p = 0; p < h.juge.size(); p++) {
            Juge* u = new Juge(*(h.juge[p]));
            juge.push_back(u);
        }
    }
    return *this;
}

void Hackathon::pushBackUnElementParticipant(Participant<std::string>* p , Hackathon& hackathon)
{
        hackathon.participant.push_back(p);
}
void Hackathon::pushBackUnElementJuge(Juge*j ,Hackathon& hackathon)
{
    hackathon.juge.push_back(j);
}
void Hackathon::pushBackUnElementOrganisateur(Organisateur*o ,Hackathon& hackathon)
{
   hackathon.organisateur.push_back(o);
}
void Hackathon::pushBackUnElementEquipe(Equipe*e ,Hackathon& hackathon)
{
  hackathon.equipe.push_back(e);
}
