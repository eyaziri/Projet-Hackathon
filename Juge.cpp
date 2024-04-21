#include "Juge.h"
#include<string>
#include<vector>
#include <iostream>
#include "Projet.h"
#include"UtilisateurPlateforme.h"
#include "Juge.h"
#include <algorithm>
#include <fstream>

Juge::Juge(int id,std::string nom, std::string prenom, std::string Ae ) : idJuge(id), UtilisateurPlatforme(nom, prenom, Ae) {}

Juge::~Juge()
{
    for (size_t i = 0; i < project.size(); ++i)
    {
        delete project[i];
    }
    project.clear();
}

std::ostream& operator<<(std::ostream& out, const Juge& j)
{
    const UtilisateurPlatforme* q = &j;
    out << *q;
    out << "Identifiant du juge : " << j.idJuge << std::endl;
    for (size_t i = 0; i < j.project.size(); ++i)
    {
        out << *(j.project[i]);
    }
    return out;
}

std::istream& operator>>(std::istream& in, Juge& j)
{
    UtilisateurPlatforme* q = &j;
    in >> *q;
    std::cout << "Donner l'identifiant du juge : " << std::endl;
    in >> j.idJuge;
    return in;
}

Juge& Juge::operator=(const Juge& j)
{
    if (this != &j)
    {
        UtilisateurPlatforme::operator=(j);

        idJuge = j.idJuge;

        for (size_t i = 0; i < project.size(); ++i)
        {
            delete project[i];
        }
        project.clear();
        for (size_t i = 0; i < j.project.size(); ++i)
        {
            project.push_back(new Projet(*(j.project[i])));
        }
    }
    return *this;
}

void Juge::DonnerNoteOriginaliteDeProjet()
{
    for (size_t i = 0; i < project.size(); ++i)
    {
        if (project[i]->getTechnologieAvancee() > 15)
        {
            project[i]->setNoteOriginaliteDeProjet(20);
        }
        else if (project[i]->getTechnologieAvancee() > 10)
        {
            project[i]->setNoteOriginaliteDeProjet(15);
        }
        else if (project[i]->getTechnologieAvancee() > 5)
        {
            project[i]->setNoteOriginaliteDeProjet(10);
        }
        else
        {
            project[i]->setNoteOriginaliteDeProjet(5);
        }
    }
}

void Juge::DonnerNoteFiabiliteDeProjet()
{
    for (size_t i = 0; i < project.size(); ++i)
    {
        if (project[i]->getNoteOriginaliteDeProjet() > 10)
        {
            project[i]->setNoteFiabiliteDeProjet(15);
        }
        else
        {
            project[i]->setNoteFiabiliteDeProjet(9);
        }
    }
}

void Juge::DonnerNoteQualiteCodeDeProjet()
{
    for (size_t i = 0; i < project.size(); i++)
    {
        if (project[i]->getNoteFiabiliteDeProjet() > 10)
        {
            project[i]->setNoteQualiteCode(15);
        }
        else
        {
            project[i]->setNoteQualiteCode(10);
        }
    }
}




void Juge::communiquerViaMessage()
{
    std::cout << "Communiquer via message..." << std::endl;
    UtilisateurPlatforme::communiquerViaMessage();
}

void Juge::communiquerViaCommentaire()
{
    std::cout << "Communiquer via commentaire..." << std::endl;
    UtilisateurPlatforme::communiquerViaCommentaire();
}

bool Juge::comparerJugesParScore(const Juge* a, const Juge* b)
{
    return a->Projet::getScore() < b->Projet::getScore();
}

//**********************************************************************************************************//

std::ostream& operator<<(std::ostream& out, const Juge * juge)
{
    out << juge->nom << " " << juge->prenom << " " << juge->adresseEmail << " " << juge->CodeUtilisateur << " " << juge->idJuge ;
    return out ;
}

std::istream& operator>>(std::istream& in, Juge * juge)
{
    in >> juge->nom ;
    in >> juge->prenom ;
    in >> juge->adresseEmail ;
    in >> juge->CodeUtilisateur ;
    in >> juge->idJuge ;
    return in ;
}

//**********************************************************************************************************//
void Juge::remplirFichierJuge(Juge j)
{
   ofstream fi ;
    fi.open("Juge.txt" , ios::app );
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }

    fi << &j << endl ;
    fi.close();
}
//********************************************************************************************//
void Juge::afficherFichierJuge(std::fstream& f)
{
    ifstream fi ;
    fi.open("Juge.txt" , ios::in);
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }else{
    Juge j ;
    while(1){
        fi >> &j ;
        if (fi.eof()){
            break;
        }
        cout << j ;
    }
    }
    fi.close();
}

void Juge::remplirIdentiteDesProjetsJugeesParCeJuge()
{
    for (size_t i = 0; i < project.size(); i++)
    {
        identiteDesProjetsJugeesParCeJuge.push_back(project[i]->getIdProjet());
    }
}

void Juge::ajouterUnProjetPourLEvaluer( vector<Equipe*>& equipes)
{
    int nombreDeLequipeChoisi;
    int b;
    Projet p;
    char addMore;
    do
    {
        std::cout << "\nVoulez-vous ajouter un projet a evalue ? (O/N) :\n ";
        std::cin >> addMore;
        if (addMore == 'O' || addMore == 'o')
        {
            std::cout<<"\nVoila les equipes existante "<<std::endl;
            for(int i=0; i<equipes.size(); i++)
            {
                std::cout<<i<<"-"<< *equipes[i];
            }
            std::cout<<"\nChoisis une equipe\n"<<std::endl;
            std::cin>>nombreDeLequipeChoisi;
            for(int i=0; i<equipes.size(); i++)
            {
                if(i==nombreDeLequipeChoisi)
                {
                    p= equipes[nombreDeLequipeChoisi]->getProjet1();
                }
            }
            project.push_back(&p);
        }
        else{
            addMore = 'n' ;
        }
    }
    while (addMore == 'O' || addMore == 'o');
}
//********************************************************************************************//
void Juge::evaluerProjets(vector<Equipe*>& equipes)
{
    ajouterUnProjetPourLEvaluer(equipes);

    for (Projet* p : project)
    {
        p->setScore(p->getNoteFiabiliteDeProjet() + p->getNoteOriginaliteDeProjet() + p->getNoteQualiteCode());
    }
    std::cout<<"votre projet est evalue avec succes ."<<std::endl;
}
