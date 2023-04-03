/*
Name: Sam Carter
Class: CPSC 122 Spring 2023
Date: April 4, 2023
Programming Assignment: PA6
Description: This program keeps track of a song library for a user through the use of linked lists. The user can load songs, save songs, display library, sort the library, search the library, insert song int library in order, remove a song from library, edit a song or exit.
*/
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
		Song * next; 
    Song * prev; // NEW: link for linking Songs together in a linked list
	public:
		Song();
		Song(string, string, string, int);
		Song(const Song&); // NEW: copy constructor
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);

    Song * getPrev();
		Song * getNext(); // NEW: getter for next
		void setNext(Song *); // NEW: setter for next
		
		void displaySong();
		
		string getStringAttributeValue(string);
};

#endif
