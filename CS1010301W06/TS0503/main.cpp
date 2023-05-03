/***********************************************************************
 * File: main.cpp
 * Author: ³¯©|¿A
 * Create Date: 2023/03/30
 * Editor: ³¯©|¿A
 * Update Date: 2023/03/17
 * Description: Student Records
***********************************************************************/
#include <iostream>

using namespace std;

// Define a structure for a student record
typedef struct {
    char firstName[25];
    char lastName[30];
    char phone[15];
} StRec;

// Declare function prototypes
void insertRecord(char input_firstName[], char input_lastName[], char input_phone[]);
void deleteRecord(char input_firstName[], char input_lastName[], char input_phone[]);
int searchRecord(char input_firstName[], char input_lastName[], char input_phone[]);
bool isValidPhone(char input_phone[]);
void printRecord();

// Declare an array of student records and a variable to keep track of the number of records
StRec studentRecords[10];
int lengthNow = 0;

int main()
{
    string action;

    // Read input from user until program is terminated
    while (cin >> action)
    {
        // Check if user wants to insert, delete, or search for a student record
        if (action == "insert" || action == "delete" || action == "search")
        {
            // Declare variables to store user input
            char input_firstName[26] = { '\0' }, input_lastName[31] = { '\0' }, input_phone[16] = { '\0' };
            cin >> input_firstName >> input_lastName >> input_phone;

            // Check if user input is valid
            if (input_firstName[25] == '\0' && input_lastName[30] == '\0' && input_phone[15] == '\0' && isValidPhone(input_phone))
            {
                // Perform action based on user input
                if (action == "insert")
                {
                    if (lengthNow < 10)
                    {
                        insertRecord(input_firstName, input_lastName, input_phone);
                    }
                    else
                    {
                        cout << "Insert Error\n";
                    }
                }
                else if (action == "delete")
                {
                    deleteRecord(input_firstName, input_lastName, input_phone);
                }
                else if (action == "search")
                {
                    int resultIndex = searchRecord(input_firstName, input_lastName, input_phone);
                    if (resultIndex >= 0)
                    {
                        cout << resultIndex << endl;
                    }
                    else
                    {
                        cout << "Search Error\n";
                    }
                }
            }
            else
            {
                cout << "Input Error\n";
            }
        }
        // Check if user wants to print all student records
        else if (action == "print")
        {
            printRecord();
        }
        else
        {
            cout << "Input Error\n";
        }
    }
    return 0;
}

bool isValidPhone(char input_phone[])
{
    // Check if each character in phone number is a digit
    int i = 0;
    while (input_phone[i] != '\0')
    {
        if (input_phone[i] < '0' || input_phone[i] > '9')
        {
            return 0;
            break;
        }
        i++;
    }
    return 1;
}

void insertRecord(char input_firstName[], char input_lastName[], char input_phone[])
{
    // Check if record already exists before inserting
    if (searchRecord(input_firstName, input_lastName, input_phone) < 0)
    {
        StRec newStudent;
        // Copy input values into new student record
        strncpy_s(newStudent.firstName, input_firstName, 25);
        strncpy_s(newStudent.lastName, input_lastName, 30);
        strncpy_s(newStudent.phone, input_phone, 15);

        // Insert new record into array
        studentRecords[lengthNow] = newStudent;
        lengthNow++;
    }
    else
    {
        cout << "Insert Error\n";
    }
}

void deleteRecord(char input_firstName[], char input_lastName[], char input_phone[])
{
    int searchIndex = searchRecord(input_firstName, input_lastName, input_phone);
    if (searchIndex >= 0)
    {
        // Shift all records after the deleted record one index to the left
        for (int i = searchIndex; i < lengthNow - searchIndex + 1; i++)
        {
            StRec tempRec;
            tempRec = studentRecords[i + 1];
            studentRecords[i] = tempRec;
        }
        // Set values of the last record to null to delete it
        strncpy_s(studentRecords[lengthNow - 1].firstName, "\0", 25);
        strncpy_s(studentRecords[lengthNow - 1].lastName, "\0", 30);
        strncpy_s(studentRecords[lengthNow - 1].phone, "\0", 15);

        lengthNow -= 1;
    }
    else
    {
        cout << "Delete Error\n";
    }
}

int searchRecord(char input_firstName[], char input_lastName[], char input_phone[])
{
    // Search through array for a matching record
    for (int i = 0; i < lengthNow; i++)
    {
        if (strcmp(studentRecords[i].firstName, input_firstName) == 0 && strcmp(studentRecords[i].lastName, input_lastName) == 0 && strcmp(studentRecords[i].phone, input_phone) == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}

void printRecord()
{
    if (lengthNow > 0)
    {
        // Print each record in array
        for (int i = 0; i < lengthNow; i++)
        {
            printf("%s %s %s\n", studentRecords[i].firstName, studentRecords[i].lastName, studentRecords[i].phone);
        }
    }
    else
    {
        cout << "Print Error\n";
    }
}
