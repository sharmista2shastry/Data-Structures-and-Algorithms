#include "vehicles.cpp"
#include <iostream>
using namespace std;

class car : public vehicle{
    public: 
        int numGears;

        void print()
        {
            cout << "NumTyres: " << numTyres << endl;
            cout << "Color: " << color << endl;
            cout << "NumGears: " << numGears << endl;
            cout << "Max Speed: " << maxSpeed << endl;
        }
};