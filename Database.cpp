#include "Database.h"
#include <iostream>
#include <fstream>
#include <utility>

#include "json.h"

using json = nlohmann::json;


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

    for (auto& peopleData : data) {
        int personID = peopleData["id"];
        string name = peopleData["name"];
        string DOB = peopleData["dob"];
        Person person(name, DOB);
        person.setID(personID);
        people[person.getID()] = person;
    }
}

//Converts the 2 unordered_maps to JSON format
void Database::storeMovies(const string& movieFile) {
    json jsonData;

    for (auto& pair : movies) {
        Movie& movie = pair.second;

        json movieData;
        movieData["id"] = movie.getID();
        movieData["title"] = movie.getTitle();
        movieData["year"] = movie.getReleaseDate();
        movieData["director"] = movie.getDirector();
        movieData["rating"] = movie.getRating();

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

//Converts the actedin, actorsin JSONs to unordered_multimaps
void Database::loadMoviesToPeople(const string& castFile) {
    ifstream file(castFile);
    if (!file.is_open()) {
        cout << "Failed to open file: " << castFile << endl;
        return;
    }

    json jsonData;
    try {
        file >> jsonData;
    }
    catch (const json::parse_error& e) {
        cout << "Failed to parse JSON file: " << e.what() << endl;
        return;
    }

    
    for (auto& entry : jsonData) {
        int movieID = entry["movieID"];
        const auto& peopleIDs = entry["peopleID"];

        for (int peopleID : peopleIDs) {
            moviesToPeople.emplace(movieID, peopleID);
        }
    }
}
void Database::loadPeopleToMovies(const string& starredInFile) {
    ifstream file(starredInFile);
    if (!file.is_open()) {
        cout << "Failed to open file: " << starredInFile << endl;
        return;
    }

    json jsonData;
    try {
        file >> jsonData;
    }
    catch (const json::parse_error& e) {
        cout << "Failed to parse JSON file: " << e.what() << endl;
        return;
    }


    for (auto& entry : jsonData) {
        int peopleID = entry["peopleID"];
        auto& movieIDs = entry["movieID"];

        for (int movieID : movieIDs) {
            peopleToMovies.emplace(peopleID, movieID);
        }
    }
}

//Converts the 2 unordered_maps to JSON format
void Database::storeMoviesToPeople(const string& castFile) const {
    json jsonData;
    for (auto& pair : moviesToPeople) {
        int movieID = pair.first;
        auto& peopleID = pair.second;

        jsonData.push_back({
            {"movieID", movieID},
            {"peopleID", peopleID}
            });
    }

    ofstream file(castFile);
    if (!file.is_open()) {
        cout << "Failed to open file: " << castFile << endl;
        return;
    }

    file << setw(4) << jsonData << endl;
    cout << "Stored movies to people data in file: " << castFile << endl;
}
void Database::storePeopleToMovies(const string& starredInFile) const {
    json jsonData;
    for (auto& pair : peopleToMovies) {
        int peopleID = pair.first;
        auto& movieID = pair.second;

        jsonData.push_back({
            {"PeopleID", peopleID},
            {"movieID", movieID}
            });
    }

    ofstream file(starredInFile);
    if (!file.is_open()) {
        cout << "Failed to open file: " << starredInFile << endl;
        return;
    }

    file << setw(4) << jsonData << endl;
    cout << "Stored movies to people data in file: " << starredInFile << endl;
}