/*
Name: Sam Carter
Class: CPSC 122 Spring 2023
Date: April 4, 2023
Programming Assignment: PA6
Description: This program keeps track of a song library for a user through the use of linked lists. The user can load songs, save songs, display library, sort the library, search the library, insert song int library in order, remove a song from library, edit a song or exit.
*/
#include "Song.h"

/*
Function: convertToLowerCase
Date created: NA
Date modified: 3/30/23
Description: This function converts words to lower string
Input Param: string s
Returns: string a
Pre: Must have a string inputed to be converted
Post: Returns a string in lower case
*/
string convertToLowercase(string s) {
	string a = s;
  for(int i = 0; i < a.size(); i++){
  a.at(i) = tolower(a.at(i));
  }
	return a;
}

/*
Function: song()
Date created: NA
Date modified: 3/30/23
Description: This function creates a default value constructor for songs, including linked list attributes.
Input Param: NA
Returns: A default song
Pre: NA
Post: Returns a default made song
*/
Song::Song() {
  title = "";
  artist = "";
  genre = "";
  rating = 1;
	next = NULL;
  prev = NULL;
}

/*
Function: song()
Date created: NA
Date modified: 3/30/23
Description: This function creates a explicit value constructor for songs
Input Param: string titleParam, string artistParam, string genreParam, int ratingParam
Returns: A song made with input parameters
Pre: Must have input parameters for song attributes
Post: Creates a new song with its own values
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
  title = titleParam;
  artist = artistParam;
  genre = genreParam;
  rating = ratingParam;
	next = NULL;
  prev = NULL;
}

/*
Function: Song()
Date Created: NA
Date Last Modified: 3/30/23
Description: This is a copy constructor for a song
Input Parameters: Song& other
Output Parameters: new song
Pre: Must have a song to copy from
Post: Returns a copied song.
*/
Song::Song(const Song& other) {
title = other.title;
artist = other.artist;
genre = other.genre;
rating = other.rating;
	next = NULL;
  prev = NULL;
}
/*
Function: getTitle()
Date created: NA 
Date modified: 3/30/23
Description: Gets the title of a song
Input Param: NA
Returns: title
Pre: Must have a song made to get title
Post: gets title of song
*/
string Song::getTitle() {
	return title;
}
/*
Function: setTitle()
Date created: NA 
Date modified: 3/30/23
Description: changes the title for a song
Input Param: string newTitle()
Returns: newTitle
Pre: must have a title to change and a new title name
Post: changes the title of song
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}
/*
Function: getArtist()
Date created: NA
Date modified: 3/30/23
Description: gets the artist of a song
Input Param: NA
Returns: artist
Pre: must have a song to get artist
Post: returns song artist
*/
string Song::getArtist() {
	return artist;
}
/*
Function: setArtist()
Date created: NA
Date modified: 3/30/23
Description: This function changes the artist of a song
Input Param: string newArtist
Returns: newArtist
Pre: Must have song made and a new artist name
Post: changes artist name
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}
/*
Function: getGenre()
Date created: NA
Date modified: 3/30/23
Description: gets the genre of a song
Input Param: NA
Returns: genre
Pre: must have a song to get genre
Post: returns song genre
*/
string Song::getGenre() {
	return genre;
}
/*
Function: setGenre()
Date created: NA
Date modified: 3/30/23
Description: This function changes the genre of a song
Input Param: string newGenre
Returns: newGenre
Pre: Must have song made and a new genre name
Post: changes genre name
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}
/*
Function: getRating()
Date created: NA
Date modified: 3/30/23
Description: gets the rating of a song
Input Param: NA
Returns: rating
Pre: must have a song to get rating
Post: returns song rating
*/
int Song::getRating() {
	return rating;
}
/*
Function: setRating()
Date created: NA
Date modified: 3/30/23
Description: This function changes the rating of a song and checks if it is in the right range
Input Param: int newRating
Returns: newRating
Pre: Must have song made and a new rating
Post: changes ratu\ing
*/
void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}
Song * Song::getPrev(){
  return prev;
}
/*
Function: getNext
Date Created: NA
Date Last Modified: NA
Description: This will get the next song in the linked list
Input Parameters: NA
Output Paramters: returns next song
Pre: Must have a current song to grab next from
Post: Gives the next song in order
*/
Song * Song::getNext() {
	return next;
}
/*
Function: setNext
Date Created: NA
Date Last Modified: NA
Description: This changes what the next pointer points to.
Input Parameters: Song * newNext
Output Paramters: a new next
Pre: Must have a song to change next and a song to assign next to
Post: Returns a song with a new next pointer value
*/
void Song::setNext(Song * newNext) {
  prev = next;
	next = newNext;
}

/*
Function: getStringAttributeValue()
Date created: NA
Date modified: 3/30/23
Description: This function gets the string of a songs attribute
Input Param: string attribute
Returns: a songs attribute (the one requested)
Pre: Must have song made and an attribute
Post: returns an attribute as a string
*/
string Song::getStringAttributeValue(string attribute) {
	string rating = "";
  
	if(attribute == "title"){
    return getTitle();
  }
  else if(attribute == "artist"){
    return getArtist();
  }
  else if(attribute == "genre"){
    return getGenre();
  }
  else if(attribute == "rating"){
    rating = to_string(getRating());
    return rating;
  }
	return "";
}

/*
Function: displaySong()
Date created: NA
Date modified: 3/30/23
Description: This function couts a song and its information
Input Param: NA
Returns: console output
Pre: Must have a song made
Post: Gives console description about song
*/
void Song::displaySong() {
cout << "Title: " << title << endl << "Sang by: " << artist << endl << "Genre: " << genre << endl << "Rating: " << rating << endl;
}

