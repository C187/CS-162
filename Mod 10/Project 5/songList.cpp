// Project 5
#include <fstream>
#include <iostream>
#include <cstring>
#include "songList.h"

using namespace std;

const char DELIMITER[5] = ";";

// Constructor 
SongList::SongList() {
    loadTrack();
}

// Load
bool SongList::loadTrack() {
	Song temp;
	ifstream songFile; 
    char t[MAX_CHAR], *token[MAX_CHAR];
	int i, j;

    songFile.open("songs.txt");
    if (!songFile) {
        cout << "Unable to open songs.txt!";
        return false;
    }

    songFile.clear();
    songFile.seekg(0, ios::beg);

    j = 0;
    while(songFile.getline(t, MAX_CHAR)) {    
        token[0] = strtok(t, DELIMITER);
        i = 0; 
        while(token[i] != NULL) {
            i++;
            token[i] = strtok(NULL, DELIMITER);
        }
        temp.setTitle(token[0]);
        temp.setArtist(token[1]);
        temp.setMin(token[2]);
		temp.setSec(token[3]);
        temp.setAlbum(token[4]);

        insertAlph(temp);
        j++;
    }
    songFile.close();
    setIds();
    return true;
}

// Add	
bool SongList::addTrack(Song& song) {
    ofstream songFile;
    songFile.open("songs.txt");
    if (!songFile) {
        cout << "Unable to open songs.txt!";
        return false;
    }

    insertAlph(song);
    songFile << songList.at(0)->getTitle() << DELIMITER[0] 
		<< songList.at(0)->getArtist() << DELIMITER[0]
        << songList.at(0)->getMin() << DELIMITER[0] 
		<< songList.at(0)->getSec() << DELIMITER[0] 
		<< songList.at(0)->getAlbum();

    for (int i = 1; i < songList.size(); i++) {
        songFile << '\n' << songList.at(i)->getTitle() << DELIMITER[0]
			<< songList.at(i)->getArtist() << DELIMITER[0]
			<< songList.at(i)->getMin() << DELIMITER[0] 
			<< songList.at(i)->getSec() << DELIMITER[0]
			<< songList.at(i)->getAlbum();
    }
    songFile.close();
    setIds();
    return true;
}

// Del
bool SongList::deleteTrack(int index) {
    ifstream songFile;
    ofstream tempFile;
    char t[MAX_CHAR];
    int j = 0;

    cout << "\nDeleting \"" << songList.at(index)->getTitle() << "\" by \"" << songList.at(index)->getArtist() << "\".\nPress enter to continue..." << endl;
    if (songList.size() <= 0) { 
        cout << "No tracks to delete." << endl;
    } 
	else if (index >= songList.size() || index < 0) {
        cout << "Invalid index!" << endl;
    } 
	else {
        songFile.open("songs.txt");
        tempFile.open("temp.txt", ios::app);
        if (!songFile) {
            cout << "Unable to open songs.txt";
        }
        while (songFile.getline(t, MAX_CHAR)) {
            if (j != index) {
                if (j != 0) {
                    tempFile << '\n' << t;
                } 
				else {
                    tempFile << t;
                }
            }
            j++;
        }
        songFile.close();
        tempFile.close();

        remove("songs.txt");
        rename("temp.txt", "songs.txt");
        songList.deleteAt(index);
        return true;
    }
    setIds();
    return false;
}

// Search by.. 0: Artist 1: Album
int SongList::search(Song *& searchResults, char query[], int mode) {
    char *foundString;
	int j;
    
    j = 0;
    for(int i = 0; i < songList.size(); i++) {
        foundString = NULL;
        switch(mode) {
            case(0):
                foundString = strstr(songList.at(i)->getArtist(), query);
                break;
            case(1):
                foundString = strstr(songList.at(i)->getAlbum(), query);
                break;
            default:
                break;
        }
        if(foundString){
            j++;
        }
    }
    searchResults = new Song[j];
    j = 0;
    for (int i = 0; i < songList.size(); i++) {
        foundString = NULL;
        switch(mode) {
            case(0):
                foundString = strstr(songList.at(i)->getArtist(), query);
                break;
            case(1):
                foundString = strstr(songList.at(i)->getAlbum(), query);
                break;
            default:
                break;
        }
        if (foundString) {
            searchResults[j].setTitle(songList.at(i)->getTitle());
            searchResults[j].setArtist(songList.at(i)->getArtist());
            searchResults[j].setMin(songList.at(i)->getMin());
			searchResults[j].setSec(songList.at(i)->getSec());
            searchResults[j].setAlbum(songList.at(i)->getAlbum());
            searchResults[j].setId(songList.at(i)->getId());
            j++;    
        }
    }
    return j;
}

// Prints track
void SongList::printTracks() {
    cout << "\nYour songs\nID - Title - Artist - Time - Album" << endl;
    for(int i = 0; i < songList.size(); i++) {
        cout << i << " - ";
        songList.at(i)->print();
    }
    pauseInput();
    return;
}

// Accessors
int SongList::getLen() {
    return songList.size();
}

Song * SongList::getSong(int index) {
    return songList.at(index);
}

// Pause
void SongList::pauseInput() {
    do {
        cout << "Press enter to continue..." << endl;
    } while (cin.get() != '\n');
    return;
}

// Compare
int SongList::compare(char * a, char * b) {
    char * str1 = new char[strlen(a) + 1];
    char * str2 = new char[strlen(b) + 1];
    int result, i, j;
    
    strcpy(str1, a);
    strcpy(str2, b);
    i = 0;
    j = 0;

    while (str1[i]) {
        if (str1[i] != ' ') {
            str1[j] = tolower(str1[i]);
            j++;
        }
        i++;
    }

    i = 0;
    j = 0;
    while (str2[i]) {
        if (str2[i] != ' ') {
            str2[j] = tolower(str2[i]);
            j++;
        }
        i++;
    }

    result = strcmp(str2, str1);
    delete str1;
    delete str2;
    return result;
}

// Insert Alphabetically
void SongList::insertAlph(Song& s) {
    if (songList.size() == 0) {
        songList.insertFirst(s);
    } 
	else {
        for (int i = 0; i < songList.size(); i++) {
            if (compare(songList.at(i)->getTitle(), s.getTitle()) == -1){
                songList.insertAt(s, i);
                break;
            } 
			else if (i == songList.size() - 1) {
                songList.insertLast(s);
                break;
            }
        }
    }
}

void SongList::setIds() {
    for (int i = 0; i < songList.size(); i++) {
        songList.setId(i);
    }
}
