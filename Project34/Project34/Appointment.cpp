#include "Appointment.h"
#include <iostream>

using namespace std;

Appointment::Appointment(const Patient& patient, const Doctor& doctor, const string& date, const string& time)
    : patient(patient), doctor(doctor), date(date), time(time) {}

void Appointment::displayAppointment() const {
    cout << "Appointment Details:" << endl;
    patient.displayInfo(); 
    doctor.displayInfo();  
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
}