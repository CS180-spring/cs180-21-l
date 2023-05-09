#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>
#include "Movie.h"
#include "Person.h"

using namespace std;

class Database {
public:
    //Constructor
    Database();

    //Converts whatever is the in the file to an unordered_map for movies and people
    //Change function types and parameters as needed
    void loadMovies(string& movieFile);
    void loadPeople(string& personFile);

    //Converts the 2 unordered_maps to JSON format
    void storeMovies(string& movieFile);
    void storePeople(string& personFile);

    //Converts the actedin, actorsin JSONs to unordered_multimaps
    void loadMoviesToPeople(string& castFile);
    void loadPeopleToMovies(string& starredInFile);

    //Converts the 2 unordered_maps to JSON format
    void storeMoviesToPeople(string& castFile) const;
    void storePeopleToMovies(string& starredInFile) const;

    
    //Ryan Chandler will do these:
    void buildDatabase();

    //building the movie queries
    void buildTitleIndex();
    void buildGenreIndex();
    void buildRatingIndex();
    void buildReleaseDateIndex();

    //building the person queries
    void buildNameIndex();
    void buildDOBIndex();


    //Add object to map and all existing queries
    void insertMovie(Movie&);
    void insertPerson(Person&);

    //Remove object from map and all existing queries
    void removeMovie(unsigned int);
    void removePerson(unsigned int);

    //Functions to update an individual Movie, and existing queries
    void updateMovieTitle(unsigned int, const string& title);
    void updateMovieDate(unsigned int, const string& date);
    void updateMovieRating(unsigned int, double rating);

    //Functions to update an individual Person, and existing queries
    void updatePersonName(unsigned int, const string& name);
    void updatePersonDOB(unsigned int, const string& db);

private:
    //The unique ID is mapped to the Movie/Person object
    unordered_map<unsigned int, Movie> movies;
    unordered_map<unsigned int, Person> people;

    //Maps unique ID of a Movie/Person to unique IDs of Movie/Person object(s)
    unordered_multimap<unsigned int, unsigned int> moviesToPeople;
    unordered_multimap<unsigned int, unsigned int> peopleToMovies;

    //Movie Queries
    multimap<string, unsigned int> titleIndex;
    unordered_multimap<string, unsigned int> genreIndex;
    multimap<double, unsigned int> ratingIndex;
    multimap<string, unsigned int> releaseDateIndex;
    //Movies a person starred in will be stored in the Person object or taken from a JSON

    //Person Queries
    multimap<string, unsigned int> nameIndex;
    multimap<string, unsigned int> dobIndex;
    //People who starred in a particular movie will be stored in the Movie object or taken from a JSON

};

#endif
