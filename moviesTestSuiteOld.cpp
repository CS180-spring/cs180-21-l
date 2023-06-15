#include "pch.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"
// Tests
    //       string title, string<vector> actors, string director, string releaseDate, string<vector> genres, int id
TEST(MovieTest, getTitle) {
    Movie m("The Shawshank Redemption", "Drank Darabont", { "Tim Robbins", "Morgan Freeman", "Bob Gunton" }, "1994", {"Drama", "Crime"}, 1);
    EXPECT_EQ(m.getTitle(), "The Shawshank Redemption");
}

TEST(MovieTest, getActors) {
    Movie m("The Shawshank Redemption", "Drank Darabont", { "Tim Robbins", "Morgan Freeman", "Bob Gunton" }, "1994", { "Drama", "Crime" }, 1);
    vector<string> expectedActors = { "Tim Robbins", "Morgan Freeman", "Bob Gunton" };
    EXPECT_EQ(m.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m("The Shawshank Redemption", "Drank Darabont", { "Tim Robbins", "Morgan Freeman", "Bob Gunton" }, "1994", { "Drama", "Crime" }, 1);
    EXPECT_EQ(m.getDirector(), "Drank Darabont");
}

TEST(MovieTest, getReleaseDate) {
    Movie m("The Shawshank Redemption", "Drank Darabont", { "Tim Robbins", "Morgan Freeman", "Bob Gunton" }, "1994", { "Drama", "Crime" }, 1);
    EXPECT_EQ(m.getReleaseDate(), "1994");
}

TEST(MovieTest, getGenre) {
    Movie m("The Shawshank Redemption", "Drank Darabont", { "Tim Robbins", "Morgan Freeman", "Bob Gunton" }, "1994", {"Drama", "Crime"}, 1);
    vector<string> expectedGenre = {"Drama", "Crime"};
    EXPECT_EQ(m.getGenre(), expectedGenre);
}

TEST(MovieTest, getID) {
    Movie m2("The Shawshank Redemption", "Drank Darabont", { "Tim Robbins", "Morgan Freeman", "Bob Gunton" }, "1994", { "Drama", "Crime" }, 1);
    EXPECT_EQ(m2.getID(), 1);
}
//---------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle2) {
    Movie m2("Star Wars: A New Hope", "George Lucas", { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" }, "1977", { "Science Fiction", "Action", "Adventure" }, 2);
    EXPECT_EQ(m2.getTitle(), "Star Wars: A New Hope");
}

TEST(MovieTest, getActors2) {
    Movie m2("Star Wars: A New Hope", "George Lucas", { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" }, "1977", { "Science Fiction", "Action", "Adventure" }, 2);
    vector<string> expectedActors = { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" };
    EXPECT_EQ(m2.getActors(), expectedActors);
}

TEST(MovieTest, getDirector2) {
    Movie m2("Star Wars: A New Hope", "George Lucas", { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" }, "1977", { "Science Fiction", "Action", "Adventure" }, 2);    
    EXPECT_EQ(m2.getDirector(), "George Lucas");
}

TEST(MovieTest, getReleaseDate2) {
    Movie m2("Star Wars: A New Hope", "George Lucas", { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" }, "1977", { "Science Fiction", "Action", "Adventure" }, 2);    
    EXPECT_EQ(m2.getReleaseDate(), "1977");
}

TEST(MovieTest, getGenre2) {
    Movie m2("Star Wars: A New Hope", "George Lucas", { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" }, "1977", { "Science Fiction", "Action", "Adventure" }, 2);   
    vector<string> expectedGenre = { "Science Fiction", "Action", "Adventure" };
    EXPECT_EQ(m2.getGenre(), expectedGenre);
}

TEST(MovieTest, getID2) {
    Movie m2("Star Wars: A New Hope", "George Lucas", { "Mark Hamill", "Harrison Ford", "Carrie Fisher", "Peter Cushing", "Alec Guinness" }, "1977", { "Science Fiction", "Action", "Adventure" }, 2);   
    EXPECT_EQ(m2.getID(), 2);
}
//----------------------------------------------------------------------------------------------------------------------------
TEST(MovieTest, getTitle3) {
    Movie m3("John Wick", "Chad Stahelski", { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" }, "2014", { "Action", "Thriller" }, 3);
    EXPECT_EQ(m3.getTitle(), "John Wick");
}
TEST(MovieTest, getActors3) {
    Movie m3("John Wick", "Chad Stahelski", { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" }, "2014", { "Action", "Thriller" }, 3);    
    vector<string> expectedActors = { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" };
    EXPECT_EQ(m3.getActors(), expectedActors);
}
TEST(MovieTest, getDirector3) {
    Movie m3("John Wick", "Chad Stahelski", { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" }, "2014", { "Action", "Thriller" }, 3);   
    EXPECT_EQ(m3.getDirector(), "Chad Stahelski");
}
TEST(MovieTest, getReleaseDate3) {
    Movie m3("John Wick", "Chad Stahelski", { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" }, "2014", { "Action", "Thriller" }, 3);   
    EXPECT_EQ(m3.getReleaseDate(), "2014");
}
TEST(MovieTest, getGenre3) {
    Movie m3("John Wick", "Chad Stahelski", { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" }, "2014", { "Action", "Thriller" }, 3);   
    vector<string> expectedGenre = { "Action", "Thriller" };
    EXPECT_EQ(m3.getGenre(), expectedGenre);
}
TEST(MovieTest, getID3) {
    Movie m3("John Wick", "Chad Stahelski", { "Keanu Reeves", "Michael Nyqvist", "Alfie Allen", "Willem Dafoe", "Adrianne Palicki" }, "2014", { "Action", "Thriller" }, 3);  
    EXPECT_EQ(m3.getID(), 3);
}
//----------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle4) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" }, "2001", { "Fantasy", "Thriller" }, 4);
    EXPECT_EQ(m4.getTitle(), "The Lord of the Rings: The Fellowship of the Ring");
}
TEST(MovieTest, getActors4) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" }, "2001", { "Fantasy", "Thriller" }, 4);
    vector<string> expectedActors = { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" };
    EXPECT_EQ(m4.getActors(), expectedActors);
}
TEST(MovieTest, getDirector4) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" }, "2001", { "Fantasy", "Thriller" }, 4);
    EXPECT_EQ(m4.getDirector(), "Peter Jackson");
}
TEST(MovieTest, getReleaseDate4) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" }, "2001", { "Fantasy", "Thriller" }, 4);
    EXPECT_EQ(m4.getReleaseDate(), "2001");
}
TEST(MovieTest, getGenre4) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" }, "2001", { "Fantasy", "Thriller" }, 4);
    vector<string> expectedGenre = { "Fantasy", "Thriller" };
    EXPECT_EQ(m4.getGenre(), expectedGenre);
}
TEST(MovieTest, getID4) {
    Movie m4("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", { "Elijah Wood", "Ian McKellen", "Viggo Mortensen", "Orlando Bloom", "Sean Astin" }, "2001", { "Fantasy", "Thriller" }, 4);
    EXPECT_EQ(m4.getID(), 4);
}
//----------------------------------------------------------------------------------------------------------------------------

TEST(MovieTest, getTitle5) {
    Movie m5("The Hunger Games", "Gary Ross", { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" }, "2012", { "Science Fiction", "Adventure" }, 5);
    EXPECT_EQ(m5.getTitle(), "The Hunger Games");
}
TEST(MovieTest, getActors5) {
    Movie m5("The Hunger Games", "Gary Ross", { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" }, "2012", { "Science Fiction", "Adventure" }, 5);
    vector<string> expectedActors = { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" };
    EXPECT_EQ(m5.getActors(), expectedActors);
}
TEST(MovieTest, getDirector5) {
    Movie m5("The Hunger Games", "Gary Ross", { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" }, "2012", { "Science Fiction", "Adventure" }, 5);
    EXPECT_EQ(m5.getDirector(), "Gary Ross");
}
TEST(MovieTest, getReleaseDate5) {
    Movie m5("The Hunger Games", "Gary Ross", { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" }, "2012", { "Science Fiction", "Adventure" }, 5);
    EXPECT_EQ(m5.getReleaseDate(), "2012");
}
TEST(MovieTest, getGenre5) {
    Movie m5("The Hunger Games", "Gary Ross", { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" }, "2012", { "Science Fiction", "Adventure" }, 5);
    vector<string> expectedGenre = { "Science Fiction", "Adventure" };
    EXPECT_EQ(m5.getGenre(), expectedGenre);
}
TEST(MovieTest, getID5) {
    Movie m5("The Hunger Games", "Gary Ross", { "Jennifer Lawrence", "Josh Hutcherson", "Liam Hemsworth", "Woody Harrelson", "Elizabeth Banks" }, "2012", { "Science Fiction", "Adventure" }, 5);
    EXPECT_EQ(m5.getID(), 5);
}


