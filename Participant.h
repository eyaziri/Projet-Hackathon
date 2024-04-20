#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "UtilisateurPlateforme.h"
#include "Connexion.h"
#include <string>
#include <vector>
#include <iostream>

template<typename U>
class Participant : public UtilisateurPlatforme
{
protected:
    std::string Competence;
    std::vector<Connexion<U>*> cnx;

public:
    Participant(std::string="", std::string="", std::string="", std::string="" );
    virtual ~Participant();
    Participant(const Participant<U>&);
    Participant& operator= (const Participant<U>&);
    void communiquerViaMessage();
    void communiquerViaCommentaire();

    friend std::ostream& operator<< (std::ostream& out, Participant<U>& p)
    {
        out << "\nNom : " << p.nom ;
        out << "\nPrenom : " << p.prenom ;
        out << "\nAdresse Mail : " <<  p.adresseEmail;
        out << "\nvotre Competence est : " << p.Competence << std::endl;
        out << "\nDate : \n" << (p.cnx[0]) ;

        return out;
    }
    friend std::istream& operator>> (std::istream& in, Participant<U>& p)
    {
        cout << "Nom : ";
        in >> p.nom ;
        cout << "Prenom : ";
        in >> p.prenom ;
        cout << "Adresse mail : ";
        in>> p.adresseEmail ;

        std::cout << "\nEntrez la competence du participant:\n ";
        in >> p.Competence;

        U date;
        std::cout << "\nEntrez la date de participation (sous la forme --/--/--): \n";
        in >> date;
        Connexion<U> *newConnexion = new Connexion<U>(date);
        p.cnx.push_back(newConnexion);



        return in ;
    }
    friend std::ostream& operator<< (std::ostream& out, Participant<U> *p)
    {
        out<<" "<< p->getNom() <<" "<<p->getPrenom()<<" "<<p->getAdresseEmail()<<" "<<" "<<p->getCompetence() << " " << (p->cnx[0]) ;

        return out ;
    }
    friend std::istream& operator>> (std::istream& in, Participant<U> *p)
    {
        int taille ;
        in >> p->nom ;
        in >> p->prenom ;
        in >> p->adresseEmail ;
        in >> p->Competence ;
        return in;
    }


    int GetCode() const
    {
        return UtilisateurPlatforme::CodeUtilisateur;
    }
    static void remplirFichierParticipant(Participant<U> &p);
    static void afficherFichierParticipant();
    std::string getCompetence()
    {
        return Competence;
    }
};


#endif // PARTICIPANT_H
