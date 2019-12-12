
//
//  satellitephone.cpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#include "satellitephone.hpp"
#include <iostream>




Satellitephone::Satellitephone( int year, const string &color, const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection, const string &glonass, const string &gps): Device(year, color, wifi, fourg, sizescreen, productivity,keypad, sensor,connection ),
glonass(glonass),gps(gps) {}

ostream &operator<<(ostream &os, const Satellitephone &scanner) {
    os << "Спутниковый телефон- " << static_cast<const Device &>(scanner) << " Цвет печати: " << scanner.glonass << " Скорость печати: ";
    return os;
}

const string &Satellitephone::getGlonass() const {
    return glonass;
}

void Satellitephone::setGlonass(const string &glonass) {
    Satellitephone::glonass = glonass;
}

const string &Satellitephone::getGps() const {
    return gps;
}

void Satellitephone::setGps(const string &gps) {
    Satellitephone::gps = gps;
}

Satellitephone::~Satellitephone() {
    
    glonass = "";
    gps = "";
}

void Satellitephone::writeToFile(ostream &file) {
    file << "satellitephone" << endl;
    Device::writeToFile(file);
    file << glonass << endl;
    file << gps<< endl;
}

void Satellitephone::readFromFile(istream &file) {
    Device::readFromFile(file);
    string glonass;
    string gps;
    file >> glonass;
    file >> gps;
    this->glonass = glonass;
    this->gps = gps;
}

istream &operator>>(istream &in, Satellitephone &satellitephone) {
    in >> static_cast<Device &>(satellitephone);
    
    string glonass;
    string gps;
    cout << "Наличие Глонасс " << endl;
    in >> glonass;
    cout << "Наличие GPS" << endl;
    in >> gps;
    satellitephone.glonass = glonass;
    satellitephone.gps = gps;
    return in;
}

Satellitephone::Satellitephone() {}

void Satellitephone::toConsole() {
    cout << *this;
}

string Satellitephone::getFilename() {
    return "satellitephone.txt";
}
