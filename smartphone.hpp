//
//  smartphone.hpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#ifndef smartphone_hpp
#define smartphone_hpp

#include <stdio.h>
#include "Device.hpp"
using namespace std;
#include <string>
#include <ostream>


class Smartphone : public Device {
private:
    string glonass;
    int memory;
    string gps;
public:
    void writeToFile(ostream &file) override;
    
    void readFromFile(istream &file) override;
    
    string getFilename() override;
    
    void toConsole() override;
    
    friend ostream &operator<<(ostream &os, const Smartphone &scanner);
    friend istream &operator>>(istream &is, Smartphone &smartphone);
    
    Smartphone();
    
    Smartphone( int year, const string &color, const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection, const string &glonass, const string &gps, int memory);
    
    const string &getGlonass() const;
    
    void setGlonass(const string &glonass);
    
    int getMemory() const;
    
    void setMemory(int memory);
    
     const string &getGps() const;
    
      void setGps(const string &gps);
    
    virtual ~Smartphone();
    
};

#endif /* smartphone_hpp */
