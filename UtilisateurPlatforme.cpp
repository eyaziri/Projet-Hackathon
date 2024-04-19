#include "UtilisateurPlatforme.h"
#include "Adresse.h"
#include "Message.h"
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

//******************************************************************************************************************************//

void UtilisateurPlatforme::communiquerViaMessage()
{
    char c;
    try
    {
        do
        {
            std::cout << "Vous voulez ajouter ou supprimer un message (A/S) : ";
           std:: cin >> c;
        } while (c != 'A' && c != 'a' && c != 'S' && c != 's');

        if (c == 'A' || c == 'a')
        {
            Message* q = new Message();
            std::cin.ignore();
            std::cin >> *q;
            msg.push_back(q);
        }
        else if (c == 'S' || c == 's')
        {
            if (msg.empty())
            {
                std::cout << "Il n'y a aucun message a supprimer." << std::endl;
                return;
            }

            std::cout << "Messages disponibles :" << std::endl;
            for (size_t i = 0; i < msg.size(); ++i)
            {
                std::cout << i + 1 << ": " << *msg[i] << std::endl;
            }

            std::cout << "Veuillez entrer le numero du message a supprimer : ";
            int index;
            std::cin >> index;

            if (index < 1 || index > static_cast<int>(msg.size()))
            {
                throw std::out_of_range("Numero de message invalide.");
            }

            delete msg[index - 1];
            msg.erase(msg.begin() + index - 1);
            std::cout << "Message supprime avec succes." << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << '\n';
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
        out << "\nL'adresse est : " << *u.adr[i] << std::endl;
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
//************************************************************************************************************//
void UtilisateurPlatforme::sinscrire()
{
    std::string ch;
    std::string motDePasse ;
    std::fstream f;
    f.open("d:\\fichierinscription.txt", std::ios::app);
    if (!f.is_open())
    {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }
    std::cout << "Donner votre nom :" << std::endl;
    std::cin >> ch;
    f << ch << " ";
    std::cout << "Donner votre mot de passe :" << std::endl;
    std::cin >> motDePasse;
    f << motDePasse << std::endl;
    f.close();
}
//***********************************************************************************************************//
std::ostream& operator<<(std::ostream& out, UtilisateurPlatforme* up)
{
    out << std::setw(5) << up->nom;
    out << std::setw(5) << up->prenom;
    out << std::setw(5) << up->adresseEmail;
    out << up->CodeUtilisateur;
    for (std::vector<Adresse*>::size_type i = 0; i < up->adr.size(); i++)
    {
        out << std::setw(5) << *up->adr[i] << std::endl;
    }
    return out;
}

//*********************************************************************************************//
std::istream& operator>>(std::istream& in, UtilisateurPlatforme* up)
{
    in >> up->nom;
    in >> up->prenom;
    in >> up->adresseEmail;
    for (std::vector<Adresse*>::size_type i = 0; i < up->adr.size(); i++)
    {
        in >> *up->adr[i];
    }
    return in;
}
//*********************************************************************************************//
void UtilisateurPlatforme::communiquerViaCommentaire()
{
    char c;
    try
    {
        do
        {
            std::cout << "Vous voulez ajouter ou supprimer un message (A/S) : ";
           std:: cin >> c;
        } while (c != 'A' && c != 'a' && c != 'S' && c != 's');

        if (c == 'A' || c == 'a')
        {
            Commentaire* q = new Commentaire();
            std::cin.ignore();
            std::cin >> *q;
            comm.push_back(q);
        }
        else if (c == 'S' || c == 's')
        {
            if (msg.empty())
            {
                std::cout << "Il n'y a aucun Commentaire a supprimer." << std::endl;
                return;
            }

            std::cout << "Commentaire disponibles :" << std::endl;
            for (size_t i = 0; i < comm.size(); ++i)
            {
                std::cout << i + 1 << ": " << *comm[i] << std::endl;
            }

            std::cout << "Veuillez entrer le numero du Commentaire a supprimer : ";
            int index;
            std::cin >> index;

            if (index < 1 || index > static_cast<int>(comm.size()))
            {
                throw std::out_of_range("Numero de Commenatire invalide.");
            }

            delete comm[index - 1];
            comm.erase(comm.begin() + index - 1);
            std::cout << "Commentaire supprime avec succes." << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << '\n';
    }
}
