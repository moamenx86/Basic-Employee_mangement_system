#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class employee
{
public:
    int id=0,age=0,salary=0;
    string name="";
    char sex;
};

vector<employee> employeeDB;

void addEmployee()
{
    employee employeeDump;
    cout<<"enter the employee name ,salary ,age ,sex(m,f):- \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,employeeDump.name);
    cin>>employeeDump.salary;
    cin>>employeeDump.age;
    cin>>employeeDump.sex;
    employeeDB.push_back(employeeDump);

}

void print_all()
{
    int id = employeeDB.size();
    while(id--)
    {
        cout<<employeeDB[id].age<<endl<<employeeDB[id].salary<<endl
        <<employeeDB[id].name<<endl<<employeeDB[id].sex<<"\n ----------------\n";

    }
}


void delete_employee()
{
    employeeDB.pop_back();
}

void updateSalary()
{
    string sname="";int newSalary=0;

    cout<<"enter the name of employee:- \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,sname);
    cout<<"enter the new salary of employee:- \n";
    cin>>newSalary;
    int id = employeeDB.size();
    while(id)
    {
        if(sname==employeeDB[id-1].name ){
           employeeDB[id-1].salary=newSalary;
           break;
        }
        id--;

    }

}

void sys()
{
        while(true)
    {
        int choice=0;
        cout<<"enter one of the following choices:-\n-------------------------------\n";
        cout<<"1. add\n2. print all\n3. delete\n4. update\n-------------\n";
        cin>>choice;
        switch(choice){
            case 1: addEmployee(); break;
            case 2: print_all(); break;
            case 3: delete_employee(); break;
            case 4: updateSalary(); break;
            default: break;
        }

    }

}

int main()
{

    sys();
    return 0;

}

