#include "Fish.h"
#include <cstdlib> 
#include <iostream>

using namespace std;

Fish :: Fish(){
	locCol =0;
	locRow=0;
	sex = rand() %2; //MF is binary, easier to randomize and compare as ints
	hunger =0;
	size = 'F';
}
/**
 *Method allows Pond to place fish randomly within its bounds, 
 */
Fish :: Fish(int row, int col){
	locCol = col;
	locRow = row;
	sex = rand()%2;
	hunger = 5;
	if(sex == 0){
		size = 'F';
	}else{ size = 'M';} 	
}

void Fish :: swim(){
	locRow = locRow + (rand()%3-1); //why is this not randomizing between -1,1?
	locCol = locCol + (rand()%3-1);
//	cout << "fish fish row, col"<< locRow<<","<< locCol<<endl;
}
