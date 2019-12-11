#include "Pond.h"
#include "World.h"

using namespace std;
/**
 * Default Constructor
 */
Pond :: Pond() : World(){
	//allows Pond to populate world without knowing World grid sizes
	row = sizeof grid / grid[0];
	col = sizeof grid[0]/ sizeof grid(char);
	
	int numfish = (row * col)/3; //fill 1/3 of pond with fish
	
	for(int i = 0; i< numfish;i++){
		int randCol = rand() %col;
		int randRow = rand()%row;
		fishpop.add(Fish(randRow,randCol));
	}
}

void Pond :: PrintGrid(){
	for(int i = 0; i<row; i++){
		for(int j = 0; j< col; j++){
			cout << "+++";
		}
		for (int j =0;j<col;j++){
			cout << "+"<<grid[i][j];
		}
		cout << "+\n";
	}
}
void Pond :: UpdateGrid(){
	//clear out fish grid 
	for (int i=0;i<row; i++){
		for (int j=0; j<col;j++){
			grid[i][j] =' ';
		}
	}
	
	//repopulate fish grid after they moved
	for(Fish f: fishpop){
		grid[f->locRow][f->locCol] = size;
	}
}

bool Pond :: checkBounds(int row, int col){
	return true;
}

void Pond :: initGrid(){
	
}




