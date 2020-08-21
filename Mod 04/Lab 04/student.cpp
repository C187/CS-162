#include "student.h"

//implement the required 3 functions here
Student::Student(const char initId[], double gpa) {
	strcpy(id, initId);
	 this->gpa = gpa;
};

bool Student::isLessThanByID(const Student& aStudent)const {
	if (strcmp(id, aStudent.id) < 0) {
		return true; 
	}
	else {
		return false; 
	}
}

bool Student::qualifyForHonor(double minGpaForHonor)const {
	if (gpa >= minGpaForHonor) {
		return true; 
	}
	else {
		return false; 
	}
};

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}