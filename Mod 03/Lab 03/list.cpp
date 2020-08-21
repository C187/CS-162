#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int& size)
{
	//insert your code here and modify the following line
	if (position < 0 || position > size)
		return false;

	for (int i = size - 1; i >= position; i--)
		intList[i + 1] = intList[i];

	intList[position] = val;

	size++;
	return true;
}

bool remove(int position, int& val, int intList[], int& size)
{
	//insert your code here and modify the following line
	if (position < 0 || position >= size)
		return false;

	val = intList[position];

	for (int i = position; i < size - 1; i++)
		intList[i] = intList[i + 1];

	size--;
	return true;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



