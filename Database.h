#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Movie.h"
#include "Person.h"
#include <fstream>
#include "json.h"
#include <iostream>
using namespace std;
using json = nlohmann::json;

class Database {
public:
    //Converts whatever is the in the file to an unordered_map for movies and people
    //Change function types and parameters as needed
    void loadMovies(const std::string& movieFile) {
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
            Movie movie(title, director, year, genreArray);
            movie.setID(movieID);
            movies[movie.getID()] = movie;
        }
    }
    void loadPeople(const std::string& personFile) {
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
    void storeMovies(const string& movieFile)  {
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
        std::ofstream file(movieFile);
        if (file.is_open()) {
            file << jsonData.dump(4); // Write the JSON data to the file with indentation
            file.close();
        }
        else {
            cout << "Failed to open the JSON file for writing." << endl;
        }

    }
    void storePeople(const string& personFile)  {
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
        std::ofstream file(personFile);
        if (file.is_open()) {
            file << jsonData.dump(4); // Write the JSON data to the file with indentation
            file.close();
        }
        else {
            cout << "Failed to open the JSON file for writing." << endl;
        }
    }

    
    //Ryan Chandler will do these:
    void buildDatabase();

    //building the movie queries
    void buildTitleIndex();
    void buildGenreIndex();
    void buildRatingIndex();
    void buildReleaseDateIndex();

    //building the person queries
    void buildNameIndex();
    void buildDOBIndex();


    //Add object to map and all existing queries
    void insertMovie(Movie&);
    void insertPerson(Person&);

    //Remove object from map and all existing queries
    void removeMovie(unsigned int);
    void removePerson(unsigned int);

private:
    //The unique ID is mapped to the Movie/Person object
    unordered_map<unsigned int, Movie> movies;
    unordered_map<unsigned int, Person> people;

    //Movie Queries
    unordered_multimap<string, unsigned int> titleIndex;
    unordered_multimap<string, unsigned int> genreIndex;
    unordered_multimap<double, unsigned int> ratingIndex;
    unordered_multimap<string, unsigned int> releaseDateIndex;
    //Movies a person starred in will be stored in the Person object or taken from a JSON

    //Person Queries
    unordered_multimap<string, unsigned int> nameIndex;
    unordered_multimap<string, unsigned int> dobIndex;
    //People who starred in a particular movie will be stored in the Movie object or taken from a JSON

};

#endif
