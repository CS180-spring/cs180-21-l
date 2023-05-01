#include "Person.h"

Person::Person() {
    this->name = "";
    this->DOB = "";
    this->personID = -1;
}

Person::Person(string name, string DOB, vector<string> moviesStarredIn, vector<string> moviesDirected) {
    this->name = name;
    this->DOB = DOB;
    this->moviesStarredIn = moviesStarredIn;
    this->moviesDirected = moviesDirected;
    this->personID = -1;
}

string Person::getName() {
    return this->name;
}

string Person::getDOB() {
    return this->DOB;
}

vector<string> Person::getMovesStarred() {
    return this->moviesStarredIn;
}

vector<string> Person::getMoviesDirected() {
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

void Person::addMovieStarred(string title) {
    this->moviesStarredIn.push_back(title);
}
void Person::addMovieDirected(string title) {
    this->moviesDirected.push_back(title);
}

void Person::removeMovieStarred(string title) {
    this->moviesStarredIn.push_back(title);
}

void Person::removeMovieDirected(string title) {
    this->moviesDirected.push_back(title);
}