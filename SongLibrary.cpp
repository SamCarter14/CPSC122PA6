/*
Name: Sam Carter
Class: CPSC 122 Spring 2023
Date: April 4, 2023
Programming Assignment: PA6
Description: This program keeps track of a song library for a user through the use of linked lists. The user can load songs, save songs, display library, sort the library, search the library, insert song int library in order, remove a song from library, edit a song or exit.
*/
#include "SongLibrary.h"

/*
Function: songLibrary
Date created: NA
Date modified: NA
Description: default value constructor for songLibrary
Input Param: NA
Returns: returns a default library
Pre: NA
Post: Gives empty library, sortAttribute starts sorting by title
*/
SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

/*
Function: SongLibrary
Date Created: NA
Date Last Modified: 4/2/23
Description: This is a copy constructor for a song library
Input Parameters: SongLibrary& other
Output Paramters: new song library
Pre: Must have a song library to copy from
Post: Returns a copied library that does not share memory
*/
SongLibrary::SongLibrary(const SongLibrary& other) { 
  sortAttribute = other.sortAttribute;
  head = NULL;
 Song * currSong = other.head;

  while(currSong != NULL){
    Song * newSong = new Song(currSong->getTitle(), currSong->getArtist(), currSong->getGenre(), currSong->getRating());
    performInsertSongInOrder(newSong);
    currSong = currSong->getNext();
  }
}

/*
Function: ~SongLibrary
Date Created: NA
Date Last Modified: 4/1/23
Description: Destructor for song library
Input Parameters: NA
Output Paramters: NA
Pre: NA
Post: Destructor for songLibrary, prevent memory loss
*/
SongLibrary::~SongLibrary() {
    if(head != NULL){
    Song * currSong = head;
    Song * prevSong = NULL;
    while(currSong != NULL){
      prevSong = currSong;
      delete currSong;
      currSong = prevSong->getNext();
    }
      head = NULL;
  }
}
/*
Function: getHead
Date Created: NA
Date Last Modified: NA
Description: this returns the head of a library
Input Parameters: NA
Output Paramters: returns head
Pre: NA
Post: Either returns head or NULL
*/
Song * SongLibrary::getHead() const {
	return head;
}

/*
Function: setHead
Date Created: NA
Date Last Modified: NA
Description: Changes the head of a library
Input Parameters:Song * newHead
Output Paramters: returns a new head
Pre: Must have a new head to point to
Post: Creates a new head for linked list
*/
void SongLibrary::setHead(Song * newHead) {
    if(head != NULL){
    Song * currSong = head;
    Song * prevSong = NULL;
    while(currSong != NULL){
      prevSong = currSong;
      delete currSong;
      currSong = currSong->getNext();
    }
     
	}
	head = newHead;
}
/*
Function:getSortAttribute
Date Created: NA
Date Last Modified: NA
Description: Returns how the song are being sorted
Input Parameters: NA
Output Paramters: returns sortAttribute
Pre: sortAttribute originally assigned title, could be changed
Post: returns sortAttribute
*/
string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}
/*
Function: getSortAttribute
Date Created: NA
Date Last Modified: NA
Description: Changes the sort Attribute
Input Parameters: string newSortAttribute
Output Paramters: returns a new sortAttribute
Pre: sortAttribute originally assigned title, could be changed
Post: Returns the new sorting method
*/
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

/*
Function: performLoad()
Date created: NA
Date modified: 3/30/23
Description: This function loads the songs from a file into a linked list
Input Param: string filename
Returns: a filled linked list of songs
Pre: Must have a filename with correct filepath
Post: Returns linked list of songs
*/
void SongLibrary::performLoad(string filename) {
	string title, artist, genre, trash;
  int rating;
  ifstream inFile;
  inFile.open(filename);
    
  setHead(NULL);
while(!inFile.eof()){
  getline(inFile, title);
  getline(inFile, artist);
  getline(inFile, genre);
  inFile >> rating;
  getline(inFile, trash);
  getline(inFile, trash);

  if(title != ""){
   Song * newSong = new Song(title, artist, genre, rating);
    performInsertSongInOrder(newSong);
  }
  title = "";
}
  inFile.close();
}
/*
Function:performSave
Date Created: NA
Date Last Modified: 3/30/23
Description: This function saves the songs from a linked list to a new file
Input Parameters: string filename
Output Paramters: new file
Pre: Must have a linked list of songs
Post: Returns a file filled with songs from list
*/
void SongLibrary::performSave(string filename) {
  ofstream outFile;
	outFile.open(filename);
  Song * currSong;
  if(head != NULL){
    currSong = head;
    while(currSong != NULL){
      outFile << currSong->getTitle() << endl;
      outFile << currSong->getArtist() << endl;
      outFile << currSong->getGenre() << endl;
      outFile << currSong->getRating() << endl;
      outFile << endl;
      currSong = currSong->getNext();
    }
  }
  outFile.close();
}

/*
Function: performSort
Date Created: NA
Date Last Modified: 4/1/23
Description: This function sorts all the songs in a linked list based on the sort Attribute
Input Parameters: NA
Output Paramters: returns a linked list sorted
Pre: Must have a linked list filled with songs
Post: Returns a linked list sorted in potentially a new way
*/
void SongLibrary::performSort() {
 Song * currSong = head;
 head = NULL;
 Song * prevSong = NULL;
  while(currSong != NULL){
    Song * newSong = new Song(currSong->getTitle(), currSong->getArtist(), currSong->getGenre(), currSong->getRating());
    performInsertSongInOrder(newSong);
    prevSong = currSong;
    currSong = currSong->getNext();
    delete prevSong;
  }
}

/*
Function:performSearch
Date Created: NA
Date Last Modified: 3/31/23
Description: This function searches for a song in a linked list
Input Parameters:string searchAttribute, string searchAttributeValue, bool * found, int * index
Output Paramters:Returns to console song details
Pre: Must have correct search attributes, else it won't find songs
Post: Returns details about a song to console
*/
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {

  Song * currSong = head;
  Song * prevSong = NULL;
  
  if (searchAttribute == "index"){
      for(int i = 1; i < *index; i++){
        prevSong = currSong;
        currSong = currSong->getNext();
        if(currSong == NULL){
          cout << "Could not find song." << endl;
          return NULL;
        }
      }
      if(currSong != NULL){
      *found = true;
      return currSong;
      }
  }
  else{
    *index = 0;
    while(currSong->getStringAttributeValue(searchAttribute) !=   searchAttributeValue){
      *index += 1;
      prevSong = currSong;
      currSong = currSong->getNext();
      if(currSong == NULL){
          cout << "Could not find song." << endl;
          *index = -1;
          *found = false;
          return NULL;
        }
    }
       
      *found = true;
        return currSong;
    }
	
}

/*
Function:performInsertSongInOrder
Date Created: NA
Date Last Modified: 3/28/23
Description: This function inserts a new song in order in a linked list based on sortAttribute
Input Parameters:Song * songToInsert
Output Paramters: Updated linked list
Pre: Must have a song to insert, do not need a linked list beforehand
Post: Returns a item in a linked list inserted in order
*/
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	if(head == NULL){
    head = songToInsert;
  }
  else {
    Song * currSong = head;
    Song * prevSong = NULL;
    
    while(currSong != NULL && currSong->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute)){
      prevSong = currSong;
      currSong = currSong->getNext();
      
    }
    if(prevSong == NULL){
      songToInsert->setNext(head);
      head = songToInsert;
    }
    else{
      songToInsert->setNext(currSong);
      prevSong->setNext(songToInsert);
    }

  }
}


/*
Function:performRemoveSong
Date Created: NA
Date Last Modified: 4/1/23
Description: Removes a song from a linked list
Input Parameters:Song * songToRemove
Output Paramters: NA
Pre: Must have a linked list with at least one song
Post: Returns a linked list minus the one song user chooses
*/
void SongLibrary::performRemoveSong(Song * songToRemove) {
  if(head != NULL){
    Song * currSong = head;
    if(head->getTitle() == songToRemove->getTitle()){
      head = head->getNext();
      delete currSong;
    }
    else{
      Song * prevSong = NULL;
      while(currSong != NULL && currSong->getTitle() != songToRemove->getTitle()){
        prevSong = currSong;
        currSong = currSong->getNext();
      }
      if(currSong != NULL){
        prevSong->setNext((currSong->getNext()));
        delete currSong;
      }
    }
      
  }
}

/*
Function: performEditSong
Date Created: Song * songToEdit, string attribute, string newAttributeValue
Date Last Modified: NA
Description: This function allows the user to edit a song attribute
Input Parameters: Song * songToEdit, string attribute, string newAttributeValue
Output Paramters: Can return output to console
Pre: Must have a song to edit
Post: Returns an edited song to array
*/
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
  int ratingNum;
	if(attribute == "title"){
    songToEdit->setTitle(newAttributeValue);
  }
  else if(attribute == "artist"){
    songToEdit->setArtist(newAttributeValue);
  }
  else if(attribute == "genre"){
    songToEdit->setGenre(newAttributeValue); 
  }
  else if(attribute == "rating"){
    ratingNum = stoi(newAttributeValue);
    songToEdit->setRating(ratingNum);
  }
  else{cout << "Invalid attribute entered." << endl;}
}
/*
Function: displayLibrary
Date Created: NA
Date Last Modified: 3/29/23
Description: This function displays all the songs in a linked list songLibrary
Input Parameters:NA
Output Paramters: returns information to console
Pre: NA
Post: Returns a song library to console, information about songs
*/
void SongLibrary::displayLibrary(){
  cout << endl << "*****SONG LIBRARY*****" << endl << endl;
  Song * currSong;
  int count = 1;
  if(head != NULL){
    currSong = head;
    while(currSong != NULL){
      cout << count << ". ";
      currSong->displaySong();
      currSong = currSong->getNext();
      cout << endl;
      count++;
    }
  }
}
/*
Function:insertSongInLibraryOrder
Date Created: 3/29/23
Date Last Modified: 3/29/23
Description: This function asks the user for information to make a song, calls performInsertSongInOrder
Input Parameters:NA
Output Paramters: NA
Pre: NA
Post: Returns a new song in linked list based on user input
*/
void SongLibrary::insertSongInLibraryOrder(){
  string title, artist, genre;
  int rating;
  cout << "Enter name of song:" << endl;
  getline(cin, title);
  cout << "Enter artist of song:" << endl;
  getline(cin, artist);
  cout << "Enter genre of song:" << endl;
  getline(cin, genre);
  cout << "Enter rating for song:" << endl;
  cin >> rating;

  Song * newSong = new Song(title, artist, genre, rating);
  performInsertSongInOrder(newSong);
}
/*
Function:sortLibrary
Date Created: 4/1/23
Date Last Modified: 4/1/23
Description: This function asks the user how they would like to sort
Input Parameters: Cin statement
Output Paramters: outputs a sorted linked list
Pre: NA
Post: Creates sorted linked list
*/
void SongLibrary::sortLibrary(){
  string sort;
  cout << "How would you like to sort?" << endl;
  getline(cin, sort);
  setSortAttribute(sort);
  performSort();
}
/*
Function:loadLibrary
Date Created: 3/30/23
Date Last Modified: 3/30/23
Description: This function asks the user for the name of a file to load songs from
Input Parameters:cin statement
Output Paramters: cretes linked list based off of file
Pre: Must have filled file
Post: Returns filled linked list
*/
void SongLibrary::loadLibrary(){
  string file;
  cout << "Enter the name of file you want to load:" << endl;
  getline(cin, file);
  performLoad(file);
}
/*
Function:saveLibrary
Date Created: 3/30/23
Date Last Modified: 3/30/23
Description: This function asks the user for the name of the file they wish to save songs to
Input Parameters: Cin statement
Output Paramters: Output file with songs
Pre: Must have a filled linked list
Post: Returns an output file filled with songs
*/
void SongLibrary::saveLibrary(){
  string file;
  cout << "Enter name of file you wish to save songs to:" << endl;
  getline(cin, file);
  performSave(file);
}
/*
Function: editSongInLibrary
Date Created: 4/1/23
Date Last Modified: 4/1/23
Description:This function asks the user how they would like to search for a song, and what they would like to change in the song
Input Parameters: Cin statements
Output Parameters: Changes a songs attribute in linked list
Pre: Must have song to edit
Post: Changes one song attribute
*/
void SongLibrary::editSongInLibrary(){
  string attribute, attributeSearchValue, changeAttribute, newAttributeValue;
  int attributeNum;
  Song * currSong = head;
  Song * prevSong = NULL;
   if(head == NULL){
        cout << "No songs to edit." << endl;
      }
  else{
  cout << "What attribute would you like to search by? (title, artist, genre, rating, index)" << endl;
  cin >> attribute;
  cout << "What " << attribute << " would you like to search for?" << endl;
  if (attribute == "index"){
    cin >> attributeNum;
      for(int i = 1; i < attributeNum; i++){
        prevSong = currSong;
        currSong = currSong->getNext();
        if(currSong == NULL){
          cout << "Could not find song." << endl;
          break;
        }
      }
      if(currSong != NULL){
      cout << "Which attribute would you like to change?(title, artist, genre or rating):" << endl;
        cin >> changeAttribute;
        cout << "And what would you like to change the " << changeAttribute          << " to?" << endl;
        getline(cin, newAttributeValue);
        getline(cin, newAttributeValue);
      performEditSong(currSong, changeAttribute, newAttributeValue);
      }
  }
  else{
    getline(cin, attributeSearchValue);
    getline(cin, attributeSearchValue);
    while(currSong->getStringAttributeValue(attribute) != attributeSearchValue){
      prevSong = currSong;
      currSong = currSong->getNext();
      if(currSong == NULL){
          cout << "Could not find song." << endl;
          break;
        }
    }
       if(currSong != NULL){
      cout << "Which attribute would you like to change?(title, artist, genre or rating):" << endl;
        cin >> changeAttribute;
        cout << "And what would you like to change the " << changeAttribute          << " to?" << endl;
        getline(cin, newAttributeValue);
        getline(cin, newAttributeValue);
      performEditSong(currSong, changeAttribute, newAttributeValue);
      }
    
    }
  }
}
/*
Function: searchLibrary
Date Created: 4/1/23
Date Last Modified: 4/1/23
Description: Asks the user how they would like to searchthe library
Input Parameters: Cin statements
Output Paramters:outputs to console if found or not found
Pre: NA
Post: Returns if song was found or not
*/
void SongLibrary::searchLibrary(){
  string attribute, attributeSearchValue;
  int index = -1;
  bool found = false;
  Song * currSong = head;
  Song * prevSong = NULL;
   if(head == NULL){
        cout << "No songs to edit." << endl;
      }
  else{
  cout << "What attribute would you like to search by? (title, artist, genre, rating, index)" << endl;
  cin >> attribute;
  cout << "What " << attribute << " would you like to search for?" << endl;
  if (attribute == "index"){
    cin >> index;
   }
    else{
      getline(cin, attributeSearchValue);
      getline(cin, attributeSearchValue);
    }
  currSong = performSearch(attribute, attributeSearchValue, &found, &index);
    if(currSong != NULL){
    cout << index + 1 << ". ";
     cout << currSong->getTitle() << endl;
     cout << currSong->getArtist() << endl;
     cout << currSong->getGenre() << endl;
     cout << currSong->getRating() << endl << endl;
    }
    else
    {cout << "Could not find song." << endl;}
  }
 } 

void SongLibrary::removeSongFromLibrary(){
  string attribute, attributeSearchValue;
  int index = -1;
  bool found = false;
  Song * currSong = head;
  Song * prevSong = NULL;
   if(head == NULL){
        cout << "No songs to edit." << endl;
      }
  else{
  cout << "What attribute would you like to search by? (title, artist, genre, rating, index)" << endl;
  cin >> attribute;
  cout << "What " << attribute << " would you like to search for?" << endl;
  if (attribute == "index"){
    cin >> index;
   }
    else{
      getline(cin, attributeSearchValue);
      getline(cin, attributeSearchValue);
    }
  currSong = performSearch(attribute, attributeSearchValue, &found, &index);   performRemoveSong(currSong);
  if (currSong == NULL){
    cout << "Could not find song." << endl;
  }
  }
 } 