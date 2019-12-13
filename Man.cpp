#include "Man.h"
#include <cstdlib>
#include <iostream>

using namespace std;

 Man :: Man (){
	 locRow = 0;
	 locCol = 0;
	 bait = 5;
	 castDistance = 2;
 }
 
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


