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
    float noteOriginaliteDeProjet = 0;
    float noteFiabiliteDeProjet = 0;
    float noteQualiteCode = 0;
    float score ;

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

    int getIdProjet() {
        return idProjet;
    }

    int getTechnologieAvancee()  {
        return technologieAvancee;
    }

    float getNoteOriginaliteDeProjet()  {
        return noteOriginaliteDeProjet;
    }

    float getNoteFiabiliteDeProjet()  {
        return noteFiabiliteDeProjet;
    }

    float getNoteQualiteCode()  {
        return noteQualiteCode;
    }

    float getScore() {
        return score ;
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

    void setScore( float x ) {
        score = x ;
    }
    void setTitreProjet( string p )
    {
        titreProjet=p;
    }
    void setDescription( string d )
    {
        description=d;
    }

    void setTechnologieAvancee( int x ) {
        technologieAvancee=x;
    }
    float getNoteFiabilite()
    {
        return noteFiabiliteDeProjet;
    }

    float getNoteoriginalite()
    {
        return noteOriginaliteDeProjet;
    }


};

#endif // PROJET_H
