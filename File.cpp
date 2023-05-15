#include "File.h"

void File::saveDatabase(const string& movieFile, const string& personFile, 
	const string& castFile, const string& starredInFile, Database& db) {
	db.storeMovies(movieFile);
	db.storePeople(personFile);
	db.storeMoviesToPeople(castFile);
	db.storePeopleToMovies(starredInFile);
}



void File::loadDatabase(const std::string& movieFile, const string& personFile, 
	const string& castFile, const string& starredInFile, Database& db) {
	db.loadMovies(movieFile);
	db.loadPeople(personFile);
	db.loadMoviesToPeople(castFile);
	db.loadPeopleToMovies(starredInFile);
}
