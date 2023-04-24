#include "Movie.h"

Movie::Movie() {
    title = "";
    director = "";
    releaseDate = "";
    movieID = -1;
}

Movie::Movie(string title, string director, vector<string> actors, string releaseDate, vector<string> genre) {
    this->title = title;
    this->director = director;
    this->actors = actors;
    this->releaseDate = releaseDate;
    this->genre = genre;
}

string Movie::getTitle() {
    return this->title;
}


string Movie::getDirector() {
    return this->director;
}

vector<string> Movie::getActors() {
    return this->actors;
}

string Movie::getReleaseDate() {
    return this->releaseDate;
}
vector<string> Movie::getGenre() {
    return this->genre;
}

void Movie::setID(int id) {
    this->movieID = id;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setDirector(string name) {
    this->director = name;
}

void Movie::addActor(string name) {
    this->actors.push_back(name);
}
void Movie::addGenre(string genre) {
    this->genre.push_back(genre);
}

void Movie::removeActor(string name) {
    for(int k = 0; k < this->actors.size(); k++) {
        if(this->actors.at(k) == name) {
            this->actors.erase(this->actors.begin() +k);
        }
    }
}

void Movie::removeGenre(string name) {
    for(int k = 0; k < this->genre.size(); k++) {
        if(this->genre.at(k) == name) {
            this->genre.erase(this->genre.begin() +k);
        }
    }
}

