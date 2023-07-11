#include <iostream>
#include <string>
using namespace std;

class vehicle{

    private:
        int maxSpeed;
    
    protected:
        int numTyres;

    public:
        string color;

    /*vehicle(){
        cout << "Vehicle's Default Constructor" << endl;
    }*/

    vehicle(int z){
        maxSpeed = z;
        cout << "Parameterised Constructor" << endl;
    }

    ~vehicle(){
        cout << "Vehicle's Destructor" << endl;
    }
};