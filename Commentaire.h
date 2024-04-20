#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

class Commentaire
{
     protected:
        std::string titreCommentaire;
        std::string texteCommentaire;
        std::string nomDestinataireCommentaire;
        std::string nomDestinateurCommentaire;
        time_t dateDeCommentaire ;

    public:
        Commentaire(std::string="", std::string="", std::string="", std::string="");
        virtual ~Commentaire();
        friend std::ostream& operator<<(std::ostream&, const Commentaire&);
        friend std::istream& operator>>(std::istream&, Commentaire&);
        friend std::ostream& operator<<(std::ostream&, Commentaire*);
        friend std::istream& operator>>(std::istream&, Commentaire*);
        static void remplirFichierCommentaire();
        static void afficherFichierCommentaire(std::fstream&);
};

#endif // COMMENTAIRE_H
