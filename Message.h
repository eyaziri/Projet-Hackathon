#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>


class Message
{
protected:
    std::string titre;
    std::string texte;
    std::string nomDestinataire;
    std::string nomDestinateur;
    time_t dateDeMessage;

public:
    Message(std::string t = "", std::string txt = "", std::string destinataire = "", std::string destinateur = "");
    virtual ~Message();

    friend std::ostream& operator<<(std::ostream&, const Message&);
    friend std::istream& operator>>(std::istream&, Message&);
    friend std::ostream& operator<<(std::ostream&, Message*);
    friend std::istream& operator>>(std::istream&, Message*);

    static void remplirFichierMessage();
    static void afficherFichierMessage(std::fstream&);
};
#endif // MESSAGE_H
