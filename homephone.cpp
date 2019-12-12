#include <iostream>
#include "homephone.hpp"

void Homephone::writeToFile(ostream &file) {
    file << "homephone" << endl;
    Device::writeToFile(file);
}

void Homephone::readFromFile(istream &file) {
    Device::readFromFile(file);
}

istream &operator>>(istream &in, Homephone &gp) {
    in >> static_cast<Device &>(gp);
    return in;
}

ostream &operator<<(ostream &os, const Homephone &gp) {
    os << "Домашний телефон - " << static_cast<const Device &>(gp);
    return os;
}

void Homephone::toConsole() {
    cout << *this;
}

string Homephone::getFilename() {
    return "homephone.txt";
}




