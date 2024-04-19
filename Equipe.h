#ifndef EQUIPE_H
#define EQUIPE_H

#include "Participant.h"
#include "Projet.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

class Equipe {
protected:
    std::string nomEquipe;
    std::vector<Participant<std::string>*> membres;
    Projet projet1;
    std::map<std::string, int> associationNomIdProjet;


public:
    Equipe() = default;
    Equipe(Projet projet, std::string nom = "");
    Equipe(const Equipe& autre);
    virtual ~Equipe();

    void ajouterMembre();
    void supprimerMembre();

    friend std::ostream& operator<<(std::ostream& out, const Equipe& equipe);
    friend std::istream& operator>>(std::istream& in, Equipe& equipe);
    friend std::ostream& operator<<(std::ostream& out, const Equipe* equipe);
    friend std::istream& operator>>(std::istream& in, Equipe* equipe);

    Equipe& operator=(const Equipe& autre);

    static void remplirFichierEquipe(Equipe);
    static void afficherFichierEquipe(std::fstream&);

//************************************************************************************************//
    std::string getNomEquipe() const {
        return nomEquipe;
    }
  //********************************************************************************************//
    Projet getProjet1() const {
        return projet1;
    }
   //********************************************************************************************************************//
    int getIdProjetParNomEquipe(const std::string& nom) const {
        if (associationNomIdProjet.find(nom) != associationNomIdProjet.end()) {
            return associationNomIdProjet.at(nom);
        }
        return -1;
    }
  //***************************************************************************************************************//
    void associerNomEquipeIdProjet(const std::string& nom, int idProjet) {
        associationNomIdProjet[nom] = idProjet;
    }
  //***********************************************************************************************************************//
    std::string getNomEquipeParIdProjet(int idProjet) const {
        for (const auto& pair : associationNomIdProjet) {
            if (pair.second == idProjet) {
                return pair.first;
            }
        }
        return "Aucune Equipe";
    }
   //***************************************************************************************************//
    static std::vector<Equipe> chargerDepuisFichier(const std::string& nomFichier);
    //***************************************************************************************************//
    int getidProjet1(){
    return projet1.getIdProjet();
    }

};

#endif // EQUIPE_H
