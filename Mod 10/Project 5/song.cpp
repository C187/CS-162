// Project 5
#include <cstring>
#include <iostream>
#include "song.h"

using namespace std;

// Constructor
Song::Song(){}

// Destructor
Song::~Song() {
    delete [] title;
    delete [] artist;
    delete [] min;
	delete [] sec;
    delete [] album;
}

// Overide
void Song::operator=(Song &s) {
    setTitle(s.getTitle());
    setArtist(s.getArtist());
	setMin(s.getMin());
    setSec(s.getSec());
    setAlbum(s.getAlbum());
    setId(s.getId());
}

// Accessors
char * Song::getTitle() {
    return title;
}

char * Song::getArtist() {
    return artist;
}

char * Song::getMin() {
    return min;
}

char * Song::getSec() {
	return sec;
}

char * Song::getAlbum() {
    return album;
}

int Song::getId() {
    return trackID;
}

// Mutators
void Song::setTitle(char * s) {
    title = new char[strlen(s) + 1];
    strcpy(this->title, s);
    return;
}

void Song::setArtist(char * s) {
    artist = new char[strlen(s) + 1];
    strcpy(this->artist, s);
    return;
}

void Song::setMin(char * s) {
    min = new char[strlen(s) + 1];
    strcpy(this->min, s);
    return;
}

void Song::setSec(char * s) {
	sec = new char[strlen(s) + 1];
	strcpy(this->sec, s);
	return;
}

void Song::setAlbum(char * s) {
    album = new char[strlen(s) + 1];
    strcpy(this->album, s);
    return;
}

void Song::setId(int i) {
    trackID = i;
    return;
}

// Print
void Song::print() {
    cout << title << " - " << artist << " - " << min << ":" << sec << " - " << album << endl;
    return;
}