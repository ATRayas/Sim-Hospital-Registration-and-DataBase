#include "Alergy.h"
//
// Created by Alejandro on 10/11/2019.
//

#include <iostream>
#include <string>
#include <vector>
#include "Alergy.h"

using namespace std;

enum Days {Saturday, Sunday, Tuesday, Wednesday, Thursday, Friday};
enum Location {Head, Cheast, legs, arms, hands, feet, crotch, face};

//Alergy::();
//string repor, vector <string> symp,
//        string descript, vector <int> sev
Alergy::Alergy(){

}
void Alergy::changeDescription(string newDescrip){
    description = newDescrip;
}

void Alergy::symptomsDelete(string sympDel){
    for(int i = 0; i < symptoms.size(); i++){
        if(sympDel == symptoms[i]){
            symptoms.erase (symptoms.begin()+i);
            severity.erase (severity.begin()+i);
        }
    }

}
void Alergy::dataStart(string report, string symp, string descript, int sev){
//    cout<< "Only enter one symp";
    reporter = report;
    symptoms.push_back(symp);
    description = (descript);
    severity.push_back(sev);
}

void Alergy::addSym(string sympA, int sev){
    symptoms.push_back(sympA);
    severity.push_back(sev);
}

void Alergy::dataOut(){
    cout << "Reporter: " << reporter << endl;
    cout << "Symptoms: ";
    for (auto const& value : symptoms)
    {
        cout << value << ", ";
    }
    cout << endl;
    cout << "Severity of symptom: ";
    for (auto const& value : severity)
    {
        cout << value << ", ";
    }
    cout << endl;
    cout << "Description: " << description << endl;
}

//class patientsWithSymp{
//public:
//    vector <Alergy> holder;
//};

//int main() {
//    //std::cout << "Hello, World!" << std::endl;
//    Alergy obj;
//    patientsWithSymp dataBase;
//    obj.dataStart("Alejandro", "Asmthma", "difficulty breathing", 2);
//    obj.addSym("dry tounge", 2);
//    //obj.dataOut();
//    obj.symptomsDelete("dry tounge");
//    obj.changeDescription("just normal asthma");
//    //obj.dataOut();
//    dataBase.holder.push_back(obj);
//    Alergy obj2 = dataBase.holder[0];
//    obj2.dataOut();
//
//    return 0;
//}
