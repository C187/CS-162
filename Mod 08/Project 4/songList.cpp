// Project 4
#include <fstream>
#include <iostream>
#include <cstring>
#include "songList.h"

using namespace std;

const char DELIMITER[5] = ";";

// Constructor 
SongList::SongList(){
    loadTrack();
}

// D estructor
SongList::~SongList(){
    delete [] songList;
}

// Load
bool SongList::loadTrack(){
    ifstream songFile; 
    char tempString[MAX_CHAR];
    char *token[MAX_CHAR];
    int i; 
    int j; 

    songFile.open("songs.txt");
    if (!songFile){
        cout << "Unable to open songs.txt!";
        return false;
    }

    numSongs = 0;
    while(songFile.getline(tempString, MAX_CHAR)) {
        numSongs++;
    }

    songList = new Song[numSongs];
    songFile.clear();
    songFile.seekg(0, ios::beg);

    j = 0;
    while(songFile.getline(tempString, MAX_CHAR)) {  
        token[0] = strtok(tempString, DELIMITER);
        i = 0; 
        while(token[i] != NULL) {
            i++;
            token[i] = strtok(NULL, DELIMITER);
        }
        songList[j].setTitle(token[0]);
        songList[j].setArtist(token[1]);
        songList[j].setMin(token[2]);
		songList[j].setSec(token[3]);
        songList[j].setAlbum(token[4]);
        songList[j].setId(j);
        j++;
    }
    songFile.close();
    return true;
}

// Add
bool SongList::addTrack(Song& song){
    ofstream songFile;
    songFile.open("songs.txt", ios::app);
    if (!songFile){
        cout << "Unable to open songs.txt!";
        return false;
    }
    songFile << song.getTitle() << DELIMITER[0] << song.getArtist() << DELIMITER[0] << song.getMin() << DELIMITER[0] << song.getSec() << DELIMITER[0] << song.getAlbum() << '\n';
    songFile.close();
    delete [] songList;
    loadTrack();
    return true;
}

// Del
bool SongList::deleteTrack(int index){
    ifstream songFile;
    ofstream tempFile;
    char tempString[MAX_CHAR];
    int j = 0;

    cout << "\nDeleting \"" << songList[index].getTitle() << "\" by \"" << songList[index].getArtist() << "\".\nPress enter to continue..." << endl;
    if(numSongs <= 0){ 
        cout << "No tracks to delete." << endl;
    } else if(index >= numSongs || index < 0){
        cout << "Invalid index!" << endl;
    } else {
        songFile.open("songs.txt");
        tempFile.open("temp.txt", ios::app);

        if (!songFile){
            cout << "Unable to open songs.txt!";
        }

        while(songFile.getline(tempString, MAX_CHAR)){
            if(j != index){
                if(j != 0){
                    tempFile << '\n' << tempString;
                } else {
                    tempFile << tempString;
                }
            }
            j++;
        }
        songFile.close();
        tempFile.close();

        remove("songs.txt");
        rename("temp.txt", "songs.txt");
        delete [] songList;
        loadTrack();
        return true;
    }
    return false;
}

// Search by.. 0: Artist 1: Album
int SongList::search(Song *& searchResults, char query[], int mode){
    char *foundString;
    int j;
    
    j = 0;
    for(int i = 0; i < numSongs; i++){
        foundString = NULL;
        switch(mode){
            case(0):
                foundString = strstr(songList[i].getArtist(), query);
                break;
            case(1):
                foundString = strstr(songList[i].getAlbum(), query);
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
    for(int i = 0; i < numSongs; i++){
        foundString = NULL;
        switch(mode){
            case(0):
                foundString = strstr(songList[i].getArtist(), query);
                break;
            case(1):
                foundString = strstr(songList[i].getAlbum(), query);
                break;
            default:
                break;
        }
        if(foundString){
            searchResults[j].setTitle(songList[i].getTitle());
            searchResults[j].setArtist(songList[i].getArtist());
            searchResults[j].setMin(songList[i].getMin());
			searchResults[j].setSec(songList[i].getSec());
            searchResults[j].setAlbum(songList[i].getAlbum());
            searchResults[j].setId(songList[i].getId());
            j++;    
        }
    }
    return j;
}

//Prints track
void SongList::printTracks() {
	cout << "\nYour songs" << endl;
	cout << "ID - Title - Artist - Time - Album" << endl;
	for (int i = 0; i < numSongs; i++) {
		cout << i << " - ";
		songList[i].print();
	}
	pauseInput();
	return;
}

// Accessors
int SongList::getNum(){
    return numSongs;
}

Song * SongList::getSong(int index){
    return &songList[index];
}

// Pause
void SongList::pauseInput(){
    do {
        cout << "Press enter to continue..." << endl;
    } while (cin.get() != '\n');
    return;
}

