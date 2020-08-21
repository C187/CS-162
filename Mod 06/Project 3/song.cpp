#define  _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "song.h"

using namespace std;

/**
 * Constructors
 **/

 //Default constructor
Song::Song() {
	strcpy(title, "No Title");
	strcpy(artist, "No Artist");
	strcpy(album, "No Album");
}

//Constructor with parameters
Song::Song(char initTitle[], char initArtist[], char initMin[], char initSec[], char initAlbum[], int id) {
	strcpy(title, initTitle);
	strcpy(artist, initArtist);
	strcpy(min, initMin);
	strcpy(sec, initSec);
	strcpy(album, initAlbum);
	trackID = id;
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
void Song::setTitle(char s[]) {
	strcpy(title, s);
	return;
}

void Song::setArtist(char s[]) {
	strcpy(artist, s);
	return;
}

void Song::setMin(char s[]) {
	strcpy(min, s);
	return;
}

void Song::setSec(char s[]) {
	strcpy(sec, s);
	return;
}

void Song::setAlbum(char s[]) {
	strcpy(album, s);
	return;
}

void Song::setId(int i) {
	trackID = i;
	return;
}

//Print 
void Song::print() {
	cout << title << " - " << artist << " - " << min << " - " << sec << " - " << album << endl;
	return;
}