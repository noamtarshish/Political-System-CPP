#ifndef ASSIGNMENT5_PARTY_H
#define ASSIGNMENT5_PARTY_H //compilation guard
#include "Politician.h"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

class Politician; //declartion that will be class politician soon

//class that represent party in the political system, the class contain her name, the name of her chairman
//(if exist) and vector that contain all the politicians of the party
class Party{

protected:
    string partyName;
    string chairman;
    vector<Politician*> politicianArray;
public:
    Party(); //default constructor
    Party(string partyN, string chairM); //constructor with values
    Party(const Party& other); //copy constructor
    virtual ~Party(); //destructor

    void addPolitician(Politician *pol);
    void deletePolitician(Politician *pol);
    virtual void primaries();
    virtual int calcPowerInElection();
    void update();

    virtual void printParty();

    string getChairman() const;
    string getPartyName() const;
    vector<Politician*> getPolitician();
    virtual int getSize() const;
    virtual void setChairman(string newchairman);


};

#endif //ASSIGNMENT5_PARTY_H
