// Project 4
#ifndef SONG
#define SONG
#define MAX_CHAR 256

class Song {
	public:
		Song();
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
		void setId(int i);
		void print();
		~Song();
	private:
		char * title;
		char * artist;
		char * min;
		char * sec;
		char * album;
		int trackId;
};
#endif