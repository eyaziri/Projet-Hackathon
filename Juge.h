#ifndef JUGE_H
#define JUGE_H

#include "UtilisateurPlateforme.h"
#include "Projet.h"
#include <string>
#include <vector>
#include <iostream>
#include "Equipe.h"


class Juge : public UtilisateurPlatforme, public Projet
{
protected:
    int idJuge;
    std::vector<Projet*> project;
    std::vector<int> identiteDesProjetsJugeesParCeJuge ;

public:
    Juge(int = 0, std::string="", std::string="",std::string="");
    virtual ~Juge();

    void communiquerViaMessage();
    void communiquerViaCommentaire();
    void DonnerNoteOriginaliteDeProjet(Projet&);
    void DonnerNoteFiabiliteDeProjet(Projet&);
    void DonnerNoteQualiteCodeDeProjet(Projet&);

    friend std::istream& operator>>(std::istream& in, Juge& juge);
    friend std::ostream& operator<<(std::ostream& out, const Juge& juge);
    friend std::istream& operator>>(std::istream& in, Juge * juge);
    friend std::ostream& operator<<(std::ostream& out, const Juge * juge);

    Juge& operator=(const Juge& autre);

    void evaluerProjets(vector<Equipe*>&);
    static bool comparerJugesParScore( Juge* a, Juge* b);

    static void remplirFichierJuge(Juge j);
    static void afficherFichierJuge();

    void remplirIdentiteDesProjetsJugeesParCeJuge();



    const std::vector<int>& getIdentiteDesProjetsJugeesParCeJuge() const {
        return identiteDesProjetsJugeesParCeJuge;
    }

    int getProjectSize()
    {
    return project.size();
    }
    Projet* getOneElementFromProject(int j)
    {
        return project[j];
    }
    void ajouterUnProjetPourLEvaluer(vector<Equipe*>&);
};

#endif // JUGE_H
