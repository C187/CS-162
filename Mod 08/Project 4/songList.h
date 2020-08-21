// Project 4
#ifndef SONGLIST
#define SONGLIST
#include "song.h"

class SongList {
    public:
        SongList();
        bool loadTrack();
        bool deleteTrack(int index);
        bool addTrack(Song& song);
        int search(Song *& searchResults, char query[], int mode);
        void printTracks();
        Song * getSong(int index);
        int getNum();
        ~SongList();
    private:
        Song * songList;
        int numSongs;
        void pauseInput();
};
#endif