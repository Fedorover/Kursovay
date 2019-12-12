//
//  Phone.hpp
//  kursach
//
//  Created by Fedor Kodzhebash on 12.12.19.
//  Copyright © 2019 Fedor Kodzhebash. All rights reserved.
//

#ifndef Phone_hpp
#define Phone_hpp

#include <stdio.h>
#include <ostream>
#include "Device.hpp"

class Phone {
private:
    static Phone *phone;
    
    int size; 
    Device **devices;
    
    Phone();
public:
    
    Phone(const Phone&) = delete;
    Phone& operator=(Phone&) = delete;
    
    Phone& add(Device &device);
    Phone& remove(int index);
    
    static Phone* getInstance() {
        if(!phone)
            phone = new Phone();
        return phone;
    }
    
    int getSize() const;
    Device **getDevices() const;
    
    void writeToFile();
    void readFromFile();
    
    friend std::ostream &operator<<(std::ostream &os, const Phone &phone);
    
    ~Phone();
};




#endif /* Phone_hpp */
