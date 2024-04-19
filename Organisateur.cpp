#include "Organisateur.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "UtilisateurPlatforme.h"
#include "Equipe.h"
#include "Hackathon.h"
#include "Juge.h"
#include "Projet.h"

Organisateur::Organisateur(int id,std::string nom, std::string prenom, std::string Ae ) : idOrganisateur(id), UtilisateurPlatforme(nom, prenom, Ae) {}

Organisateur::~Organisateur() {}

void Organisateur::communiquerViaMessage()
{
    std::cout << "Communiquer via message..." << std::endl;
    UtilisateurPlatforme::communiquerViaMessage();
}

void Organisateur::communiquerViaCommentaire()
{
    std::cout << "Communiquer via commentaire..." << std::endl;
    UtilisateurPlatforme::communiquerViaCommentaire();
}

void Organisateur::sinscrire()
{
    std::cout << "S'inscrire à un hackathon..." << std::endl;
    UtilisateurPlatforme::sinscrire();
}

std::ostream& operator<<(std::ostream& out, const Organisateur& o)
{
    const UtilisateurPlatforme* q = &o;
    out << *q;
    out << "\n l'identite d'organisateur est: " << o.idOrganisateur << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Organisateur& o)
{
    UtilisateurPlatforme* q = &o;
    in >> *q;
    std::cout << "Donner votre identite d'organisateur :" << std::endl;
    in >> o.idOrganisateur;
    return in;
}



void Organisateur::remplirFichierOrganisateur(Organisateur o)
{
    std::fstream f;
    f.open("fichierOrganisateur.txt", std::ios::out | std::ios::app);
    if (!f.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }
    f << o << std::endl;
    f.close();
}

void Organisateur::afficherFichierOrganisateur(std::fstream& f)
{
    f.open("fichierOrganisateur.txt", std::ios::in);
    if (!f.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    Organisateur o;
    while (f >> o)
    {
        std::cout << o << std::endl;
    }

    f.close();
}
//********************************************************************************************************************//
void Organisateur::annoncerEtRecompenserGagnant()
{
    try
    {
        if (Hackathon::getJuge().empty())
        {
            throw std::logic_error("Aucun juge disponible pour évaluer les projets.");
        }

        auto compareProjectsByScore = [](const Projet* a, const Projet* b)
        {
            return a->getScore() > b->getScore();
        };

        std::vector<Projet*> tousProjets;

        for (std::vector<Juge*>::size_type i = 0; i < Hackathon::getJuge().size(); ++i)
        {
            for (int j = 0; j < Hackathon::getJuge()[i]->getProjectSize(); ++j)

            {
                tousProjets.push_back(Hackathon::getJuge()[i]->getOneElementFromProject(j));
            }
        }

        if (tousProjets.empty())
        {
            throw std::logic_error("Aucun projet evalue.");
        }

        sort(tousProjets.begin(), tousProjets.end(),compareProjectsByScore);

        Projet* premierProjet = tousProjets.front();
        int idPremierProjet = premierProjet->getIdProjet();
        std::string nomEquipePremier = "Inconnue";
        for (std::vector<Equipe*>::size_type j = 0; j < Hackathon::getEquipe().size(); ++j)
        {
            if (Hackathon::getEquipe()[j]->getidProjet1() == idPremierProjet)
            {
                nomEquipePremier = Hackathon::getEquipe()[j]->getNomEquipeParIdProjet(idPremierProjet);
                break;
            }
        }

        std::cout << "Le gagnant du premier prix est l'equipe " << nomEquipePremier << " avec un score de "
                  << premierProjet->getScore() << ". Ils remportent un prix de 2000 DT !" << std::endl;

        if (tousProjets.size() > 1)
        {
            Projet* deuxiemeProjet = tousProjets[1];
            int idDeuxiemeProjet = deuxiemeProjet->getIdProjet();

            std::string nomEquipeDeuxieme = "Inconnue";
           for (std::vector<Equipe*>::size_type j = 0; j < Hackathon::getEquipe().size(); ++j)
            {
                if (Hackathon::getEquipe()[j]->getidProjet1() == idDeuxiemeProjet)
                {
                    nomEquipeDeuxieme = Hackathon::getEquipe()[j]->getNomEquipeParIdProjet(idDeuxiemeProjet);
                    break;
                }
            }

            std::cout << "Le gagnant de la deuxieme place est l'equipe " << nomEquipeDeuxieme << " avec un score de "
                      << deuxiemeProjet->getScore() << ". Ils remportent un prix de 1500 DT !" << std::endl;
        }

        if (tousProjets.size() > 2)
        {
            Projet* troisiemeProjet = tousProjets[2];
            int idTroisiemeProjet = troisiemeProjet->getIdProjet();

            std::string nomEquipeTroisieme = "Inconnue";
            for (std::vector<Equipe*>::size_type j = 0; j < Hackathon::getEquipe().size(); ++j)
            {
                if (Hackathon::getEquipe()[j]->getidProjet1()== idTroisiemeProjet)
                {
                    nomEquipeTroisieme = Hackathon::getEquipe()[j]->getNomEquipeParIdProjet(idTroisiemeProjet);
                    break;
                }
            }

            std::cout << "Le gagnant de la troisieme place est l'equipe " << nomEquipeTroisieme << " avec un score de "
                      << troisiemeProjet->getScore() << ". Ils remportent un prix de 1000 DT !" << std::endl;
        }

        int nbGagnants = std::min(3, static_cast<int>(tousProjets.size()));
        for (int i = 3; i < nbGagnants; ++i)
        {
            Projet* projetGagnant = tousProjets[i];
            int idProjetGagnant = projetGagnant->getIdProjet();

            std::string nomEquipeGagnante = "Inconnue";
            for (std::vector<Equipe*>::size_type j = 0; j < Hackathon::getEquipe().size(); ++j)
            {
                if (Hackathon::getEquipe()[j]->getidProjet1() == idProjetGagnant)
                {
                    nomEquipeGagnante = Hackathon::getEquipe()[j]->getNomEquipeParIdProjet(idProjetGagnant);
                    break;
                }
            }

            std::cout << "Score : " << projetGagnant->getScore() << " | Equipe gagnante : " << nomEquipeGagnante << std::endl;
        }
    }
    catch (const std::logic_error& e)
    {
        std::cerr << "Erreur logique : " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
}
