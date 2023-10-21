#ifndef ASSIGNMENT5_POLITICALSYS_H
#define ASSIGNMENT5_POLITICALSYS_H //compilation guard
#include "Party.h"
#include "DemocraticParty.h"
#include "RepublicanParty.h"
#include "Politician.h"
#include "Dpolitician.h"
#include "Dsocialpolitician.h"
#include "Dleaderpolitician.h"
#include "Rpolitician.h"
#include "Rsocialpolitician.h"
#include "Rleaderpolitician.h"
#include <vector>
#include "Exception.h"

using namespace std;

//class that represent the political system. the class contain all the politicians and parties
class PoliticalSys{

public:

    vector<Politician*> politicianSysArray; //all the politicians
    vector<Politician*> leaderRepublicanArray; //all the Republican politicians from type leader
    vector<Politician*> socialRepublicanArray; //all the Republican politicians from type social
    vector<Politician*> leaderDemocraticArray; //all the Democratic politicians from type leader
    vector<Politician*> socialDemocraticArray; //all the Democratic politicians from type social
    vector<Politician*> democraticAllArray; //all the Democratic politicians
    vector<Politician*> republicanAllArray; //all the Republican politicians

    Party *biggestParty; //pointer to the biggest party

    vector<Party*> partySysArray; //all the parties
    vector<Party*> democraticPartyArray; //all the democratic parties
    vector<Party*> republicanPartyArray; //all the republican parties


    PoliticalSys(string filepath); //constructor with file path
    PoliticalSys(); //default constructor
    ~PoliticalSys(); //destructor

    void addPolitician(); //add new politician to the political system
    void addPoliticianWithParameters(string& first, string& last, int& idnumber, int& powernumber, string& typePolitician ,string& typeParty);
    void addParty(); //add new party to the political system
    void addPartyWithParameters(string& nameParty,string& typeParty);
    void removePolitician(); //remove politician from the political system
    void removePoliticianWithParameters(int& id);
    void removeParty(); //remove party from the political system
    void removePartyWithParameters(string& partyName);
    void elections(); //do elections in all the parties in the political system
    void printPoliticians() const; //print all the politicians in the political system
    void printParties() const; //print all the parties include their politicians in the political system
    void BiggestParty() const; //print the party with the highest number of politicians in the political system

    //helper functions:
    bool checkID(int idToCheck);
    bool checkRD(string typeParty);
    bool checkLS(string typePol);
    bool checkPartyName(string partyName);
    void updateBiggestParty(); //function that update the biggest party after changes in the political system
    void deleteAll();


};


#endif //ASSIGNMENT5_POLITICALSYS_H
