#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient(int reg_no, const string& name, int age, char sex, const string& address)
    : Person(name, age, sex), reg_no(reg_no), address(address) {}

void Patient::displayInfo() const {
    cout << "Registration No: " << reg_no << std::endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << (sex == 'M' ? "Male" : "Female") << std::endl;
    cout << "Address: " << address << endl;
}

int Patient::getRegNo() const {
    return reg_no; 

}