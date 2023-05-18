#ifndef Sorter_H
#define Sorter_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Movie.h"
#include "Person.h"
using namespace std;

class Sorter {
public:
    /*
    Nick or Ryan will do this class. Whoever doesn't will implement the Searcher class.
    Functions should sort the vector according to specified fields
    */


    //Movie sort functions
    void sortByTitle(vector<Movie>&) const;
    void sortByReleaseDate(vector<Movie>&) const;
    void sortByRating(vector<Movie>&) const;

    //Person sort functions
    void sortByName(vector<Person>&) const;
    void sortByDOB(vector<Person>&) const;

};

#endif
