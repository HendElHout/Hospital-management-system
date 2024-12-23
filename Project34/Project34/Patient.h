#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

using namespace std;

class Patient : public Person {
private:
    int reg_no;
    string address;

public:
    Patient(int reg_no, const string& name, int age, char sex, const string& address);
    void displayInfo() const override; 
    int getRegNo() const; 
};

#endif 