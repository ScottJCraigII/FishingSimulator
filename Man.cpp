//  Written By Scott J. Craig and Carrie E. Adkins
//  Finished 12/13/2019 11:30 pm
//  This is a fish simulation  rules listed in read me

#include "Man.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// this is the man default constructor
 Man :: Man (){
	 locRow = 0;
	 locCol = 0;
	 bait = 5;
	 castDistance = 2;
 }

// this moves the man from one position to another, used each day
void Man :: move(){
	locRow = locRow + ((rand()%3)-1);
	locCol = locCol + ((rand()%3)-1);
 }

/**
 * Unused user actions implemented
 */
void Man :: move(int row, int col){
	locRow = row;
	locCol = col;
}

// Overloaded operator to move the man
void Man::operator()(int row, int col){
	locRow = row;
	locCol = col;
}

