#ifndef PROJET_H
#define PROJET_H

#include <string>
#include <vector>
#include <iostream>

using namespace std ;

class Projet {
protected:
    int idProjet;
    std::string titreProjet;
    std::string description;
    int technologieAvancee;
    float noteOriginaliteDeProjet;
    float noteFiabiliteDeProjet;
    float noteQualiteCode;
    float score;

public:
    Projet(std::string="", std::string="", int=0, int=0);
    virtual ~Projet();

    friend std::istream& operator>>(std::istream&, Projet&);
    friend std::ostream& operator<<(std::ostream&, const Projet&);

    string getTitreProjet()
    {
        return titreProjet;
    }
    string getDescription()
    {
        return description;
    }

    int getIdProjet() const {
        return idProjet;
    }

    int getTechnologieAvancee() const {
        return technologieAvancee;
    }

    float getNoteOriginaliteDeProjet() const {
        return noteOriginaliteDeProjet;
    }

    float getNoteFiabiliteDeProjet() const {
        return noteFiabiliteDeProjet;
    }

    float getNoteQualiteCode() const {
        return noteQualiteCode;
    }

    float getScore() const {
        return score;
    }

    void setNoteOriginaliteDeProjet(float x) {
        noteOriginaliteDeProjet = x;
    }

    void setNoteFiabiliteDeProjet(float x) {
        noteFiabiliteDeProjet = x;
    }

    void setNoteQualiteCode(float x) {
        noteQualiteCode = x;
    }

    void setScore(float x) {
        score = x;
    }
    void setTitreProjet(string p)
    {
        titreProjet=p;
    }
    void setDescription(string d)
    {
        description=d;
    }

    void setTechnologieAvancee(int x) {
        technologieAvancee=x;
    }

};

#endif // PROJET_H
