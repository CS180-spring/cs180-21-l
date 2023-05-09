#include <iostream>
#include "File.h"

using namespace std;

int main() {
	Database myDb;
	File myFile;
	myFile.loadDatabase("Movies.json", "People.json", myDb);
	myFile.saveDatabase("Movies1.json", "People1.json", myDb);
}