/*
Author: Chris Hall
Date: 4 - JULY - 2020
Class: CS - 162 - 30179
Assignment: Project 2
Sources: None
Description: Programs loads songs.txt if it exists in the directory if it doesn’t one will be made after adding the first track to the list. The program allows a user to modify (add/remove) tracks, search by artist, and list all tracks currently saved.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

// Global constants 
const int maxChar = 256;
const char delimiter[5] = ";"; // Required delimiter

// Required struct
struct Song {
	char title[maxChar];
	char artist[maxChar];
	char min[maxChar];
	char sec[maxChar];
	char album[maxChar];
};

// Prototypes
void pause();
void inputCheck(char t[]);
int loadTrack(Song trackList[]);
int search(Song trackList[], int &n, Song results[]);
void write(int& n, Song song);
void addTrack(Song trackList[], int& n);
void tracks(Song trackList[], int n);
void deleteTrack(Song trackList[], int& n);

// Main
int main() {
	Song trackList[maxChar];
	Song results[maxChar];
	int n = loadTrack(trackList), t;
	char input;
	bool run = true;

	cout << "Welcome to project 2: song boogaloo!!\nThis project will automatically load your songs.text so you can modify it here.\n" << endl;

	do {
		cout << "Main menu:\n1. Search by Artist.\n2. Add a track.\n3. Delete track.\n4. List all tracks.\n5. Exit program." << endl;
		cin >> input;
		switch (input) {
			case '1': // Search
				cin.clear();
				cin.ignore(maxChar, '\n');
				t = search(trackList, n, results);
				if (t == 0) {
					cout << "Nothing found!" << endl;
					pause();
				}
				else {
					tracks(results, t);
				}
				break;

			case '2': // Add
				cin.clear();
				cin.ignore(maxChar, '\n');
				addTrack(trackList, n);
				break;

			case '3': // Delete
				cin.clear();
				cin.ignore(maxChar, '\n');
				deleteTrack(trackList, n);
				break;

			case '4': // List
				cin.clear();
				cin.ignore(maxChar, '\n');
				tracks(trackList, n);
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

// Pause - Extra fuction
void pause() {
	do {
		cout << "Continue with enter." << endl;
	} while (cin.get() != '\n');
	return;
}

// Semicolon filter (because I don't want to deal with bad data) - Extra fuction
void inputCheck(char t[]) {
	bool isGoodInput;
	do {
		isGoodInput = true;
		cin.getline(t, maxChar);
		if (strchr(t, delimiter[0])) {
			isGoodInput = false;
			cout << "It looks like you used a semicolon (;).\nUnfortunately, that's the delimiter for this project so you can’t use it.\nPlease correct your entry below." << endl;
		}
	} while (!isGoodInput);
	return;
}

// Load - Required fuction 1
int loadTrack(Song trackList[]) {
	Song temp;
	ifstream file;
	int i, k = 0;
	char t[maxChar], *token[maxChar];

	file.open("songs.txt");
	if (!file) {
		cout << "Although it looks like you don't have a songs.txt file in this directory.\nNo worries! One will be created for you after you add a song. However, if you have a songs.txt file you want to work with you should exit the program and put it in this directory.\n" << endl;
	}
	while (file.getline(t, maxChar)) {
		token[0] = strtok(t, delimiter);
		i = 0;
		while (token[i] != NULL) {
			i++;
			token[i] = strtok(NULL, delimiter);
		}
		strcpy(temp.title, token[0]);
		strcpy(temp.artist, token[1]);
		strcpy(temp.min, token[2]);
		strcpy(temp.sec, token[3]);
		strcpy(temp.album, token[4]);
		trackList[k] = temp;
		k++;
	}
	file.close();
	return k;
}

// Artist search - Required fuction 2
int search(Song trackList[], int &n, Song results[]) {
	int k = 0;
	char search[maxChar], *found;

	cout << "\nSearch by Arist: ";
	inputCheck(search);

	for (int i = 0; i < n; i++) {
		found = NULL;
		found = strstr(trackList[i].artist, search);
		if (found) {
			results[k] = trackList[i];
			k++;
		}
	}
	return k;
}

// Add song p1 - Required fuction 3
void write(int& n, Song song) {
	ofstream file;
	file.open("songs.txt", ios::app);
	file << song.title << delimiter[0] << song.artist << delimiter[0] << song.min << delimiter[0] << song.sec << delimiter[0] << song.album << "\n";
	n += 1;
	file.close();
	return;
}

// Add song p2 - Required fuction 3
void addTrack(Song trackList[], int& n) {
	Song temp;
	char t[maxChar], input;
	bool run = true;

	do {
		cout << "\nAdd a Track.\nSong title:" << endl;
		inputCheck(t);
		strcpy(temp.title, t);

		cout << "Artist:" << endl;
		inputCheck(t);
		strcpy(temp.artist, t);

		cout << "Runtime in minutes:" << endl;
		inputCheck(t);
		strcpy(temp.min, t);

		cout << "Runtime in seconds:" << endl;
		inputCheck(t);
		strcpy(temp.sec, t);

		cout << "Album:" << endl;
		inputCheck(t);
		strcpy(temp.album, t);

		cout << "\nYou've entered: " << temp.title << " - " << temp.artist << " - " << temp.min << ":" << temp.sec << " - " << temp.album << "\nAdd it to songs.txt? (y/n): ";
		cin >> input;

		if (input == 'y') {
			run = false;
			cout << "\nAdding " << temp.title << " to songs.txt.\n" << endl;
			write(n, temp);
		}
		if (input == 'n') {
			run = false;
		}
		cin.clear();
		cin.ignore(maxChar, '\n');
	} while (run);

	loadTrack(trackList);
	pause();
	return;
}


// Delete - Required fuction 4
void deleteTrack(Song trackList[], int& n) {
	ifstream file;
	ofstream tempFile;
	int id, songIndex = 0;
	char t[maxChar], input;
	bool run = true, con;

	cout << "\nHere's a list of your current Tracks.\nID - Title - Artist - Duration - Album" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << " - " << trackList[i].title << " - " << trackList[i].artist << " - " << trackList[i].min << ":" << trackList[i].sec << " - " << trackList[i].album << endl;
	}

	if (n > 0) {
		do {
			cout << "Enter the ID of the song you want to delete: ";
			do {
				if (!(cin >> songIndex)) {
				}
				else if (songIndex < 0 || songIndex >= n) {
					cout << "\nThat ID can't be found. Try again: ";
				}
				else {
					break;
				}
				cin.clear();
				cin.ignore(maxChar, '\n');
			} while (con);

			cout << "You want to delete " << trackList[songIndex].title << " - " << trackList[songIndex].artist << " - " << trackList[songIndex].min << ":" << trackList[songIndex].sec << " - " << trackList[songIndex].album << "? (y/n): ";
			cin >> input;

			if (input == 'y') {
				cin.clear();
				cin.ignore(maxChar, '\n');
				run = false;
				cout << "\nDeleting " << trackList[songIndex].title << endl;

				file.open("songs.txt");
				tempFile.open("tempSongs.txt", ios::app);

				if (!file) {
					cout << "Can't open songs.txt!!!";
				}

				id = 0;
				while (file.getline(t, maxChar)) {
					if (id != songIndex) {
						tempFile << t << '\n';
					}
					id++;
				}
				file.close();
				tempFile.close();

				remove("songs.txt");
				rename("tempSongs.txt", "songs.txt");
				n = loadTrack(trackList);
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
		cout << "It doesn't look like you have any songs." << endl;
	}
	pause();
	return;
}

// List all songs - Required fuction 5
void tracks(Song trackList[], int n) {
	cout << "\nYour Tracks.\nID - Title - Artist - Duration - Album" << endl;
	for (int i = 0; i < n; i++) {
		cout << i << " - " << trackList[i].title << " - " << trackList[i].artist << " - " << trackList[i].min << ":" << trackList[i].sec << " - " << trackList[i].album << endl;
	}
	pause();
	return;
}