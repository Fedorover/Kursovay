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
   
    int year;//год производства
    string color;//цвет
    string wifi;//вифи
    string fourg;//4g
    int sizescreen;
   //int memory;
    int productivity;
    string keypad;
    string sensor;
    string connection;
public:
    
    virtual void writeToFile(ostream &file);
    virtual void readFromFile(istream &file);
    virtual string getFilename() = 0;
    
    Device( int year, const string &color, const string &wifi, const string &fourg, int sizescreen, int productivity, const string &keypad, const string &sensor,const string &connection );
      virtual ~Device();
    

    
    const string &getKeypad() const;
    
    const string &getSensor() const;
    
    const string &getConnection() const;
    
    const string &getWifi() const;
    
    const string &getFourg() const;
    
    void setWifi(const string &wifi);
    
  
    void setFourg(const string &fourg);
    
    void setKeypad(const string &keypad);
    
    void setSensor(const string &sensor);
    
    void setConnection(const string &connection);
    
    int getYear() const;
    
    int getSizescreen() const;
    
   //int getMemory() const;
    
    int getProductivity() const;
    
    void setYear(int year);
    
    void setSizescreen(int sizescreen);
    
   // void setMemory(int memory);
    
    void setProductivity(int productivity);
    
    
    const string &getColor() const;
    
    void setColor(const string &color);
    
    //const string &getGlonass() const;
    
    //void setGlonass(const string &glonass);
    
    virtual void toConsole();
    
    friend ostream &operator<<(ostream &os, const Device &device);
    friend istream &operator>>(istream &in, Device &device);
    
    Device();
    
};




#endif /* Device_hpp */


