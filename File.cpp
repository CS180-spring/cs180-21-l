#include "File.h"

void File::saveDatabase(const string& movieFile, const string& personFile, Database& db) {
	db.storeMovies(movieFile);
	db.storePeople(personFile);
}



void File::loadDatabase(const std::string& movieFile, const string& personFile, Database& db) {
	db.loadMovies(movieFile);
	db.loadPeople(personFile);
}
