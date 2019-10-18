//
// Created by Alejandro on 10/11/2019.
//

#ifndef SIM_HOSPITAL_REGISTRATION_AND_DATABASE_ADDRESS_H
#define SIM_HOSPITAL_REGISTRATION_AND_DATABASE_ADDRESS_H
#include <string>
#include <vector>
using namespace std;

class Address{
private:
string state;
string city;
int addressNumber;
string addressStreetName;


public:
    Address();
    string getState() { return state; }
    string getCity() { return city; }
    int getAddressNumber(){ return  addressNumber; }
    string getAddressStreetName() { return addressStreetName; }

    void setState(string tempState);
    void setCity(string tempCity);
    void setAddressNumber(int tempAddressNumber);
    void setAddressStreetName(string tempAddressStreetName);
    void newPatientAddressStart(string tempState, string tempCity,
            int tempAddressNumber, string tempAddressStreetName);
	void dataOut();



};

#endif //SIM_HOSPITAL_REGISTRATION_AND_DATABASE_ADDRESS_H
