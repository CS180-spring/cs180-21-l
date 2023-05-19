#include<string>
#include<vector>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
    public:
        //Constructors
        Movie();
        Movie(string title, string director, string releaseDate, double rating, vector<string> genre);

        //Accessor methods
        unsigned int getID();
        string getTitle();
        string getDirector();
        string getReleaseDate();
        vector<string> getGenre();
        double getRating();

        //Modifier methods
        void setID(unsigned int id);
        void setTitle(string title);
        void setReleaseDate(string date);
        void setDirector(string name);
        void setRating(double rating);
        void addGenre(string genre);
        void removeGenre(string genre);

    private:
        //Private variables
        unsigned int movieID;
        string title;
        double rating;
        string director;
        string releaseDate;
        vector<string> genre;
};

#endif