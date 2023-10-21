#ifndef ASSIGNMENT5_DLEADERPOLITICIAN_H
#define ASSIGNMENT5_DLEADERPOLITICIAN_H //compilation guard

#include "Dpolitician.h"

//class that inherit from Dpolitician that inherit itself from Politician
//the class represent Democratic politician from leader type
class Dleaderpolitician: public Dpolitician {

public:
    Dleaderpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty); //constructor with values
    ~Dleaderpolitician();

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


#endif //ASSIGNMENT5_DLEADERPOLITICIAN_H
