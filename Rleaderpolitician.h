#ifndef ASSIGNMENT5_RLEADERPOLITICIAN_H
#define ASSIGNMENT5_RLEADERPOLITICIAN_H //compilation guard

#include "Rpolitician.h"

//class that inherit from Rpolitician that inherit itself from Politician
//the class represent Republican politician from leader type
class Rleaderpolitician: public Rpolitician {

public:
    Rleaderpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty);
    ~Rleaderpolitician();

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



#endif //ASSIGNMENT5_RLEADERPOLITICIAN_H
