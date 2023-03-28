#include "SongLibrary.h"


SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

// TODO: finish SongLibrary copy constructor
SongLibrary::SongLibrary(const SongLibrary& other) {
	head = NULL; // TODO: fix this
}

// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {

}

Song * SongLibrary::getHead() const {
	return head;
}

// TODO: finish this function
void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		// TODO: free old list here!!
	}
	head = newHead;
}

string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSave(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSort() {

}

// TODO: finish this function
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	
	return NULL; // TODO: fix this
}

// TODO: finish this function
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	
}


// TODO: finish this function
void SongLibrary::performRemoveSong(Song * songToRemove) {
	
}

// TODO: finish this function
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	
}
