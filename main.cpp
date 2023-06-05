#include <iostream>
#include <sstream>
#include "File.h"
// Still need all other functions header files and cpp 

using namespace std;

int main() {
    Database myDb;
    File myFile;
    myFile.loadDatabase("Movies.json", "People.json", "ActorFilms.json", "MovieCast.json", myDb);

    int mainChoice = 0;
    int userChoice = 0;

    // Menu option for users
    cout << "Welcome to Team L's Movie Rating Database!" << endl;
    cout << "How can I help you?" << endl;
    cout << "------------------------------------" << endl;
    cout << "1. Perform CRUD operations for the database." << endl;
    cout << "2. Quit" << endl;
    cin >> mainChoice;
    if (mainChoice == 2) {
        return 0;
    }
    else {
        bool shouldContinue = true;  // Control variable to determine when to return to the main menu

        while (shouldContinue) {
            cout << "What would you like to do?" << endl;
            cout << "--------------------------------" << endl;
            cout << "1. Add a movie to the database." << endl;
            cout << "2. Add a person to the database" << endl;
            cout << "3. Delete a movie in the database." << endl;
            cout << "4. Delete a person in the database." << endl;
            cout << "5. Update a movie title." << endl;
            cout << "6. Update a movie date." << endl;
            cout << "7. Update a movie rating." << endl;
            cout << "8. Update a person's name." << endl;
            cout << "9. Update a person's DOB." << endl;
            cout << "10. Quit." << endl;
            cout << "--------------------------------" << endl;
            cout << "Enter your choice: ";
            cin >> userChoice;
            cin.ignore(); // Ignore the newline character

            switch (userChoice) {
            case 1: {
                string title, director, year;
                double rating;
                vector<string> genre;

                // Prompt the user for movie details
                cout << "Enter movie details:" << endl;
                cout << "Title: ";
                getline(cin, title);
                cout << "Director: ";
                getline(cin, director);
                cout << "Year: ";
                getline(cin, year);
                cout << "Rating: ";
                cin >> rating;
                cin.ignore(); // Ignore the newline character
                cout << "Genres (separated by commas): ";
                string genreInput;
                getline(cin, genreInput);
                stringstream ss(genreInput);
                string genreToken;
                while (getline(ss, genreToken, ',')) {
                    genre.push_back(genreToken);
                }

                // Create a Movie object and add it to the database
                Movie movie(title, director, year, rating, genre);
                myDb.insertMovie(movie);
                break;
            }
            case 2: {
                string name, dob;

                // Prompt the user for person details
                cout << "Enter person details:" << endl;
                cout << "Name: ";
                getline(cin, name);
                cout << "Date of Birth: ";
                getline(cin, dob);

                // Create a Person object and add it to the database
                vector<unsigned int> moviesStarredIn;
                vector<unsigned int> moviesDirected;
                Person person(name, dob, moviesStarredIn, moviesDirected);
                myDb.insertPerson(person);
                break;
            }
            case 3: {
                unsigned int movieID;

                // Prompt the user for the movie ID to delete
                cout << "Enter the ID of the movie to delete: ";
                cin >> movieID;

                // Remove the movie from the database
                myDb.removeMovie(movieID);
                break;
            }
            case 4: {
                unsigned int personID;

                // Prompt the user for the person ID to delete
                cout << "Enter the ID of the person to delete: ";
                cin >> personID;

                // Remove the person from the database
                myDb.removePerson(personID);
                break;
            }
            case 5: {
                unsigned int movieID;
                string newTitle;

                // Prompt the user for the movie ID and new title
                cout << "Enter the ID of the movie to update: ";
                cin >> movieID;
                cin.ignore(); // Ignore the newline character
                cout << "Enter the new title: ";
                getline(cin, newTitle);

                // Update the movie's title
                myDb.updateMovieTitle(movieID, newTitle);
                break;
            }
            case 6: {
                unsigned int movieID;
                string newDate;
                cout << "Enter the movie ID: ";
                cin >> movieID;
                cin.ignore();
                cout << "Enter the new release date: ";
                cin.ignore();
                getline(cin, newDate);

                if (myDb.movies.find(movieID) != myDb.movies.end()) {
                    myDb.updateMovieDate(movieID, newDate);
                    cout << "Movie release date updated successfully." << endl;
                }
                else {
                    cout << "Movie not found in the database." << endl;
                }
                break;
            }

            case 7: {
                unsigned int movieID;
                double newRating;
                cout << "Enter the movie ID: ";
                cin >> movieID;
                cout << "Enter the new rating: ";
                cin >> newRating;

                if (myDb.movies.find(movieID) != myDb.movies.end()) {
                    myDb.updateMovieRating(movieID, newRating);
                    cout << "Movie rating updated successfully." << endl;
                }
                else {
                    cout << "Movie not found in the database." << endl;
                }
                break;
            }

            case 8: {
                unsigned int personID;
                string newName;
                cout << "Enter the person ID: ";
                cin >> personID;
                cin.ignore();
                cout << "Enter the new name: ";
                getline(cin, newName);

                if (myDb.people.find(personID) != myDb.people.end()) {
                    myDb.updatePersonName(personID, newName);
                    cout << "Person's name updated successfully." << endl;
                }
                else {
                    cout << "Person not found in the database." << endl;
                }
                break;
            }

            case 9: {
                unsigned int personID;
                string newDOB;
                cout << "Enter the person ID: ";
                cin >> personID;
                cin.ignore();
                cout << "Enter the new date of birth: ";
                getline(cin, newDOB);

                if (myDb.people.find(personID) != myDb.people.end()) {
                    myDb.updatePersonDOB(personID, newDOB);
                    cout << "Person's date of birth updated successfully." << endl;
                }
                else {
                    cout << "Person not found in the database." << endl;
                }
                break;
            }

            case 10:
                // Quit.
                shouldContinue = false;
                break;

            default:
                cout << "Invalid Choice!" << endl;
                cout << "Please select a valid choice." << endl;
            }
        }
    }

    myFile.saveDatabase("Movies1.json", "People1.json", "ActorFilms1.json", "MovieCast1.json", myDb);

    return 0;
}
