//
//  Phone.cpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#include "Phone.hpp"

#include <iostream>
#include <fstream>



#include "smartphone.hpp"
#include "homephone.hpp"
#include "satellitephone.hpp"


using namespace std;

Phone* Phone::phone= nullptr;

Phone::Phone() {
    size = 0;
    devices = new Device*[size];
}

Phone::~Phone() {
    size = 0;
    delete []devices;
}

std::ostream &operator<<(std::ostream &os, const Phone &phone) {
    os << "Всего: " << phone.size << endl;
    for (int i = 0; i < phone.size; ++i) {
        phone.devices[i]->toConsole();
        cout << endl;
    }
    return os;
}

int Phone::getSize() const {
    return size;
}


Device **Phone::getDevices() const {
    return devices;
}

Phone &Phone::add(Device &device) {
    this->size++;
    Device **copy = new Device*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->devices[i];
    }
    this->devices = new Device*[this->size];
    for (int j = 0; j < this->size - 1; ++j) {
        this->devices[j] = copy[j];
    }
    this->devices[size - 1] = &device;
    return *this;
}

Phone &Phone::remove(int index) {
    if (index < 0 || index >= this->size) {
        cout << "Ошибка, неверный индекс массива" << endl;
    } else {
        int k = 0;
        Device **copy = new Device*[this->size-1];
        for (int i = 0; i < this->size; ++i) {
            if (i != index) {
                copy[k] = this->devices[i];
                k++;
            }
        }
        this->size--;
        this->devices = new Device*[this->size];
        for (int j = 0; j < this->size; ++j) {
            this->devices[j] = copy[j];
        }
    }
    return *this;
}

void Phone::writeToFile() {
    const string files[] = {
        "smartphone.txt", "homephone.txt", "satellitephone.txt"
    };
    const int length = 3;
    for (int j = 0; j < 3; ++j) {
        ofstream file;//создаем обьект класса ofstream
        int count = 0;// счетчик
        
        
        try//ИСКЛЮЧЕНИЕ
        {
            file.open(files[j], ios_base::out);// ios_base::out - для того чтобы не удалялось предыдущее

            if (!file.is_open()) // если файл не открыт
            {
                throw 123 ;   //переходим  для обработки ошибки
            }
            cout << "Успешное открытие файла\n" << endl;
        
        }
        catch (int)//ЛОВИМ ИСКЛЮЧЕНИЕ
        {
            cout << " Такого файла не существует\n" << endl;
        }
        
        for (int i = 0; i < size; ++i) {
            if (devices[i]->getFilename() == files[j]) {
                count++;
            }
        }
        file << count << endl;
        for (int i = 0; i < size; ++i) {
            if (devices[i]->getFilename() == files[j]) {
                devices[i]->writeToFile(file);
                file << endl;
            }
        }
        
        try
        {
            file.close();
            cout << "Файл закрыт" << endl;
        }
        catch (const exception& exc)
        {
            cout << " Закрыть файл не удалось. Такого файла не существует" << endl;
        }
            }
}

void Phone::readFromFile() {
    const string files[] = {
        "smartphone.txt", "homephone.txt", "satellitephone.txt"
    };
    for (int j = 0; j < 3; ++j) {
        ifstream is;
        
        
        try//ИСКЛЮЧЕНИЕ
        {
           is.open(files[j], ios_base::in);// ios_base::out - для того чтобы не удалялось предыдущее
            
            if (!is.is_open()) // если файл не открыт
            {
                throw 123 ;   //переходим  для обработки ошибки
            }
            cout << "Успешное открытие файла\n" << endl;
        }
        catch (int)//ЛОВИМ ИСКЛЮЧЕНИЕ
        {
            cout << " Такого файла не существует\n" << endl;
        }
        
        
        int size;
        is >> size;
        for (int i = 0; i < size; ++i) {
            string currentDevice;
            is >> currentDevice;
            if (currentDevice == "smartphone") {
                Smartphone *mfu = new Smartphone();
                mfu->readFromFile(is);
                this->add(*mfu);
            }
            if (currentDevice == "homephone") {
                Homephone *p = new Homephone();
                p->readFromFile(is);
                this->add(*p);
            }
            if (currentDevice == "satellitephone") {
                Satellitephone *sc = new Satellitephone();
                sc->readFromFile(is);
                this->add(*sc);
            }
            
            }
        
        try
        {
            if(!is.is_open()){
                throw 12;
            }
            is.close();
            cout << "Файл закрыт" << endl;
        }
        catch (int)
        {
            cout << " Закрыть файл не удалось. " << endl;
        }
    }
    
    }

