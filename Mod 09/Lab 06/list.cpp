//put your implementation of LinkedList class here
#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
}

// delete the entire list
LinkedList::~LinkedList() {
	Node *temp = head;

	while (head != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

// addAtBeginning
void LinkedList::addAtBeginning(int val) {
	Node *n = new Node;
	n->data = val;
	n->next = NULL;
	n->prev = NULL;

	if (head == NULL) {
		head = n;
	}
	else {
		n->next = head;
		head->prev = n;
		head = n;
	}
}

// addAtEnd
void LinkedList::addAtEnd(int val) {
	Node *n = new Node;
	n->data = val;
	n->next = NULL;
	n->prev = NULL;

	if (head == NULL) {
		head = n;
	}
	else {
		Node *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
	}
}

// addAtIndex
bool LinkedList::addAtIndex(int val, int index) {
	int i = 0;
	Node *n = new Node;
	n->data = val;
	n->next = NULL;
	n->prev = NULL;

	if (index == 0) {
		addAtBeginning(val);
	}
	else {
		if (head == NULL) { // empty check
			return false;
		}

		Node *temp = head;
		while (i != index && temp != NULL) {
			temp = temp->next;
			i++;
		}
		if (i != index) { // index check
			return false;
		}
		else {
			temp->prev->next = n;
			n->prev = temp->prev;
			n->next = temp;
			temp->prev = n;
		}
	}
	return true;
}

// remove
bool LinkedList::remove(int val) {
	Node *temp = head;
	bool found = false;

	if (head == NULL) { // empty check
		return false;
	}
	else {
		while (temp != NULL) {
			if (temp->data == val) {
				found = true;
				break;
			}
			temp = temp->next;
		}
		if (!found) {
			return false;
		}
		else {
			if (temp->prev == NULL) {
				head = head->next;
			}
			else {
				temp->prev->next = temp->next;
			}
			if (temp->next != NULL) {
				temp->next->prev = temp->prev;
			}
		}
	}
	return true;
}

// printForward
void LinkedList::printForward() const {
	if (head == NULL) { // empty check
		cout << "printForward is empty" << endl;
	}
	else {
		Node *temp = head;
		cout << "\nprintForward:" << endl;
		while (temp != NULL) {
			cout << temp->data << " "; // spacer
			temp = temp->next;
		}
	}
}

// printBackward
void LinkedList::printBackward() {
	if (head == NULL) { // empty check
		cout << "printBackward is empty" << endl;
	}
	cout << "\nprintBackward:" << endl;
	printBackwardR(head);
}
// printBackwardR
void LinkedList::printBackwardR(Node *curr) const {
	if (curr == NULL) {
		return;
	}
	printBackwardR(curr->next);
	cout << curr->data << " "; // spacer
}