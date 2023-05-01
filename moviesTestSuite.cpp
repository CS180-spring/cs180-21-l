#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"
// Tests
TEST(MovieTest, getTitle) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Andy Dufresne"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getTitle(), "The Shawshank Redemption");
}

TEST(MovieTest, getActors) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Andy Dufresne"}, "Drank Darabont", "1994", "Crime drama", 1);
    std::vector<std::string> expectedActors = {"Tim Robbins", "Andy Dufresne"};
    EXPECT_EQ(m.getActors(), expectedActors);
}

TEST(MovieTest, getDirector) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Andy Dufresne"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getDirector(), "Drank Darabont");
}

TEST(MovieTest, getReleaseDate) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Andy Dufresne"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getReleaseDate(), "1994");
}

TEST(MovieTest, getGenre) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Andy Dufresne"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getGenre(), "Crime drama");
}

TEST(MovieTest, getID) {
    Movie m("The Shawshank Redemption", {"Tim Robbins", "Andy Dufresne"}, "Drank Darabont", "1994", "Crime drama", 1);
    EXPECT_EQ(m.getID(), 1);
}


