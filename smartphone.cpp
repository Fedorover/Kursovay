//
//  smartphone.cpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#include "smartphone.hpp"
#include <iostream>



Smartphone::Smartphone( int year, const string &color, const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection, const string &glonass, const string &gps, int memory ): Device(year, color, wifi, fourg, sizescreen, productivity,keypad, sensor,connection ),
glonass(glonass),
memory(memory),gps(gps) {}

ostream &operator<<(ostream &os, const Smartphone &scanner) {
    os << "Смартфон- " << static_cast<const Device &>(scanner) << " Цвет печати: " << scanner.glonass << " Скорость печати: "
    << scanner.memory;
    return os;
}

const string &Smartphone::getGlonass() const {
    return glonass;
}

void Smartphone::setGlonass(const string &glonass) {
    Smartphone::glonass = glonass;
}

int Smartphone::getMemory() const {
    return memory;
}

void Smartphone::setMemory(int memory) {
    Smartphone::memory = memory;
}
const string &Smartphone::getGps() const {
    return gps;
}

void Smartphone::setGps(const string &gps) {
    Smartphone::gps = gps;
}

Smartphone::~Smartphone() {
    memory = 0;
    glonass = "";
    gps = "";
}

void Smartphone::writeToFile(ostream &file) {
    file << "smartphone" << endl;
    Device::writeToFile(file);
    file << memory << endl;
    file << glonass << endl;
    file << gps<< endl;
}

void Smartphone::readFromFile(istream &file) {
    Device::readFromFile(file);
    int memory;
    string glonass;
    string gps;
    file >> memory;
    file >> glonass;
    file >> gps;
    this->glonass = glonass;
    this->memory = memory;
    this->gps = gps;
}

istream &operator>>(istream &in, Smartphone &smartphone) {
    in >> static_cast<Device &>(smartphone);
    int memory;
    string glonass;
    string gps;
    cout << "Объем памяти " << endl;
    in >> memory;
    cout << "Наличие Глонасс " << endl;
    in >> glonass;
    cout << "Наличие GPS" << endl;
    in >> gps;
    smartphone.glonass = glonass;
    smartphone.memory = memory;
    smartphone.gps = gps;
    return in;
}

Smartphone::Smartphone() {}

void Smartphone::toConsole() {
    cout << *this;
}

string Smartphone::getFilename() {
    return "smartphone.txt";
}


