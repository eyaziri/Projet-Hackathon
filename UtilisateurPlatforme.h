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
class Message;
class Commentaire;


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
};

#endif // UTILISATEURPLATFORME_H
