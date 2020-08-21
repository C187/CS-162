#include "student.h"

int main()
{
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);

	s1.print();
	s2.print();

	//write code to test Student::isLessThanByID
	cout << "\n(For the following, 1 = true, 0 = false)\n" << endl;
	cout << "s1 < s2 : " << s1.isLessThanByID(s2) << endl;
	cout << "s2 < s1 : " << s2.isLessThanByID(s1) << endl;

	//write code to test Student::qualifyForHonor
	cout << "s1 gpa >= 3.75 : " << s1.qualifyForHonor(3.75) << endl; // Apparently PCC's honour role is 3.75
	cout << "s2 gpa >= 3.75 : " << s2.qualifyForHonor(3.75) << endl;

	return 0;
}
