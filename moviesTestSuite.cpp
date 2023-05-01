#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"
// Tests
TEST(MovieTest, getTitle) {
    //       string title, string<vector> actors, string director, string releaseDate, string<vector> genres, int id
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", {"Drama, Crime"}, 1);
    EXPECT_EQ(m.getTitle(), "The Shawshank Redemption");
}

TEST(MovieTest, getActors) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", {"Drama, Crime"}, 1);
    std::vector<std::string> expectedActors = {"Tim Robbins", "Morgan Freeman", "Bob Gunton"};
    EXPECT_EQ(m.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", {"Drama, Crime"}, 1);
    EXPECT_EQ(m.getDirector(), "Drank Darabont");
}

TEST(MovieTest, getReleaseDate) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", {"Drama, Crime"}, 1);
    EXPECT_EQ(m.getReleaseDate(), "1994");
}

TEST(MovieTest, getGenre) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", {"Drama, Crime"}, 1);
    EXPECT_EQ(m.getGenre(), {"Drama, Crime"});
}

TEST(MovieTest, getID) {
    Movie m2("The Shawshank Redemption", {"Tim Robbins", "Morgan Freeman", "Bob Gunton"}, "Drank Darabont", "1994", {"Drama, Crime"}, 1);
    EXPECT_EQ(m.getID(), 1);
}
//---------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", {"Science Fiction", "Action", "Adventure"}, 2);
    EXPECT_EQ(m2.getTitle(), "Star Wars: A New Hope");
}

TEST(MovieTest, getActors) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", {"Science Fiction", "Action", "Adventure"}, 2);
    std::vector<std::string> expectedActors = {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"};
    EXPECT_EQ(m2.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", {"Science Fiction", "Action", "Adventure"}, 2);
    EXPECT_EQ(m2.getDirector(), "George Lucas");
}

TEST(MovieTest, getReleaseDate) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", {"Science Fiction", "Action", "Adventure"}, 2);
    EXPECT_EQ(m2.getReleaseDate(), "1977");
}

TEST(MovieTest, getGenre) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", {"Science Fiction", "Action", "Adventure"}, 2);
    EXPECT_EQ(m2.getGenre(), {"Science Fiction", "Action", "Adventure"});
}

TEST(MovieTest, getID) {
    Movie m2("Star Wars: A New Hope", {"Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness"}, "George Lucas", "1977", {"Science Fiction", "Action", "Adventure"}, 2);
    EXPECT_EQ(m2.getID(), 2);
}
//----------------------------------------------------------------------------------------------------------------------------
TEST(MovieTest, getTitle) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", {"Action", "Thriller"}, 3);
    EXPECT_EQ(m3.getTitle(), "John Wick");
}
TEST(MovieTest, getActors) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", {"Action", "Thriller"}, 3);
    std::vector<std::string> expectedActors = {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"};
    EXPECT_EQ(m3.getActors(), expectedActors);
}
TEST(MovieTest, getDirector) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", {"Action", "Thriller"}, 3);
    EXPECT_EQ(m3.getTitle(), "Chad Stahelski");
}
TEST(MovieTest, getReleaseDate) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", {"Action", "Thriller"}, 3);
    EXPECT_EQ(m3.getTitle(), "2014");
}
TEST(MovieTest, getGenre) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", {"Action", "Thriller"}, 3);
    EXPECT_EQ(m3.getGenre(), {"Action", "Thriller"});
}
TEST(MovieTest, getID) {
    Movie m3("John Wick", {"Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki"}, "Chad Stahelski", "2014", {"Action", "Thriller"}, 3);
    EXPECT_EQ(m3.getID(), 3);
}
//----------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"}, "Peter Jackson", "2001", {"Fantasy", "Thriller"}, 4);
    EXPECT_EQ(m4.getTitle(), "The Lord of the Rings: The Fellowship of the Ring");
}
TEST(MovieTest, getActors) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"}, "Peter Jackson", "2001", {"Fantasy", "Thriller"}, 4);
    std::vector<std::string> expectedActors = {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"};
    EXPECT_EQ(m4.getActors(), expectedActors);
}
TEST(MovieTest, getDirector) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"}, "Peter Jackson", "2001", {"Fantasy", "Thriller"}, 4);
    EXPECT_EQ(m4.getDirector(), "Peter Jackson");
}
TEST(MovieTest, getReleaseDate) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"}, "Peter Jackson", "2001", {"Fantasy", "Thriller"}, 4);
    EXPECT_EQ(m4.getReleaseDate(), "2001");
}
TEST(MovieTest, getGenre) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"}, "Peter Jackson", "2001", {"Fantasy", "Thriller"}, 4);
    EXPECT_EQ(m4.getGenre(), {"Fantasy", "Thriller"});
}
TEST(MovieTest, getID) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", {"Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin"}, "Peter Jackson", "2001", {"Fantasy", "Thriller"}, 4);
    EXPECT_EQ(m4.getID(), 4);
}
//----------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle) {
    Movie m5("The Hunger Games", {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"}, "Gary Ross", "2012", {"Science Fiction", "Adventure"}, 5);
    EXPECT_EQ(m5.getTitle(), "The Hunger Games");
}
TEST(MovieTest, getActors) {
    Movie m5("The Hunger Games", {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"}, "Gary Ross", "2012", {"Science Fiction", "Adventure"}, 5);
    std::vector<std::string> expectedActors = {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"};
    EXPECT_EQ(m4.getActors(), expectedActors);
}
TEST(MovieTest, getDirector) {
    Movie m5("The Hunger Games", {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"}, "Gary Ross", "2012", {"Science Fiction", "Adventure"}, 5);
    EXPECT_EQ(m5.getDirector(), "Gary Ross");
}
TEST(MovieTest, getReleaseDate) {
    Movie m5("The Hunger Games", {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"}, "Gary Ross", "2012", {"Science Fiction", "Adventure"}, 5);
    EXPECT_EQ(m5.getReleaseDate(), "2012");
}
TEST(MovieTest, getGenre) {
    Movie m5("The Hunger Games", {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"}, "Gary Ross", "2012", {"Science Fiction", "Adventure"}, 5);
    EXPECT_EQ(m5.getGenre(), {"Science Fiction", "Adventure"});
}
TEST(MovieTest, getID) {
    Movie m5("The Hunger Games", {"Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks"}, "Gary Ross", "2012", {"Science Fiction", "Adventure"}, 5);
    EXPECT_EQ(m5.getID(), 5);
}

