#include "Song.h"

// TODO: finish this function
string convertToLowercase(string s) {
	return "";
}

// TODO: finish Song default value constructor
Song::Song() {

	next = NULL;
}

// TODO: finish Song explicit value constructor
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {

	next = NULL;
}

// TODO: finish Song copy constructor
Song::Song(const Song& other) {

	next = NULL;
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

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

Song * Song::getNext() {
	return next;
}

void Song::setNext(Song * newNext) {
	next = newNext;
}

// TODO: finish this function
string Song::getStringAttributeValue(string attribute) {
	return "";
}

// TODO: finish this function
void Song::displaySong() {

}

