#ifndef ROSTER_H
#define ROSTER_H
#pragma once
#include "Student.h"

#include <string>
#include <vector>

using namespace std;


class Roster
{
public:
	Roster(int classSize);	
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID); // print error if not exist
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	string stringifyDegree(DegreeProgram degreeProgram);
	string getStudentID(int index);
	~Roster();

private:
	Student* classRosterArray;
	Student* student;
	int rosterSize;
};


#endif // !ROSTER_H