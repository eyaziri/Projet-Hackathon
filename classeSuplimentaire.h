#ifndef CLASSESUPLIMENTAIRE_H
#define CLASSESUPLIMENTAIRE_H
#include "Projet.h"
#include "Juge.h"

class classeSuplimentaire:public Projet, public Juge
{
    public:
        classeSuplimentaire();
        virtual ~classeSuplimentaire();

    protected:

    private:
};

#endif // CLASSESUPLIMENTAIRE_H
