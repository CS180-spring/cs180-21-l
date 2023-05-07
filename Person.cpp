#include "Person.h"

Person::Person() {
    this->name = "";
    this->DOB = "";
    this->personID = -1;
}

Person::Person(string name, string DOB, vector<unsigned int> moviesStarredIn, vector<unsigned int> moviesDirected) {
    this->name = name;
    this->DOB = DOB;
    this->moviesStarredIn = moviesStarredIn;
    this->moviesDirected = moviesDirected;
    this->personID = -1;
}

unsigned int Person::getID() {
    return this->personID;
}

string Person::getName() {
    return this->name;
}

string Person::getDOB() {
    return this->DOB;
}

vector<unsigned int> Person::getMovesStarred() {
    return this->moviesStarredIn;
}

vector<unsigned int> Person::getMoviesDirected() {
    return this->moviesDirected;
}
 
void Person::setID(int id) {
    this->personID = id;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setDOB (string date) {
    this->DOB = date;
}

void Person::addMovieStarred(unsigned int id) {
    this->moviesStarredIn.push_back(id);
}
void Person::addMovieDirected(unsigned int id) {
    this->moviesDirected.push_back(id);
}

void Person::removeMovieStarred(unsigned int id) {
    for(int k = 0; k < this->moviesStarredIn.size(); k++) {
        if(this->moviesStarredIn.at(k) == id) {
            this->moviesStarredIn.erase(this->moviesStarredIn.begin() + k);
        }
    }
}

void Person::removeMovieDirected(unsigned int id) {
    for(int k = 0; k < this->moviesDirected.size(); k++) {
        if(this->moviesDirected.at(k) == id) {
            this->moviesDirected.erase(this->moviesDirected.begin() + k);
        }
    }
}