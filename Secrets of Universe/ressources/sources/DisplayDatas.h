#ifndef DISPLAYDATAS_H
#define DISPLAYDATAS_H

#include <Coordonnees.h>

class DisplayDatas
{
    public:
        DisplayDatas(int,int,Coordonnees);
        virtual ~DisplayDatas();

        Coordonnees coor;
        int type;
        int etat;
};

#endif // DISPLAYDATAS_H