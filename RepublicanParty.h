#ifndef ASSIGNMENT5_REPUBLICANPARTY_H
#define ASSIGNMENT5_REPUBLICANPARTY_H //compilation guard

#include "Party.h"
#include "Rleaderpolitician.h"
#include "Rsocialpolitician.h"

//class that inherit from class Party to represent party from type Republican
class RepublicanParty: public Party
{
private:


public:
    RepublicanParty(); //default constructor
    RepublicanParty(string partyN, string chairM); //constructor with values
    virtual ~RepublicanParty(){}; //constructor


    //virtual functions that inherit from Party functions class
    virtual void printParty();
    virtual void primaries();
    virtual int calcPowerInElection();
    virtual int getSize() const;
    virtual void setChairman(string newchairman);


};


#endif //ASSIGNMENT5_REPUBLICANPARTY_H
