#ifndef ASSIGNMENT5_DSOCIALPOLITICIAN_H
#define ASSIGNMENT5_DSOCIALPOLITICIAN_H //compilation guard

#include "Dpolitician.h"

//class that inherit from Dpolitician that inherit itself from Politician
//the class represent Democratic politician from social type
class Dsocialpolitician: public Dpolitician {

public:
    Dsocialpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty); //constructor with values
    ~Dsocialpolitician();

    //virtual functions that inherit from Politician
    virtual int getPower();
    virtual int getPowerInPrimeries();
    virtual void printPolitician();
    virtual void setParty(Party *party) {
        Politician::setParty(party);
    }
    virtual Party* getParty() {
        return Politician::getParty();
    }
    virtual void updateChairman(string firstName,string partyName);



};

#endif //ASSIGNMENT5_DSOCIALPOLITICIAN_H
