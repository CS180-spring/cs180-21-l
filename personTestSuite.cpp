#include "pch.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../Person.h"


TEST(PersonTest, getDOB1) {
    Person p("Leonardo DiCaprio", "November 11, 1974", { "Titanic", "The Wolf of Wall Street", "The Great Gatsby", "Django Unchained" }, { "The Wolf of Wall Street", "Delirium", "Red Riding Hood" });
    EXPECT_EQ(p.getDOB(), "November 11, 1974");

}


TEST(PersonTest, getMoviesStarred1) {
    Person p("Leonardo DiCaprio", "November 11, 1974", { "Titanic", "The Wolf of Wall Street", "The Great Gatsby", "Django Unchained" }, { "The Wolf of Wall Street", "Delirium", "Red Riding Hood" });
    vector<string> expectedMoviesStarred = { "Titanic", "The Wolf of Wall Street", "The Great Gatsby", "Django Unchained" };
    EXPECT_EQ(p.getMoviesStarred(), expectedMoviesStarred);

}

TEST(PersonTest, getMoviesDirected1) {
    Person p("Leonardo DiCaprio", "November 11, 1974", { "Titanic", "The Wolf of Wall Street", "The Great Gatsby", "Django Unchained" }, { "The Wolf of Wall Street", "Delirium", "Red Riding Hood" });
    vector<string> expectedMoviesDirected = { "The Wolf of Wall Street", "Delirium", "Red Riding Hood" };
    EXPECT_EQ(p.getMoviesDirected(), expectedMoviesDirected);

}
//---------------------------------------------------------------------------------------------------------------------------

TEST(PersonTest, getName2) {
    Person p("Keanu Reeves", "September 2, 1964", { "Toy Story 4", "John Wick", "The Matrix", "John Wick: Chapter 2", "John Wick: Chapter 3 - Parabellum", "John Wick: Chapter 4" }, { "Man of Tai Chi" });
    EXPECT_EQ(p.getName(), "Keanu Reeves");

}

TEST(PersonTest, getDOB2) {
    Person p("Keanu Reeves", "September 2, 1964", { "Toy Story 4", "John Wick", "The Matrix", "John Wick: Chapter 2", "John Wick: Chapter 3 - Parabellum", "John Wick: Chapter 4" }, { "Man of Tai Chi" });
    EXPECT_EQ(p.getDOB(), "September 2, 1964");

}

TEST(PersonTest, getmoviesStarred2) {
    Person p("Keanu Reeves", "September 2, 1964", { "Toy Story 4", "John Wick", "The Matrix", "John Wick: Chapter 2", "John Wick: Chapter 3 - Parabellum", "John Wick: Chapter 4" }, { "Man of Tai Chi" });
    vector<string> expectedMoviesStarred = { "Toy Story 4", "John Wick", "The Matrix", "John Wick: Chapter 2", "John Wick: Chapter 3 - Parabellum", "John Wick: Chapter 4" };
    EXPECT_EQ(p.getMoviesStarred(), expectedMoviesStarred);

}

TEST(PersonTest, getmoviesDirected2) {
    Person p("Keanu Reeves", "September 2, 1964", { "Toy Story 4", "John Wick", "The Matrix", "John Wick: Chapter 2", "John Wick: Chapter 3 - Parabellum", "John Wick: Chapter 4" }, { "Man of Tai Chi" });
    vector<string> expectedMoviesDirected = { "Man of Tai Chi" };
    EXPECT_EQ(p.getMoviesDirected(), expectedMoviesDirected);

}






































