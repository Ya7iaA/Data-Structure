#include <iostream>
#include <string>
using namespace std;

// Using Linkedlist to track employee salary history

class employeeTracker
{
public:
    int id;
    string name;
    double previousSalary;
    string dateOfChange;
    double bonus;
    employeeTracker *arrow;
};

class employeeSingleLinkedList
{
private:
    employeeTracker *head;

public:
    employeeSingleLinkedList()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void addEmployee(int id, string name, string dateOfChange, double previousSalary)
    {
        if (doSearch(id))
        {
            cout << "This Employee Exist";
        }
        else
        {
            employeeTracker *newNode = new employeeTracker();
            newNode->previousSalary = previousSalary;
            newNode->dateOfChange = dateOfChange;
            newNode->bonus = 0.0;
            newNode->id = id;
            newNode->name = name;
            newNode->arrow = head;
            head = newNode;
        }
    }
    bool doSearch(int id)
    {
        employeeTracker *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                return true;
            }
            temp = temp->arrow;
        }
        return false;
    }
    string getName(int id)
    {
        employeeTracker *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                return temp->name;
            }
            temp = temp->arrow;
        }
        return "";
    }
    void insertRecord(int id, double previousSalary, double bonus, string dateOfChange)
    {
        if (!doSearch(id))
        {
            cout << "Doesn't Exist" << endl;
        }
        else
        {
            employeeTracker *newNode = new employeeTracker();
            newNode->previousSalary = previousSalary;
            newNode->dateOfChange = dateOfChange;
            newNode->bonus = bonus;
            newNode->id = id;
            string name = getName(id);
            newNode->name = name;
            newNode->arrow = head;
            head = newNode;
        }
    }
    void displayAllEmployee()
    {
        if (isEmpty())
        {
            cout << "No Employee Founded" << endl;
        }
        else
        {
            employeeTracker *temp = head;
            int empId[100];
            string empName[100];
            int curArr = 0;
            while (temp != NULL)
            {
                bool found = false;
                for (int i = 0; i < curArr; i++)
                {
                    if (temp->id == empId[i])
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    empId[curArr] = temp->id;
                    empName[curArr] = temp->name;
                    curArr++;
                }
                temp = temp->arrow;
            }
            for (int i = 0; i < curArr; i++)
            {
                cout << "Employee ID: " << empId[i] << endl
                     << "Employee Name: " << empName[i] << endl;
                cout << "---------------------------" << endl;
            }
        }
    }
    void displayRecord(int id)
    {
        if (doSearch(id))
        {
            employeeTracker *temp = head;
            while (temp != NULL)
            {
                if (temp->id == id)
                {
                    cout << "Employee ID: " << temp->id << endl
                         << "Employee Name: " << temp->name << endl
                         << "Previous Salary: " << temp->previousSalary << endl
                         << "Bonus: " << temp->bonus << endl
                         << "Date of Change: " << temp->dateOfChange << endl;
                    cout << "---------------------------" << endl;
                    temp = temp->arrow;
                }
                else
                {
                    temp = temp->arrow;
                }
            }
        }
        else
        {
            cout << "No record found with ID: " << id << endl;
        }
    }
    void displayAllRecords()
    {
        if (isEmpty())
        {
            cout << "No Records Founded" << endl;
        }
        else
        {
            employeeTracker *temp = head;
            while (temp != NULL)
            {
                cout << "Employee ID: " << temp->id << endl
                     << "Employee Name: " << temp->name << endl
                     << "Previous Salary: " << temp->previousSalary << endl
                     << "Bonus: " << temp->bonus << endl
                     << "Date of Change: " << temp->dateOfChange << endl;
                cout << "---------------------------" << endl;
                temp = temp->arrow;
            }
        }
    }
};

int main()
{
    int id, process;
    double previousSalary, bonus;
    string name, dateOfChange;
    employeeSingleLinkedList trackEmployee;
    do
    {
        cout << "===Employee Salary History Tracker===" << endl;
        cout << "1 => Add New Employee" << endl
             << "2 => Add New Record" << endl
             << "3 => Display Record With ID" << endl
             << "4 => Display All Record" << endl
             << "5 => Display All Employee" << endl
             << "0 => Exit Program" << endl
             << "------------------------------------" << endl;
        cout << "Enter Process: ";
        cin >> process;
        cout << "------------------------------------" << endl;
        switch (process)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Salary: ";
            cin >> previousSalary;
            cout << "Entre Date: ";
            cin >> dateOfChange;
            trackEmployee.addEmployee(id, name, dateOfChange, previousSalary);
            cout << "------------------------------------" << endl;
            break;
        case 2:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Previous Salary: ";
            cin >> previousSalary;
            cout << "Entre Bonus: ";
            cin >> bonus;
            cout << "Entre Date: ";
            cin >> dateOfChange;
            trackEmployee.insertRecord(id, previousSalary, bonus, dateOfChange);
            cout << "------------------------------------" << endl;
            break;
        case 3:
            cout << "Enter ID: ";
            cin >> id;
            cout << "------------------------------------" << endl;
            trackEmployee.displayRecord(id);
            cout << "------------------------------------" << endl;
            break;
        case 4:
            trackEmployee.displayAllRecords();
            cout << "------------------------------------" << endl;
            break;
        case 5:
            trackEmployee.displayAllEmployee();
            cout << "------------------------------------" << endl;
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            cout << "------------------------------------" << endl;
            break;
        default:
            cout << "Invalid Entry , Please Try Again" << endl;
            cout << "------------------------------------" << endl;
            break;
        }
    } while (process != 0);
}