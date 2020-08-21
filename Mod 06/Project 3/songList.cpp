#define  _CRT_SECURE_NO_WARNINGS // VS17 Flag
#include <fstream>
#include <iostream>
#include <cstring>
#include "songList.h"

using namespace std;

const char DELIMITER[5] = ";";

//Constructor 
SongList::SongList() {
	loadTrack();
}

// Load
bool SongList::loadTrack() {
	ifstream songFile;
	char tempString[MAX_CHAR];
	char *token[MAX_CHAR]; //to split
	int i;
	int j; //total number of songs

	songFile.open("songs.txt");
	if (!songFile) {
		cout << "Unable to open songs.txt!";
		return false;
	}

	j = 0;
	while (songFile.getline(tempString, MAX_CHAR)) { //get entire line (including spaces)
		token[0] = strtok(tempString, DELIMITER);
		i = 0;
		while (token[i] != NULL) {
			i++;
			token[i] = strtok(NULL, DELIMITER);
		}

		songList[j] = Song(token[0], token[1], token[2], token[3], token[4], j);
		j++;
	}
	numSongs = j;
	songFile.close(); //close filestream
	return true;
}

// Add
bool SongList::addTrack(Song song) {
	ofstream songFile;
	songFile.open("songs.txt", ios::app);
	if (!songFile) {
		cout << "Unable to open songs.txt!";
		return false;
	}
	songFile << song.getTitle() << DELIMITER[0] << song.getArtist() << DELIMITER[0]
		<< song.getMin() << DELIMITER[0] << song.getSec() << DELIMITER[0] << song.getAlbum() << '\n';
	songFile.close();
	loadTrack();
	return true;
}

// Del
bool SongList::deleteSong(int index) {
	ifstream songFile;
	ofstream tempFile;
	char tempString[MAX_CHAR];
	int j;

	cout << "Deleting " << songList[index].getTitle() << "...\n" << endl;
	if (numSongs <= 0) {
		cout << "No files to delete!" << endl;
	}
	else if (index >= numSongs || index < 0) {
		cout << "Invalid index!" << endl;
	}
	else {
		songFile.open("songs.txt");
		tempFile.open("temp.txt", ios::app);

		if (!songFile) {
			cout << "Unable to open songs.txt!";
		}

		j = 0;
		while (songFile.getline(tempString, MAX_CHAR)) {
			if (j != index) {
				tempFile << tempString << '\n';
			}
			j++;
		}
		songFile.close();
		tempFile.close();

		remove("songs.txt");
		rename("temp.txt", "songs.txt");
		loadTrack();
		return true;
	}
	return false;
}

// Search tracks
int SongList::search(Song searchResults[], char query[], int mode) {
	char *foundString;
	int j;

	j = 0;
	for (int i = 0; i < numSongs; i++) {
		foundString = NULL;

		foundString = strstr(songList[i].getArtist(), query);


		if (foundString) {
			searchResults[j] = songList[i];
			j++;
		}
	}
	return j;
}

// Prints track
void SongList::printSongs() {
	cout << "\nYour songs" << endl;
	cout << "ID - Title - Artist - Min - Sec - Album" << endl;
	for (int i = 0; i < numSongs; i++) {
		cout << i << " - ";
		songList[i].print();
	}
	pauseInput();
	return;
}


// Accessors
int SongList::getNum() {
	return numSongs;
}

Song SongList::getSong(int index) {
	return songList[index];
}


// Pause
void SongList::pauseInput() {
	do {
		cout << "Press enter to continue..." << endl;
	} while (cin.get() != '\n');
	return;
}
