/*
Name: Sam Carter
Class: CPSC 122 Spring 2023
Date: April 4, 2023
Programming Assignment: PA6
Description: This program keeps track of a song library for a user through the use of linked lists. The user can load songs, save songs, display library, sort the library, search the library, insert song int library in order, remove a song from library, edit a song or exit.
*/
#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute; // NEW: keep track of what attribute the library is currently ordered by
	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); // NEW: copy constructor
		~SongLibrary();
		Song * getHead() const; // UPDATED: name
		void setHead(Song *); // UPDATED: name
		string getSortAttribute() const; // NEW: getter for sortAttribute
		void setSortAttribute(string); // NEW: setter for sortAttribute
		
		void performLoad(string);
		void performSave(string);
		void performSort(); // UPDATED: no parameter for sort attribute, using Song's sortAttribute member variable
		Song * performSearch(string, string, bool *, int *); // UPDATED: parameter list and return type
		void performInsertSongInOrder(Song *); // NEW: replaces addSong()
		void performRemoveSong(Song *); // UPDATED: parameter list
		void performEditSong(Song *, string, string); // UPDATED: parameter list

    void displayLibrary();
    void insertSongInLibraryOrder();
    void sortLibrary();
    void loadLibrary();
    void saveLibrary();
    void editSongInLibrary();
    void searchLibrary();
    void removeSongFromLibrary();

};

#endif
