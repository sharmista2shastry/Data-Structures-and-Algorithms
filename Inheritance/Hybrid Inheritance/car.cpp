#include "vehicles.cpp"
#include <iostream>
using namespace std;

class car : virtual public vehicle{
    public: 
        int numGears;

        car(){
            cout << "Car's Default Constructor" << endl;
        }

        /*car(int x, int y): vehicle(5){
            cout << "Car's Parameterised Constructor" << endl;
        }*/

        ~car(){
            cout << " Car's Destructor" << endl;
        }

        /*void print()
        {
            cout << "NumTyres: " << numTyres << endl;
            cout << "Color: " << color << endl;
            cout << "NumGears: " << numGears << endl;
            //cout << "Max Speed: " << maxSpeed << endl;
        }*/
};