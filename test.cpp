#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"
#include "Database.h"
#include <utility>
#include "json.h"



using json = nlohmann::json;
using namespace std;

// Test suite for the Database class
class DatabaseTest : public ::testing::Test {
protected:
    // Set up the test fixture before each test
    void SetUp() override {
        // Create a new Database object
        database = new Database();
    }

    // Tear down the test fixture after each test
    void TearDown() override {
        // Delete the Database object
        delete database;
    }

    // The Database object under test
    Database* database;
};
// Test that the loadMovies() function loads the movies from the specified file

TEST_F(DatabaseTest, loadMovies) {
    // Create a test file with some movies
    ofstream file("test_movies.json");
    file << R"(
[
  {
    "id": 1,
    "title": "The Shawshank Redemption",
    "year": "1994",
    "director": "Frank Darabont",
    "genre": ["Drama"]
  },
  {
    "id": 2,
    "title": "The Godfather",
    "year": "1972",
    "director": "Francis Ford Coppola",
    "genre": ["Crime", "Drama"]
  },
  {
    "id": 3,
    "title": "The Dark Knight",
    "year": "2008",
    "director": "Christopher Nolan",
    "genre": ["Action", "Crime", "Drama"]
  }
]
)";
    file.close();

    // Load the movies from the test file
    std::string movieFile = "test_movies.json";
    database->loadMovies(movieFile);

    // Check that the movies were loaded correctly
    EXPECT_EQ(database->getMovies().size(), 3);
    EXPECT_EQ(database->getMovieByID(1).getTitle(), "The Shawshank Redemption");
    EXPECT_EQ(database->getMovieByID(2).getTitle(), "The Godfather");
    EXPECT_EQ(database->getMovieByID(3).getTitle(), "The Dark Knight");

    // Check that the movies were loaded into the database correctly
    auto movie1 = database->getMovieByID(1);
    EXPECT_EQ(movie1.getID(), 1);
    EXPECT_EQ(movie1.getTitle(), "The Shawshank Redemption");
    EXPECT_EQ(movie1.getYear(), "1994");
    EXPECT_EQ(movie1.getDirector(), "Frank Darabont");
    vector<string> expectedGenres1 = { "Drama" };
    EXPECT_EQ(movie1.getGenre(), expectedGenres1);
   
    auto movie2 = database->getMovieByID(2);
    EXPECT_EQ(movie2.getID(), 2);
    EXPECT_EQ(movie2.getTitle(), "The Godfather");
    EXPECT_EQ(movie2.getYear(), "1972");
    EXPECT_EQ(movie2.getDirector(), "Francis Ford Coppola");
    vector<string> expectedGenres2 = { "Crime", "Drama" };
    EXPECT_EQ(movie2.getGenre(), expectedGenres2);

    auto movie3 = database->getMovieByID(3);
    EXPECT_EQ(movie3.getID(), 3);
    EXPECT_EQ(movie3.getTitle(), "The Dark Knight");
    EXPECT_EQ(movie3.getYear(), "2008");
    EXPECT_EQ(movie3.getDirector(), "Christopher Nolan");
    vector<string> expectedGenres3 = { "Action", "Crime", "Drama" };
    EXPECT_EQ(movie3.getGenre(), expectedGenres3);

}


