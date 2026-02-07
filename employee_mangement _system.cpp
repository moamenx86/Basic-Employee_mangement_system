#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class employee
{
public:
    int id=0, age=0, salary=0;
    string name="";
    char sex;
};

vector<employee> employeeDB;

int getIntInput() {
    string input;
    getline(cin, input);
    try {
        return stoi(input);
    } catch (...) {
        return 0;
    }
}

//adding employees
void addEmployee()
{
    employee employeeDump;
    string tempSex;

    cout << "enter the employee name:- \n";
    getline(cin, employeeDump.name);

    cout << "enter the salary:- \n";
    employeeDump.salary = getIntInput();

    cout << "enter the age:- \n";
    employeeDump.age = getIntInput();

    cout << "enter the sex(m,f):- \n";
    getline(cin, tempSex);
    if (!tempSex.empty()) {
        employeeDump.sex = tempSex[0];
    }

    employeeDB.push_back(employeeDump);
}

//print all employees
void print_all()
{
    int id = employeeDB.size();
    while(id--)
    {
        cout << employeeDB[id].age << endl << employeeDB[id].salary << endl
             << employeeDB[id].name << endl << employeeDB[id].sex << "\n ----------------\n";
    }
}

//delete an employee
void delete_employee()
{
    if (!employeeDB.empty()) {
        employeeDB.pop_back();
    }
}

// update a salary of an employee
void updateSalary()
{
    string sname = "";
    int newSalary = 0;

    cout << "enter the name of employee:- \n";
    getline(cin, sname);

    cout << "enter the new salary of employee:- \n";
    newSalary = getIntInput();

    int id = employeeDB.size();
    while(id)
    {
        if(sname == employeeDB[id-1].name){
           employeeDB[id-1].salary = newSalary;
           break;
        }
        id--;
    }
}

// system controller
void sys()
{
    while(true)
    {
        string choiceStr;
        cout << "\nenter one of the following choices:-\n-------------------------------\n";
        cout << "1. add\n2. print all\n3. delete\n4. update\n5. exit\n-------------\n";

        getline(cin, choiceStr);
        int choice = 0;
        try { choice = stoi(choiceStr); } catch(...) { choice = 0; }

        switch(choice){
            case 1: addEmployee(); break;
            case 2: print_all(); break;
            case 3: delete_employee(); break;
            case 4: updateSalary(); break;
            case 5: return;
            default: cout << "Invalid choice, try again.\n"; break;
        }
    }
}

int main()
{
    sys();
    return 0;
}
