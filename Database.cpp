#include "pch.h"
#include <gtest/gtest.h>
#include "Database.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "json.h"

using json = nlohmann::json;
using namespace std;

Database::Database() { }

void Database::loadMovies(string& movieFile) {
    ifstream file(movieFile);
    if (!file.is_open()) {
        cout << "Failed to open the JSON file." << endl;
        return;
    }
    json data;
    file >> data;
    file.close();

    for (const auto& movieData : data) {
        int movieID = movieData["id"];
        string title = movieData["title"];
        string year = movieData["year"];
        const auto& genreData = movieData["genre"];
        vector<string, allocator<string>> genreArray(genreData.begin(), genreData.end());
        string director = movieData["director"];
        Movie movie(title, director, year, genreArray);
        movie.setID(movieID);
        movies[movie.getID()] = movie;
    }
}



void Database::loadPeople(string& personFile) {
    ifstream file(personFile);
    if (!file.is_open()) {
        cout << "Failed to open the JSON file." << endl;
        return;
    }
    json data;
    file >> data;
    file.close();

    for (auto& peopleData : data) {
        int personID = peopleData["id"];
        string name = peopleData["name"];
        string DOB = peopleData["dob"];
        Person person(name, DOB);
        person.setID(personID);
        people[person.getID()] = person;
    }
}
bool Database::loadPeopleTest(string& personFile) {
    ifstream file(personFile);
    if (file.is_open()) {
        cout << "Person file loaded successfully" << endl;
        return true;
    }
    else {
        cout << "Failed to open the Person file" << endl;
        return false;
    }
}

bool Database::loadMoviesTest(string& movieFile) {
    ifstream file(movieFile);
    if (file.is_open()) {
        cout << "Movie file loaded successfully" << endl;
        return true;
    }
    else {
        cout << "Failed to open the Movies file" << endl;
        return false;
    }
}

//Converts the 2 unordered_maps to JSON format
void Database::storeMovies(string& movieFile) {
    json jsonData;

    for (auto& pair : movies) {
        Movie& movie = pair.second;

        json movieData;
        movieData["id"] = movie.getID();
        movieData["title"] = movie.getTitle();
        movieData["year"] = movie.getYear();
        movieData["director"] = movie.getDirector();

        json genreArray = json::array();
        for (auto& genre : movie.getGenre()) {
            genreArray.push_back(genre);
        }
        movieData["genre"] = genreArray;
        jsonData.push_back(movieData);
    }

    // Store the JSON data to a file or do any other necessary processing
    ofstream file(movieFile);
    if (file.is_open()) {
        file << jsonData.dump(4); // Write the JSON data to the file with indentation
        file.close();
    }
    else {
        cout << "Failed to open the JSON file for writing." << endl;
    }
}

void Database::storePeople(string& personFile) {
    json jsonData;

    for (auto& pair : people) {
        Person& person = pair.second;

        json personData;
        personData["id"] = person.getID();
        personData["name"] = person.getName();
        personData["DOB"] = person.getDOB();

        jsonData.push_back(personData);
    }

    // Store the JSON data to a file or do any other necessary processing
    ofstream file(personFile);
    if (file.is_open()) {
        file << jsonData.dump(4); // Write the JSON data to the file with indentation
        file.close();
    }
    else {
        cout << "Failed to open the JSON file for writing." << endl;
    }
}

// Returns a vector of all the movies in the database
vector<Movie> Database::getMovies() {
    vector<Movie> moviesVector;
    for (const auto& movie : movies) {
        moviesVector.push_back(movie.second);
    }
    return moviesVector;
}


// Returns the movie with the specified ID
Movie Database::getMovieByID(int movieID) {
    auto it = movies.find(movieID);
    if (it != movies.end()) {
        return it->second;
    }
    else {
        return Movie("", "", "", {});
    }
}

// Returns a vector of all the people in the database
vector<Person> Database::getPeople() {
    vector<Person> peopleVector;
    for (const auto& person : people) {
        peopleVector.push_back(person.second);
    }
    return peopleVector;
}


// Returns the person with the specified ID
Person Database::getPersonByID(int personID) {
    auto it = people.find(personID);
    if (it != people.end()) {
        return it->second;
    }
    else {
        return Person("", "");
    }
}
