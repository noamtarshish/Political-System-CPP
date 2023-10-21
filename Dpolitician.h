#ifndef ASSIGNMENT5_DPOLITICIAN_H
#define ASSIGNMENT5_DPOLITICIAN_H //compilation guard

#include "Politician.h"

//class that inherit from Politician class and represent Democratic Politician
class Dpolitician: public Politician {

public:
    Dpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty);
    ~Dpolitician();

};


#endif //ASSIGNMENT5_DPOLITICIAN_H
