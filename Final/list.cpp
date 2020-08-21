/*
Author: Chris Hall
Date: 19 - AUG - 2020
Class: CS - 162 - 30179
Assignment: Final
*/

//Function definitions go in this file.
//Remmeber that the linked list is not in a class so you do not need any scope resolution
//i.e no: LinkedList::
#include "list.h"
#include <iostream>
using namespace std;

// Find even numbers
int countEven(node *head) {
	int count = 0;
	
	while (head != NULL) {
		if ((head->data) % 2 == 0) {
			count++;
		}
		head = head->next;
	}
	
	return count;
}


// Display second from last
int findSecondFinal(node * &head) {
	node* temp = head;

	while (temp != NULL) {
		if (temp->next->next == NULL) {
			return temp->data;
		}

		temp = temp->next;
	}
}

// Delete second from last
int removeSecondFinal(node * &head) {
	node* temp = head;

	// Check for short list
	if (temp == NULL || temp->next == NULL) {
		return -1;
	}

	// Delete
	while (temp->next->next->next != NULL) {
		temp = temp->next;
	}

	delete (temp->next);
}