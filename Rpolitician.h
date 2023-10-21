#ifndef ASSIGNMENT5_RPOLITICIAN_H
#define ASSIGNMENT5_RPOLITICIAN_H //compilation guard

#include "Politician.h"

//function that inherit from politician and represent Republican politician
class Rpolitician: public Politician {

public:
    Rpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty);
    ~Rpolitician();

};


#endif //ASSIGNMENT5_RPOLITICIAN_H
