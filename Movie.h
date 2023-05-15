#include<string>
#include<vector>
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:
    //Constructors
    Movie();
    Movie(string title, string director, string year, vector<string, allocator<string>> genre);

    //Accessor methods
    unsigned int getID() const;
    string getTitle() const;
    string getDirector() const;
    vector<unsigned int> getActors();
    string getYear() const;
    vector<string, allocator<string>> getGenre() const;

    //Modifier methods
    void setID(unsigned int id);
    void setTitle(string title);
    void setDirector(string name);
    void setYear(string year);
    void addActor(unsigned int id);
    void addGenre(string name);

    void removeActor(unsigned int id);
    void removeGenre(string genre);

    bool operator==(const Movie& other) const;

private:
    //Private variables
    unsigned int movieID;
    string title;
    string director;
    //vector<unsigned int> actors;
    string year;
    vector<string, allocator<string>> genre;
};

#endif
#include "gtest/gtest.h"
