#include "Participant.h"
#include "Connexion.h"
#include <iostream>
#include <string>
#include <vector>
#include "UtilisateurPlatforme.h"

template<typename T>
Participant<T>::Participant(std::string Competence, std::string nom, std::string prenom, std::string Ae): Competence(Competence), UtilisateurPlatforme(nom, prenom, Ae)
{
    Connexion<T>* q = new Connexion<T>();
    cnx.push_back(q);
}

template<typename T>
Participant<T>::~Participant()
{
    for (size_t i = 0; i < cnx.size(); ++i)
    {
        delete cnx[i];
    }
    cnx.clear();
}

template<typename T>
Participant<T>::Participant(const Participant<T> &w) : UtilisateurPlatforme(w)
{
    Competence = w.Competence;
    for (size_t i = 0; i < w.cnx.size(); ++i)
    {
        Connexion<T>* q = new Connexion<T>(*(w.cnx[i]));
        cnx.push_back(q);
    }
}

template<typename T>
std::ostream& operator<< (std::ostream &out, const Participant<T> &p) {
    const UtilisateurPlatforme *q = &p;
    out << *q;
    out << "\nCompetence: " << p.Competence << std::endl;
    for (size_t i = 0; i < p.cnx.size(); ++i) {
        out << p.cnx[i] << std::endl;
    }
    return out;
}


template<typename T>
std::istream& operator>> (std::istream &in, Participant<T> &p)
{
    UtilisateurPlatforme *q = &p;
    in >> *q;

    std::cout << "\n Entrez la competence du participant: ";
    in >> p.Competence;

    T date;
    std::cout << "\n Entrez la date de participation (sous la forme --/--/--): ";
    in >> date;

    Connexion<T> *newConnexion = new Connexion<T>(date);
    p.cnx.push_back(newConnexion);

    return in;
}

template<typename T>
Participant<T>& Participant<T>::operator= (const Participant<T> &p)
{
    if (this != &p)
    {
        UtilisateurPlatforme::operator=(p);
        Competence = p.Competence;

        for (size_t i = 0; i < cnx.size(); ++i)
        {
            delete cnx[i];
        }
        cnx.clear();

        for (size_t i = 0; i < p.cnx.size(); ++i)
        {
            Connexion<T>* newConnexion = new Connexion<T>(*(p.cnx[i]));
            cnx.push_back(newConnexion);
        }
    }
    return *this;
}

template<typename T>
void Participant<T>::communiquerViaMessage()
{
    UtilisateurPlatforme::communiquerViaMessage();
}

template<typename T>
void Participant<T>::communiquerViaCommentaire()
{
    UtilisateurPlatforme::communiquerViaCommentaire();
}
template<typename T>
void Participant<T>::sinscrire()
{
    std::cout << "inscription .." << std::endl;
    UtilisateurPlatforme::sinscrire();
}

template<typename T>

void Participant<T>::remplirFichierParticipant(Participant<T> p) {
    std::fstream f;
    f.open("fichierParticipant.txt", std::ios::out | std::ios::in |std::ios::trunc);
    if (!f.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }
    f << &p << std::endl;
    f.close();
}

template<typename T>

void Participant<T>::afficherFichierParticipant() {
    std::ifstream f("fichierParticipant.txt");
    if (!f.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    Participant<std::string> p;
    while (f >> &p) {
        std::cout << &p << std::endl;
    }

    f.close();
}



template<typename T>
std::ostream& operator<< (std::ostream &out, const Participant<T> *p) {
    const Participant<T> *q = dynamic_cast<const Participant<T>*>(p);
    if (q) {
        out << *q;
        out << "\nCompetence: " << q->Competence << std::endl;
        for (size_t i = 0; i < q->cnx.size(); ++i) {
            out << q->cnx[i] << std::endl;
        }
    }
    return out;
}

template<typename T>
std::istream& operator>> (std::istream &in, Participant<T> *p) {
    Participant<T> *q = dynamic_cast<Participant<T>*>(p);
    if (q) {
        in >> *q;
        std::cout << "\n Entrez la competence du participant: ";
        in >> q->Competence;

        T date;
        std::cout << "\n Entrez la date de participation (sous la forme --/--/--): ";
        in >> date;

        Connexion<T> *newConnexion = new Connexion<T>(date);
        q->cnx.push_back(newConnexion);
    }
    return in;
}

template class Participant<std::string>;
