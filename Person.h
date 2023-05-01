#include<string>
#include<vector>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
    public:
        Person();
        Person(string name, string DOB, vector<string> moviesStarredIn, vector<string> moviesDirected);

        string getName();
        string getDOB();
        vector<string> getMovesStarred();
        vector<string> getMoviesDirected();

        void setID(int id);
        void setName(string name);
        void setDOB (string date);
        
        void addMovieStarred(string title);
        void addMovieDirected(string title);

        void removeMovieStarred(string title);
        void removeMovieDirected(string title);

    private:
        int personID;
        string name;
        string DOB;
        vector<string> moviesStarredIn;
        vector<string> moviesDirected;
};

#endif