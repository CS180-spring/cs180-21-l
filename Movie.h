#include<string>
#include<vector>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
    public:
        //Constructors
        Movie();
        Movie(string title, string director, vector<unsigned int> actors, string releaseDate, vector<string> genre);

        //Accessor methods
        unsigned int getID();
        string getTitle();
        string getDirector();
        vector<unsigned int> getActors();
        string getReleaseDate();
        vector<string> getGenre();

        //Modifier methods
        void setID(unsigned int id);
        void setTitle(string title);
        void setDirector(string name);

        void addActor(unsigned int id);
        void addGenre(string name);

        void removeActor(unsigned int id);
        void removeGenre(string genre);

    private:
        //Private variables
        unsigned int movieID;
        string title;
        string director;
        vector<unsigned int> actors;
        string releaseDate;
        vector<string> genre;
};

#endif