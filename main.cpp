#include <iostream>
#include <string>
#include <sstream>
#include "Roster.h"

using namespace std;

int main()
{
    cout << "C867 - SCRIPTING AND PROGRAMMING: APPLICATIONS " << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 009458449" << endl;
    cout << "Name: Jonathan Asencio" << endl;

    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Jonathan,Asencio,jasenc3@wgu.edu,27,14,21,21,SOFTWARE" };
    int arraySize = sizeof(studentData) / sizeof(string);
    string token;

    string id;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInClass1;
    int daysInClass2;
    int daysInClass3;
    DegreeProgram program;


    Roster* classRoster = new Roster(arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        string stringToParse = studentData[i];
        stringstream s(stringToParse);

        getline(s, id, ',');
        getline(s, firstName, ',');
        getline(s, lastName, ',');
        getline(s, emailAddress, ',');
        getline(s, token, ',');
        age = stoi(token);
        getline(s, token, ',');
        daysInClass1 = stoi(token);
        getline(s, token, ',');
        daysInClass2 = stoi(token);
        getline(s, token, ',');
        daysInClass3 = stoi(token);
        getline(s, token, ',');
        if (token == "SOFTWARE") {
            program = SOFTWARE;
        }
        else if (token == "SECURITY") {
            program = SECURITY;
        }
        else if (token == "NETWORK") {
            program = NETWORK;
        }
        else {
            cerr << "Error: Invalid degree program" << endl;

        }

        classRoster->add(id, firstName, lastName, emailAddress, age, daysInClass1, daysInClass2, daysInClass3, program);

    }
    cout << "\nDisplaying all students:" << endl;
    classRoster->printAll();

    cout << "\nDisplaying invalid emails\n" << endl;
    classRoster->printInvalidEmails();

    cout << "Showing students in degree program: SOFTWARE \n" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    cout << "\n" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        string studentID = classRoster->getStudentID(i);
        classRoster->printAverageDaysInCourse(studentID);
    }

    cout << "\nRemoving A3: \n" << endl;
    classRoster->remove("A3");
    classRoster->printAll();

    cout << "\nRemoving A3 again:\n" << endl;
    classRoster->remove("A3");

    //for (int i = 0; i < arraySize; i++)
    //{
    //    delete &classRoster[i];
    //}
    delete classRoster;


}
