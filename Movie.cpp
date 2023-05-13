#include "Movie.h"

Movie::Movie() {
    this->title = "";
    this->director = "";
    this->releaseDate = "";
    this->rating = -1;
    this->movieID = -1;
}

Movie::Movie(string title, string director, string releaseDate, double rating, vector<string> genre) {
    this->title = title;
    this->director = director;
    this->releaseDate = releaseDate;
    this->rating = rating;
    this->genre = genre;
}

unsigned int Movie::getID() {
    return this->movieID;
}

string Movie::getTitle() {
    return this->title;
}


string Movie::getDirector() {
    return this->director;
}

vector<string> Movie::getGenre() {
    return this->genre;
}

string Movie::getReleaseDate() {
    return this->releaseDate;
}

double Movie::getRating() {
    return this->rating;
}

void Movie::setID(unsigned int id) {
    this->movieID = id;
}

void Movie::setReleaseDate(string date) {
    this->releaseDate = date;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setDirector(string name) {
    this->director = name;
}

void Movie::setRating(double value) {
    this->rating = value;
}

void Movie::addGenre(string genre) {
    this->genre.push_back(genre);
}

void Movie::removeGenre(string name) {
    for(int k = 0; k < this->genre.size(); k++) {
        if(this->genre.at(k) == name) {
            this->genre.erase(this->genre.begin() +k);
        }
    }
}

