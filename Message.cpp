#include "Message.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
Message::Message()
{
    //ctor
}
Message::~Message()
{
    //dtor
}
ostream& operator<< (ostream & out, Message & message)
{
    out << "\nTitre : " << message.titre ;
    out << "\nTexte : " << message.text ;
    out << "\nDestinateur : " << message.destinateur ;
    out << "\nDestinataire : " << message.destinataire ;
    out << "\nDate de publication : " << message.datePublication<<endl ;
    return out ;
}


istream & operator>> ( istream & in, Message & message)
{
    cout << "\nTitre : " ;
    in >> message.titre ;
    fflush(stdin);
    cout << "\nTexte : " ;
    getline(in, message.text ) ;
    cout << "\nDestinateur : " ;
    in >> message.destinateur;
    cout << "\nDestinataire : " ;
    in >> message.destinataire ;
    message.generateTime();
}

ostream& operator<< (ostream & out, Message * message)
{
    out << message->titre << " " << message->text <<" "<<"** "<< " " << message->destinateur << " "<< message->destinataire << " " << message->datePublication << " " ;
    return out ;
}

istream & operator>> ( istream & in, Message * message)
{
    string tmp ="" ;
    in >> message->titre ;
    while (tmp != "**")
    {
        message->text += tmp ;
        message->text += " " ;
        in >> tmp ;
    }
    in >> message->destinateur ;
    in >> message->destinataire ;
    in >> message->datePublication ;
    return in ;
}


void Message::remplirFile(Message& message)
{
    ofstream fi ;
    fi.open("Message.txt" , ios::app );
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }

    fi << &message << endl ;
    fi.close();
}

void Message::afficherMessages()
{
    ifstream fi ;
    fi.open("Message.txt" , ios::in);
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }else{
    Message message ;
    while(1){
        fi >> &message ;
        if (fi.eof())
        {
            break;
        }
        cout << message ;
    }
    }
    fi.close();
}


