// Project 5
#include "song.h"
#include <cstddef> 
using namespace std;

struct node {
    Song info;
    struct node *next;
};

class linkedList {
    public:
        linkedList() {
            head = NULL;
            tail = NULL;
            count = 0;
        }
        void insertFirst(Song& s);
        void insertAt(Song& s, int index);
        void insertLast(Song& s);
        void deleteFirst();
        void deleteAt(int index);
        void deleteLast();
        void print();
        int size();
        Song * at(int index);
        void setId(int index);
        ~linkedList();
    protected:
        int count;
        node * head;
        node * tail;
};
