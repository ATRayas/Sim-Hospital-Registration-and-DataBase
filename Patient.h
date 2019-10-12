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
    string name;
    string phoneNumber;
    string emergencyContact;
    string dob;
    string sex;

public:
    Patient();
    string getName() { return name; }
    string getPhoneNum() { return phoneNumber; }
    string getEmergencyCon() { return emergencyContact; }
    string getDOB() { return dob; }
    string getSex() { return sex; }

    void setNamePatient(string patientName);
    void setPhonePatient(string patientPhone);
    void setEmergencyContact(string patientEC);
    void setDOBPatient(string patientDOB);
    void setSexPatient(string sexP);
    void dataStart(string patientName, string patientPhone,
            string patientEC, string patientDOB, string sexP);
    void dataOut();

};

#endif //PATIENTS_PATIENT_H
