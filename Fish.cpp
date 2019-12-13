#include "Fish.h"
#include <cstdlib> 
#include <iostream>

using namespace std;

Fish :: Fish(){
	locCol =0;
	locRow=0;
	sex = rand() %2; //MF is binary, easier to randomize and compare as ints
	hunger =0;
	weight=8;
	size = 'S';
}
/**
 *Method allows Pond to place fish randomly within its bounds, 
 */
Fish :: Fish(int row, int col){
	locCol = col;
	locRow = row;
	sex = rand()%2;
	hunger = 5;
	weight = rand()%4+4;
	size = 'S';
}

void Fish :: swim(){
	locRow = locRow + ((rand()%3)-1);
	locCol = locCol + ((rand()%3)-1);
}

void Fish :: grow(){
	if (weight<18) {
		weight += 3*(rand()%6+1);
	}else if (weight < 30){
		weight += 2*(rand()%6+1);
	}else {
		weight += (rand()%6+1);
	}
}

void Fish :: setSize(){
	if(weight/16>=3){ //set ui char based on weight 3lbs is L
			size='L';
		}else if(weight/16>=2){
			size ='M';
		}

}
