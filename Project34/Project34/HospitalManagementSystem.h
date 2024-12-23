#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H
using namespace std;
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include <vector>
#include <iostream>

class HospitalManagementSystem {
private:
    vector<Patient> patients;       
    vector<Doctor> doctors;         
    vector<Appointment> appointments; 

public:
    void run();                          
    void addPatient(const Patient& patient); 
    void addDoctor(const Doctor& doctor); 
    void scheduleAppointment(const Appointment& appointment); 
    void displayPatients() const;        
    void displayDoctors() const;         
    void displayAppointments() const;    
};

#endif 