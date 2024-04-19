#include "Equipe.h"
#include "Participant.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Equipe::Equipe(Projet projet, std::string nomEquipe) : projet1(projet), nomEquipe(nomEquipe)
{
    Participant<std::string>* p;
    std::cin >>p;
    Participant<std::string>* q = new Participant<std::string>(*p);
    membres.push_back(q);
}

Equipe::~Equipe()
{
    for (size_t i = 0; i < membres.size(); i++)
    {
        delete membres[i];
    }
    membres.clear();
}

Equipe::Equipe(const Equipe& e)
{
    nomEquipe = e.nomEquipe;
    projet1 = e.projet1;
    for (size_t i = 0; i < e.membres.size(); i++)
    {
        Participant<std::string>* newParticipant = new Participant<std::string>(*(e.membres[i]));
        membres.push_back(newParticipant);
    }
}

void Equipe::ajouterMembre()
{
    Participant<std::string>* p;
    std::cin >>p;
    Participant<std::string>* newParticipant = new Participant<std::string>(*p);
    membres.push_back(newParticipant);
}

void Equipe::supprimerMembre()
{
    int x;
    std::cout << "Pour vous faciliter la tache, on va afficher les membres de cette equipe : " << std::endl << std::endl;
    for (size_t i = 0; i < membres.size(); i++)
    {
        std::cout << "Membre " << i + 1 << ": " << *(membres[i])<< std::endl;
    }

    std::cout << "Donner le code du membre que tu veux supprimer : ";
    std::cin >> x;

    for (size_t i = 0; i < membres.size(); i++)
    {
        if (membres[i]->GetCode() == x)
        {
            delete membres[i];
            membres.erase(membres.begin() + i);
            std::cout << "Le membre a ete supprime avec succes." << std::endl;
            return;
        }
    }

    std::cout << "Aucun membre avec le code " << x << " n'a ete trouve." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Equipe& e)
{
    out << "Le pseudo de l'equipe est : " << e.nomEquipe << std::endl;
    out << e.projet1 << std::endl;
    for (size_t i = 0; i < e.membres.size(); i++)
    {
        out << *(e.membres[i]) << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Equipe& e)
{
    std::cout << "\n Donner le pseudo de votre equipe : \n";
    in >> e.nomEquipe;
    in >> e.projet1;
    char addMore;
    do
    {
        std::cout << "Voulez-vous ajouter un nouveau membre ? (O/N) : ";
        std::cin >> addMore;
        if (addMore == 'O' || addMore == 'o')
        {
            Participant<std::string>* p= new Participant<std::string>();
            std::cin >> *p;
            e.membres.push_back(p);
        }
    }
    while (addMore == 'O' || addMore == 'o');
    return in;
}

Equipe& Equipe::operator=(const Equipe& e)
{
    if (this != &e)
    {
        nomEquipe = e.nomEquipe;
        projet1 = e.projet1;
        for (size_t i = 0; i < membres.size(); i++)
        {
            delete membres[i];
        }
        membres.clear();
        for (size_t i = 0; i < e.membres.size(); i++)
        {
            Participant<std::string>* q = new Participant<std::string>(*e.membres[i]);
            membres.push_back(q);
        }
    }
    return *this;
}


void Equipe::remplirFichierEquipe(Equipe e)
{
    std::fstream f;
    f.open("fichierEquipe.txt", std::ios::out | std::ios::in |std::ios::trunc);
    if (!f.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }
    f << &e << std::endl;
    f.close();
}

void Equipe::afficherFichierEquipe(std::fstream& f)
{
    f.open("fichierEquipe.txt", std::ios::out| std::ios::in |std::ios::trunc);
    if (!f.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    Equipe *e;
    while (f >> e)
    {
        std::cout << e << std::endl;
    }

    f.close();
}
std::vector<Equipe> Equipe::chargerDepuisFichier(const std::string& nomFichier)
{
    std::vector<Equipe> equipes;

    std::ifstream fichier(nomFichier);
    if (!fichier.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier " << nomFichier << std::endl;
        return equipes;
    }

    std::string ligne;
    while (std::getline(fichier, ligne))
    {
        std::istringstream iss(ligne);
        Equipe equipe;
        iss >> equipe;
        equipes.push_back(equipe);
    }

    fichier.close();

    return equipes;
}
std::ostream& operator<<(std::ostream& out, const Equipe* e)
 {
   out << "Le pseudo de l'equipe est : " << e->nomEquipe << std::endl;
    out << e->projet1 << std::endl;
    for (size_t i = 0; i < e->membres.size(); i++)
    {
        out << *(e->membres[i]) << std::endl;
    }
    return out;
 }
  std::istream& operator>>(std::istream& in, Equipe* e)
  {
      std::cout << "\n Donner le pseudo de votre equipe : \n";
    in >> e->nomEquipe;
    in >> e->projet1;
    char addMore;
    do
    {
        std::cout << "Voulez-vous ajouter un nouveau membre ? (O/N) : ";
        std::cin >> addMore;
        if (addMore == 'O' || addMore == 'o')
        {
            Participant<std::string>* p= new Participant<std::string>();
            std::cin >> *p;
            e->membres.push_back(p);
        }
    }
    while (addMore == 'O' || addMore == 'o');
    return in;
  }
