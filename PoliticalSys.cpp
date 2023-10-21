#include "PoliticalSys.h"
#include <fstream>
#include <string>
#include <sstream>

//default constructor
PoliticalSys::PoliticalSys() {

}

//add politician to the political system. the function ask from the user the details of the politician
//and add the politician to the political system by his type and his party type.
//to every type, the function create Politician and add is to all vectors that he needs to belong.
void PoliticalSys::addPolitician() {

    string first;
    string last;
    int idnumber;
    int powernumber;
    string typePolitician;
    string typeParty;

while (true) {
    try {

        cout << "First name:" << endl;
        cin >> first;
        cout << "Last name:" << endl;
        cin >> last;
        cout << "ID:" << endl;
        cin >> idnumber;
        cout << "Power:" << endl;
        cin >> powernumber;
        cout << "Republican or Democratic person" << endl;
        cin >> typeParty;
        cout << "Leader or Social" << endl;
        cin >> typePolitician;

        if (idnumber < 0 || !checkID(idnumber) || powernumber < 0 || !checkRD(typeParty) || !checkLS(typePolitician)) {
            throw detailsInvalidException();
        }
        addPoliticianWithParameters(first, last, idnumber, powernumber, typePolitician, typeParty);
        break;


    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}
}

//helper function to addPolitician that get the parameters from the user and add the politician to the political system
void PoliticalSys::addPoliticianWithParameters(string& first, string& last, int& idnumber, int& powernumber, string& typePolitician,
                                               string& typeParty) {

    Politician *pol;
    Party *party= nullptr;

    if (typeParty == "R") { //case 1 - the Politician is Republican
        if (typePolitician == "S") { //case 1a- the politician is Republican social
            pol = new Rsocialpolitician(first, last, idnumber, powernumber, party);
            politicianSysArray.push_back(pol);
            socialRepublicanArray.push_back(pol);


        } else { //case 1b - the Politician is Republican leader
            pol = new Rleaderpolitician(first, last, idnumber, powernumber, party);
            politicianSysArray.push_back(pol);
            leaderRepublicanArray.push_back(pol);

        }

        republicanAllArray.push_back(pol); //anyway add him to the vector contain all the Republican politicians
        for (int i = 0; i < republicanPartyArray.size(); i++) { //find the smallest party to add it the new politician
            if (party == nullptr)
                party = republicanPartyArray[i];
            else if (republicanPartyArray[i]->getSize() < party->getSize()) {
                party = republicanPartyArray[i];
            }

        }
        party->addPolitician(pol); //add the politician to the party
        pol->setParty(party); //set the party as the party of the politician

    } else { //case 2 - the politician is Democratic
        if (typePolitician == "S") {  //case 2a - the politician is social
            pol = new Dsocialpolitician(first, last, idnumber, powernumber, party);
            politicianSysArray.push_back(pol);
            socialDemocraticArray.push_back(pol);

        } else { //case 2b - the politician is leader
            pol = new Dleaderpolitician(first, last, idnumber, powernumber, party);
            politicianSysArray.push_back(pol);
            leaderDemocraticArray.push_back(pol);

        }


        democraticAllArray.push_back(pol);   //anyway add him to the vector contain all the Republican politicians
        for (int i = 0; i < democraticPartyArray.size(); i++) { //find the smallest party to add it the  new politician
            if (party == nullptr)
                party = democraticPartyArray[i];
            if (democraticPartyArray[i]->getSize() < party->getSize()) {
                party = democraticPartyArray[i];
            }

        }

        party->addPolitician(pol); //add the politician to the party
        pol->setParty(party); //set the party as the party of the politician
    }




    this->updateBiggestParty(); //check who is the smallest party after the addition of the politician


}

//function that add party to the political system. the function get the name and the type of the party from the user
//the function identify where to add the party and add it. after the addition the function check if there are
//politicians that fit to the party and add them to the new party
void PoliticalSys::addParty() {

while (true) {
    try {
        string nameParty;
        string typeParty;

        cout << "Name:" << endl;
        cin >> nameParty;
        cout << "Republican or Democratic party" << endl;
        cin >> typeParty;

        if (!checkPartyName(nameParty) || !checkRD(typeParty)) {
            throw detailsInvalidException();
        }
        addPartyWithParameters(nameParty,typeParty);
        break;

    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}
}

//helper function to addParty that get the parameters from the user and add the party to the political system
void PoliticalSys::addPartyWithParameters(string& nameParty, string& typeParty) {

    Party *party;


    if (typeParty == "D") { //case 1 - the type of the party is Democratic party
        party = new DemocraticParty(nameParty, "None");
        democraticPartyArray.push_back(party);
        partySysArray.push_back(party);

        for (int i = 0; i < democraticAllArray.size(); i++) {
            //if the politician has not party - the function add it to the new party
            if (democraticAllArray[i]->getParty() == nullptr) {
                party->addPolitician(democraticAllArray[i]);
                democraticAllArray[i]->setParty(party);
            }

                //if the politician has party - the function check if the party is with less politician than his party
            else if (democraticAllArray[i]->getParty()->getSize() > party->getSize()) {
                democraticAllArray[i]->getParty()->deletePolitician(democraticAllArray[i]);
                party->addPolitician(democraticAllArray[i]);
                democraticAllArray[i]->setParty(party);

            }
        }

    } else { //case 2 - the type of the party is Republican party
        party = new RepublicanParty(nameParty, "None");
        republicanPartyArray.push_back(party);
        partySysArray.push_back(party);

        for (int i = 0; i < republicanAllArray.size(); i++) {
            //if the politician has not party - the function add it to the new party
            if (republicanAllArray[i]->getParty() == nullptr) {
                party->addPolitician(republicanAllArray[i]);
                republicanAllArray[i]->setParty(party);

                //if the politician has party - the function check if the party is with less politician than his party
            } else if (republicanAllArray[i]->getParty()->getSize() > party->getSize()) {
                republicanAllArray[i]->getParty()->deletePolitician(republicanAllArray[i]);
                party->addPolitician(republicanAllArray[i]);
                republicanAllArray[i]->setParty(party);

            }
        }
    }
    this->updateBiggestParty(); //calling the update function to determine who is the biggest

}


//function that remove politician from the political system. the function ask the user the id of the politician
//the function search the politician and remove it from his party and from the memory.
void PoliticalSys::removePolitician() {

while(true) {
    try {

        if (politicianSysArray.empty())
            break;

        cout << "---Remove Politician---" << endl;
        int id;
        cout << "Enter the ID:" << endl;
        cin >> id;


        if (id < 0 || checkID(id)) { //if id less than zero or the id is not found
            throw idInvalidException();
        }
        removePoliticianWithParameters(id); //calling to helper function
        break;

    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}
}

//helper function to removePolitician that get the parameters from the user and remove the politician from the political system
void PoliticalSys::removePoliticianWithParameters(int& id) {

    Party *party;
    Politician *pol;

    if (!politicianSysArray.empty()) { //if there are politicians in the political system
        for (int i = 0; i < politicianSysArray.size(); i++) {
            if (politicianSysArray[i]->getID() == id) {
                pol = politicianSysArray[i];
                string firstname = pol->getFirstName();
                string chairman = pol->getParty()->getChairman();
                party = pol->getParty();
                if (chairman == firstname) { //if the removed politician is the chairman of the party
                    for (int j = 0; j < party->getSize(); j++) {
                        party->setChairman("None");

                    }
                }
                party->deletePolitician(pol); //remove the politician
                politicianSysArray.erase(politicianSysArray.begin() + i); //remove his place in vector
                delete pol;
                break;

            }
        }
    } else
        return;

    this->updateBiggestParty(); //calling the update function to determine who is the biggest



}

//function that remove party from the political system. the function gets the name of the party from the user
//the function find the party in the vector that contains all the parties, find all the politicians that
//belong to this party, set their party to nullptr and find for every politician new party that fit to his type
void PoliticalSys::removeParty() {

while(true) {
    try {

        if (partySysArray.empty())
            break;

        cout << "---Remove Party---" << endl;
        string partyName;
        cout << "Enter party name:" << endl;
        cin >> partyName;

        if (checkPartyName(partyName)) {
            throw nameInvalidException();
        }
        removePartyWithParameters(partyName);
        break;

    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}
}

//helper function to removeParty that get the parameters from the user and remove the party from the political system
void PoliticalSys::removePartyWithParameters(string& partyName) {

    Party *party1;
    Politician *pol;
    vector<Party *> partyArray;

    if (!partySysArray.empty()) { //if there are parties in the political system
        for (int i = 0; i < partySysArray.size(); i++) {
            if (partySysArray[i]->getPartyName() == partyName) {
                party1 = partySysArray[i];
                partySysArray.erase(partySysArray.begin() + i); //remove the party from the vector contains all the parties
                break;
            }
        }

        //find if the party is republican or democratic
        for (int x = 0; x < republicanPartyArray.size(); x++) {
            if (republicanPartyArray[x] == party1) {
                partyArray = republicanPartyArray;
                republicanPartyArray.erase(republicanPartyArray.begin() + x);
            }
        }
        for (int x = 0; x < democraticPartyArray.size(); x++) {
            if (democraticPartyArray[x] == party1) {
                democraticPartyArray.erase(democraticPartyArray.begin() + x);
                partyArray = democraticPartyArray;

            }
        }
        party1->setChairman("None");
        for (int j = 0; j < party1->getSize(); j++) {
            pol = party1->getPolitician()[j];
            pol->setParty(nullptr);
            pol->setParty(partyArray[0]);
            partyArray[0]->addPolitician(pol);

            for (int i=1;i<partyArray.size();i++){
                if (pol->getParty()->getSize() > partyArray[i]->getSize()) {
                    pol->getParty()->deletePolitician(pol);
                    pol->setParty(nullptr);
                    pol->setParty(partyArray[i]);
                    partyArray[i]->addPolitician(pol);
                }
            }

        }
        delete party1; //remove the memory of the party

    }

    this->updateBiggestParty();


}


//function that generate elections in the political system. the function divided to three parts:
//part 1 - primaries in every party and determine the chairman
//part 2 - calculate the overall power of every party in the political system
//part 3 - determine the party that win the election
void PoliticalSys::elections() {

    if (partySysArray.empty())
        return;

    cout << "---Primaries----" << endl;
    for (int i=0;i<partySysArray.size();i++)
        partySysArray[i]->primaries();

    cout << "----Elections----" << endl;
    for (int i=0;i<partySysArray.size();i++)
        cout << "Party: " << partySysArray[i]->getPartyName() << ",Power: " << partySysArray[i]->calcPowerInElection() << endl;

    cout << "----Elections Results----" << endl;

    Party *winner = nullptr; //pointer that point to the party that has the highest power and won the election
    for (int i=0;i<partySysArray.size();i++){

        if (winner == nullptr){
            winner=partySysArray[i];
            continue;
        }
        if (partySysArray[i]->calcPowerInElection() > winner->calcPowerInElection())
            winner = partySysArray[i];
    }

    if (winner != nullptr)
        cout << winner->getPartyName() << " party won the elections and " << winner->getChairman() <<
        " is the prime minister" << endl;


}

//function that print all the politician in the political system
void PoliticalSys::printPoliticians() const{

    if (politicianSysArray.empty())
        return;
    cout << "----Politicians----" << endl;
    for (int i=0;i<politicianSysArray.size();i++)
        politicianSysArray[i]->printPolitician();


}

//function that print all the parties in the political system
void PoliticalSys::printParties() const{

    if (partySysArray.empty())
        return;
    cout << "----Parties----" << endl;
    for (int i=0;i<partySysArray.size();i++)
        partySysArray[i]->printParty();


}

//function that display the biggest party and the amount of politicians
void PoliticalSys::BiggestParty() const{

    if (partySysArray.empty())
        return;

    cout << "----Biggest Party----" << endl;
    cout << "[" << biggestParty->getPartyName() << "," << biggestParty->getSize() << "]" << endl;

}

//helper function to the biggest party function that check who is the party with the highest number of politician
//the function called after any change in the amount of politicians of parties in the political system
void PoliticalSys::updateBiggestParty() {

    Party *biggest=nullptr; //pointer to the biggest party
    for (int i=0;i<partySysArray.size();i++){
        if (biggest == nullptr)
            biggest=partySysArray[i];
        else if (partySysArray[i]->getSize() > biggest->getSize()) //if there is party with more politician replace the biggest pointer
            biggest=partySysArray[i];
        else if (partySysArray[i]->getSize() == biggest->getSize()){ //if there is two parties biggest the len of their name determine the biggest
            if (partySysArray[i]->getPartyName().size() > biggest->getPartyName().size())
                biggest=partySysArray[i];
        }
    }

    this->biggestParty=biggest; //update the field of the biggest party


}

//function that get file path into constructor and extract the politicians and parties in the political systems
PoliticalSys::PoliticalSys(string filepath) {

    ifstream file(filepath);
    string line;
    bool politicians = false;
    while (getline(file, line)) {
        if (line == "Politicians:\r") {
            politicians = true;
            continue;
        }
        if (line == "Parties:\r") {
            politicians = false;
            continue;
        }
        if (politicians) {
            string first, last, id, power, typeParty, typePolitician;
            stringstream read(line);
            read >> first >> last >> id >> power >> typeParty >> typePolitician;
            int powerInt = stoi(power);
            int idInt = stoi(id);

            Politician *pol;
            Party *party=nullptr;

            //same actions as in addPolitician() function;
            if (typeParty == "R") {
                if (typePolitician == "S") {
                    pol = new Rsocialpolitician(first, last, idInt, powerInt, party);
                    politicianSysArray.push_back(pol);
                    socialRepublicanArray.push_back(pol);

                } else {
                    pol = new Rleaderpolitician(first, last, idInt, powerInt, party);
                    politicianSysArray.push_back(pol);
                    leaderRepublicanArray.push_back(pol);

                }

                republicanAllArray.push_back(pol);
                if (!republicanPartyArray.empty()) {
                    party = republicanPartyArray[0];
                    for (int i = 1; i < republicanPartyArray.size(); i++) {
                        if (republicanPartyArray[i]->getSize() < party->getSize()) {
                            party = republicanPartyArray[i];
                            party->addPolitician(pol);
                        }

                    }
                }

            } else {
                if (typePolitician == "S") {
                    pol = new Dsocialpolitician(first, last, idInt, powerInt, party);
                    politicianSysArray.push_back(pol);
                    socialDemocraticArray.push_back(pol);

                } else {
                    pol = new Dleaderpolitician(first, last, idInt, powerInt, party);
                    politicianSysArray.push_back(pol);
                    leaderDemocraticArray.push_back(pol);

                }

                democraticAllArray.push_back(pol);
                if (!democraticPartyArray.empty()) {
                    party = democraticPartyArray[0];
                    for (int i = 1; i < democraticPartyArray.size(); i++) {
                        if (democraticPartyArray[i]->getSize() < party->getSize()) {
                            party = democraticPartyArray[i];
                            party->addPolitician(pol);

                        }

                    }
                }

            }
        }

        else{ //same actions as in addParty() function;

            Party *party;
            string nameParty,typeParty;
            stringstream read(line);
            read >> nameParty >> typeParty;

//            addPartyWithParameters(nameParty,typeParty);

            if (typeParty=="D"){
                party = new DemocraticParty(nameParty,"None");
                democraticPartyArray.push_back(party);
                partySysArray.push_back(party);

                for (int i=0;i<democraticAllArray.size();i++) {

                    if (democraticAllArray[i]->getParty() == nullptr){
                        party->addPolitician(democraticAllArray[i]);
                        democraticAllArray[i]->setParty(party);
                    }


                    else if (democraticAllArray[i]->getParty()->getSize() > party->getSize()){
                        democraticAllArray[i]->getParty()->deletePolitician(democraticAllArray[i]);
                        party->addPolitician(democraticAllArray[i]);
                        democraticAllArray[i]->setParty(party);


                    }
                }

            }
            else{
                party = new RepublicanParty(nameParty,"None");
                republicanPartyArray.push_back(party);
                partySysArray.push_back(party);

                for (int i=0;i<republicanAllArray.size();i++){
                    if (republicanAllArray[i]->getParty() == nullptr){
                        party->addPolitician(republicanAllArray[i]);
                        republicanAllArray[i]->setParty(party);
                    }
                    else if (republicanAllArray[i]->getParty()->getSize() > party->getSize()){
                        republicanAllArray[i]->getParty()->deletePolitician(republicanAllArray[i]);
                        party->addPolitician(republicanAllArray[i]);
                        republicanAllArray[i]->setParty(party);

                    }
                }


            }
        }
    }
    this->updateBiggestParty(); //calling the update function to determine who is the biggest

    file.close();

}


//destructor to the class
PoliticalSys::~PoliticalSys() {

    deleteAll();
}

bool PoliticalSys::checkID(int idToCheck) {


    for (int i=0;i<politicianSysArray.size();i++){
        if (politicianSysArray[i]->getID()==idToCheck)
            return false;
    }
    return true;

}

bool PoliticalSys::checkRD(string typeParty) {

    if (typeParty == "R" || typeParty == "D")
        return true;
    else
        return false;
}

bool PoliticalSys::checkLS(string typePol) {

    if (typePol == "L" || typePol == "S")
        return true;
    else
        return false;
}

bool PoliticalSys::checkPartyName(string partyName) {

    for (int i=0;i<partySysArray.size();i++){
        if (partySysArray[i]->getPartyName()==partyName)
            return false;

    }
    return true;
}

void PoliticalSys::deleteAll() {

    for(auto politician : politicianSysArray)
        delete politician; //remove every politician in the political system
    politicianSysArray.clear();

    for(auto party : partySysArray)
        delete party; //delete every party in the political system
    partySysArray.clear();
}








