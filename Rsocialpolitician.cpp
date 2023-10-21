#include "Rsocialpolitician.h"

//constructor with values
Rsocialpolitician::Rsocialpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty) : Rpolitician(
        fN, lN, idNumber, powerNumber, pParty) {

}

//function that print the details of Republican social politician
void Rsocialpolitician::printPolitician() {

    cout << "Republican ";
    Politician::printPolitician();
    cout << ", Type:S, Chairman: " << politicianParty->getChairman() << endl;

}

int Rsocialpolitician::getPower() {
    return power*2; //social politician double his power in election
}

int Rsocialpolitician::getPowerInPrimeries() {
    return 0;
}

void Rsocialpolitician::updateChairman(string firstName, string partyName) {
    Politician::updateChairman(firstName, partyName);
}
