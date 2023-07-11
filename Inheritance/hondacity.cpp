#include "car.cpp"
#include<iostream>
using namespace std;

class hondaCity : public car{
    public:

    hondaCity(): car (2, 5){
        cout << "Honda City's constructor" << endl;
    }

    ~hondaCity(){
        cout << "Honda City's destructor" << endl;
    }
};