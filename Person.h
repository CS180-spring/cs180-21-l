#include<string>
#include<vector>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
    public:
        //Constructors
        Person();
        Person(string name, string DOB);
        Person(string name, string DOB, vector<unsigned int> moviesStarredIn, vector<unsigned int> moviesDirected);
        //Accessor methods
        unsigned int getID();
        string getName();
        string getDOB();
        vector<unsigned int> getMovesStarred();
        vector<unsigned int> getMoviesDirected();

        //Modifier methods
        void setID(unsigned int id);
        void setName(string name);
        void setDOB (string date);
        void addMovieStarred(unsigned int id);
        void addMovieDirected(unsigned int id);
        void removeMovieStarred(unsigned int id);
        void removeMovieDirected(unsigned int id);
    private:
        //Private variables
        vector<unsigned int> moviesStarredIn;
        vector<unsigned int> moviesDirected;
        unsigned int personID;
        string name;
        string DOB;
};

#endif