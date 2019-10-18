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
#include <cstdlib>

using namespace std;

struct patientData {
	Patient patientInfo;
	Address address;
	Alergy patientAllergy;
	long PatientID;
};

class patientFullTotal {
public:
	vector <patientData> holder;

};

Patient inputPatientBasicInfo() {
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

Alergy inputAllergy() {
	Alergy alergy;
	cout << "2: Does Patient have allergies enter yes for yes and no for no: ";
	string userInput;
	cin >> userInput;
	if (userInput == "yes") {
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
		}
		else {
			string tempOneSymp;
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
	else {
		cout << endl;
		alergy.dataStart("None", { "None" }, "No allergies noted", { 0 });
		return alergy;
	}

}

Address inputAddress() {
	Address address;
	cout << endl;
	cout << "State: ";
	string tempState;
	cin.ignore();
	getline(cin, tempState);
	cout << endl;
	cout << "City: ";
	string tempCity;
	cin.ignore();
	getline(cin, tempCity);
	cout << endl;
	cout << "Address number: ";
	int tempAddNum;
	cin >> tempAddNum;
	cout << endl;
	cout << "Street name: ";
	string tempStreetName;
	cin.ignore();
	getline(cin, tempStreetName);
	cout << endl;
	address.newPatientAddressStart(tempState, tempCity, tempAddNum, tempStreetName);
	return address;


}

patientData decisionRedo(patientData newPatientTemp) {
	Patient patientTemp;
	Alergy alergyDataTemp;
	Address addressTemp;
	bool time = false;
	string userInput;
	while (time == false) {
		cout << "Enter save to finish entry. Enter patient to redo patient data. "
			"Enter allergy to redo allergy data. Enter address to redo address data.: ";
		cin >> userInput;
		cout << endl;
		if (userInput == "save") {
			time = true;
			return newPatientTemp;
		}
		else if (userInput == "patient") {

		}
		else if (userInput == "allergies") {
			alergyDataTemp = inputAllergy();
			newPatientTemp.patientAllergy = alergyDataTemp;

		}
		else if (userInput == "address") {

		}
	}
}

patientFullTotal testData() {
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
	addressData.newPatientAddressStart("Arizona", "Phoneix", 6341, "Verde Lane");
	newPatient.address = addressData;
	alergyData.dataStart("Faustino Rayas", { "Asthma" }, "difficulty breathing", { 2 });
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
	return -1;
}

void falseOptionSelected(int checkIfExistTemp, patientFullTotal patientDataBaseTemp) {
	bool options = false;
	bool againOptions = false;
	while (options == false) {
		if (againOptions == false) {
			cout << "Entered false option, to cancel search/viewing of info type 0 otherwise" << endl;
		}
		else {
			cout << "3 options of data to display from patient possible" << endl;
		}
		againOptions = true;
		cout << "Type 1 for general patient info" << endl;
		cout << "Type 2 for patient address info" << endl;
		cout << "Type 3 for patient allergy info" << endl;
		cout << "Type 0 to cancel search/viewing of info" << endl;
		int nurseInputTemp;
		cin >> nurseInputTemp;
		cout << endl;
		if (nurseInputTemp == 1) {
			patientDataBaseTemp.holder[checkIfExistTemp].patientInfo.dataOut();
			cout << "ID: " << patientDataBaseTemp.holder[0].PatientID << endl;
			cout << endl;
		}
		else if (nurseInputTemp == 2) {
			patientDataBaseTemp.holder[checkIfExistTemp].address.dataOut();
			cout << endl;
		}
		else if (nurseInputTemp == 3) {
			patientDataBaseTemp.holder[checkIfExistTemp].patientAllergy.dataOut();
			cout << endl;
		}
		else if (nurseInputTemp == 0) {
			options = true;
		}
		else {
			againOptions = false;
		}
	}
}

int main() {
	//initialize
	patientFullTotal patientDataBase = testData();
	Patient patient;
	Alergy alergyData;
	Address addressData;

	bool cancel = false;
	bool checker = false;
	while (checker == false) {
		cout << "Type 1 for search of patient" << endl;
		cout << "Type 2 for new patient entrance" << endl;
		int nurseInput;
		cin >> nurseInput;
		if (nurseInput == 1) {
			if (patientDataBase.holder.size() > 0) {
				string nurseCancel;
				bool checkPatientExist = false;
				while (checkPatientExist == false) {
					int checkIfExist = patientFoundChecker(patientDataBase);

					if (checkIfExist == -1) {
						cout << "Unable to find patient matching input given" << endl;
						cout << "If you want to cancel type cancel other wise type anything to try again: " << endl;
						cin >> nurseCancel;
						if (nurseCancel == "cancel") {
							checkPatientExist = true;
						}
					}
					else {
						if (nurseCancel == "cancel") {

						}
						else {
							bool lookInfo = true;
							checkPatientExist = true;
							while (lookInfo == true) {
								cout << "3 options of data to display from patient possible" << endl;
								cout << "Type 1 for general patient info" << endl;
								cout << "Type 2 for patient address info" << endl;
								cout << "Type 3 for patient allergy info" << endl;
								cout << "Type 0 to cancel search/viewing of info" << endl;
								cin >> nurseInput;
								cout << endl;
								if (nurseInput == 1) {
									patientDataBase.holder[checkIfExist].patientInfo.dataOut();
									cout << "ID: " << patientDataBase.holder[0].PatientID << endl;
									cout << endl;
								}
								else if (nurseInput == 2) {
									patientDataBase.holder[checkIfExist].address.dataOut();
									cout << endl;
								}
								else if (nurseInput == 3) {
									patientDataBase.holder[checkIfExist].patientAllergy.dataOut();
									cout << endl;
								}
								else if (nurseInput == 0) {
									lookInfo = false;
								}
								else {
									lookInfo = false;
									falseOptionSelected(checkIfExist, patientDataBase);
								}
							}
						}

					}
				}
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
			else {
				cout << "Database is empty please add patient data first" << endl;
			}

		}
		else {
			cout << "Task order of entering in new Patient Info:" << endl;
			cout << "1: Basic Patient Info Data:" << endl;
			cout << "2: Allergy Data:" << endl;
			cout << "3: Patient Address Address Data:" << endl;

			cout << "To cancel new Patient input type cancel otherwise type anything else: ";
			string nurseinputCancel;
			cin >> nurseinputCancel;
			if (nurseinputCancel == "cancel") {
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
				if (nurseinputCancel == "cancel") {
					cout << endl;
				}
				else {
					cout << endl;
					alergyData = inputAllergy();
					newPatient.patientAllergy = alergyData;
					cout << "To cancel new Patient input type cancel otherwise type anything else: ";
					cin >> nurseinputCancel;
					if (nurseinputCancel == "cancel") {
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
	return 0;
}
