#include "HospitalManagementSystem.h"
#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

void HospitalManagementSystem::run() {
    cout << "Welcome to the Hospital Management System!" << std::endl;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Schedule Appointment\n";
        cout << "4. Display Patients\n";
        cout << "5. Display Doctors\n";
        cout << "6. Display Appointments\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int reg_no, age;
            char sex;
            string name, address;

            cout << "Enter Registration Number: ";
            cin >> reg_no;
            cout << "Enter Name: ";
            cin.ignore(); 
            getline(std::cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Sex (M/F): ";
            cin >> sex;
            cout << "Enter Address: ";
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, address);

            Patient newPatient(reg_no, name, age, sex, address);
            addPatient(newPatient);
            break;
        }
        case 2: {
            string name, specialization, contact_no;
            int age;
            char sex;

            cout << "Enter Doctor's Name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Sex (M/F): ";
            cin >> sex;
            cout << "Enter Specialization: ";
            cin.ignore(); 
            getline(cin, specialization);
            cout << "Enter Contact Number: ";
            getline(cin, contact_no);

            Doctor newDoctor(name, age, sex, specialization, contact_no);
            addDoctor(newDoctor);
            break;
        }
        case 3: {
            int reg_no;
            string date, time;

            cout << "Enter Patient Registration Number: ";
            cin >> reg_no;

            Patient* patientPtr = nullptr;
            for (auto& patient : patients) {
                if (patient.getRegNo() == reg_no) { 
                    patientPtr = &patient;
                    break;
                }
            }

            if (patientPtr == nullptr) {
                cout << "Patient not found!" << endl;
                break;
            }

   
            cout << "\nAvailable Doctors:\n";
            for (size_t i = 0; i < doctors.size(); ++i) {
                cout << i + 1 << ". ";
                doctors[i].displayInfo();
            }

            
            int doctorChoice;
            cout << "Select a doctor by number: ";
            cin >> doctorChoice;

            if (doctorChoice < 1 || doctorChoice > doctors.size()) {
                cout << "Invalid doctor selection!" << endl;
                break;
            }

            Doctor selectedDoctor = doctors[doctorChoice - 1];

            cout << "Enter Appointment Date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter Appointment Time (HH:MM AM/PM): ";
            cin >> time;

            
            Appointment newAppointment(*patientPtr, selectedDoctor, date, time);
            scheduleAppointment(newAppointment);
            cout << "Appointment scheduled successfully!" << endl;
            break;
        }
        case 4:
            displayPatients();
            break;
        case 5:
            displayDoctors();
            break;
        case 6:
            displayAppointments();
            break;
        case 7:
            std::cout << "Exiting the system." << endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 7);
}


void HospitalManagementSystem::addPatient(const Patient& patient) {
    patients.push_back(patient);
}


void HospitalManagementSystem::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}


void HospitalManagementSystem::scheduleAppointment(const Appointment& appointment) {
    appointments.push_back(appointment);
}


void HospitalManagementSystem::displayPatients() const {
    cout << "\nRegistered Patients:\n";
    for (const auto& patient : patients) {
        patient.displayInfo();
        cout << "------------------------\n";
    }
}


void HospitalManagementSystem::displayDoctors() const {
    cout << "\nRegistered Doctors:\n";
    for (const auto& doctor : doctors) {
        doctor.displayInfo();
        cout << "------------------------\n";
    }
}


void HospitalManagementSystem::displayAppointments() const {
    cout << "\nScheduled Appointments:\n";
    for (const auto& appointment : appointments) {
        appointment.displayAppointment();
        cout << "------------------------\n";
    }
}