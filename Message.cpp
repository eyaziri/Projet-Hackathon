#include "Message.h"

Message::Message(std::string titre, std::string texte, std::string nomDestinataire, std::string nomDestinateur): titre(titre), texte(texte), nomDestinataire(nomDestinataire), nomDestinateur(nomDestinateur) {
    dateDeMessage = time(0);
}

Message::~Message() {}

std::ostream& operator<<(std::ostream& out, const Message& m) {
    out << "\n- Le titre du message est : " << m.titre << std::endl;
    out << "\n- Le destinataire du message est : " << m.nomDestinataire << std::endl;
    out << "\n- Le destinateur du message est : " << m.nomDestinateur << std::endl;
    char* dt = ctime(&m.dateDeMessage);
    out << "\n- La date et l'heure du message sont : " << dt;
    out << "\n- Le contenu du message est : " << m.texte << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Message& m) {
    std::cout << "\nDonner le titre du message : ";
    std::getline(in >> std::ws, m.titre);
    std::cout << "\nDonner le nom du destinateur du message : ";
    std::getline(in >> std::ws, m.nomDestinateur);
    std::cout << "\nDonner le nom du destinataire du message : ";
    std::getline(in >> std::ws, m.nomDestinataire);
    std::cout << "\nDonner le contenu du message : ";
    std::getline(in >> std::ws, m.texte);
    m.dateDeMessage = time(0);
    return in;
}

std::ostream& operator<<(std::ostream& out, Message* m) {
    out << m->titre << "\t" << m->nomDestinataire << "\t" << m->nomDestinateur << "\t" << m->texte << "\t";
    char* dt = ctime(&m->dateDeMessage);
    out << dt;
    return out;
}

std::istream& operator>>(std::istream& in, Message* m) {
    std::getline(in >> std::ws, m->titre);
    std::getline(in >> std::ws, m->nomDestinateur);
    std::getline(in >> std::ws, m->nomDestinataire);
    std::getline(in >> std::ws, m->texte);
    in >> m->dateDeMessage;
    return in;
}

void Message::remplirFichierMessage() {
    std::fstream f;
    f.open("fichierMessage.txt", std::ios::out | std::ios::app);
    if (!f.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    Message m;
    std::cin >> m;
    f << m << std::endl;
    f.close();
}

void Message::afficherFichierMessage(std::fstream& f) {
    f.open("fichierMessage.txt", std::ios::in);
    if (!f.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    Message m;
    while (f >> m) {
        std::cout << m << std::endl;
    }

    f.close();
}
