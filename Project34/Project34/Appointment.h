#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"
#include "Doctor.h"

using namespace std;

class Appointment {
private:
    Patient patient;
    Doctor doctor;
    string date; 
    string time; 

public:
    Appointment(const Patient& patient, const Doctor& doctor, const string& date, const string& time);
    void displayAppointment() const; 
};

#endif 