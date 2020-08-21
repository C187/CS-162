#define _CRT_SECURE_NO_WARNINGS // Flag for Visual Studio 17

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
public:
	Student(const char initId[], double initGpa);
	bool isLessThanByID(const Student& aStudent) const;
	bool qualifyForHonor(double minGpaForHonor) const;
	void print()const;
private:
	const static int MAX_CHAR = 100;
	char 	id[MAX_CHAR];
	double	gpa;
};
#endif

