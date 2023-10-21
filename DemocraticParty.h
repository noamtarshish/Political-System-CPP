#ifndef ASSIGNMENT5_DEMOCRATICPARTY_H
#define ASSIGNMENT5_DEMOCRATICPARTY_H //compilation guard
#include "Party.h"
#include "Dleaderpolitician.h"
#include "Dsocialpolitician.h"

//class that inherit from class Party to represent party from type Republican
class DemocraticParty: public Party
{

public:
    DemocraticParty(); //default constructor
    DemocraticParty(string partyN, string chairM); //constructor with values
    virtual ~DemocraticParty(){}; //destructor

    //virtual functions that inherit from Party functions class
    virtual void printParty();
    virtual void primaries();
    virtual int calcPowerInElection();
    virtual int getSize() const;
    virtual void setChairman(string newchairman);


};


#endif //ASSIGNMENT5_DEMOCRATICPARTY_H
