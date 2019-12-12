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
    << " наличие 4G: "<<device.fourg <<" наличие сенсора : "<<device.sensor<<" тип связи: "<<device.connection<<" наличие клавиатуры: "<<device.keypad<<" производительность: "<< device.productivity <<" размер экрана: "<<device.sizescreen;
    return os;
}

void Device::writeToFile(ostream &file) {
    file << year << endl << color  << endl << wifi << endl << fourg  << endl << sensor << endl << connection << endl << keypad << endl << productivity << endl<< sizescreen << endl ;
}

void Device::readFromFile(istream &file) {
    int year;
    file >> year;
    
    string color;
    file >> color;
    

    string wifi;
    file >> wifi;
    
    string fourg;
    file >>fourg;
    
    string sensor;
    file >>sensor;
    
    string connection;
    file >>connection;
    
    string keypad;
    file >>keypad;
    
    int productivity;
    file >> productivity;
    
    int sizescreen;
    file >> sizescreen;
    
    
    this->year = year;
    this->color = color;
   
    this->wifi = wifi;
    
    this->fourg = fourg;
    this->sensor = sensor;
    
    this->connection = connection;
    
    this->productivity =productivity;
    this->keypad = keypad;
    
    this->sizescreen = sizescreen;
    
}

istream &operator>>(istream &in, Device &device) {
    
   
    cout << "Введите год производства: " << endl;
    int year;
    in >> year;
    cout << "Введите цвет: " << endl;
    string color;
    in >> color;
    cout << "Введите наличие wifi: " << endl;
    string wifi;
    in >> wifi;
    cout << "Наличие 4G: " << endl;
    string fourg;
    in >> fourg;
    cout << "Наличие сенсора: " << endl;
    string sensor;
    in >> sensor;
    cout << "Тип связи: " << endl;
    string connection;
    in >> connection;
    cout << "Наличие клавиатуры: " << endl;
    string keypad;
    in >> keypad;
    cout << "Введите производительность: " << endl;
    int productivity;
    in >> productivity;
    cout << "Введите размер экрана: " << endl;
    int sizescreen;
    in >> sizescreen;

    
    
    device.year = year;
    device.color = color;
    device.wifi = wifi;
    device.fourg = fourg;
    device.sensor = sensor;
    device.connection = connection;
    device.keypad = keypad;
    device.productivity = productivity;
    device.sizescreen = sizescreen;
    
    
    
    return in;
}

Device::Device() {}

void Device::toConsole() {
    cout << *this;
}


