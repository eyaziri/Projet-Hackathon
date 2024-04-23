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
    out<<"\nLe nom: "<<j.nom;
    out<<"\nLe prenom "<<j.prenom;
    out<<"\nL' adresse email: "<<j.adresseEmail;
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

void Juge::DonnerNoteOriginaliteDeProjet(Projet& p)
{
        if (p.getTechnologieAvancee() > 15)

           {
            p.setNoteOriginaliteDeProjet(20);
           }

        else if (p.getTechnologieAvancee() < 10 && p.getTechnologieAvancee()>5)

            {p.setNoteOriginaliteDeProjet(15);}

        else if (p.getTechnologieAvancee() < 5)
        {
            p.setNoteOriginaliteDeProjet(10);
        }
}

void Juge::DonnerNoteFiabiliteDeProjet(Projet &p)
{
        if (p.getNoteOriginaliteDeProjet() > 10)
        {
            p.setNoteFiabiliteDeProjet(15);
        }
        else
        {
            p.setNoteFiabiliteDeProjet(9);
        }
}

void Juge::DonnerNoteQualiteCodeDeProjet(Projet& p)
{
        if (p.getNoteFiabiliteDeProjet() > 10)
        {
            p.setNoteQualiteCode(15);
        }
        else
        {
            p.setNoteQualiteCode(10);
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

bool Juge::comparerJugesParScore( Juge* a,  Juge* b)
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
void Juge::afficherFichierJuge()
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
//*****************************************************************************************//

void Juge::ajouterUnProjetPourLEvaluer( vector<Equipe*>& equipes)
{
    int nombreDeLequipeChoisi;
    Projet p;
    char addMore;
    do
    {
        std::cout << "\nVoulez-vous ajouter un projet a evalue ? (O/N) :\n ";
        std::cin >> addMore;
        if (addMore == 'O' || addMore == 'o')
        {
            std::cout<<"\nVoila les equipes existante : "<<std::endl;
            for(int i=0; i<equipes.size(); i++)
            {
                std::cout<<i<<"-";
                std::cout<< *equipes[i];
            }
            std::cout<<"\nChoisis une equipe :\n"<<std::endl;

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
void Juge::evaluerProjets(vector<Equipe*>& equipes) {

    ajouterUnProjetPourLEvaluer(equipes);

    for (int i = 0; i < project.size(); i++) {

        DonnerNoteFiabiliteDeProjet(*project[i]);
        DonnerNoteOriginaliteDeProjet(*project[i]);
        DonnerNoteQualiteCodeDeProjet(*project[i]);


        float reliabilityScore = project[i]->getNoteFiabilite();
        float originalityScore = project[i]->getNoteoriginalite();
        float codeQualityScore = project[i]->getNoteQualiteCode();
        float totalScore = reliabilityScore + originalityScore + codeQualityScore;


        project[i]->setScore(totalScore);
    }
}
