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
    private:
        //Private variables
        unsigned int personID;
        string name;
        string DOB;
};

#endif