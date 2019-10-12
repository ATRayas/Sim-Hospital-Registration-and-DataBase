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
};

class patientFullTotal{
public:
    vector <patientData> holder;

};

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

patientFullTotal decisionRedo(){
    patientFullTotal patientDataBaseTemp;
    patientData newPatientTemp;
    Patient patientTemp;
    Alergy alergyDataTemp;
    bool time = false;
    while(time == false) {
        cout << "Enter save to finish entry. Enter patient to redo patient data. "
                "Enter allergy to redo allergies data. Enter address to redo address data.: ";
        string userInput;
        cin >> userInput;
        cout << endl;
        if (userInput == "save") {
            time = true;
            patientDataBaseTemp.holder.push_back(newPatientTemp);
            return patientDataBaseTemp;
        }
        else if (userInput == "patient"){
            alergyDataTemp = inputAllergy();
            newPatientTemp.patientAllergy = alergyDataTemp;
        }
        else if (userInput == "allergies"){

        }
        else if (userInput == "address"){

        }
    }
}

int main(){
    //initialize
    patientFullTotal patientDataBase;
    Patient patient;
    Alergy alergyData;
    Address addressData;
    bool time = false;
    bool checker = false;
    while(checker == false) {
        cout << "Type 1 for search of patient" << endl;
        cout << "Type 2 for new patient entrance" << endl;
        int nurseInput;
        cin >> nurseInput;
        if(nurseInput == 1){
            if (patientDataBase.holder.size() > 0){
                patientDataBase.holder[0].patientInfo.dataOut();
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
            patientData newPatient;
            cout << "1: Enter Patient Data: name, phone number, emergency contact number, and gender" << endl;
            cout << "2: Does Patient have allergies enter yes for yes and no for no:" << endl;
            alergyData = inputAllergy();
            cout << "3: Enter Patient's Address info: reporter's name, symptoms,"
                    " description of allergy/allergies, severity number: " << endl;
            patient.dataStart("Alejandro Rayas", "6026961550", "None", "09/26/1995", "Male");
            cout << "Task 1 complete" << endl;
            newPatient.patientInfo = patient;
            alergyData.dataStart("Faustino Rayas", {"Asthma"}, "difficulty breathing", 2);
            cout << "Task 2 complete" << endl;
            newPatient.patientAllergy = alergyData;
            patientDataBase = decisionRedo();
        }


    }
    //patientDataBase.holder
    return 0;
}