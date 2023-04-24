#include<string>
#include<vector>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
    public:
        Movie();
        Movie(string title, string director, vector<string> actors, string releaseDate, vector<string> genre);

        string getTitle();
        string getDirector();
        vector<string> getActors();
        string getReleaseDate();
        vector<string> getGenre();

        void setID(int id);
        void setTitle(string title);
        void setDirector(string name);

        void addActor(string name);
        void addGenre(string name);

        void removeActor(string name);
        void removeGenre(string genre);

    private:
        int movieID;
        string title;
        string director;
        vector<string> actors;
        string releaseDate;
        vector<string> genre;
};

#endif