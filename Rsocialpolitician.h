#ifndef ASSIGNMENT5_RSOCIALPOLITICIAN_H
#define ASSIGNMENT5_RSOCIALPOLITICIAN_H //compilation guard


#include "Rpolitician.h"

//class that inherit from Rpolitician that inherit itself from Politician
//the class represent Republican politician from social type
class Rsocialpolitician: public Rpolitician {

public:
    Rsocialpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty); //constructor with values
    ~Rsocialpolitician();

    //virtual functions that inherit from Politician
    virtual int getPower() ;
    virtual int getPowerInPrimeries() ;
    virtual void printPolitician();
    virtual void setParty(Party *party) {
        Politician::setParty(party);
    }
    virtual Party* getParty() const{
        return Politician::getParty();
    }
    virtual void updateChairman(string firstName,string partyName);


};


#endif //ASSIGNMENT5_RSOCIALPOLITICIAN_H
