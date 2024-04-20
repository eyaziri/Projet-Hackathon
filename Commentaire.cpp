#include "Commentaire.h"
#include <fstream>
#include <string>

using namespace std ;

Commentaire::Commentaire()
{
    //ctor
}

Commentaire::~Commentaire()
{
    //dtor
}

ostream& operator<< (ostream & out, Commentaire & commentaire)
{
    out << "\nTitre : " << commentaire.titre ;
    out << "\nTexte : " << commentaire.text ;
    out << "\nAuteur : " << commentaire.auteur ;
    out << "\nDate de publication : " << commentaire.datePublication<<endl ;
    return out ;
}


istream & operator>> ( istream & in, Commentaire & commentaire)
{
    cout << "\nTitre : " ;
    in >> commentaire.titre ;
    fflush(stdin);
    cout << "\nTexte : " ;
    getline(in , commentaire.text ) ;
    cout << "\nAuteur : " ;
    in >> commentaire.auteur;
    commentaire.generateTime();
}

ostream& operator<< (ostream & out, Commentaire * commentaire)
{
    out << commentaire->titre << " " << commentaire->text << " "<< "**" << " " << commentaire->auteur << " " << commentaire->datePublication << " " ;
    return out ;
}

istream & operator>> ( istream & in, Commentaire * commentaire)
{
    string tmp ="";
    in >> commentaire->titre ;
    while(tmp != "**")
    {
        commentaire->text += tmp ;
        commentaire->text += " ";
        in >> tmp ;
    }
    in >> commentaire->auteur;
    in >> commentaire->datePublication ;
    return in ;
}


void Commentaire::remplirFile(Commentaire& commentaire)
{
    ofstream fi ;
    fi.open("Commentaire.txt" ,ios::app );
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }

    fi << &commentaire << endl ;
    fi.close();
}

void Commentaire::afficherFichier()
{
      ifstream fi ;
    fi.open("Commentaire.txt" , ios::in);
    if (!fi.is_open())
    {
        cerr << "error";
        return ;
    }else{
    Commentaire commentaire ;
    while(1){
        fi >> &commentaire ;
        if (fi.eof()){
            break;
        }
        cout << commentaire ;
    }
    }
    fi.close();
}
