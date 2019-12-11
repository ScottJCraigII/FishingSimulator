#include "Fish.h"
#include <cstdlib> 

Fish :: Fish(){
	locCol =0;
	locRow=0;
	sex = rand() %1; 
	hunger =0;
	size = 1;
}
/**
 *Method allows Pond to place fish randomly within its bounds, 
 */
Fish :: Fish(int row, int col){
	locCol = col;
	locRow = row;
	sex = rand()%1;
	hunger = 5;
	size = rand()%3; 
}
