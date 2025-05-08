#include <iostream>
#include <string>
using namespace std;

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

// LinkedList [All employees' salary tracker in one object]

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

// LinkedList [Every object is a employee's salary tracker]

class employeeLinkedList
{
private:
    employeeTracker *head;

public:
    employeeLinkedList()
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
    void displayRecord()
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
};

int main()
{
    // LinkedList [Every object is a employee's salary tracker]

    // employeeLinkedList employeeOne;
    // employeeOne.insertRecord(1, "Mohamed", 1000, 100, "01-05-2022");
    // employeeOne.insertRecord(1, "Mohamed", 1100, 100, "01-01-2023");
    // employeeOne.displayRecord();
    // employeeLinkedList employeeTwo;
    // employeeTwo.insertRecord(2, "Fared", 2000, 100, "01-05-2020");
    // employeeTwo.insertRecord(2, "Fared", 2100, 100, "01-01-2023");
    // employeeTwo.displayRecord();

    // cout << "-------------------------------------------------" << endl;

    // LinkedList [All employees' salary tracker in one object]

    // employeeSingleLinkedList trackEmployee;
    // trackEmployee.insertRecord(1, "Ali", 1000, 100, "01-05-2020");
    // trackEmployee.insertRecord(1, "Ali", 1100, 100, "01-01-2021");
    // trackEmployee.insertRecord(2, "Ahmed", 2000, 100, "01-05-2019");
    // trackEmployee.insertRecord(2, "Ahmed", 2100, 100, "01-01-2020");
    // trackEmployee.displayRecord(1);
    // trackEmployee.displayAllRecords();

    // cout << "-------------------------------------------------" << endl;

    // LinkedList [All employees' salary tracker in one object (user input)]

    // int id, process;
    // double previousSalary, bonus;
    // string name, dateOfChange;
    // employeeSingleLinkedList trackEmployee;
    // do
    // {
    //     cout << "===Employee Salary History Tracker===" << endl;
    //     cout << "1 => Add New Record" << endl
    //          << "2 => Display Record With ID" << endl
    //          << "3 => Display All Record" << endl
    //          << "0 => Exit Program" << endl
    //          << "------------------------------------" << endl;
    //     cout << "Enter Process: ";
    //     cin >> process;
    //     cout << "------------------------------------" << endl;
    //     switch (process)
    //     {
    //     case 1:
    //         cout << "Enter ID: ";
    //         cin >> id;
    //         cout << "Enter Name: ";
    //         cin >> name;
    //         cout << "Enter Previous Salary: ";
    //         cin >> previousSalary;
    //         cout << "Entre Bonus: ";
    //         cin >> bonus;
    //         cout << "Entre Date: ";
    //         cin >> dateOfChange;
    //         trackEmployee.insertRecord(id, name, previousSalary, bonus, dateOfChange);
    //         cout << "------------------------------------" << endl;
    //         break;
    //     case 2:
    //         cout << "Enter ID: ";
    //         cin >> id;
    //         cout << "------------------------------------" << endl;
    //         trackEmployee.displayRecord(id);
    //         cout << "------------------------------------" << endl;
    //         break;
    //     case 3:
    //         trackEmployee.displayAllRecords();
    //         cout << "------------------------------------" << endl;
    //         break;
    //     case 0:
    //         cout << "Exiting program. Goodbye!" << endl;
    //         cout << "------------------------------------" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Entry , Please Try Again" << endl;
    //         cout << "------------------------------------" << endl;
    //         break;
    //     }
    // } while (process != 0);
}