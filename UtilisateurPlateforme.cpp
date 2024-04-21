#include "UtilisateurPlateforme.h"
#include "Adresse.h"
#include "Message.h"
#include "Commentaire.h"
#include <fstream>
#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
#include<vector>

int UtilisateurPlatforme::CodeUtilisateur = 0;
UtilisateurPlatforme::UtilisateurPlatforme(std::string nom, std::string prenom, std::string Ae): nom(nom), prenom(prenom), adresseEmail(Ae)
{
    Adresse* q = new Adresse();
    adr.push_back(q);
    Message* m = new Message();
    msg.push_back(m);
    Commentaire* c = new Commentaire();
    comm.push_back(c);
    CodeUtilisateur++;
}
//******************************************************************************************************************************//
UtilisateurPlatforme::~UtilisateurPlatforme()
{
    for (std::vector<Adresse*>::size_type i = 0; i < adr.size(); i++)
    {
        delete adr[i];
    }
    adr.clear();
}

//******************************************************************************************************************************//
UtilisateurPlatforme::UtilisateurPlatforme(const UtilisateurPlatforme& w)
{
    nom = w.nom;
    prenom = w.prenom;
    adresseEmail = w.adresseEmail;
    CodeUtilisateur = w.CodeUtilisateur;
    for (std::vector<Adresse*>::size_type i = 0; i < w.adr.size(); i++)
    {
        Adresse* q = new Adresse(*w.adr[i]);
        adr.push_back(q);
    }
}

//****************************************************************************************************************//
std::ostream& operator<<(std::ostream& out, const UtilisateurPlatforme& u)
{
    out << "\nLe nom est : " << u.nom << std::endl;
    out << "\nLe prenom est : " << u.prenom << std::endl;
    out << "\nL'adresse email est : " << u.adresseEmail << std::endl;
    out << "\nLe codeUtilisateur est : " << u.CodeUtilisateur << std::endl;
    for (std::vector<Adresse*>::size_type i = 0; i < u.adr.size(); i++)
    {
        out << *u.adr[i] << std::endl;
    }
    return out;
}
//******************************************************************************************************************//
std::istream& operator>>(std::istream& in, UtilisateurPlatforme& u)
{
    std::cout << "\n Donner votre nom :" << std::endl;
    in >> u.nom;
    std::cout << "\n Donner votre prenom :" << std::endl;
    in >> u.prenom;
    std::cout << "\nDonner votre adresse_email :" << std::endl;
    in >> u.adresseEmail;
    for (std::vector<Adresse*>::size_type i = 0; i < u.adr.size(); i++)
    {
        in >> (*(u.adr[i]));
    }
    return in;
}

//*********************************************************************************************************//
UtilisateurPlatforme& UtilisateurPlatforme::operator=(const UtilisateurPlatforme& u)
{
    if (this != &u)
    {
        nom = u.nom;
        prenom = u.prenom;
        adresseEmail = u.adresseEmail;
        CodeUtilisateur = u.CodeUtilisateur;
        for (std::vector<Adresse*>::size_type i = 0; i < adr.size(); i++)
        {
            delete adr[i];
        }
        adr.clear();
        for (std::vector<Adresse*>::size_type i = 0; i < u.adr.size(); i++)
        {
            Adresse* q = new Adresse(*u.adr[i]);
            adr.push_back(q);
        }
    }
    return *this;
}

//******************************************************************************************************************************//

void UtilisateurPlatforme::communiquerViaMessage()
{
    cout << "----------------Tous les messages--------------------"<<endl;
    Message::afficherMessages();
    Message message ;
    cin >> message ;
    message.remplirFile(message);
}
//*********************************************************************************************//
void UtilisateurPlatforme::communiquerViaCommentaire()
{
   cout << "----------------Tous les commentaires--------------------"<<endl;
   Commentaire::afficherFichier();
   Commentaire commentaire ;
   cin >> commentaire ;
   commentaire.remplirFile(commentaire);
}
