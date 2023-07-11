#include "student.cpp"
#include "teacher.cpp"

class TA: public student, public teacher{
    public:

    void print()
    {
        cout << "TA" << endl;
    }
};