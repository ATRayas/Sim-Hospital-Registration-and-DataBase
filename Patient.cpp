#include <iostream>
#include <string>
#include <vector>
#include "Alergy.h"
#include "Patient.h"

using namespace std;

Patient::Patient(){

}

void Patient::setNamePatient(string patientName){
    name = patientName;
}

void Patient::setPhonePatient(string patientPhone) {
    phoneNumber = patientPhone;
}

void Patient::setEmergencyContact(string patientEC) {
    emergencyContact = patientEC;
}

void Patient::setDOBPatient(string patientDOB) {
    dob = patientDOB;
}

void Patient::setSexPatient(string sexP) {
    sex = sexP;
}

void Patient::dataStart(string patientName, string patientPhone,
        string patientEC, string patientDOB, string sexP) {
    name = patientName;
    phoneNumber = patientPhone;
    emergencyContact = patientEC;
    dob = patientDOB;
    sex = sexP;
}

void Patient::dataOut() {
    cout << "Patient name: " << name << endl;
    cout << "Patient phone number: " << phoneNumber << endl;
    cout << "Patient emergency contact number: " << emergencyContact << endl;
    cout << "Patient Gender: " << sex << endl;

}
