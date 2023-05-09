#ifndef FILE_H
#define FILE_H

#include <fstream>
#include "Database.h"

using namespace std;

//Per Nick, there will be 4 JSON files
//To be more Agile, we will only focus on 2 for now: Movies.JSON and People.JSON
//Get load and save done by the start of Monday's lab


class File {
public:
    void saveDatabase(const string& movieFile, const string& personFile, Database& db);


    void loadDatabase(const std::string& movieFile, const string& personFile, Database& db);

};

#endif