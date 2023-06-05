#include "File.h"

void File::saveDatabase(string movieFile,string personFile, 
	const string& castFile, const string& starredInFile, Database& db) {
	db.storeMovies(movieFile);
	db.storePeople(personFile);
	db.storeMoviesToPeople(castFile);
	db.storePeopleToMovies(starredInFile);
}



void File::loadDatabase(std::string movieFile,string personFile, 
	const string& castFile, const string& starredInFile, Database& db) {
	db.loadMovies(movieFile);
	db.loadPeople(personFile);
	db.loadMoviesToPeople(castFile);
	db.loadPeopleToMovies(starredInFile);
}
