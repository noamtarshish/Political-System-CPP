#include <string>
#include "Party.h"

//default constructor
Party::Party() {


}

//constructor with values
Party::Party(string partyN,string chairM) {


    partyName=partyN; //initialize strings
    chairman=chairM;


}

//copy constructor
Party::Party(const Party &other) {

    politicianArray=other.politicianArray;
    partyName=other.partyName;
    chairman=other.chairman;

}

//add new politician to the vector that contain all the politicians of the party
void Party::addPolitician(Politician *pol) {

    if (pol == nullptr)
        delete this;
    politicianArray.push_back(pol);

}
//delete politician from the vector that contain all the politicians of the party by find his index
void Party::deletePolitician(Politician *pol) {


    int index;
    for (int i=0;i<politicianArray.size();i++){
        if (politicianArray[i]->getID()==pol->getID())
            index=i;
    }
    politicianArray.erase(politicianArray.begin()+index);

}

string Party::getChairman() const {

    if (this== nullptr)
        return "None";
    return chairman;
}

string Party::getPartyName() const{
    return partyName;
}

void Party::printParty() {

    cout << "Party: " << partyName << ", chairman:" << chairman << ", Size:" << politicianArray.size()  << endl;
    if (!politicianArray.empty()){
    for (int i=0;i<politicianArray.size() ;i++) {
        cout << '\t';
        politicianArray[i]->printPolitician();
    }
    }
}

//function that calculate the power of party in election by sum the overall power of the politician of the party
int Party::calcPowerInElection() {

    int powerSum=0;
    for (int i=0;i<politicianArray.size() ;i++){
        powerSum+=politicianArray[i]->getPower();
    }
    return powerSum;

}

int Party::getSize() const{
    return politicianArray.size();
}


//function that find the politician with the highest power among the leader politician and set him as the chairman
//of the party. the function also update the other politician in the party who is the chairman
void Party::primaries() {

    Politician *leader = nullptr;

    for (int i=0; i<politicianArray.size(); i++)
    {

        if (politicianArray[i]->getPowerInPrimeries() > 0){
            if (leader == nullptr) //if there is no leader until no
                leader=politicianArray[i];
            else if (politicianArray[i]->getPowerInPrimeries() > leader->getPowerInPrimeries())
                leader=politicianArray[i];
        }
    }


    if (leader != nullptr) {
        cout << leader->getFirstName() << " is the chairman of " << partyName << endl;
        this->setChairman(leader->getFirstName()); //update the chairman of the party
        this->update(); //update the other politician who is the chairman

    }

}

Party::~Party() {

    politicianArray.clear(); //destructor for the party
}

void Party::setChairman(string newchairman) {
    chairman=newchairman;
}

//function that update the other politicians in the party who is the chairman
void Party::update() {

    for (int i = 0; i < politicianArray.size(); i++) {
        politicianArray[i]->updateChairman(this->chairman, partyName);

    }

}
//getter to the vector of the politicians party
vector<Politician *> Party::getPolitician() {
    return politicianArray;
}
