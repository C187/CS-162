/*
Author: Chris Hall
Date: 22 - JULY - 2020
Class: CS - 162 - 30179
Assignment: Midterm
*/

#include <iostream>
//#include <cstdlib>
//#include <cassert> 
#include <cstring>

using namespace std;

int getNumber();
void stringInfo(const char myString[], int & numVowels, int & numSpaces);

int main()
{
	// Part 1
	int num;
	num = getNumber();
	cout << "Your number is.. " << num << endl;
	// Part 2
	char myString[100] = "Test sentence for CS162 midterm";
	int numVowels = 0, numSpaces = 0;
	stringInfo(myString, numVowels, numSpaces);
	cout << "'Test sentence for CS162 midterm' has " << numVowels << " vowels and " << numSpaces << " spaces." << endl;
	return 0;
}

// Part 1
int getNumber() {
	int n;
	do { // Asking for a positive whole number greater than 0.
		cout << "Enter a positive whole number: ";
		cin >> n;
		cout << endl;
	} while (n <= 0); // Checks is number <= 0

	cin.clear();
	return n;
}

// Part 2
void stringInfo(const char myString[], int &numVowels, int &numSpaces) {
	for (int i = 0; i < strlen(myString); i++) {
		if (myString[i] == 'a') { // a
			numVowels++;
		}
		else if (myString[i] == 'e') { // e
			numVowels++;
		}
		else if (myString[i] == 'i') { // i
			numVowels++;
		}
		else if (myString[i] == 'o') { // o
			numVowels++;
		}
		else if (myString[i] == 'u') { // u
			numVowels++;
		}
		else if (myString[i] == ' ') { // space
			numSpaces++;
		}
	}

}