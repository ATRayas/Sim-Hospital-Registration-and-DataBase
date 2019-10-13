#include <iostream>
#include <string>
#include <vector>
#include "Alergy.h"
#include "Patient.h"

using namespace std;

Patient::Patient(){

}

void Patient::setFNamePatient(string patientFName){
    Fname = patientFName;
}

void Patient::setLNamePatient(string patientLName){
    Lname = patientLName;
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

void Patient::dataStart(string patientFirstName, string patientLastName, string patientPhone,
        string patientEC, string patientDOB, string sexP) {
    Fname = patientFirstName;
    Lname = patientLastName;
    phoneNumber = patientPhone;
    emergencyContact = patientEC;
    dob = patientDOB;
    sex = sexP;
}

void Patient::dataOut() {
    cout << "Patient first name: " << Fname << endl;
    cout << "Patient last name: " << Lname << endl;
    cout << "Patient phone number: " << phoneNumber << endl;
    cout << "Patient emergency contact number: " << emergencyContact << endl;
    cout << "Patient date of birth: " << dob << endl;
    cout << "Patient Gender: " << sex << endl;

}
