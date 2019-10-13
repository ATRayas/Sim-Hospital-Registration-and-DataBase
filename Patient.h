//
// Created by Alejandro on 10/11/2019.
//

#ifndef PATIENTS_PATIENT_H
#define PATIENTS_PATIENT_H
#include <string>
#include <vector>
using namespace std;

class Patient{
private:
    string Fname;
    string Lname;
    string phoneNumber;
    string emergencyContact;
    string dob;
    string sex;

public:
    Patient();
    string getFirstName() { return Fname; }
    string getLasttName() { return Lname; }
    string getPhoneNum() { return phoneNumber; }
    string getEmergencyCon() { return emergencyContact; }
    string getDOB() { return dob; }
    string getSex() { return sex; }

    void setFNamePatient(string patientFName);
    void setLNamePatient(string patientLName);
    void setPhonePatient(string patientPhone);
    void setEmergencyContact(string patientEC);
    void setDOBPatient(string patientDOB);
    void setSexPatient(string sexP);
    void dataStart(string patientFirstName, string patientLastName, string patientPhone,
            string patientEC, string patientDOB, string sexP);
    void dataOut();

};

#endif //PATIENTS_PATIENT_H
