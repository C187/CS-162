/*
Author: Chris Hall
Date: 16 - AUG - 2020
Class: CS - 162 - 30179
Assignment: Project 5
Sources: Project 4
Description: Programs loads songs.txt if it exists in the directory if it doesn’t one will be made after
adding the first track to the list. The program allows a user to modify (add/remove) tracks, search by
artist, and list all tracks currently saved.
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "songList.h"
#define MAX_CHAR 256

using namespace std;

// Main UI functions
void addTrack(SongList& s);
void deleteTrack(SongList& songs);
void searchBy(SongList& s, int mode);

// Helper function
void inputCheck(char t[]);

int main() {
    SongList s;
    char input;
	bool run = true;

	cout << "Welcome to project 5!\nThis project will automatically load your songs.txt so you can modify it here.\n" << endl;

    do {
		cout << "Main menu:\n1. Search by Artist.\n2. Search by Album\n3. Add a track.\n4. Delete track.\n5. List all tracks.\n6. Exit program." << endl; cin >> input;
		switch (input) {
		case '1': // Search - Artist
			searchBy(s, 0);
			break;

		case '2':  // Search - Album
			searchBy(s, 1);
			break;

		case '3': // Add
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			addTrack(s);
			break;

		case '4': // Delete
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			deleteTrack(s);
			break;

		case '5': // List
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			s.printTracks();
			break;

		case '6': // Exit
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
			run = false;
			break;

		default:
			cout << "\nThat's not an option. Try again.\n" << endl;
			cin.clear();
			cin.ignore(MAX_CHAR, '\n');
		}
    } while (run);
    return 0;
}

// Semicolon filter and checks if input is blank
void inputCheck(char t[]) {
	bool isGoodInput;
	do {
		isGoodInput = true;
		cin.getline(t, MAX_CHAR);
		if (strchr(t, ';')) {
			isGoodInput = false;
			cout << "It looks like you used a semicolon (;).\nUnfortunately, that's the delimiter for this project so you can’t use it.\nPlease correct your entry below." << endl;
		}
		if (t && !t[0]) {
			isGoodInput = false;
			cout << "You can't just enter nothing..\nPlease correct your entry below." << endl;
		}
	} while (!isGoodInput);
	return;
}

// Add song
void addTrack(SongList& s) {
    Song temp = Song();
	char * t = new char[MAX_CHAR], input;
	bool run = true;

    do {
		cout << "\nAdd a Track.\nSong title: ";
		inputCheck(t);
		temp.setTitle(t);

		cout << "Artist: ";
		inputCheck(t);
		temp.setArtist(t);

		cout << "Runtime in minutes: ";
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
		if (input == 'y' || input == 'Y') {
			run = false;
			cout << "Adding \"" << temp.getTitle() << "\" by \"" << temp.getArtist() << "\" to songs.txt.\n" << endl;
			s.addTrack(temp);
			delete[] t;
		}
		if (input == 'n' || input == 'N') {
			run = false;
		}
		cin.clear();
		cin.ignore(MAX_CHAR, '\n');
	} while (run);
    return;
}

// Delete
void deleteTrack(SongList& songs) {
	char input;
	bool run = true;
	int songIndex;

    if(songs.getLen() > 0) {
        do {
			cout << "Enter the index number of the track you want to delete." << endl;
            do {
                if (!(cin >> songIndex)) {
                    cout << "You must use a number." << endl;
                } 
				else if (songIndex < 0 || songIndex >= songs.getLen()) {
                    cout << "Can't be less than zero." << endl;
                } 
				else {
                    break;
                }
                cin.clear();
                cin.ignore(MAX_CHAR, '\n');
            } while (1);
            
            cout << "You want to delete " 
                << songs.getSong(songIndex)->getTitle() << " - " 
                << songs.getSong(songIndex)->getArtist() << " - " 
                << songs.getSong(songIndex)->getMin() << ":"
				<< songs.getSong(songIndex)->getSec() << " - "
                << songs.getSong(songIndex)->getAlbum() << "? (y/n): ";

            cin >> input;
			if (input == 'y' || input == 'Y') {
				cin.clear();
				cin.ignore(MAX_CHAR, '\n');
				run = false;
				songs.deleteTrack(songIndex);
			}
			if (input == 'n' || input == 'N') {
				cin.clear();
				cin.ignore(MAX_CHAR, '\n');
				run = false;
			}
			else {
                cin.clear();
                cin.ignore(MAX_CHAR, '\n');
            }
        } while(run);
    } 
	else {
		cout << "You currently don't have any tracks saved." << endl;
    }
    return;
}

// Search by..
void searchBy(SongList& s, int mode){
    cin.clear();
    cin.ignore(MAX_CHAR, '\n');
    char searchString[MAX_CHAR];
    Song * searchResults;
    int searchHits = 0;

    switch(mode) {
		case(0):
			cout << "\nSearch by Artist: ";
			break;
		case(1):
			cout << "\nSearch by Album: ";
			break;
		default:
			break;
    }

    inputCheck(searchString);
    searchHits = s.search(searchResults, searchString, mode); 
    cout << "ID - Title - Artist - Time - Album" << endl;
    if(searchHits) {
        for(int i = 0; i < searchHits; i++) {
            cout << searchResults[i].getId() << " - ";
            searchResults[i].print();
        }
    } 
	else {
        cout << "No results.\n" << endl;
    }
    do {
        cout << "Enter to continue." << endl;
    } 
	while (cin.get() != '\n');
    delete [] searchResults;
    return;
}