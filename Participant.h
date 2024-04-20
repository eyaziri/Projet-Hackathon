#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "UtilisateurPlatforme.h"
#include "Connexion.h"
#include <string>
#include <vector>
#include <iostream>

template<typename T>
class Participant : public UtilisateurPlatforme {
protected:
    std::string Competence;
    std::vector<Connexion<T>*> cnx;

public:
    Participant(std::string="", std::string="", std::string="", std::string="");
    virtual ~Participant();
    Participant(const Participant<T>&);
    Participant& operator= (const Participant<T>&);
    void sinscrire();
    void communiquerViaMessage();
    void communiquerViaCommentaire();
    template<typename U>
    friend std::ostream& operator<< (std::ostream& out, const Participant<U>& p);
    template<typename U>
    friend std::istream& operator>> (std::istream& in, Participant<U>& p);
    template<typename U>
    friend std::ostream& operator<< (std::ostream& out, const Participant<U> *p);
    template<typename U>
    friend std::istream& operator>> (std::istream& in, Participant<U> *p);


    int GetCode() const { return UtilisateurPlatforme::CodeUtilisateur; }
    static void remplirFichierParticipant(const Participant<T> p);
    static void afficherFichierParticipant();
    std::string getCompetence()
    {
        return Competence;
    }
};


#endif // PARTICIPANT_H
