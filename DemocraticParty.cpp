#include "DemocraticParty.h"

//default constructor
DemocraticParty::DemocraticParty() {

    Party();

}

//constructor with values
DemocraticParty::DemocraticParty(string partyN, string chairM) : Party(partyN, chairM) {

}

//function that print the party
void DemocraticParty::printParty(){

    cout << "Democrat ";
    Party::printParty();

}

//function that return the amount of politicians in party
int DemocraticParty::getSize() const {
    return politicianArray.size();
}

//function that set new chairman to the party
void DemocraticParty::setChairman(string newchairman) {
    Party::setChairman(newchairman);

}

//function that do primaries in the party
void DemocraticParty::primaries() {
    Party::primaries();
}

//function that calculate the power of the party in election
int DemocraticParty::calcPowerInElection() {
    return Party::calcPowerInElection();
}




