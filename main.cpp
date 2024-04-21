#include <iostream>
#include <string>
#include "Message.h"
#include "Connexion.h"
#include "Commentaire.h"
#include "UtilisateurPlateforme.h"
#include "Projet.h"
#include "Participant.h"
#include "Equipe.h"
#include "Organisateur.h"
#include "Hackathon.h"
#include "Juge.h"
#include <vector>
#include <fstream>


using namespace std;

int main()
{
    system("color F0");
    int choix;
    Hackathon h;

    std::cout << "Bienvenue sur notre plateforme !" << std::endl;

    do
    {

        std::cout << "\n Veuillez choisir parmi les options suivantes :" << std::endl;
        std::cout << "1. Vous etes participant" << std::endl;
        std::cout << "2. Vous etes organisateur" << std::endl;
        std::cout << "3. Vous etes juge" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> choix;

        switch (choix)
        {
        case 1:
        {
            std::cout << "\n Vous etes participant. \n" << std::endl;
            Participant<std::string> p ;

            int choice ;
            do
            {
                std::cout << "\n Veuillez choisir parmi les options suivantes :" << std::endl;
                std::cout << "1. s'inscrire" << std::endl;
                std::cout << "2. Former une equipe" << std::endl;
                std::cout << "3. Communiquer via message" << std::endl;
                std::cout << "4. Communiquer via commentaire" << std::endl;
                std::cout << "5. Return" <<std::endl;
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    cin >> p;
                    h.pushBackUnElementParticipant(&p,h);
                    p.remplirFichierParticipant(p);

                }
                break;
                case 2:
                {
                    Equipe e;
                    cin >> e;
                    h.pushBackUnElementEquipe(&e,h);
                    e.remplirFichierEquipe(e);
                }
                break;
                case 3:
                {
                    p.communiquerViaMessage();

                }
                break;
                case 4:
                {
                    p.communiquerViaCommentaire();

                }
                break;
                case 5:
                {
                    choix = 1 ;
                }
                break;
                default :
                    break;

                }

            }
            while (choix != 1);

            break;
        }
        case 2:
        {
            cout << "\n Vous etes organisateur. \n" << endl;
            Organisateur o;
            int choice ;
            do
            {
                std::cout << "\n Veuillez choisir parmi les options suivantes :" << std::endl;
                std::cout << "1. s'inscrire" << std::endl;
                std::cout << "2. Annoncer les gagnants " << std::endl;
                std::cout << "3. Communiquer via message" << std::endl;
                std::cout << "4. Communiquer via commentaire" << std::endl;
                std::cout << "5. Return" <<std::endl;
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    cin >> o;
                    h.pushBackUnElementOrganisateur(&o,h);
                    o.remplirFichierOrganisateur(o);
                }
                break;
                case 2:
                {
                    o.annoncerEtRecompenserGagnant(Hackathon::getEquipe(),Hackathon::getJuge());
                }
                break;
                case 3:
                {
                    o.communiquerViaMessage();
                }
                break;
                case 4:
                {
                    o.communiquerViaCommentaire();
                }
                break;
                case 5:
                {
                    choix = 2 ;
                }
                break;
                default :
                    break;

                }

            }
            while (choix != 2);


            break;
        }
        case 3:
        {
            cout << " \n Vous etes juge. \n" << endl;
            Juge j;
            int choice ;
            do
            {
                std::cout << "\n Veuillez choisir parmi les options suivantes :" << std::endl;
                std::cout << "1. s'inscrire" << std::endl;
                std::cout << "2. Evaluer projet" << std::endl;
                std::cout << "3. Communiquer via message" << std::endl;
                std::cout << "4. Communiquer via commentaire" << std::endl;
                std::cout << "5. Return" <<std::endl;
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    cin >> j;
                    h.pushBackUnElementJuge(&j,h);
                    j.remplirFichierJuge(j);
                }
                break;
                case 2:
                {
                    j.evaluerProjets(Hackathon::getEquipe());
                }
                break;
                case 3:
                {
                    j.communiquerViaMessage();
                }
                break;
                case 4:
                {
                    j.communiquerViaCommentaire();
                }
                break;
                case 5:
                {
                    choix = 7 ;
                }
                break;
                default :
                    break;
                }
            }
            while (choix != 7);

            break;
        }

        case 4:
            cout << "\n Au revoir !" << endl;
            break;
        default:
            cout << "\nChoix invalide. Veuillez entrer un nombre entre 1 et 5." << endl;
            break;
        }

    }
    while (choix != 4);

    return 0;
}
