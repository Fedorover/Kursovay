

#ifndef TP
#define TP


#include "Device.hpp"

class Homephone : public Device {
public:
    void writeToFile(ostream &file) override;
    void readFromFile(istream &file) override;
    
    string getFilename() override;
    
    void toConsole() override;
    
    friend ostream &operator<<(ostream &os, const Homephone &gp);
    friend istream &operator>>(istream &in, Homephone &gp);
};


#endif

