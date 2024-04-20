#include "Equipe.h"
#include "Participant.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Equipe::Equipe(Projet projet, std::string nomEquipe) : projet1(projet), nomEquipe(nomEquipe)
{
    Participant<std::string>* p;
    std::cin>>p;
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

std::ostream& operator<<(std::ostream& out, Equipe* e)
 {
    out << e->getNomEquipe() << " " << e->getProjet1().getTitreProjet() << " " << e->getProjet1().getDescription() << " ** " << e->getProjet1().getTechnologieAvancee() << " " << e->getMembres().size() ;
    for ( int i=0 ; i<e->getMembres().size() ;i++)
    {
        out << " " << e->getMailMembre(i) ;
    }
    return out;
 }
  std::istream& operator>>(std::istream& in, Equipe* e)
  {
    string s1 = "" , s2 = "";
    int s3 ;
    in >> e->nomEquipe ;
    string tmp = "" ;
    in >> tmp ;
    while( tmp != "**")
    {
        s2 += tmp ;
        s2 += " " ;
        in >> tmp ;
    }
    in >> s3 ;
    e->setProjet(s1,s2,s3);
    int taille ;
    in >> taille ;
    for ( int i=0 ; i<taille ; i++)
    {
        in >> tmp ;
        e->setMembre(tmp , i) ;
    }
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
    ofstream fi ;
    fi.open("Equipe.txt" , ios::app );
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }

    fi << &e ;
    fi.close();
}

void Equipe::afficherFichierEquipe()
{
    ifstream fi ;
    fi.open("Equipe.txt" , ios::in);
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }else{
    Equipe equipe;
    while(1){
        fi >> &equipe ;
        if (fi.eof()){
            break;
        }
        cout << equipe ;
    }
    }
    fi.close();
}

