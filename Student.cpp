#include <iostream>
#include <string>

#include "Degree.h"
#include "Student.h"
#include "Roster.h"
using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = emailAddress;
	this->studentAge = age;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->degreeProgram = degree;
}

Student::Student()
{
	this->studentID = "Empty";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->studentAge = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram = SOFTWARE;
}

//Accessors
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}
int Student::GetAge() const {
	return studentAge;
}
int Student::GetDaysInClass(int index) const {
	return daysInCourse[index];
}

DegreeProgram Student::GetDegree() const {
	return degreeProgram;
}

//Mutators
void Student::SetStudentID(string id) {
	studentID = id;
}
void Student::SetFirstName(string fName) {
	firstName = fName;
}
void Student::SetLastName(string lName) {
	lastName = lName;
}
void Student::SetEmail(string emailToSet) {
	email = emailToSet;
}
void Student::SetAge(int age) {
	studentAge = age;
}
void Student::SetDaysInClass(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

}
void Student::SetDegreeProgram(DegreeProgram degree) {
	degreeProgram = degree;
}

string Student::stringifyDegree(DegreeProgram degreeProgram) {

	string degreeToString;

	switch (degreeProgram)
	{
	case 0:
		degreeToString = "SOFTWARE";
		break;
	case 1:
		degreeToString = "SECURITY";
		break;
	case 2:
		degreeToString = "NETWORK";
		break;
	default:
		break;
	}

	return degreeToString;
}

void Student::PrintStudentInfo() {

	cout << studentID << "\t";
	cout << firstName << "\t";
	cout << lastName << "\t";
	cout << studentAge << "\t";
	cout << "{" << daysInCourse[0] << ",";
	cout << daysInCourse[1] << ",";
	cout << daysInCourse[2] << "}" << "\t";
	cout << stringifyDegree(degreeProgram) << endl;
}