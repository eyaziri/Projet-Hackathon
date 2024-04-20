#ifndef HACKATHON_H
#define HACKATHON_H

#include <vector>
#include "Equipe.h"
#include "Participant.h"
#include "Juge.h"
#include "Organisateur.h"


class Hackathon {
protected:
    static std::vector<Equipe*> equipe;
    static std::vector<Participant<std::string>*> participant;
    static std::vector<Organisateur*> organisateur;
    static std::vector<Juge*> juge;

public:
    Hackathon();
    Hackathon(const Hackathon& autre);
    friend std::ostream& operator<<(std::ostream& out, const Hackathon& hackathon);
    friend std::istream& operator>>(std::istream& in, Hackathon& hackathon);
    Hackathon& operator=(const Hackathon& );
    virtual ~Hackathon();
    void pushBackUnElementParticipant(Participant<std::string>* , Hackathon& hackathon);
    void pushBackUnElementJuge(Juge* ,Hackathon& hackathon);
    void pushBackUnElementOrganisateur(Organisateur* ,Hackathon& hackathon);
    void pushBackUnElementEquipe(Equipe* ,Hackathon& hackathon);

    static std::vector<Equipe*>& getEquipe() {
        return equipe;
    }

    static std::vector<Participant<std::string>*>& getParticipant() {
        return participant;
    }

    static std::vector<Organisateur*>& getOrganisateur() {
        return organisateur;
    }

    static std::vector<Juge*>& getJuge() {
        return juge;
    }

};

#endif // HACKATHON_H
