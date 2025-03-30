#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to handle the user registration process
void registerUser() {
    string username, password;
    
    cout << "Enter a new username: ";
    cin >> username;
    
    // Create a file with the username as the filename
    ofstream outFile(username + ".txt");

    if (!outFile) {
        cout << "Error creating user file!" << endl;
        return;
    }

    // Ask for the user's password
    cout << "Enter a password: ";
    cin >> password;

    // Store the username and password in the file
    outFile << username << endl << password << endl;
    
    cout << "Registration successful!" << endl;
    outFile.close();
}

// Function to handle user login process
void loginUser() {
    string username, password, inputUsername, inputPassword;
    
    cout << "Enter your username: ";
    cin >> inputUsername;

    ifstream inFile(inputUsername + ".txt");

    // Check if the file exists (user exists)
    if (!inFile) {
        cout << "User does not exist!" << endl;
        return;
    }

    // Read the username and password from the file
    getline(inFile, username);
    getline(inFile, password);

    // Ask for the user's password input
    cout << "Enter your password: ";
    cin >> inputPassword;

    // Check if the entered password matches the stored password
    if (inputPassword == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password!" << endl;
    }

    inFile.close();
}

int main() {
    int choice;

    while (true) {
        cout << "==== Login and Registration System ====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
