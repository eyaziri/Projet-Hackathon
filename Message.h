#ifndef MESSAGE_H
#define MESSAGE_H
#include <ctime>
#include <string>

using namespace std ;


class Message
{
    public:
        Message();
        virtual ~Message();
        friend ostream& operator<< (ostream & , Message &);
        friend istream& operator>> ( istream & , Message & );
        friend ostream& operator<< (ostream & , Message *);
        friend istream& operator>> ( istream & , Message * );
        void remplirFile( Message& );
        static void afficherMessages();

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
        string destinateur ;
        string destinataire ;
};

#endif // MESSAGE_H
