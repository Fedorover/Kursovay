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

const string &Device::getGps() const {
    return gps;
}

void Device::setGps(const string &gps) {
    Device::gps = gps;
}

int Device::getYear() const {
    return year;
}

void Device::setYear(int year) {
    Device::year = year;
}

const string &Device::getColor() const {
    return color;
}

void Device::setColor(const string &color) {
    Device::color = color;
}

const string &Device::getGlonass() const {
    return glonass;
}

void Device::setGlonass(const string &glonass) {
    Device::glonass = glonass;
}

Device::~Device() {
    color = "";
    gps = "";
    year = 0;
    color = "";
    glonass = "";
}

const string &Device::getWifi() const {
    return wifi;
}

void Device::setWifi(const string &wifi) {
    Device::wifi = wifi;
}

Device::Device(const string &gps, int year, const string &color, const string &glonass, const string &wifi)
: gps(gps), year(year), color(color), glonass(glonass), wifi(wifi) {}

ostream &operator<<(ostream &os, const Device &device) {
    os << "Наличие GPS: " << device.gps << " год производства: " << device.year << " цвет: " << device.color << " наличие глонасс: "
    << device.glonass << " наличие wifi: " << device.wifi;
    return os;
}

void Device::writeToFile(ostream &file) {
    file << gps << endl << year << endl << color << endl << glonass << endl << wifi << endl;
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
    this->gps = gps;
    this->year = year;
    this->color = color;
    this->glonass = glonass;
    this->wifi = wifi;
    
}

istream &operator>>(istream &in, Device &device) {
    cout << "Введите наличие GPS: " << endl;
    string gps;
    in >> gps;
    cout << "Введите год производства:" << endl;
    int year;
    in >> year;
    cout << "Введите цвет" << endl;
    string color;
    in >> color;
    cout << "Введите наличие глонасс: " << endl;
    string glonass;
    in >> glonass;
    cout << "Введите наличие wifi: " << endl;
    string wifi;
    in >> wifi;
    device.gps = gps;
    device.year = year;
    device.color = color;
    device.glonass = glonass;
    device.wifi = wifi;
    return in;
}

Device::Device() {}

void Device::toConsole() {
    cout << *this;
}


