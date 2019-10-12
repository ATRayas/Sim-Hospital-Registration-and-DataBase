//
// Created by Alejandro on 10/11/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "Address.h"

Address::Address(){

}

void Address::setState(string tempState) {
    state = tempState;
}

void Address::setCity(string tempCity) {
    city = tempCity;
}

void Address::setAddressNumber(int tempAddressNumber) {
    addressNumber = tempAddressNumber;
}

void Address::setAddressStreetName(string tempAddressStreetName) {
    addressStreetName = tempAddressStreetName;
}

void Address::newPatientAddressStart(string tempState, string tempCity,
        int tempAddressNumber, string tempAddressStreetName) {
    state = tempState;
    city = tempCity;
    addressNumber = tempAddressNumber;
    addressStreetName = tempAddressStreetName;
}


