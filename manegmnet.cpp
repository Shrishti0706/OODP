#include <iostream>
using namespace std;

class EmployeeManager {
private:
    static const int MAX_EMPLOYEES = 100; 
    int employeeIDs[MAX_EMPLOYEES];
    double salaries[MAX_EMPLOYEES];
    int employeeCount;

public:
    EmployeeManager() : employeeCount(0) {}

    
    void updateEmployee(int empID, double newSalary) {
        for (int i = 0; i < employeeCount; i++) {
            if (employeeIDs[i] == empID) {
                salaries[i] = newSalary;
                cout << "Updated salary for Employee ID: " << empID << " to " << newSalary << endl;
                return;
            }
        }

    
        if (employeeCount < MAX_EMPLOYEES) {
            employeeIDs[employeeCount] = empID;
            salaries[employeeCount] = newSalary;
            employeeCount++;
            cout << "Added new employee. ID: " << empID << ", Salary: " << newSalary << endl;
        } else {
            cout << "Error: Employee list is full!" << endl;
        }
    }

    
    void displaySalary(int empID) {
        for (int i = 0; i < employeeCount; i++) {
            if (employeeIDs[i] == empID) {
                cout << "Employee ID: " << empID << ", Salary: " << salaries[i] << endl;
                return;
            }
        }
        cout << "Employee ID not found!" << endl;
    }
};

int main() {
    EmployeeManager manager;
    manager.updateEmployee(101, 50000);
    manager.updateEmployee(102, 60000);
    manager.updateEmployee(101, 55000);  

    manager.displaySalary(101);
    manager.displaySalary(102);
    manager.displaySalary(103);

    return 0;
}
