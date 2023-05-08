#include "Movie.h"

Movie::Movie() {
    title = "";
    director = "";
    year = -1;
    movieID = -1;
}

Movie::Movie(string title, string director, string year, vector<string> genre) {
    this->title = title;
    this->director = director;
    this->year = year;
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


string Movie::getYear() {
    return this->year;
}
vector<string> Movie::getGenre() {
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

//void Movie::removeActor(unsigned int id) {
//    for(int k = 0; k < this->actors.size(); k++) {
//        if(this->actors.at(k) == id) {
//            this->actors.erase(this->actors.begin() +k);
//        }
//    }
//}
//
//void Movie::removeGenre(string name) {
//    for(int k = 0; k < this->genre.size(); k++) {
//        if(this->genre.at(k) == name) {
//            this->genre.erase(this->genre.begin() +k);
//        }
//    }
//}

