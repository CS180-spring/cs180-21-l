#include<string>
#include<vector>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
    public:
        //Constructors
        Movie();
        Movie(string title, string director, string year, vector<string> genre);
        

        //Accessor methods
        unsigned int getID();
        string getTitle();
        string getDirector();
        string getYear();
        vector<string> getGenre();

        //Modifier methods
        void setID(unsigned int id);
        void setYear(string year);
        void setTitle(string title);
        void setDirector(string name);
        void addGenre(string name);
        void removeGenre(string genre);

    private:
        //Private variables
        unsigned int movieID;
        string title;
        string director;
        string year;
        vector<string> genre;
};

#endif

//Deleted actors from movie class per the new design document
// "2. Movies JSON, has the field of ID, Title, Year, Genre, Director "
//Changed releaseDate to year to be consistent with json file