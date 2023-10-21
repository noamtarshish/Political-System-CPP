#include "RepublicanParty.h"
//default constructor
RepublicanParty::RepublicanParty() {

    Party();

}
//constructor with values
RepublicanParty::RepublicanParty(string partyN, string chairM) : Party(partyN, chairM) {

}

//function that print the party
void RepublicanParty::printParty(){

    cout << "Republican ";
    Party::printParty();

}

//function that return the amount of politicians in party
int RepublicanParty::getSize() const{
    return politicianArray.size();
}

//function that set new chairman to the party
void RepublicanParty::setChairman(string newchairman) {
    Party::setChairman(newchairman);

}

//function that do primaries in the party
void RepublicanParty::primaries() {
    Party::primaries();
}

//function that calculate the power of the party in election
int RepublicanParty::calcPowerInElection() {
    return Party::calcPowerInElection();
}

