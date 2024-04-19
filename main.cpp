#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patient {
private:
    string name;
    string treatmentDate;
    string condition;
    string prescription;
    string dischargeDate;

public:
    Patient(string n, string tDate, string cond, string pres, string dDate)
    : name(n), treatmentDate(tDate), condition(cond), prescription(pres), dischargeDate(dDate) {}

    string getName() const {
        return name;
    }

    void printInfo() const {
        cout << "Patient's Name: " << name
             << "\nTreatment Date: " << treatmentDate
             << "\nCondition Treated: " << condition
             << "\nPrescription: " << prescription
             << "\nDischarge Date: " << dischargeDate << endl << endl;
    }
};

void addPatient(vector<Patient>& patients) {
    string name, treatmentDate, condition, prescription, dischargeDate;
    cout << "Enter Patient's Name, Treatment Date, Condition Treated, Prescription, and Discharge Date:" << endl;
    getline(cin, name);
    getline(cin, treatmentDate);
    getline(cin, condition);
    getline(cin, prescription);
    getline(cin, dischargeDate);
    patients.emplace_back(name, treatmentDate, condition, prescription, dischargeDate);
    cout << "Patient added successfully!\n\n";
}

void searchPatient(const vector<Patient>& patients) {
    string searchName;
    cout << "Enter the name of the patient to search for: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto& patient : patients) {
        if (patient.getName() == searchName) {
            cout << "Patient found:\n";
            patient.printInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No patient found with the name " << searchName << ".\n\n";
    }
}

int main() {
    vector<Patient> patients;
    string command;

    while (true) {
        cout << "Enter command (add, search, exit): ";
        getline(cin, command);

        if (command == "add") {
            addPatient(patients);
        } else if (command == "search") {
            searchPatient(patients);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
