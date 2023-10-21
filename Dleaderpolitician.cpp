#include "Dleaderpolitician.h"

//constructor with values
Dleaderpolitician::Dleaderpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty) : Dpolitician(
        fN, lN, idNumber, powerNumber, pParty) {

}

int Dleaderpolitician::getPower() {
    return power;
}

//function that print the details of Democratic leader politician
void Dleaderpolitician::printPolitician() {

    cout << "Democratic ";
    Politician::printPolitician();
    cout << ", Type:L, Chairman: " << politicianParty->getChairman() << endl;

}

int Dleaderpolitician::getPowerInPrimeries() {
    return power;
}

void Dleaderpolitician::updateChairman(string firstName, string partyName) {
    Politician::updateChairman(firstName, partyName);
}
