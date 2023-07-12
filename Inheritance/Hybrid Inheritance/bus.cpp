#include "truck.cpp"
 
class bus : public car, public truck {
    public:
    bus(){
        cout << "Bus's Default Constructor" << endl;
    }

    ~bus(){
        cout << "Bus's Destructor" << endl;
    }
};