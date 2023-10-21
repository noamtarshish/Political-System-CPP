#include "Rleaderpolitician.h"
//constructor with values
Rleaderpolitician::Rleaderpolitician(string fN, string lN, int idNumber, int powerNumber, Party *pParty) : Rpolitician(
        fN, lN, idNumber, powerNumber, pParty) {

}

int Rleaderpolitician::getPower() {
    return power;
}
//function that print the details of Republican leader politician
void Rleaderpolitician::printPolitician() {

    cout << "Republican Person:" << firstName << " " << lastName << ", Id:" << id << ", Power:" << power;
    cout << ", Type:L, Chairman: " << politicianParty->getChairman() << endl;

}

int Rleaderpolitician::getPowerInPrimeries() {
    return power;
}

void Rleaderpolitician::updateChairman(string firstName, string partyName) {
    Politician::updateChairman(firstName, partyName);
}
