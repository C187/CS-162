// Project 5
#ifndef SONGLIST
#define SONGLIST
#include "song.h"
#include "linkedList.h"

class SongList {
    public:
        SongList();
        bool loadTrack();
        bool deleteTrack(int index);
        bool addTrack(Song& song);
        int search(Song *& searchResults, char query[], int mode);
        void printTracks();
        Song * getSong(int index);
        int getLen();
    private:
        linkedList songList;
        void insertAlph(Song& s);
        int compare(char * a, char * b);
        void setIds();
        void pauseInput();
};

#endif