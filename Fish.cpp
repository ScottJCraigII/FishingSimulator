//  Written By Scott J. Craig and Carrie E. Adkins
//  Finished 12/13/2019 11:30 pm
//  This is a fish simulation  rules listed in read me

#include "Fish.h"
#include <cstdlib> 
#include <iostream>

using namespace std;

// default constructor
Fish :: Fish(){
	locCol =0;
	locRow=0;
	sex = rand() %2; //MF is binary, easier to randomize and compare as ints
	hunger =0;
	weight=8;
	size = 'S';
}

// constructor that places fish randomly within the 3D grid, assigns sex randomly
// assigns the starting weight, hunger and size of the fish

Fish :: Fish(int row, int col){
	locCol = col;
	locRow = row;
	sex = rand()%2;
	hunger = 5;
	weight = rand()%4+4;
	size = 'S';
}

// This moves the fish to different locations randomly

void Fish :: swim(){
	locRow = locRow + ((rand()%3)-1);
	locCol = locCol + ((rand()%3)-1);
}

// this causes the fish to grow with the base rate being based on the size before
// growth, random allows this growth to be different for each fish and season

void Fish :: grow(){
	if (weight<18) {
		weight += 3*(rand()%6+1);
	}else if (weight < 30){
		weight += 2*(rand()%6+1);
	}else {
		weight += (rand()%6+1);
	}
}

// This sets the size of an inividual fish based on which category it fits
// fish start S and then grow to M and last grow to L.  Then based on which size the character displayed changes
void Fish :: setSize(){
	if(weight/16>=3){ //set ui char based on weight 3lbs is L
			size='L';
		}else if(weight/16>=2){
			size ='M';
		}

}

