#ifndef SONG
#define SONG
#define MAX_CHAR 128

class Song {
public:
	Song();
	Song(char initTitle[], char initArtist[], char initMin[], char initSec[], char album[], int id);
	char * getTitle();
	char * getArtist();
	char * getMin();
	char * getSec();
	char * getAlbum();
	int getId();
	void setTitle(char s[]);
	void setArtist(char s[]);
	void setMin(int newMin);
	void setSec(int newSec);
	void setMin(char s[]);
	void setSec(char s[]);
	void setAlbum(char s[]);
	void setId(int i);
	void print();
private:
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char min[MAX_CHAR];
	char sec[MAX_CHAR];;
	char album[MAX_CHAR];
	int trackID;
};

#endif