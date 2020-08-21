// Project 5
#ifndef SONG
#define SONG
#define MAX_CHAR 256

class Song {
    public:
        Song();
        void operator=(Song &s);
        char * getTitle();
        char * getArtist();
        char * getMin();
		char * getSec();
        char * getAlbum();
        int getId();
        void setTitle(char * s);
        void setArtist(char * s);
        void setMin(char * s);
		void setSec(char * s);
        void setAlbum(char * s);
        void print();
        void setId(int id);
        ~Song();
    private:
        char * title;
        char * artist;
        char * min;
		char * sec;
        char * album;
        int trackID;
};

#endif