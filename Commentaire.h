#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std ;

class Commentaire
{
    public:
        Commentaire();
        virtual ~Commentaire();
        friend ostream& operator<< (ostream & , Commentaire &);
        friend istream& operator>> ( istream & , Commentaire & );
        friend ostream& operator<< (ostream & , Commentaire *);
        friend istream& operator>> ( istream & , Commentaire * );
        void remplirFile( Commentaire& );
        static void afficherFichier();

        void generateTime() {
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);

        int year = localTime->tm_year + 1900;
        int month = localTime->tm_mon + 1;
        int day = localTime->tm_mday;

        datePublication = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
        }


    private:
        string titre ;
        string text ;
        string datePublication ;
        string auteur ;
};

#endif // COMMENTAIRE_H
