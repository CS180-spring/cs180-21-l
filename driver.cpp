#include <iostream>
// Still need all other functions header files and cpp 

using namespace std;

int main(){

    int mainChoice = 0;
    int userChoice = 0;

    // Menu option for users
    cout << "Welcome to Team L's Movie Rating Database!" << endl;
    cout << "How can I help you?" << endl; 
    cout << "------------------------------------" << endl; 
    cout << "1. Enter the curd operations for the database." << endl;
    cout << "2. Quit"

    if(mainChoice == 2){
        return 0;
    } else{
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

        switch(userChoice){
            case 1:
                // Add movie function 
                break;
            
            case 2:
                // Add person function
                break;

            case 3:
                // Delete the whole movie function 
                break;

            case 4:
                // Delete the whole person function 
                break;

            case 5: 
                // Update movie title function 
                break;
                
            case 6: 
                // Update movie date function 
                break;

            case 7:
                // Update movie rating function
                break;

            case 8: 
                // Update person's name function 
                break;

            case 9: 
                // Update person's DOB function
                break;

            case 10: 
                return 0;
                break;

            default:
                cout << "Invalid Choice!" << endl;
                cout << "Please select a valid choice." << endl; 
        }

    }

    return 0; 
}