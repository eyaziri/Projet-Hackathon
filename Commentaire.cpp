#include "Commentaire.h"
#include "Commentaire.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>

Commentaire::Commentaire(std::string titre, std::string texte, std::string destinataire, std::string destinateur): titreCommentaire(titre), texteCommentaire(texte), nomDestinataireCommentaire(destinataire), nomDestinateurCommentaire(destinateur) {
    dateDeCommentaire = time(0);
}

Commentaire::~Commentaire() {}

std::ostream& operator<<(std::ostream& out, const Commentaire& m) {
    out << "\n- Titre du commentaire : " << m.titreCommentaire << std::endl;
    out << "\n- Destinateur du commentaire : " << m.nomDestinateurCommentaire << std::endl;
    out << "\n- Destinataire du commentaire : " << m.nomDestinataireCommentaire << std::endl;
    char* dt = ctime(&m.dateDeCommentaire);
    out << "\n- Date et heure du commentaire : " << dt;
    out << "\n- Contenu du commentaire : " << m.texteCommentaire << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Commentaire& m) {
    std::cout << "\nDonner le titre du commentaire : \n";
    std::getline(in, m.titreCommentaire);
    std::cout << "\nDonner le nom du destinateur du commentaire : \n";
    std::getline(in, m.nomDestinateurCommentaire);
    std::cout << "\nDonner le nom du destinataire du commentaire : \n";
    std::getline(in, m.nomDestinataireCommentaire);
    std::cout << "\nDonner le contenu du commentaire : \n";
    std::getline(in, m.texteCommentaire);
    // Assume we'll set the date when the object is created
    m.dateDeCommentaire = time(0);
    return in;
}

std::ostream& operator<<(std::ostream& out, Commentaire* m) {
    out << std::left << std::setw(20) << m->titreCommentaire;
    out << std::left << std::setw(20) << m->nomDestinataireCommentaire;
    out << std::left << std::setw(20) << m->nomDestinateurCommentaire;
    out << std::left << std::setw(20) << m->texteCommentaire;
    char* dt = ctime(&m->dateDeCommentaire);
    out << dt << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Commentaire* m) {
    std::getline(in, m->titreCommentaire);
    std::getline(in, m->nomDestinateurCommentaire);
    std::getline(in, m->nomDestinataireCommentaire);
    std::getline(in, m->texteCommentaire);
    in >> m->dateDeCommentaire;
    return in;
}

void Commentaire::remplirFichierCommentaire() {
    std::fstream f("fichierCommentaire.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!f.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier !" << std::endl;
        exit(-1);
    }

    Commentaire m;
    std::cout << "\n Saisir un commentaire :" << std::endl;
    std::cin >> m;
    f << m << std::endl;
    f.close();
}

void Commentaire::afficherFichierCommentaire(std::fstream& f) {
    f.open("fichierCommentaire.txt", std::ios::in | std::ios::out);
    if (!f.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier !" << std::endl;
        exit(-1);
    }

   Commentaire m;
    f.seekg(0);
    while (f >> m) {
        std::cout << m << std::endl;
    }
    f.close();
}
