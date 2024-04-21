#include "Organisateur.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "UtilisateurPlateforme.h"
#include "Equipe.h"
#include "Juge.h"
#include "Projet.h"
#include <fstream>

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

std::ostream& operator<<(std::ostream& out , const Organisateur* organisateur )
{
   out << organisateur->nom << " " << organisateur->prenom << " " << organisateur->adresseEmail << " " << organisateur->idOrganisateur <<"\n";
   return out ;
}

std::istream& operator>>(std::istream& in, Organisateur* organisateur )
{
    in >> organisateur->nom ;
    in >> organisateur->prenom ;
    in >> organisateur->adresseEmail ;
    in >> organisateur->idOrganisateur ;
    return in ;
}


void Organisateur::remplirFichierOrganisateur(Organisateur o)
{
    ofstream fi ;
    fi.open("Organisateur.txt" , ios::app );
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }

    fi << &o << endl ;
    fi.close();
}
void Organisateur::afficherFichierOrganisateur()
{
    ifstream fi ;
    fi.open("Organisateur.txt" , ios::in);
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }else{
    Organisateur org ;
    while(1){
        fi >> &org ;
        if (fi.eof()){
            break;
        }
        cout << org ;
    }
    }
    fi.close();
}
//********************************************************************************************************************//
void Organisateur::annoncerEtRecompenserGagnant( vector<Equipe*>& equipes , vector<Juge*>& juges)
{
    try
    {
        if (juges.empty())
        {
            throw std::logic_error("Aucun juge disponible pour évaluer les projets.");
        }

        auto compareProjectsByScore = [](const Projet* a, const Projet* b)
        {
            return a->getScore() > b->getScore();
        };

        std::vector<Projet*> tousProjets;

        for (std::vector<Juge*>::size_type i = 0; i < juges.size(); ++i)
        {
            for (int j = 0; j < juges[i]->getProjectSize(); ++j)

            {
                tousProjets.push_back(juges[i]->getOneElementFromProject(j));
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
        for (std::vector<Equipe*>::size_type j = 0; j < equipes.size(); ++j)
        {
            if (equipes[j]->getidProjet1() == idPremierProjet)
            {
                nomEquipePremier = equipes[j]->getNomEquipeParIdProjet(idPremierProjet);
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
           for (std::vector<Equipe*>::size_type j = 0; j < equipes.size(); ++j)
            {
                if (equipes[j]->getidProjet1() == idDeuxiemeProjet)
                {
                    nomEquipeDeuxieme = equipes[j]->getNomEquipeParIdProjet(idDeuxiemeProjet);
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
            for (std::vector<Equipe*>::size_type j = 0; j < equipes.size(); ++j)
            {
                if (equipes[j]->getidProjet1()== idTroisiemeProjet)
                {
                    nomEquipeTroisieme = equipes[j]->getNomEquipeParIdProjet(idTroisiemeProjet);
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
            for (std::vector<Equipe*>::size_type j = 0; j < equipes.size(); ++j)
            {
                if (equipes[j]->getidProjet1() == idProjetGagnant)
                {
                    nomEquipeGagnante = equipes[j]->getNomEquipeParIdProjet(idProjetGagnant);
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
