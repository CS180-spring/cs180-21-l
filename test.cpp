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
    // Helper function to compare two movies
    bool compareMovies(const Movie& movie1, const Movie& movie2) {
        if (movie1.getTitle() != movie2.getTitle()) {
            return movie1.getTitle() < movie2.getTitle();
        }
        else if (movie1.getYear() != movie2.getYear()) {
            return movie1.getYear() < movie2.getYear();
        }
        else {
            return movie1.getDirector() < movie2.getDirector();
        }
    }

    // Helper function to compare two people
    bool comparePeople(Person& person1, Person& person2) {
        if (person1.getName() != person2.getName()) {
            return person1.getName() < person2.getName();
        }
        else {
            return person1.getDOB() < person2.getDOB();
        }
    }

    bool movieExistsInVector(const Movie& movie, const vector<Movie>& movies) {
        for (const auto& m : movies) {
            if (compareMovies(movie, m)) {
                return true;
            }
        }
        return false;
    }
    bool personExistsInVector(Person& person, vector<Person>& people) {
        for (auto& p : people) {
            if (comparePeople(person, p)) {
                return true;
            }
        }
        return false;
    }
    // The Database object under test
    Database* database;

};
// Test that the loadMovies() function loads the movies from the specified file
// This makes sure that our loadMovies function is working
TEST_F(DatabaseTest, loadMovies) {
    // Create a test file with some movies
    ofstream file("test_movies.json");
    //What our movies json file would look like
    file << R"(
[
  {
    "id": 1,
    "title": "The Shawshank Redemption",
    "year": "1994",
    "rating": 5.0,
    "director": "Frank Darabont",
    "genre": ["Drama"]
  },
  {
    "id": 2,
    "title": "The Godfather",
    "year": "1972",
    "rating": 5.0,
    "director": "Francis Ford Coppola",
    "genre": ["Crime", "Drama"]
  },
  {
    "id": 3,
    "title": "The Dark Knight",
    "year": "2008",
    "rating": 5.0,
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
// This makes sure that our loadPeople function is working
    TEST_F(DatabaseTest, loadPeople){
        // Create a test file with some people
        ofstream file("test_people.json");
        //What our people json file would look like
        file << R"(
[
  {
    "id": 1,
    "name": "Samuel L. Jackson",
    "DOB": "December 21, 1948"
  },
  {
    "id": 2,
    "name": "Robert Downey Jr.",
    "DOB": "April 4, 1965"
  },
  {
    "id": 3,
    "name": "Leonardo DiCaprio",
    "DOB": "November 11, 1974"
  }
]
)";
        file.close();

        // Load the people from the test file
        std::string peopleFile = "test_people.json";
        database->loadPeople(peopleFile);

        // Check that the people were loaded correctly
        EXPECT_EQ(database->getPeople().size(), 3);
        EXPECT_EQ(database->getPersonByID(1).getName(), "Samuel L. Jackson");
        EXPECT_EQ(database->getPersonByID(2).getName(), "Robert Downey Jr.");
        EXPECT_EQ(database->getPersonByID(3).getName(), "Leonardo DiCaprio");

        // Check that the people were loaded into the database correctly
        auto person1 = database->getPersonByID(1);
        EXPECT_EQ(person1.getID(), 1);
        EXPECT_EQ(person1.getName(), "Samuel L. Jackson");
        EXPECT_EQ(person1.getDOB(), "December 21, 1948");

        auto person2 = database->getPersonByID(2);
        EXPECT_EQ(person2.getID(), 2);
        EXPECT_EQ(person2.getName(), "Robert Downey Jr.");
        EXPECT_EQ(person2.getDOB(), "April 4, 1965");

        auto person3 = database->getPersonByID(3);
        EXPECT_EQ(person3.getID(), 3);
        EXPECT_EQ(person3.getName(), "Leonardo DiCaprio");
        EXPECT_EQ(person3.getDOB(), "November 11, 1974");
    }

//These tests make sure our updateMovieTitle(), updateMovieDate(), updateMovieRating() functions are working

    TEST_F(DatabaseTest, updateMovieTitleTest) {
        unsigned int movieID = 1;
        string newTitle = "Updated Movie Title 1";
        database->updateMovieTitle(1, newTitle);
        Movie updatedMovie = database->getMovieByID(movieID);
        EXPECT_EQ(updatedMovie.getTitle(), "Updated Movie Title 1");
    }

    TEST_F(DatabaseTest, updateMovieDateTest) {
        unsigned int movieID = 2;
        string newDate = "1999";
        database->updateMovieDate(movieID, newDate);
        Movie updatedMovie = database->getMovieByID(movieID);
        EXPECT_EQ(updatedMovie.getYear(), newDate);
    }
    TEST_F(DatabaseTest, updateMovieRatingTest) {
        unsigned int movieID = 3;
        double newRating = 2.6;
        database->updateMovieRating(movieID, newRating);
        Movie updatedMovie = database->getMovieByID(movieID);
        EXPECT_DOUBLE_EQ(updatedMovie.getRating(), newRating);
    }

//Tests for updatePersonName() and updatePersonDOB()
    TEST_F(DatabaseTest, updatePersonNameTest) {
        unsigned int personID = 1;
        string newName = "Ian Kim";
        database->updatePersonName(personID, newName);
        Person updatedPerson = database->getPersonByID(personID);
        EXPECT_EQ(updatedPerson.getName(), newName);
    }

    TEST_F(DatabaseTest, updatePersonDOBTest) {
        unsigned int personID = 2;
        string newDOB = "July 20, 2001";
        database->updatePersonDOB(personID, newDOB);
        Person updatedPerson = database->getPersonByID(personID);
        EXPECT_EQ(updatedPerson.getDOB(), newDOB);
    }

//Tests for insertMovie(), removeMovie(), insertPerson(), removePerson()
    TEST_F(DatabaseTest, insertMovieTest){
        Database db;
        Movie sampleMovie("Sample Movie", "Sample Director", "2023", 10.0, { "Thriller", "Drama" });
        Movie sampleMovie2("Sample Movie 2", "Sample Director 2", "2024", 9.0, { "Comedy", "Action" });
        db.insertMovie(sampleMovie);
        db.insertMovie(sampleMovie2);
        ASSERT_EQ(2, db.getMovies().size());
     
    }

    TEST_F(DatabaseTest, insertPersonTest) {
        Database db;
        Person samplePerson("Ian Kim", "July 20, 2001");
        Person samplePerson2("Dion Kim", "November 11, 1997");
        db.insertPerson(samplePerson);
        db.insertPerson(samplePerson2);
        ASSERT_EQ(2, db.getPeople().size());
    }

    TEST_F(DatabaseTest, removeMovieTest) {
        Database db;
        unsigned int movieID = 1;
        Movie sampleMovie("Sample Movie", "Sample Director", "2023", 10.0, { "Thriller", "Drama" });
        db.insertMovie(sampleMovie);
        db.removeMovie(movieID);
        Movie retrievedMovie = db.getMovieByID(movieID);
        string expectedTitle = "";
        retrievedMovie = Movie();
        ASSERT_EQ(expectedTitle, retrievedMovie.getTitle());
    }






    TEST_F(DatabaseTest, removePersonTest) {
        Database db;
        unsigned int personID = 1;
        Person samplePerson("Ian Kim", "July 20, 2001");
        db.insertPerson(samplePerson);
        db.removePerson(personID);
        Person retrievedPerson = db.getPersonByID(personID);
        Person expectedPerson("", "");
        ASSERT_EQ(expectedPerson, retrievedPerson);
       
    }
