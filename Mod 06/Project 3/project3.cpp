/*
Author: Chris Hall
Date: 20 - JULY - 2020
Class: CS - 162 - 30179
Assignment: Project 3
Sources: Project 2, sampleProj3
Description: Programs loads songs.txt if it exists in the directory if it doesn’t one will be made after
adding the first track to the list. The program allows a user to modify (add/remove) tracks, search by
artist, and list all tracks currently saved.
*/

#define  _CRT_SECURE_NO_WARNINGS // VS17 flag

#include <iostream>
#include <fstream>
#include <cstring>
#include "songList.h"

// #define MAX_CHAR 128

using namespace std;

// Global constants 
const int maxChar = 256;

//main ui functions
void addTrack(SongList& s);
void deleteTrack(SongList& songs);
void search(SongList s, int mode);
//helper function prototypes
void inputCheck(char tempString[]);

//
//void numInputCheck(int tempInt[]);

int main() {
	SongList s;
	Song searchResults[maxChar];
	//int num;
	char input;
	bool run = true;

	cout << "Welcome to project 3: classy songs!!\nThis project will automatically load your songs.text so you can modify it here.\n" << endl;

	do {
		cout << "Main menu:\n1. Search by Artist.\n2. Add a track.\n3. Delete track.\n4. List all tracks.\n5. Exit program." << endl;

		cin >> input;
		switch (input) {

		case '1': // Search
			search(s, 0);
			break;

		case '2': // Add
			cin.clear();
			cin.ignore(maxChar, '\n');
			addTrack(s);
			break;

		case '3': // Delete
			cin.clear();
			cin.ignore(maxChar, '\n');
			deleteTrack(s);
			break;

		case '4': // List
			cin.clear();
			cin.ignore(maxChar, '\n');
			s.printSongs();
			break;

		case '5': // Exit
			cin.clear();
			cin.ignore(maxChar, '\n');
			run = false;
			break;

		default: // Bad input
			cout << "\nThat's not an option. Try again.\n" << endl;
			cin.clear();
			cin.ignore(maxChar, '\n');
		}
	} while (run);
	return 0;
}

// Semicolon filter
void inputCheck(char t[]) {
	bool isGoodInput;
	do {
		isGoodInput = true;
		cin.getline(t, maxChar);
		if (strchr(t, ';')) {
			isGoodInput = false;
			cout << "It looks like you used a semicolon (;).\nUnfortunately, that's the delimiter for this project so you can’t use it.\nPlease correct your entry below." << endl;
		}
	} while (!isGoodInput);
	return;
}

//Add song
void addTrack(SongList& a) {
	Song temp;
	char t[maxChar], input;
	bool run = true;

	do {
		cout << "\nAdd a Track.\nSong title: ";
		inputCheck(t);
		temp.setTitle(t);

		cout << "Artist: ";
		inputCheck(t);
		temp.setArtist(t);

		cout << "Runtime in minutes: "; //note change to int
		inputCheck(t);
		temp.setMin(t);

		cout << "Runtime in seconds: ";
		inputCheck(t);
		temp.setSec(t);

		cout << "Album: ";
		inputCheck(t);
		temp.setAlbum(t);

		cout << "\nYou've entered: ";
		temp.print();
		cout << "\nAdd it to songs.txt? (y/n): ";
		cin >> input;
		if (input == 'y') {
			run = false;
			cout << "Adding " << temp.getTitle() << " to songs.txt.\n" << endl;
			a.addTrack(temp);
		}
		if (input == 'n') {
			run = false;
		}
		cin.clear();
		cin.ignore(maxChar, '\n');
	} while (run);
	
	return;
}

//Delete 
void deleteTrack(SongList& songs) {
	bool run = true;
	char input;
	int songIndex;
	
	if (songs.getNum() > 0) {
		do {
			cout << "Enter the index number of the track you want to delete." << endl;
			do {
				if (!(cin >> songIndex)) {
					cout << "You must use a number." << endl;
				}
				else if (songIndex < 0 || songIndex >= songs.getNum()) {
					cout << "Can't be less than zero." << endl;
				}
				else {
					break;
				}
				cin.clear();
				cin.ignore(maxChar, '\n');
			} while (1);

			cout << "You want to delete " 
				<< songs.getSong(songIndex).getTitle() << " - "
				<< songs.getSong(songIndex).getArtist() << " - "
				<< songs.getSong(songIndex).getMin() << ":"
				<< songs.getSong(songIndex).getSec() << " - "
				<< songs.getSong(songIndex).getAlbum() << "? (y/n): ";

			cin >> input;
			if (input == 'y') {
				cin.clear();
				cin.ignore(maxChar, '\n');
				run = false;
				songs.deleteSong(songIndex);
			}
			if (input == 'n') {
				cin.clear();
				cin.ignore(maxChar, '\n');
				run = false;
			}
			else {
				cin.clear();
				cin.ignore(maxChar, '\n');
			}
		} while (run);
	}
	else {
		cout << "You currently don't have any tracks saved." << endl;
	}
	return;
}

//Search
void search(SongList s, int mode) {
	cin.clear();
	cin.ignore(maxChar, '\n');
	char searchString[maxChar];
	Song searchResults[maxChar];
	int searchHits = 0;

	cout << "\nSearch by Artist: ";
	inputCheck(searchString);

	searchHits = s.search(searchResults, searchString, mode);
	cout << "ID - Title - Artist - Minutes - Seconds - Album" << endl;
	if (searchHits) {
		for (int i = 0; i < searchHits; i++) {
			cout << searchResults[i].getId() << " - ";
			searchResults[i].print();
		}
	}
	else {
		cout << "No results\n" << endl;
	}
	do {
		cout << "Enter to continue." << endl;
	} while (cin.get() != '\n');
	return;
}