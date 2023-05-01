#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"
// Tests
TEST(MovieTest, getTitle) {
    Movie m("The Godfather", {"Marlon Brando", "Al Pacino"}, "Francis Ford Coppola", "1972", "Crime drama", 1);
    EXPECT_EQ(m.getTitle(), "The Godfather");
}

TEST(MovieTest, getActors) {
    Movie m("The Godfather", {"Marlon Brando", "Al Pacino"}, "Francis Ford Coppola", "1972", "Crime drama", 1);
    std::vector<std::string> expectedActors = {"Marlon Brando", "Al Pacino"};
    EXPECT_EQ(m.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m("The Godfather", {"Marlon Brando", "Al Pacino"}, "Francis Ford Coppola", "1972", "Crime drama", 1);
    EXPECT_EQ(m.getDirector(), "Francis Ford Coppola");
}

TEST(MovieTest, getReleaseDate) {
    Movie m("The Godfather", {"Marlon Brando", "Al Pacino"}, "Francis Ford Coppola", "1972", "Crime drama", 1);
    EXPECT_EQ(m.getReleaseDate(), "1972");
}

TEST(MovieTest, getGenre) {
    Movie m("The Godfather", {"Marlon Brando", "Al Pacino"}, "Francis Ford Coppola", "1972", "Crime drama", 1);
    EXPECT_EQ(m.getGenre(), "Crime drama");
}

TEST(MovieTest, getID) {
    Movie m("The Godfather", {"Marlon Brando", "Al Pacino"}, "Francis Ford Coppola", "1972", "Crime drama", 1);
    EXPECT_EQ(m.getID(), 1);
}
