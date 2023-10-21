#include "Dsocialpolitician.h"

//constructor with values
Dsocialpolitician::Dsocialpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty) : Dpolitician(
        fN, lN, idNumber, powerNumber, pParty) {

}

int Dsocialpolitician::getPower() {
    return power*2; //social politician double his power in election
}

//function that print the details of Democratic social politician
void Dsocialpolitician::printPolitician() {

    cout << "Democratic ";
    Politician::printPolitician();
    cout << ", Type:S, Chairman: " << politicianParty->getChairman() << endl;
}

//social politician dont participate in the primeries
int Dsocialpolitician::getPowerInPrimeries() {
    return 0;
}

void Dsocialpolitician::updateChairman(string firstName, string partyName) {
    Politician::updateChairman(firstName, partyName);
}
