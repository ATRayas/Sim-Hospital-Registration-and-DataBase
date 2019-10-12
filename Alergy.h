//
// Created by Alejandro on 10/11/2019.
//

#ifndef PATIENTS_ALERGY_H
#define PATIENTS_ALERGY_H
#include <string>
#include <vector>
using namespace std;

class Alergy {
private:
    string reporter;
    vector<string> symptoms;
    string description;
    vector<int> severity;

public:
    Alergy();
    void changeDescription(string newDescrip);

    void symptomsDelete(string sympDel);

    void dataStart(string report, string symp, string descript, int sev);

    void addSym(string sympA, int sev);

    void dataOut();

    string getReporter() { return reporter; }
    vector<string> getSymptoms() { return symptoms; }
    string getDescription()  { return description; }
    vector<int> getSeverity()  { return severity; }
};


#endif //PATIENTS_ALERGY_H
