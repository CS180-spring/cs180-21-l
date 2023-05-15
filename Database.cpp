#include "Database.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "json.h"

using json = nlohmann::json;
using namespace std;

Database::Database() { }

void Database::loadMovies(const string& movieFile) {
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
        const auto& genreArray = movieData["genre"];
        string director = movieData["director"];
        double rating = movieData["rating"];
        Movie movie(title, director, year, rating, genreArray);
        movie.setID(movieID);
        movies[movie.getID()] = movie;
    }
}

void Database::loadPeople(const string& personFile) {
    ifstream file(personFile);
    if (!file.is_open()) {
        cout << "Failed to open the JSON file." << endl;
        return;
    }
    json data;
    file >> data;
    file.close();

    for (auto&  peopleData: data) {
        int personID = peopleData["id"];
        string name = peopleData["name"];
        string DOB = peopleData["dob"];
        Person person(name, DOB);
        person.setID(personID);
        people[person.getID()] = person;
    }
}

//Converts the 2 unordered_maps to JSON format
void Database::storeMovies(const string& movieFile)  {
    json jsonData;

    for (auto& pair : movies) {
        Movie& movie = pair.second;

        json movieData;
        movieData["id"] = movie.getID();
        movieData["title"] = movie.getTitle();
        movieData["year"] = movie.getReleaseDate();
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

void Database::storePeople(const string& personFile) {
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