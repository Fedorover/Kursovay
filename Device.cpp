//
//  Device.cpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#include "Device.hpp"
#include <iostream>



using namespace std;



int Device::getYear() const {
    return year;
}

void Device::setYear(int year) {
    Device::year = year;
}

int Device::getSizescreen() const {
    return sizescreen;
}

void Device::setSizescreen(int sizescreen) {
    Device::sizescreen = sizescreen;
}



int Device::getProductivity() const {
    return productivity;
}

void Device::setProductivity(int productivity) {
    Device::productivity = productivity;
}

const string &Device::getColor() const {
    return color;
}

void Device::setColor(const string &color) {
    Device::color = color;
}



Device::~Device() {
    color = "";
   // gps = "";
    year = 0;
    color = "";
    //glonass = "";
     sizescreen=0;
    // memory=0;
     productivity=0;
    keypad="";
     sensor="";
     connection="";
    fourg="";
}

const string &Device::getWifi() const {
    return wifi;
}

void Device::setWifi(const string &wifi) {
    Device::wifi = wifi;
}

const string &Device::getFourg() const {
    return fourg;
}

void Device::setFourg(const string &fourg) {
    Device::fourg = fourg;
}

const string &Device::getKeypad() const {
    return keypad;
}

void Device::setKeypad(const string &keypad) {
    Device::keypad = keypad;
}
const string &Device::getSensor() const {
    return sensor;
}

void Device::setSensor(const string &sensor) {
    Device::sensor = sensor;
}
const string &Device::getConnection() const {
    return connection;
}

void Device::setConnection(const string &connection) {
    Device::connection = connection;
}



Device::Device( int year, const string &color,  const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection ) {}

ostream &operator<<(ostream &os, const Device &device) {
    os  << " Год производства: " << device.year << " цвет: " << device.color << " наличие wifi: " << device.wifi
    << ""<<device.fourg <<""<<device.sensor<<""<<device.connection<<""<<device.keypad<<""<<device.productivity<<""<<device.sizescreen;
    return os;
}

void Device::writeToFile(ostream &file) {
    file << year << endl << color  << endl << wifi  << endl << sensor << endl << wifi << endl;
}

void Device::readFromFile(istream &file) {
    string gps;
    file >> gps;
    int year;
    file >> year;
    string color;
    file >> color;
    string glonass;
    file >> glonass;
    string wifi;
    file >> wifi;
    
    this->year = year;
    this->color = color;
   
    this->wifi = wifi;
    
}

istream &operator>>(istream &in, Device &device) {
    
   
    cout << "Введите год производства:" << endl;
    int year;
    in >> year;
    cout << "Введите цвет" << endl;
    string color;
    in >> color;
 
  
    cout << "Введите наличие wifi: " << endl;
    string wifi;
    in >> wifi;

    device.year = year;
    device.color = color;

    device.wifi = wifi;
    return in;
}

Device::Device() {}

void Device::toConsole() {
    cout << *this;
}


