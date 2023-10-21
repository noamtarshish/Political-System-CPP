#ifndef ASSIGNMENT5_POLITICIAN_H
#define ASSIGNMENT5_POLITICIAN_H //compilation guard
#include "Party.h"
#include <string>
using namespace std;
class Party;


//class that represent politician in the political system. the fields in class:
//first name and last name - name of the politician
//power - the power of the politician - used in election and to choose who will be the chairman of the party
//id - id of the politician - unique for every politician
//politicianparty - field from party type that represent the party that the politician belong to
class Politician
{

protected:
    int power;
    Party *politicianParty;
    string firstName;
    string lastName;
    int id;
public:
    Politician();//default constructor
    Politician(string fN, string lN,int idNumber, int powerNumber,Party *pParty); //constructor with values
    Politician(const Politician& other); //copy constructor
    ~Politician();//destructor

    virtual void printPolitician(); //print the politician

    string getFirstName() const; //getter to his first name
    string getLastName() const; //getter to his last name
    int getID() const; //getter to his id
    virtual int getPower() ; //getter to his power
    virtual int getPowerInPrimeries() ; //function that get the power of politician in election
    virtual void updateChairman(string firstName,string partyName); //update the politician who is the chairman
    virtual void setParty(Party *party); //set new party to the politician
    virtual Party* getParty() const; //getter to the party of the politician


};

#endif //ASSIGNMENT5_POLITICIAN_H
