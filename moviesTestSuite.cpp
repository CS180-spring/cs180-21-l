#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"
// Tests
TEST(MovieTest, getTitle) {
    //      Movie Title, Vector String of actor names in movie, Director name string, release date string, genre string, ID int
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getTitle(), "The Shawshank Redemption");
}

TEST(MovieTest, getActors) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", "Crime drama", 1);
    std::vector<std::string> expectedActors = {"Tim Robbins", "Morgan Freeman", "Bob Gunton"};
    EXPECT_EQ(m.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getDirector(), "Drank Darabont");
}

TEST(MovieTest, getReleaseDate) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getReleaseDate(), "1994");
}

TEST(MovieTest, getGenre) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getGenre(), "Crime drama");
}

TEST(MovieTest, getID) {
    Movie m2("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getID(), 1);
}
//---------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", "Science-Fiction", 2);
    EXPECT_EQ(m.getTitle(), "Star Wars: A New Hope");
}

TEST(MovieTest, getActors) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", "Science-Fiction", 2);
    std::vector<std::string> expectedActors = {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"};
    EXPECT_EQ(m.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", "Science-Fiction", 2);
    EXPECT_EQ(m.getDirector(), "George Lucas");
}

TEST(MovieTest, getReleaseDate) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", "Science-Fiction", 2);
    EXPECT_EQ(m.getReleaseDate(), "1977");
}

TEST(MovieTest, getGenre) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", "Science-Fiction", 2);
    EXPECT_EQ(m.getGenre(), "Science-Fiction");
}

TEST(MovieTest, getID) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", "Science-Fiction", 2);
    EXPECT_EQ(m.getID(), 2);
}
//----------------------------------------------------------------------------------------------------------------------------
TEST(MovieTest, getTitle) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", "Action", 3);
    EXPECT_EQ(m.getTitle(), "John Wick");
}
TEST(MovieTest, getActors) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", "Action", 3);
    std::vector<std::string> expectedActors = {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"};
    EXPECT_EQ(m.getActors(), expectedActors);
}
TEST(MovieTest, getDirector) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", "Action", 3);
    EXPECT_EQ(m.getTitle(), "Chad Stahelski");
}
TEST(MovieTest, getReleaseDate) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", "Action", 3);
    EXPECT_EQ(m.getTitle(), "2014");
}
TEST(MovieTest, getGenre) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", "Action", 3);
    EXPECT_EQ(m.getGenre(), "Action");
}
TEST(MovieTest, getID) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", "Action", 3);
    EXPECT_EQ(m.getID(), 3);
}
//----------------------------------------------------------------------------------------------------------------------------


