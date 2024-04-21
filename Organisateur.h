#ifndef ORGANISATEUR_H
#define ORGANISATEUR_H

#include "UtilisateurPlateforme.h"
#include "Equipe.h"

#include "Projet.h"
#include "Juge.h"

class Organisateur : public UtilisateurPlatforme {
protected:
    int idOrganisateur;
public:
    Organisateur(int = 0, std::string = "", std::string = "", std::string = "");
    virtual ~Organisateur();

    friend std::ostream& operator<<(std::ostream& , const Organisateur& );
    friend std::istream& operator>>(std::istream& , Organisateur& );
    friend std::ostream& operator<<(std::ostream& , const Organisateur* );
    friend std::istream& operator>>(std::istream& , Organisateur* );

    void communiquerViaMessage() override;
    void communiquerViaCommentaire() override;
    void annoncerEtRecompenserGagnant(vector<Equipe*>& ,vector<Juge*>&);

    static void remplirFichierOrganisateur(Organisateur );
    static void afficherFichierOrganisateur();


};

#endif // ORGANISATEUR_H
