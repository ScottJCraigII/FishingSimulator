#include "Man.h"
 Man :: Man (){
	 locRow = 0;
	 locCol = 0;
	 bait = 5;
	 cast = 2;
 }
 
 void Man:: move(){
	locRow = locRow + ((rand()%3)-1);
	locCol = locCol + ((rand()%3)-1);
 }

//void Man :: cast(){

