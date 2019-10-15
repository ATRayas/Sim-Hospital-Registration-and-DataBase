//
// Created by Alejandro on 10/11/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "Alergy.h"
#include "OverArch.h"
#include "Patient.h"
#include "Address.h"

struct patientData {
    Patient patientInfo;
    Address address;
    Alergy patientAllergy;
    long PatientID;
};

class patientFullTotal{
public:
    vector <patientData> holder;

};

Patient inputPatientBasicInfo(){
    Patient tempPatient;
    cout << "Patient's first name: ";
    string tempPatientFName;
    cin >> tempPatientFName;
    cout << endl;
    cout << "Patient's last name: ";
    string tempPatientLName;
    cin >> tempPatientLName;
    cout << endl;
    cout << "Patient's phone number: ";
    string tempPatientPhone;
    cin >> tempPatientPhone;
    cout << endl;
    cout << "Patient's emergency contact number: ";
    string tempEmergencyConNum;
    cin >> tempEmergencyConNum;
    cout << endl;
    cout << "Patient's  DOB in XX/XX/XXXX Format: ";
    string tempDOB;
    cin >> tempDOB;
    cout << endl;
    cout << "Patient's gender: ";
    string tempGender;
    cin >> tempGender;
    cout << endl;
    tempPatient.dataStart(tempPatientFName, tempPatientLName, tempPatientPhone,
                          tempEmergencyConNum, tempDOB, tempGender);
    return tempPatient;
}

Alergy inputAllergy(){
    Alergy alergy;
    cout << "2: Does Patient have allergies enter yes for yes and no for no:" << endl;
    string userInput;
    cin >> userInput;
    if(userInput == "yes") {
        cout << "Reporter's name: ";
        string tempRepoName;
        cin >> tempRepoName;
        cout << "Enter multiple for more than one allergies and anything for one: ";
        vector<string> tempSymp;
        string userInput;
        cin >> userInput;
        cout << endl;
        int numSymp = 1;
        if (userInput == "multiple") {
            cout << "Enter number of symptoms: ";

            cin >> numSymp;
            cout << endl;

            for (int i = numSymp; i < numSymp; i++) {
                string tempSympInput;
                cin >> tempSympInput;
                cout << endl;
                tempSymp.push_back(tempSympInput);

            }
        } else {
            string tempOneSymp ;
            cin >> tempOneSymp;
            tempSymp.push_back(tempOneSymp);
            cout << endl;
        }
        vector<int> tempSev;
        cout << "Enter severity numbers of each symptom in order entered: ";
        if (userInput == "multiple") {
            for (int i = numSymp; i < numSymp; i++) {
                int tempSevInput;
                cin >> tempSevInput;
                cout << endl;
                tempSev.push_back(tempSevInput);
            }
        }
        else {
            int tempSevInput;
            cin >> tempSevInput;
            tempSev.push_back(tempSevInput);
            cout << endl;
        }
        cout << "Enter description of allergy/allergies: ";
        string tempDescription;
        cin >> tempDescription;
        cout << endl;
        return alergy;
    }
    else{
        alergy.dataStart("None", {"None"}, "No allergies noted", {0});
        return alergy;
    }

}

Address inputAddress(){
    Address address;
    cout << "State: ";
    string tempState;
    cin >> tempState;
    cout << endl;
    cout << "City: " << endl;
    string tempCity;
    cin >> tempCity;
    cout << endl;
    cout << "Address number: " << endl;
    int tempAddNum;
    cin >> tempAddNum;
    cout << endl;
    cout << "Street name: " << endl;
    string tempStreetName;
    cin >> tempStreetName;
    cout << endl;
    address.newPatientAddressStart(tempState, tempCity, tempAddNum, tempStreetName);
    return address;


}

patientData decisionRedo(patientData newPatientTemp){
    Patient patientTemp;
    Alergy alergyDataTemp;
    Address addressTemp;
    bool time = false;
    while(time == false) {
        cout << "Enter save to finish entry. Enter patient to redo patient data. "
                "Enter allergy to redo allergies data. Enter address to redo address data.: ";
        string userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == "save") {
            time = true;
            return newPatientTemp;
        }
        else if (userInput == "patient"){

        }
        else if (userInput == "allergies"){
            alergyDataTemp = inputAllergy();
            newPatientTemp.patientAllergy = alergyDataTemp;

        }
        else if (userInput == "address"){

        }
    }
}

patientFullTotal testData(){
//          TESTING INPUT BELOW------********************************************************
    cout << "Welcome to the Sim-Hospital-Registration-Database Program by Alejandro Rayas" << endl;
    cout << "This program is pre-loaded with ""fake"" patient data to simulate a hospital database" << endl;
    cout << "Hope you enjoy!" << endl;
    patientFullTotal patientDataBaseTest;
    patientData newPatient;
    Patient patient;
    Alergy alergyData;
    Address addressData;
    patient.dataStart("Alejandro", "Rayas", "6026961550", "None", "09/26/1995", "Male");
    newPatient.patientInfo = patient;
    alergyData.dataStart("Faustino Rayas", {"Asthma"}, "difficulty breathing", {2});
    newPatient.patientAllergy = alergyData;
    newPatient.PatientID = patientDataBaseTest.holder.size() + 1;
    patientDataBaseTest.holder.push_back(newPatient);
    return patientDataBaseTest;

}

int patientFoundChecker(patientFullTotal patientDataBaseSearch) {
    string nurseSearchFName;
    string nurseSearchLName;
    string nurseSearchDOB;
    cout << "Enter patient's first name: ";
    cin >> nurseSearchFName;
    cout << endl;
    cout << "Enter patient's last name: ";
    cin >> nurseSearchLName;
    cout << endl;
    cout << "Enter patient's DOB name: ";
    cin >> nurseSearchDOB;
    cout << endl;
    for (int i = 0; i < patientDataBaseSearch.holder.size(); i++) {
        string tempSearchFname = patientDataBaseSearch.holder[i].patientInfo.getFirstName();
        string tempSearchLname = patientDataBaseSearch.holder[i].patientInfo.getLasttName();
        string tempSearchDOB = patientDataBaseSearch.holder[i].patientInfo.getDOB();
        if (tempSearchFname == nurseSearchFName && tempSearchLname == nurseSearchLName
            && tempSearchDOB == nurseSearchDOB) {
            return i;
        }
    }
    return 0;
}

int main(){
    //initialize
    patientFullTotal patientDataBase = testData();
    Patient patient;
    Alergy alergyData;
    Address addressData;

    bool cancel = false;
    bool checker = false;
    while(checker == false) {
        cout << "Type 1 for search of patient" << endl;
        cout << "Type 2 for new patient entrance" << endl;
        int nurseInput;
        cin >> nurseInput;
        if(nurseInput == 1){
            if (patientDataBase.holder.size() > 0){
                bool checkPatientExist = false;
                int checkIfExist = patientFoundChecker(patientDataBase);
                if(checkIfExist == 0){
                    cout << "Unable to find patient matching input given" << endl;
                    cout << "Try again if you believe this is a mistake" << endl;
                }
                else{
                    cout <<"3 options of data to display from patient possible";
                    cout << "Type 1 for general patient info" << endl;
                    cout << "Type 2 for patient address info" << endl;
                    cout << "Type 3 for patient allergy info" << endl;
                }
                string nurseSearchFName;
                string nurseSearchLName;
                string nurseSearchDOB;
                cout << "Enter patient's first name: ";
                cin >> nurseSearchFName;
                cout << endl;
                cout << "Enter patient's last name: ";
                cin >> nurseSearchLName;
                cout << endl;
                cout << "Enter patient's DOB name: ";
                cin >> nurseSearchDOB;
                cout << endl;
                for(int i = 0; i < patientDataBase.holder.size(); i++){
                    string tempSearchFname = patientDataBase.holder[i].patientInfo.getFirstName();
                    string tempSearchLname = patientDataBase.holder[i].patientInfo.getLasttName();
                    string tempSearchDOB = patientDataBase.holder[i].patientInfo.getDOB();
                    if(tempSearchFname == nurseSearchFName && tempSearchLname == nurseSearchLName
                       && tempSearchDOB == nurseSearchDOB){
                        checkPatientExist = true;
                        return patientDataBase.holder.[i];
                    }
                }
                patientDataBase.holder[0].patientInfo.dataOut();
                cout << "ID: "<< patientDataBase.holder[0].PatientID << endl;
//                cout<< "Enter Patient name then after enter address: ";
//                string tempName;
//                string tempAdd;
//                cin >> tempName;
//                cout << endl;
//                cin >> tempAdd;
//                vector<int>::iterator it = find(patientDataBase.holder.begin(), patientDataBase.holder.end(), tempAdd);
//                tempName = find (patientDataBase.holder.begin(), vec.end(), ser);
//                if (it != vec.end())
//                {
//                    std::cout << "Element " << ser <<" found at position : " ;
//                    std:: cout << it - vec.begin() + 1 << "\n" ;
//                }
//                else
//                    std::cout << "Element not found.\n\n";
            }
            else{
                cout << "Database is empty please add patient data first" << endl;
            }

        }
        else {
            cout << "Task order of entering in new Patient Info:" << endl;
            cout << "1: Basic Patient Info Data:"<< endl;
            cout << "2: Allergy Data:" << endl;
            cout << "3: Patient Address Address Data:" << endl;

            cout << "To cancel new Patient input type cancel otherwise type anything else: ";
            string nurseinputCancel;
            cin >> nurseinputCancel;
            if (nurseinputCancel == "cancel"){
                cout << endl;
            }
            else {
                cout << endl;
                patientData newPatient;
                cout << "1: Enter Patient Data:" << endl;
                patient = inputPatientBasicInfo();
                newPatient.patientInfo = patient;

                cout << "To cancel new Patient input type cancel otherwise type anything else: ";
                cin >> nurseinputCancel;
                if (nurseinputCancel == "cancel"){
                    cout << endl;
                }
                else {
                    cout << endl;
                    cout << "2: Does Patient have allergies enter yes for yes and no for no:" << endl;
                    alergyData = inputAllergy();
                    newPatient.patientAllergy = alergyData;
                    cout << "To cancel new Patient input type cancel otherwise type anything else: ";
                    cin >> nurseinputCancel;
                    if (nurseinputCancel == "cancel"){
                        cout << endl;
                    }
                    else {
                        cout << "3: Enter Patient's Address info:" << endl;
                        addressData = inputAddress();
                        newPatient.address = addressData;
                        newPatient = decisionRedo(newPatient); // While loop to check if data input is done.
                        newPatient.PatientID = patientDataBase.holder.size() + 1;
                        patientDataBase.holder.push_back(newPatient); //insert patient data into our vector
                    }
                }
            }
        }


    }
    //patientDataBase.holder
    return 0;
}
