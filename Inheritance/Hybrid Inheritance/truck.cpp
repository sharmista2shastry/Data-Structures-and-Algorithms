#include "car.cpp"

class truck: virtual public vehicle{
    public:
    truck(){
        cout << "Truck's default constructor" << endl;
    }

    ~truck(){
        cout << "Truck's Destructor" << endl;
    }
};