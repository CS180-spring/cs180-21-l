#include "pch.h"
#include <gtest/gtest.h>
#include "Movie.h"

Movie::Movie() {
    title = "";
    director = "";
    year = "";
    movieID = -1;
}

Movie::Movie(string title, string director, string year, vector<string, allocator<string>> genre) {
    this->title = title;
    this->director = director;
    this->year = year;
    this->genre = genre;
}

bool Movie::operator==(const Movie& other) const {
    return movieID == other.movieID &&
        title == other.title &&
        year == other.year &&
        director == other.director &&
        genre == other.genre;
}

unsigned int Movie::getID() const{
    return this->movieID;
}

string Movie::getTitle() const {
    return this->title;
}


string Movie::getDirector() const {
    return this->director;
}

/*vector<unsigned int> Movie::getActors() {
    return this->actors;
}*/

string Movie::getYear() const{
    return this->year;
}
vector<string, allocator<string>> Movie::getGenre() const{
    return this->genre;
}
void Movie::setYear(string year) {
    this->year = year;
}

void Movie::setID(unsigned int id) {
    this->movieID = id;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setDirector(string name) {
    this->director = name;
}

void Movie::addGenre(string genre) {
    this->genre.push_back(genre);
}

/*void Movie::removeActor(unsigned int id) {
    for (int k = 0; k < this->actors.size(); k++) {
        if (this->actors.at(k) == id) {
            this->actors.erase(this->actors.begin() + k);
        }
    }
}

void Movie::removeGenre(string name) {
    for (int k = 0; k < this->genre.size(); k++) {
        if (this->genre.at(k) == name) {
            this->genre.erase(this->genre.begin() + k);
        }
    }
}
*/
