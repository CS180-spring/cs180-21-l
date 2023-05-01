#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;

using json = nlohmann::json;


void add_movie_to_database(const std::string& filename)
{
    json movie;

    std::cout << "Enter movie ID: ";
    int id;
    std::cin >> id;
    movie["ID"] = id;

    std::cout << "Enter movie title: ";
    std::string title;
    std::cin.ignore(); 
    std::getline(std::cin, title);
    movie["Title"] = title;

    std::cout << "Enter movie year: ";
    int year;
    std::cin >> year;
    movie["Year"] = year;

    std::cout << "Enter movie genres (comma-separated): ";
    std::string genres_input;
    std::cin.ignore(); 
    std::getline(std::cin, genres_input);
    std::vector<std::string> genres;
    std::stringstream genres_stream(genres_input);
    std::string genre;
    while (std::getline(genres_stream, genre, ',')) {
        genres.push_back(genre);
    }
    movie["Genre"] = genres;

    std::cout << "Enter movie director: ";
    std::string director;
    std::getline(std::cin, director);
    movie["Director"] = director;

    std::cout << "Enter movie actors (comma-separated): ";
    std::string actors_input;
    std::getline(std::cin, actors_input);
    std::vector<json> actors;
    std::stringstream actors_stream(actors_input);
    std::string actor;
    while (getline(actors_stream, actor, ',')) {
        std::string character;
        std::cout << "Enter character played by " << actor << ": ";
        std::getline(std::cin, character);
        actors.push_back({{"name", actor}, {"character", character}});
    }
    movie["Actors"] = actors;

    // Open database file and add movie to it
    std::ifstream input_file("Movies.json");
    json database;
    input_file >> database;

    database.push_back(movie);

    std::ofstream output_file(filename);
    output_file << std::setw(4) << database << std::endl;
}