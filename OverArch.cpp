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
                    cout << "Enter severity numbers of each symptom in order entered: ";
                    if (userInput == "multiple") {
                        for (int i = numSymp; i < numSymp; i++) {
                            string tempSympInput;
                            cin >> tempSympInput;
                            cout << endl;
                            tempSymp.push_back(tempSympInput);
                        }
                    }
                    else {
                        int tempSev;
                        cin >> tempSev;
                        cout << endl;
                    }
                    cout << "Enter description of allergy/allergies: ";
                    string tempDescription;
                    cin >> tempDescription;
                    cout << endl;
                }
                else{
                    alergy.dataStart("None", {"None"}, "difficulty breathing", {0});
                }
                cout << "3: Enter Patient's Address info: reporter's name, symptoms,"
                        " description of allergy/allergies, severity number: " << endl;
                patient.dataStart("Alejandro Rayas", "6026961550", "None", "09/26/1995", "Male");
                cout << "Task 1 complete" << endl;
                newPatient.patientInfo = patient;
                alergy.dataStart("Faustino Rayas", {"Asthma"}, "difficulty breathing", 2);
                cout << "Task 2 complete" << endl;
                newPatient.patientAllergy = alergy;
                patientDataBase.holder.push_back(newPatient);
                cout << "Are you sure you are done? Enter Yes for Yes:";
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