

//
//  homephone.cpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#include "homephone.hpp"
#include <iostream>



Homephone::Homephone( int year, const string &color, const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection, const string &glonass, const string &gps): Device(year, color, wifi, fourg, sizescreen, productivity,keypad, sensor,connection ),
glonass(glonass),gps(gps) {}

ostream &operator<<(ostream &os, const Homephone &scanner) {
    os << "Смартфон- " << static_cast<const Device &>(scanner) << " Цвет печати: " << scanner.glonass << " Скорость печати: ";
    return os;
}

const string &Homephone::getGlonass() const {
    return glonass;
}

void Homephone::setGlonass(const string &glonass) {
    Homephone::glonass = glonass;
}

const string &Homephone::getGps() const {
    return gps;
}

void Homephone::setGps(const string &gps) {
    Homephone::gps = gps;
}

Homephone::~Homephone() {
    
    glonass = "";
    gps = "";
}

void Homephone::writeToFile(ostream &file) {
    file << "homephone" << endl;
    Device::writeToFile(file);
    file << glonass << endl;
    file << gps<< endl;
}

void Homephone::readFromFile(istream &file) {
    Device::readFromFile(file);
    string glonass;
    string gps;
    file >> glonass;
    file >> gps;
    this->glonass = glonass;
    this->gps = gps;
}

istream &operator>>(istream &in, Homephone &homephone) {
    in >> static_cast<Device &>(homephone);
    
    string glonass;
    string gps;
    cout << "Наличие Глонасс " << endl;
    in >> glonass;
    cout << "Наличие GPS" << endl;
    in >> gps;
    homephone.glonass = glonass;
    homephone.gps = gps;
    return in;
}

Homephone::Homephone() {}

void Homephone::toConsole() {
    cout << *this;
}

string Homephone::getFilename() {
    return "homephone.txt";
}




