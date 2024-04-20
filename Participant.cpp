#include "Participant.h"
#include "Connexion.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "UtilisateurPlateforme.h"

template<typename U>
Participant<U>::Participant(std::string Competence, std::string nom, std::string prenom, std::string Ae ): Competence(Competence), UtilisateurPlatforme(nom, prenom, Ae)
{
}
//**************************************************************************************************************//

template<typename U>
Participant<U>::~Participant()
{
    for (typename std::vector<Connexion<U>*>::size_type i = 0; i < cnx.size(); i++)
    {
        delete cnx[i];
    }
    cnx.clear();
}
//**************************************************************************************************************//
template<typename U>
Participant<U>::Participant(const Participant<U> &w) : UtilisateurPlatforme(w)
{
    Competence = w.Competence;
    for (size_t i = 0; i < w.cnx.size(); ++i)
    {
        Connexion<U>* q = new Connexion<U>(*(w.cnx[i]));
        cnx.push_back(q);
    }
}

//**************************************************************************************************************/
template<typename U>
Participant<U>& Participant<U>::operator= (const Participant<U> &p)
{
    if (this != &p)
    {
        UtilisateurPlatforme::operator=(p);
        Competence = p.Competence;

        for (typename std::vector<Connexion<U>*>::size_type i = 0; i < p.cnx.size(); i++)
        {
            delete cnx[i];
        }
        cnx.clear();

        for (size_t i = 0; i < p.cnx.size(); ++i)
        {
            Connexion<U>* newConnexion = new Connexion<U>(*(p.cnx[i]));
            cnx.push_back(newConnexion);
        }
    }
    return *this;
}
//**************************************************************************************************************//
template<typename U>
void Participant<U>::communiquerViaMessage()
{
    UtilisateurPlatforme::communiquerViaMessage();
}
//**************************************************************************************************************//
template<typename U>
void Participant<U>::communiquerViaCommentaire()
{
    UtilisateurPlatforme::communiquerViaCommentaire();
}
//**************************************************************************************************************//
template<typename U>

void Participant<U>::remplirFichierParticipant(Participant<U>& p)
{
     ofstream fi ;
    fi.open("Participant.txt" , ios::app );
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }

    fi << &p << endl ;
    fi.close();
}
//**************************************************************************************************************//
template<typename U>

void Participant<U>::afficherFichierParticipant() {
    ifstream fi ;
    fi.open("Participant.txt" , ios::in);
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }else{
    Participant<U> participant ;
    while(1){
        fi >> &participant ;
        if (fi.eof()){
            break;
        }
        cout << participant ;
    }
    }
    fi.close();
}


template class Participant<std::string>;

