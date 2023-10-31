#include <iostream>
#include <vector>
#include <regex>

#include "Roster.h"



Roster::Roster(int classSize)
{
	rosterSize = classSize;
	classRosterArray = new Student [classSize]();
	for (int i = 0; i < classSize; i++)
	{
		Student* s = new Student();
		classRosterArray[i] = *s;
	}
}

void Roster::add(string studentID, string firstName,
	string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i].GetStudentID() == "Empty")
		{
			classRosterArray[i] = *newStudent;
			break;
		}
	}

}
void Roster::remove(string studentID) {
	bool found = false;

	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i].GetStudentID() == studentID)
		{
			found = true;
			copy(classRosterArray + (i + 1), classRosterArray + rosterSize, classRosterArray + i);
			rosterSize--;

			//delete classRosterArray[i];
			break;
		}
	}

	if (!found)
	{
		cout << "Error: Student with ID: " << studentID << " not found." << endl;
	}

} // print error if not exist
void Roster::printAll() {

	for (int i = 0; i < rosterSize; i++)
	{
		classRosterArray[i].PrintStudentInfo();
	}
}
void Roster::printAverageDaysInCourse(string studentID) {
	
	int averageDays = 0;

	for (int i = 0; i < rosterSize; i++)
	{
		if(classRosterArray[i].GetStudentID() == studentID)
		{
			for (int j = 0; j < 3; j++)
			{
				averageDays += classRosterArray[i].GetDaysInClass(j);

			}
			averageDays = averageDays / 3;
			cout << studentID << ",\t" << "Average Days in class: " << averageDays << endl;
			break;
		}
	}	
}
void Roster::printInvalidEmails() {



	for (int i = 0; i < rosterSize; i++)
	{
		int d = 0;
		string emailToValidate = classRosterArray[i].GetEmail();

		if (emailToValidate.find('@') != string::npos)
		{
			d++;
		}
		if (emailToValidate.find('.') != string::npos)
		{
			d++;
		}
		if (emailToValidate.find(' ') != string::npos)
		{
			d--;
		}
		if (d != 2)
		{
			cout << emailToValidate << " - is invalid" << endl;
		}
	}
} // This function is ugly but works

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i].GetDegree() == degreeProgram)
		{
			classRosterArray[i].PrintStudentInfo();
		}
	}
}

string Roster::getStudentID(int index) {
	return classRosterArray[index].GetStudentID();
}

Roster::~Roster()
{
}
