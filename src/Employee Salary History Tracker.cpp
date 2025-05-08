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
    void insertRecord(int id, string name, double previousSalary, double bonus, string dateOfChange)
    {
        employeeTracker *newNode = new employeeTracker();
        newNode->previousSalary = previousSalary;
        newNode->dateOfChange = dateOfChange;
        newNode->bonus = bonus;
        newNode->id = id;
        newNode->name = name;
        if (isEmpty())
        {
            head = newNode;
            newNode->arrow = NULL;
        }
        else
        {
            newNode->arrow = head;
            head = newNode;
        }
    }
    bool searchRecord(int id)
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
    void displayRecord(int id)
    {
        if (searchRecord(id))
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
        employeeTracker *temp = head;
        if (temp == NULL)
        {
            cout << "No records found" << endl;
        }
        else
        {
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
        cout << "1 => Add New Record" << endl
             << "2 => Display Record With ID" << endl
             << "3 => Display All Record" << endl
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
            cout << "Enter Previous Salary: ";
            cin >> previousSalary;
            cout << "Entre Bonus: ";
            cin >> bonus;
            cout << "Entre Date: ";
            cin >> dateOfChange;
            trackEmployee.insertRecord(id, name, previousSalary, bonus, dateOfChange);
            cout << "------------------------------------" << endl;
            break;
        case 2:
            cout << "Enter ID: ";
            cin >> id;
            cout << "------------------------------------" << endl;
            trackEmployee.displayRecord(id);
            cout << "------------------------------------" << endl;
            break;
        case 3:
            trackEmployee.displayAllRecords();
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