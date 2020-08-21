// Project 5
#include <iostream>
#include <stdexcept>
#include "linkedList.h"

linkedList::~linkedList() {
    node * cur;
    node * next;
    cur = head;
    while (cur->next != NULL) {
        next = cur->next;
        delete cur;
        cur = next;
    }
    delete tail;
}

int linkedList::size() {
    return count;
}

void linkedList::insertFirst(Song& s) {
    node * temp = new node;
    temp -> info = s;
    temp -> next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    } 
	else {
        temp -> next = head;
        head = temp;
    }
    count += 1;
}

void linkedList::insertAt(Song& s, int index){
    node * temp = new node;
    node * before;
    node * cur;
    temp -> info = s;
    temp -> next = NULL;
    cur = head;
    if (index > count){
        throw invalid_argument("Out of bounds");
    } 
	else if (index == 0) {
        insertFirst(s);
    } 
	else if (index == count) {
        insertLast(s);
    } 
	else {
        for(int i = 1; i < index + 1; i++) {
            before = cur;
            cur = cur->next;
        }
        before->next = temp;
        temp->next = cur;
        count += 1;
    }
}

void linkedList::insertLast(Song& s) {
    node * temp = new node;
    temp -> info = s;
    temp -> next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    } 
	else {
        tail->next = temp;
        tail = temp;
    }
    count += 1;
}

void linkedList::deleteFirst() {
    node * temp;
    temp = head;
    head = head->next;
    delete temp;
    count -= 1;
}

void linkedList::deleteAt(int index) {
    node * before;
    node * cur;
    node * temp;
    cur = head;
    if (index > count) {
        throw invalid_argument("Out of bounds");
    } 
	else if (index == 0) {
        deleteFirst();
    } 
	else if (index == count - 1) {
        deleteLast();
    } 
	else {
        for(int i = 1; i < index + 1; i++) {
            before = cur;
            cur = cur->next;
        }
        temp = cur;
        before->next = cur->next;
        delete temp;
        count -= 1;
    }
}

void linkedList::deleteLast() {
    node * curr;
    node * temp;
    curr = head;
    while (curr->next != NULL) {
        temp = curr;
        curr = curr->next;
    }
    tail = temp;
    temp->next = NULL;
    delete curr;
    count -= 1;
}

void linkedList::print() {
    node * temp;
    temp = head;
    while (temp != NULL) {
        temp->info.print();
        temp = temp->next;
    }
}

Song * linkedList::at(int index) {
    node * cur;
    cur = head;
    if (index > count - 1) {
        throw invalid_argument("Out of bounds");
    } 
	else if (index == 0) {
        return &head->info;
    } 
	else {
        for(int i = 1; i < index + 1; i++) {
            cur = cur->next;
        }
        return &cur->info;
    }
}

void linkedList::setId(int index) {
    node * before;
    node * cur;
    cur = head;
    if(index > count - 1) {
        throw invalid_argument("Out of bounds");
    } 
	else if (index == 0) {
        head->info.setId(index);
    } 
	else {
        for(int i = 1; i < index + 1; i++) {
            before = cur;
            cur = cur->next;
        }
        cur->info.setId(index);
    }
}