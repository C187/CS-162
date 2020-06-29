/*
Author: Chris Hall
Date: 28 - JUNE - 2020
Class: CS - 162 - 30179
Assignment: 1
Sources: None
Description: Program to specify a budget, enter items with price into a cart, and compare.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	int loop = 1, count = 0;
	float budget = 0, iPrice = 0, total = 0;
	char item[20];

	cout << "This program allows you to specify your budget, add itmes to your cart, and then compare the cost of the cart to your budget." << endl;
	cout << "\nTo start enter your budget: $";
	cin >> budget;

	cout << "\nNow that we know your budget you can start adding items to your cart.\n" << endl;

	while (loop) {
		cout << "Name of item to add to your cart: ";
		cin >> item;
		cout << "You've entered: " << item << endl;
		cout << "The items price: $";
		cin >> iPrice;
		cout << "You've entered: $" << fixed << setprecision(2) << iPrice << endl;

		if (iPrice < 0) {
			cout << "Item price must be greater than 0.\nPlease enter a new price: $";
			cin >> iPrice;
		}

		count ++;
		total += iPrice;

		cout << "Please enter 1 to contune adding items or 0 to finish: ";
		cin >> loop;
		cout << endl;
		if (loop != 0 && loop != 1) {
			cout << "You must enter 1 to contune or 0 to finish: " << endl;
			cin >> loop;
		}
	}

	cout << "You've added " << count << " items to your cart." << endl;
	cout << "The total price of all those items is $" << fixed << setprecision(2) << total << endl;
	cout << "You will have " << fixed << setprecision(2) << budget - total << " dollars left from your budget if you buy all the items in your cart." << endl;

	return 0;
}
