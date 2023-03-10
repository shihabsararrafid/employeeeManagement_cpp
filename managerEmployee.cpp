#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Menu()
{
    cout << "*********Main Menu ************\n";
    cout << "  1.Add Employee\n ";
    cout << " 2.Add Manager\n ";
    cout << " 3.Add Employee to Manager\n ";
    cout << " 4.Delete Employee from Manager\n ";
    cout << " 5.Delete Employee\n ";
    cout << " 6.Delete Manager\n ";
    cout << " 7.Show Employee Info\n ";
    cout << " 8.Show Manager Info\n ";
    cout << " 9.Exit\n ";
    cout << "Enter a valid option <1-9>\n THANK YOU\n";
}
class employee
{
public:
    string name;
    string code;
    int salary;
    int age;
    bool is_manager = false;
    bool is_added = false;
    employee(string name, string code, int salary, int age)
    {
        this->name = name;
        this->code = code;
        this->salary = salary;
        this->age = age;
    }
    void Display(string status)
    {
        cout << status + " Name   : " << name << "\n";
        cout << status + " Code   : " << code << "\n";
        cout << status + " Salary : " << salary << "\n";
        cout << status + " Age    : " << age << "\n";
    }
    string getCode()
    {
        return code;
    }
    void setAdded()
    {
        is_added = true;
    }
    bool checkAdded()
    {
        return is_added;
    }
};
vector<employee> e;

int SearchInEmployeeList(string code)
{
    int index = -1;
    for (int i = 0; i < e.size(); i++)
    {
        if (e[i].getCode() == code)
            return i;
    }
    return index;
}

class manager : public employee
{
    vector<string> supervisedEmployee;

public:
    manager(string name, string code, int salary, int age) : employee(name, code, salary, age)
    {
        is_manager = true;
    };
    void addEmployeeToManager(string code)
    {
        supervisedEmployee.push_back(code);
    }
    void deleteEmployeeFromManager(string c)
    {
        int index = -1;
        for (int i = 0; i < supervisedEmployee.size(); i++)
        {
            if (supervisedEmployee[i] == c)
            {
                index = i;
            }
        }
        if (index == -1)
        {
            cout << "\nThis employee is not added to the manager\n ";
        }
        else
        {
            supervisedEmployee.erase(supervisedEmployee.begin() + index);
            cout << "\n Employee Successfully Deleted from Manager Supervision\n ";
        }
    }
    void Display(string status)
    {

        employee::
            Display(status);
        if (supervisedEmployee.size() > 0)
        {
            cout << "\nHere is the employee list who are in supervision of Mr. " + name << endl;
            for (int i = 0; i < supervisedEmployee.size(); i++)
            {
                int index = -1;

                index = SearchInEmployeeList(supervisedEmployee[i]);
                if (index == -1)
                    cout << "Employee List has been deleted\n";
                else
                    e[index].Display(status);
                cout << "\n";
            }
        }
        else
        {
            cout << "No employee is under supervision of Mr. " + name << "\n";
        }
    }
    string getCode()
    {
        // cout << " Calling get code \n"
        //  << endl;
        return employee::
            getCode();
    }
    void addEmployee(string c)
    {
        supervisedEmployee.push_back(c);
    }
};

// manager m[100];
vector<manager> m;

int SearchInManagerList(string code)
{
    int index = -1;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i].getCode() == code)
            return i;
    }
    return index;
}

int ec = 0, mc = 0;
void add(int option)
{
    string status;
    if (option == 1)
        status = "Employee";
    else if (option == 2)
        status = "Manager";

    string name;
    string code = "E000";
    string code1 = "M000";
    int age;
    int salary;
    cout << "Enter " + status + " Name: \n";
    cin >> name;
    cout << "Enter " + status + " Age: \n";
    cin >> age;
    cout << "Enter " + status + " Salary: \n";
    cin >> salary;
    // cout << "Enter " + status + " Name: \n";
    // cin >> name;
    if (option == 1)
    {
        ec++;
        string s = to_string(ec);
        string coden = code + s;
        employee e1(name, coden, age, salary);
        e.push_back(e1);
        cout << status + " added successfully and " + status + " code is -- " << coden << endl;
        // e[ec](name, code, age, salary);
        // employee(name)
    }
    else
    {
        mc++;
        string s = to_string(mc);
        string coden = code1 + s;
        manager m1(name, coden, age, salary);
        m.push_back(m1);
        cout << status + " added successfully and " + status + " code is -- " << coden << endl;
    }
    // cout<<
}
void displayInfo(int option)
{
    string code;
    string status;
    if (option == 7)
        status = "Employee";
    else if (option == 8)
        status = "Manager";
    cout << "Enter " + status + " code :";
    cin >> code;
    int index = -1;
    if (option == 7)
    {

        index = SearchInEmployeeList(code);
        if (index == -1)
            cout << "\n Employee Doesnot Exist in the DataBase \n";
        else
        {

            e[index].Display(status);
        }
    }
    else if (option == 8)
    {

        index = SearchInManagerList(code);
        if (index == -1)
            cout << "\n Manager Doesnot Exists in the List \n";
        // cout << index << endl;
        else
            m[index].Display(status);
    }
}
void addEmployee()
{
    string mCode, eCode;
    cout << " Enter Manager code = \n";
    cin >> mCode;
    cout << " Enter Employee code = \n";
    cin >> eCode;
    int index = -1;
    index = SearchInManagerList(mCode);
    int index2 = -1;
    index2 = SearchInEmployeeList(eCode);
    if (index == -1 && index2 == -1)
        cout << "\n No manager and employee found with this codes\n";
    else if (index == -1)
        cout << "\n No manager found with this code\n";
    else if (index2 == -1)
        cout << "\n No employee found with this code\n";
    else
    {
        if (e[index2].checkAdded())
        {
            cout << "\n You cannot add same employee to different managers\n";
        }
        else
        {
            e[index2].setAdded();

            m[index].addEmployeeToManager(eCode);
            cout << "\n Employee Successfully Added\n";
        }
    }
    // if ()
}
void deleteEmployeeFromManager()
{
    string mCode, eCode;
    cout << "Enter Manager Code : \n";
    cin >> mCode;

    int index = SearchInManagerList(mCode);
    if (index == -1)
    {
        cout << " Sorry !!! Manager Does not Exists \n";
    }
    else
    {
        cout << " Enter Employee Code  : \n";
        cin >> eCode;
        m[index].deleteEmployeeFromManager(eCode);
    }
}

void deleteEmployee()
{
    string mCode, eCode;
    cout << "Enter Employee Code : \n";
    cin >> eCode;
    int index = SearchInEmployeeList(eCode);
    if (index == -1)
    {
        cout << " Sorry !!! Employee Does not Exists \n";
    }
    else
    {
        e.erase(e.begin() + index);
        cout << " Employee Deleted Successfully \n";
    }
}

void deleteManager()
{
    string mCode, eCode;
    cout << "Enter Manager Code : \n";
    cin >> mCode;
    int index = SearchInManagerList(mCode);
    if (index == -1)
    {
        cout << " Sorry !!! Manager Does not Exists \n";
    }
    else
    {
        m.erase(m.begin() + index);
        cout << " Manager Deleted Successfully \n";
    }
}
int main()
{
    while (1)
    {
        /* code */
        Menu();
        int option;
        cin >> option;
        cout << " \n\n";
        if (option > 9)
        {
            cout << "\nDon't You have any eyes !!!!\n Please Enter a valid option . \n";
        }
        else
        {
            if (option == 9)
            {
                cout << " Thank You \n Have a nice time .\n\n";
                return 0;
            }
            else
            {
                switch (option)
                {
                case 1:
                    add(1);
                    break;
                case 2:
                    add(2);
                    break;
                case 3:
                    addEmployee();
                    break;
                case 4:
                    deleteEmployeeFromManager();
                    break;
                case 5:
                    deleteEmployee();
                    break;
                case 6:
                    deleteManager();
                    break;
                case 7:
                    displayInfo(7);
                    break;
                case 8:
                    displayInfo(8);
                    break;
                }
            }
        }
    }

    return 0;
}