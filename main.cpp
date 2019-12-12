#include <iostream>
#include <fstream>

#include "Phone.hpp"
#include "smartphone.hpp"
#include "homephone.hpp"
#include "satellitephone.hpp"
using namespace std;

const string FILENAME = "text.txt";

void printMenu() {
    cout << "0 - выход" << endl;
    cout << "1 - добавить устройство" << endl;
    cout << "2 - удалить устройство" << endl;
    cout << "3 - записать в файл" << endl;
    cout << "4 - прочитать из файла" << endl;
    cout << "5 - вывод устройств на экран" << endl;
}

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    Phone *phone = Phone::getInstance();
    
    bool isRunning = true;
    int mode;
    while (isRunning) {
        printMenu();
        cin >> mode;
        switch(mode) {
            case 0:
                isRunning = false;
                break;
            case 1:
                cout << "Выберите что хотите добавить" << endl;
                cout << "1 - смартфон, 2 - домашний телефон, 3 - спутниковый телефон " << endl;
                int selected;
                cin >> selected;
                if (selected == 1) {
                    Smartphone *p = new Smartphone();
                    cin >> *p;
                    Phone::getInstance()->add(*p);
                }
                if (selected == 2) {
                    Homephone *mfu = new Homephone();
                    cin >> *mfu;
                    Phone::getInstance()->add(*mfu);
                }
                if (selected == 3) {
                    Satellitephone *sc = new Satellitephone();
                    cin >> *sc;
                    Phone::getInstance()->add(*sc);
                }
               
                break;
            case 2:
                cout << "Введите индекс удаляемого устройства" << endl;
                int removed;
                cin >> removed;
                Phone::getInstance()->remove(removed);
                break;
            case 3:
                try {
                    Phone::getInstance()->writeToFile();
                } catch (exception e) {
                    cout << "Не удается записать в файл" << e.what();
                }
                break;
            case 4:
                try {
                    Phone::getInstance()->readFromFile();
                } catch (exception e) {
                    cout << "Не удается прочитать файл" << e.what();
                }
                break;
            case 5:
                cout << *Phone::getInstance();
                break;
                
        }
        
    }
    
    return 0;
}


