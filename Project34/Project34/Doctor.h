#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

using namespace std;

class Doctor : public Person {
private:
    string specialization;
    string contact_no;

public:
    Doctor(const string& name, int age, char sex, const string& specialization, const string& contact_no);
    void displayInfo() const override; 
};

#endif 