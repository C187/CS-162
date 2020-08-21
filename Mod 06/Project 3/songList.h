#ifndef SONGLIST
#define SONGLIST
#include "song.h"

class SongList {
public:
	SongList();
	bool loadTrack();
	bool deleteSong(int index);
	bool addTrack(Song song);
	int search(Song searchResults[], char query[], int mode);
	void printSongs();
	Song getSong(int index);
	int getNum();
private:
	Song songList[128];
	int numSongs;
	void pauseInput();
};

#endif