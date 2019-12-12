//
//  homephone.hpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#ifndef homephone_hpp
#define homephone_hpp

#include <stdio.h>
#include "Device.hpp"
using namespace std;
#include <string>
#include <ostream>


class Homephone : public Device {
private:
    string glonass;
   
    string gps;
public:
    void writeToFile(ostream &file) override;
    
    void readFromFile(istream &file) override;
    
    string getFilename() override;
    
    void toConsole() override;
    
    friend ostream &operator<<(ostream &os, const Homephone &scanner);
    friend istream &operator>>(istream &is, Homephone &homephone);
    
    Homephone();
    
    Homephone( int year, const string &color, const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection, const string &glonass, const string &gps);
    
    const string &getGlonass() const;
    
    void setGlonass(const string &glonass);
    
    const string &getGps() const;
    
    void setGps(const string &gps);
    
    virtual ~Homephone();
    
};

#endif /* homephone_hpp */

