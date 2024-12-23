#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    char sex;


public:
    Person(const string& name, int age, char sex);
    virtual void displayInfo() const = 0; 
};

#endif 