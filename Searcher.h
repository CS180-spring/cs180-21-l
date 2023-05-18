#ifndef SEARCHER_H
#define SEARCHER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Movie.h"
#include "Person.h"
using namespace std;

class Searcher {
public:
    /*
    Nick or Ryan will do this class. Whoever doesn't will implement the Sorter class.
    Functions should return a vector, who's attributes match specified field
    */


    //Movie search functions
    vector<Movie> searchByTitle(const string& title, vector<Movie>&) const;
    vector<Movie> searchByReleaseDate(const string& date, vector<Movie>&) const;
    vector<Movie> searchByRating(const string& genre, vector<Movie>&) const;

    //Person search functions
    vector<Person> searchByName(const string& name, vector<Person>&) const;
    vector<Person> searchByDOB(const string& name, vector<Person>&) const;

};

#endif
