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
    this->maxMovieID = 0;
    for (const auto& movieData : data) {
        unsigned int movieID = movieData["id"];
        this->maxMovieID = max(movieID, maxMovieID);
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

void Database::loadPeople(string& personFile) {
    ifstream file(personFile);
    if (!file.is_open()) {
        cout << "Failed to open the JSON file." << endl;
        return;
    }
    json data;
    file >> data;
    file.close();
    this->maxPersonID = 0;
    for (auto&  peopleData: data) {
        unsigned int personID = peopleData["id"];
        this->maxPersonID = max(maxPersonID, personID);
        string name = peopleData["name"];
        string DOB = peopleData["dob"];
        Person person(name, DOB);
        person.setID(personID);
        people[person.getID()] = person;
    }
}

//Converts the 2 unordered_maps to JSON format
void Database::storeMovies(string& movieFile)  {
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

//Inserting methods
void Database::insertMovie(Movie& movie) {
    // Sets the new ID to 1 greater than the current max ID
    maxMovieID++;
    movies[maxMovieID] = movie;

    //Updating Queries
    titleIndex.insert(make_pair(movie.getTitle(), maxMovieID));
    ratingIndex.insert(make_pair(movie.getRating(), maxMovieID));
    releaseDateIndex.insert(make_pair(movie.getReleaseDate(), maxMovieID));
    vector<string> genres = movie.getGenre();
    for (string genre : genres) {
        genreIndex.insert(make_pair(genre, maxMovieID));
    }
}

void Database::insertPerson(Person& person) {
    // Sets the new ID to 1 greater than the current max ID
    maxPersonID++;
    people[maxPersonID] = person;

    //Updating Queries
    nameIndex.insert(make_pair(person.getName(), maxPersonID));
    dobIndex.insert(make_pair(person.getDOB(), maxPersonID));
}

//Removal methods
void Database::removeMovie(unsigned int movieID) {
    Movie movie = movies[movieID];
    movies.erase(movieID);

    //Updating Queries
    //Used Chat-GPT to find out how to iterate multimaps
    auto titleRange = titleIndex.equal_range(movie.getTitle());
    for (auto it = titleRange.first; it != titleRange.second; ++it) {
        if (it->second == movieID) {
            titleIndex.erase(it);
            break;
        }
    }
    auto ratingRange = ratingIndex.equal_range(movie.getRating());
    for (auto it = ratingRange.first; it != ratingRange.second; ++it) {
        if (it->second == movieID) {
            ratingIndex.erase(it);
            break;
        }
    }

    auto releaseDateRange = releaseDateIndex.equal_range(movie.getReleaseDate());
    for (auto it = releaseDateRange.first; it != releaseDateRange.second; ++it) {
        if (it->second == movieID) {
            releaseDateIndex.erase(it);
            break;
        }
    }

    vector<string> genres = movie.getGenre();
    for (string& genre : genres) {
        auto genreRange = genreIndex.equal_range(genre);
        for (auto it = genreRange.first; it != genreRange.second; ++it) {
            if (it->second == movieID) {
                genreIndex.erase(it);
                break;
            }
        }
    }
}

void Database::removePerson(unsigned int personID) {
    Person person = people[personID];
    people.erase(personID);

    //Updating Queries
    //Used Chat-GPT to find out how to iterate multimaps
    auto dobRange = dobIndex.equal_range(person.getDOB());
    for (auto it = dobRange.first; it != dobRange.second; ++it) {
        if (it->second == personID) {
            dobIndex.erase(it);
            break;
        }
    }
    
    auto nameRange = nameIndex.equal_range(person.getName());
    for (auto it = nameRange.first; it != nameRange.second; ++it) {
        if (it->second == personID) {
            releaseDateIndex.erase(it);
            break;
        }
    }
}

//Movie updating methods
void Database::updateMovieTitle(unsigned int movieID, const string& title) {
    auto range = titleIndex.equal_range(movies[movieID].getTitle());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == movieID) {
            titleIndex.erase(it);
            titleIndex.insert(make_pair(title, movieID));
            break;
        }
    }
    movies[movieID].setTitle(title);
}
void Database::updateMovieDate(unsigned int movieID, const string& date) {
    auto range = releaseDateIndex.equal_range(movies[movieID].getReleaseDate());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == movieID) {
            releaseDateIndex.erase(it);
            releaseDateIndex.insert(make_pair(date, movieID));
            break;
        }
    }
    movies[movieID].setReleaseDate(date);
}
void Database::updateMovieRating(unsigned int movieID, double rating) {
    auto range = ratingIndex.equal_range(movies[movieID].getRating());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == movieID) {
            ratingIndex.erase(it);
            ratingIndex.insert(make_pair(rating, movieID));
            break;
        }
    }
    movies[movieID].setRating(rating);
}

//Person updating methods
void Database::updatePersonName(unsigned int personID, const string& name) {
    auto range = nameIndex.equal_range(people[personID].getName());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == personID) {
            nameIndex.erase(it);
            nameIndex.insert(make_pair(name, personID));
            break;
        }
    }
    people[personID].setName(name);
}
void Database::updatePersonDOB(unsigned int personID, const string& dob) {
    auto range = dobIndex.equal_range(people[personID].getDOB());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == personID) {
            dobIndex.erase(it);
            dobIndex.insert(make_pair(dob, personID));
            break;
        }
    }
    people[personID].setDOB(dob);
}

//Query Functions
void Database::buildMovieQueries() {
    for (auto& [id, movie] : movies) {
        titleIndex.insert(make_pair(movie.getTitle(), id));
        ratingIndex.insert(make_pair(movie.getRating(), id));
        releaseDateIndex.insert(make_pair(movie.getReleaseDate(), id));
        vector<string> genres = movie.getGenre();
        for (string genre : genres) {
            genreIndex.insert(make_pair(genre, id));
        }
    }
}

void Database::buildPersonQueries() {
    for (auto& [id, person] : people) {
        nameIndex.insert(make_pair(person.getName(), id));
        dobIndex.insert(make_pair(person.getDOB(), id));
    }
}