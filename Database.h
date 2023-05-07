#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Movie.h"
#include "Person.h"
using namespace std;

class Database {
public:
    //Converts whatever is the in the file to an unordered_map for movies and people
    //Change function types and parameters as needed
    void loadMovies();
    void loadPeople();

    //Converts the 2 unordered_maps to JSON format
    void storeMovies(unordered_map<unsigned int, Movie>) const;
    void storePeople(unordered_map<unsigned int, Person>) const;

    
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

private:
    //The unique ID is mapped to the Movie/Person object
    unordered_map<unsigned int, Movie> movies;
    unordered_map<unsigned int, Person> people;

    //Movie Queries
    unordered_multimap<string, unsigned int> titleIndex;
    unordered_multimap<string, unsigned int> genreIndex;
    unordered_multimap<double, unsigned int> ratingIndex;
    unordered_multimap<string, unsigned int> releaseDateIndex;
    //Movies a person starred in will be stored in the Person object or taken from a JSON

    //Person Queries
    unordered_multimap<string, unsigned int> nameIndex;
    unordered_multimap<string, unsigned int> dobIndex;
    //People who starred in a particular movie will be stored in the Movie object or taken from a JSON

};

#endif
