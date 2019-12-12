//
//  Device.hpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#ifndef Device_hpp
#define Device_hpp

#include <stdio.h>
#include <string>
#include <ostream>

using namespace std;

class Device {
private:
    string gps;//наличие gps
    int year;//год производства
    string color;//цвет
    string glonass;//глонас
    string wifi;//вифи
    string fourg;//4g
    int sizescreen;
    int memory;
    int productivity;
    string keypad;
    string sensor;
    string connection;
public:
    
    virtual void writeToFile(ostream &file);
    virtual void readFromFile(istream &file);
    virtual string getFilename() = 0;
    
    Device(const string &gps, int year, const string &color, const string &glonass, const string &wifi);
    
    const string &getGps() const;
    
    const string &getWifi() const;
    
    void setWifi(const string &wifi);
    
    virtual ~Device();
    
    void setGps(const string &gps);
    
    int getYear() const;
    
    void setYear(int year);
    
    const string &getColor() const;
    
    void setColor(const string &color);
    
    const string &getGlonass() const;
    
    void setGlonass(const string &glonass);
    
    virtual void toConsole();
    
    friend ostream &operator<<(ostream &os, const Device &device);
    friend istream &operator>>(istream &in, Device &device);
    
    Device();
    
};




#endif /* Device_hpp */


