#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"


// Tests for Person
TEST(PersonTest, getFullName) {
    //(first name, last name, {movieActedIn1, movieActedIn2}, {movieDirected1}, age)
    Person p("Marlon", "Brando", {"The Godfather", "Apocalypse Now"}, {"One-Eyed Jacks"}, 80);
    EXPECT_EQ(p.getFullName(), "Marlon Brando");
}

TEST(PersonTest, getMoviesActedIn) {
    Person p("Marlon", "Brando", {"The Godfather", "Apocalypse Now"}, {"One-Eyed Jacks"}, 80);
    std::vector<std::string> expectedMoviesActedIn = {"The Godfather", "Apocalypse Now"};
    EXPECT_EQ(p.getMoviesActedIn(), expectedMoviesActedIn);
}

TEST(PersonTest, getCharactersPlayed) {
    Person p("Robert", "Downey Jr.", {"Iron Man", "The Avengers"}, {"None"}, 57);
    std::vector<std::string> expectedCharactersPlayed = {"Tony Stark"};
    EXPECT_EQ(p.getCharactersPlayed(), expectedCharactersPlayed);
}

TEST(PersonTest, getMoviesDirected) {
    Person p("Marlon", "Brando", {"The Godfather", "Apocalypse Now"}, {"One-Eyed Jacks"}, 80);
    std::vector<std::string> expectedMoviesDirected = {"One-Eyed Jacks"};
    EXPECT_EQ(p.getMoviesDirected(), expectedMoviesDirected);
}

TEST(PersonTest, getAge) {
    Person p("Marlon", "Brando", {"The Godfather", "Apocalypse Now"}, {"One-Eyed Jacks"}, 80);
    EXPECT_EQ(p.getAge(), "80");
}
