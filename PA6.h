/*
Name: Sam Carter
Class: CPSC 122 Spring 2023
Date: April 4, 2023
Programming Assignment: PA6
Description: This program keeps track of a song library for a user through the use of linked lists. The user can load songs, save songs, display library, sort the library, search the library, insert song int library in order, remove a song from library, edit a song or exit.
*/
#ifndef PA6_H
#define PA6_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 9;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif
