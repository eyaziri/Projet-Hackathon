#ifndef UTILISATEURPLATFORME_H
#define UTILISATEURPLATFORME_H

#include"Adresse.h"
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <ctime>
#include"Message.h"
#include"Commentaire.h"


class UtilisateurPlatforme {
protected:
    std::string nom;
    std::string prenom;
    std::string adresseEmail;
    static int CodeUtilisateur;
    std::vector<Adresse*> adr;
    std::vector<Message*> msg;
    std::vector<Commentaire*> comm;


public:
    UtilisateurPlatforme(std::string="", std::string="", std::string="");
    UtilisateurPlatforme(const UtilisateurPlatforme&);
    virtual ~UtilisateurPlatforme();
    virtual void sinscrire() = 0;
    virtual void communiquerViaMessage() = 0;
    virtual void communiquerViaCommentaire() = 0;
    friend std::ostream& operator<< (std::ostream&, const UtilisateurPlatforme&);
    friend std::istream& operator>> (std::istream&, UtilisateurPlatforme&);
    friend std::ostream& operator<< (std::ostream&, UtilisateurPlatforme*);
    friend std::istream& operator>> (std::istream&, UtilisateurPlatforme*);
    UtilisateurPlatforme& operator=(const UtilisateurPlatforme&);
    std::string getNom()
    {
        return nom;
    }
    std::string getPrenom()
    {
        return prenom;
    }
    std::string getAdresseEmail()
    {
        return adresseEmail;
    }
    std::vector<Adresse*> getAdresse()
    {
     return adr;
    }

    void setNom( std::string n){
        nom = n ;
    }
     void setprenom( std::string n){
        prenom = n ;
    }
     void setAdresseMail( std::string n){
        adresseEmail = n ;
    }
     void set( std::string n){
        nom = n ;
    }
};

#endif // UTILISATEURPLATFORME_H
