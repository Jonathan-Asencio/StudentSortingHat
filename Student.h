#ifndef STUDENT_H
#define STUDENT_H


#pragma once

#include "Degree.h"
#include <string>

using namespace std;

class Student
{
public:
	Student();
	Student(string studentID, 
		string firstName, string lastName, 
		string emailAddress, int age, 
		int daysInCourse1, int daysInCourse2, 
		int daysInCourse3,
		DegreeProgram degree);
	//Accessors
	std::string GetStudentID() const;
	std::string GetFirstName() const;
	std::string GetLastName() const; 
	std::string GetEmail() const;
	int GetAge() const;
	int GetDaysInClass(int index) const;
	DegreeProgram GetDegree() const;

	//Mutators
	void SetStudentID(string id);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmail(string emailToSet);
	void SetAge(int age);
	void SetDaysInClass(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void SetDegreeProgram(DegreeProgram degree);
	string stringifyDegree(DegreeProgram degreeProgram);

	void PrintStudentInfo();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int studentAge;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

};

#endif // !STUDENT_H