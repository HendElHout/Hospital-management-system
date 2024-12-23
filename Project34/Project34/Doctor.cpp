#include "Doctor.h"
#include <iostream>

using namespace std;

Doctor::Doctor(const string& name, int age, char sex, const string& specialization, const string& contact_no)
    : Person(name, age, sex), specialization(specialization), contact_no(contact_no) {}

void Doctor::displayInfo() const {
    cout << "Doctor Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << (sex == 'M' ? "Male" : "Female") << endl;
    cout << "Specialization: " << specialization << endl;
    cout << "Contact No: " << contact_no << endl;
}