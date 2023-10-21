#include "Politician.h"

//default constructor
Politician::Politician() {

}
//constructor with values
Politician::Politician(string fN, string lN, int idNumber, int powerNumber, Party *pParty) {

    firstName=fN;
    lastName=lN;
    id=idNumber;
    power=powerNumber;
    politicianParty=pParty;

}

//copy constructor
Politician::Politician(const Politician &other) {

    firstName=other.firstName;
    lastName=other.lastName;
    id=other.id;
    power=other.power;
    politicianParty=other.politicianParty;
}

//function that print the details of the politician
void Politician::printPolitician() {


    cout << "Person:" << firstName << " " << lastName << ", Id:" << id << ", Power:" << power;

}

string Politician::getFirstName() const{
    return firstName;
}

string Politician::getLastName() const{
    return lastName;
}

int Politician::getID() const{
    return id;
}

int Politician::getPower() {
    return power;
}


void Politician::updateChairman(string fName, string pName) {

    this->politicianParty->setChairman(fName);
}

int Politician::getPowerInPrimeries() {
    return 0;
}

void Politician::setParty(Party *party) {

    politicianParty = party;

}

Party* Politician::getParty() const{
    return politicianParty;
}


Politician::~Politician() {

    politicianParty=nullptr;

}

