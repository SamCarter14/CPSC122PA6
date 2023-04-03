/*
Name: Sam Carter
Class: CPSC 122 Spring 2023
Date: April 4, 2023
Programming Assignment: PA6
Description: This program keeps track of a song library for a user through the use of linked lists. The user can load songs, save songs, display library, sort the library, search the library, insert song int library in order, remove a song from library, edit a song or exit.
*/
#include "PA6.h"

/*
Function: displayMenu
Date Created: NA
Date Last Modified: NA
Description: This function displays the menu options for the user to choose from.
Input Parameters: NA
Output Paramters: outputs to console menu options
Pre: NA
Post: outputs to console menu options
*/
void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Insert song in order" << endl;
	cout << "7) Remove song" << endl;
	cout << "8) Edit song" << endl;
	cout << "9) Exit" << endl;
}

/*
Function: getValidchoice()
Date created: NA
Date modified: NA
Description: Determines whether or not user input is a valid input
Input Param: NA
Returns: Returns cout statement if input is invalid.
Pre: Must have user input about option
Post: returns user choice if it is acceptable
*/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

/*
Function: executeUserChoice()
Date created: NA
Date modified: 4/2/23
Description: This code calls lib functions in order to execute the users decision
Input Param: int choice, SongLibrary& lib
Returns: Either ends program or runs user option
Pre: Must have user input
Post: Execute users wishes about songs
*/
void executeUserChoice(int choice, SongLibrary& lib) {
	switch (choice) {
		case 1:
      lib.loadLibrary();
			break;
		case 2:
			lib.saveLibrary();
			break;
		case 3: 
      lib.displayLibrary();
			break;
		case 4:
      lib.sortLibrary();
			break;
		case 5:
		 lib.searchLibrary();
			break;
		case 6:
      lib.insertSongInLibraryOrder();
			break;
		case 7:
		  lib.removeSongFromLibrary();
			break;
		case 8:
			lib.editSongInLibrary();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

/*
Function: runMusicManager()
Date created: NA
Date modified: NA
Description: This function executes userchoice if their decision is valid
Input Param: NA
Returns: Executes user choice or console statement thanking user
Pre: The user must have given a VALID choice
Post: The program either executes user choice or thanks them for using program
*/
void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}
