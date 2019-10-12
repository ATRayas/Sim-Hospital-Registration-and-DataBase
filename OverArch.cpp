//
// Created by Alejandro on 10/11/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "Alergy.h"
#include "OverArch.h"
#include "Patient.h"

struct patientData {
    Patient patientInfo;
    Alergy patientAllergy;
};

class patientFullTotal{
public:
    vector <patientData> holder;

};



int main(){
    //initialize
    patientFullTotal patientDataBase;
    Patient patient;
    Alergy alergy;
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
            while(time == false) {
                cout << "Order of entering in new Patient Info:" << endl;
                patientData newPatient;
                cout << "1: Enter Patient Data: name, address, phone number, emergency contact number, and gender"
                     << endl;
                cout << "2: Enter Patient's Allergy info reporter's name, symptoms,"
                        " description of allergy/allergies, severity number: " << endl;
                patient.dataStart("Alejandro Rayas", "6341 W Verde Lane", "6026961550", "None", "09/26/1995", "Male");
                cout << "Task 1 complete" << endl;
                newPatient.patientInfo = patient;
                alergy.dataStart("Faustino Rayas", "Asthma", "difficulty breathing", 2);
                cout << "Task 2 complete" << endl;
                newPatient.patientAllergy = alergy;
                patientDataBase.holder.push_back(newPatient);
                cout << "Are you sure you are done? Enter Yes for Yes:";
                string userInput;
                cin >> userInput;
                cout << endl;
                if (userInput == "Yes") {
                    time = true;
                }
            }
        }


    }
    //patientDataBase.holder
    return 0;
}