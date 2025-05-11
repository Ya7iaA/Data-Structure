#include <iostream>
#include <string>
using namespace std;

// Using Linkedlist to track employee leave

class employeeLeave
{
public:
    int id;
    string name;
    string dateOfStart;
    string dateOfEnd;
    string type;
    string status;
    employeeLeave *arrow;
};

class employeeLeaveManagement
{
private:
    employeeLeave *head;

public:
    employeeLeaveManagement()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void addEmployee(int id, string name)
    {
        if (doSearch(id))
        {
            cout << "This Employee Exist";
        }
        else
        {
            employeeLeave *newNode = new employeeLeave();
            newNode->type = "None";
            newNode->dateOfEnd = "None";
            newNode->dateOfStart = "None";
            newNode->status = "None";
            newNode->id = id;
            newNode->name = name;
            newNode->arrow = head;
            head = newNode;
        }
    }
    bool doSearch(int id)
    {
        employeeLeave *temp = head;
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
        employeeLeave *temp = head;
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
    void insertRecord(int id, string type, string dateOfStart, string dateOfEnd, string status)
    {
        if (!doSearch(id))
        {
            cout << "Doesn't Exist" << endl;
        }
        else
        {
            employeeLeave *newNode = new employeeLeave();
            newNode->type = type;
            newNode->dateOfEnd = dateOfEnd;
            newNode->dateOfStart = dateOfStart;
            newNode->status = status;
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
            employeeLeave *temp = head;
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
    void displayLeaveEmployee()
    {
        if (isEmpty())
        {
            cout << "No Employee Founded" << endl;
        }
        else
        {
            employeeLeave *temp = head;
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
                if (!found && temp->status == "Accept")
                {
                    empId[curArr] = temp->id;
                    empName[curArr] = temp->name;
                    curArr++;
                }
                temp = temp->arrow;
            }
            if (curArr == 0)
            {
                cout << "No Leave Employee" << endl;
            }
            else
            {
                for (int i = 0; i < curArr; i++)
                {
                    cout << "Employee ID: " << empId[i] << endl
                         << "Employee Name: " << empName[i] << endl;
                    cout << "---------------------------" << endl;
                }
            }
        }
    }
    void displayRecord(int id)
    {
        if (doSearch(id))
        {
            employeeLeave *temp = head;
            while (temp != NULL)
            {
                if (temp->id == id)
                {
                    cout << "Employee ID: " << temp->id << endl
                         << "Employee Name: " << temp->name << endl
                         << "Leave Type: " << temp->type << endl
                         << "Date Of Start: " << temp->dateOfStart << endl
                         << "Date Of End: " << temp->dateOfEnd << endl
                         << "Leave Status: " << temp->status << endl;
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
            employeeLeave *temp = head;
            while (temp != NULL)
            {
                cout << "Employee ID: " << temp->id << endl
                     << "Employee Name: " << temp->name << endl
                     << "Leave Type: " << temp->type << endl
                     << "Date Of Start: " << temp->dateOfStart << endl
                     << "Date Of End: " << temp->dateOfEnd << endl
                     << "Leave Status: " << temp->status << endl;
                cout << "---------------------------" << endl;
                temp = temp->arrow;
            }
        }
    }
};

int main()
{
    int id, process;
    string name, type, status, dateOfStart, dateOfEnd;
    employeeLeaveManagement leaveEmployee;
    do
    {
        cout << "===Employee Leave Management System===" << endl;
        cout << "1 => Add New Employee" << endl
             << "2 => Add New Record" << endl
             << "3 => Display Record With ID" << endl
             << "4 => Display All Record" << endl
             << "5 => Display All Employee" << endl
             << "6 => Display Leave Employee" << endl
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
            leaveEmployee.addEmployee(id, name);
            cout << "------------------------------------" << endl;
            break;
        case 2:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter The Type: ";
            cin >> type;
            cout << "Entre Date Of Start: ";
            cin >> dateOfStart;
            cout << "Entre Date Of End: ";
            cin >> dateOfEnd;
            cout << "Enter The Status" << endl;
            cin >> status;
            leaveEmployee.insertRecord(id, type, dateOfStart, dateOfEnd, status);
            cout << "------------------------------------" << endl;
            break;
        case 3:
            cout << "Enter ID: ";
            cin >> id;
            cout << "------------------------------------" << endl;
            leaveEmployee.displayRecord(id);
            cout << "------------------------------------" << endl;
            break;
        case 4:
            leaveEmployee.displayAllRecords();
            cout << "------------------------------------" << endl;
            break;
        case 5:
            leaveEmployee.displayAllEmployee();
            cout << "------------------------------------" << endl;
            break;
        case 6:
            leaveEmployee.displayLeaveEmployee();
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
