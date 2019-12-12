#include "Pond.h"
#include "World.h"
//#include "Fish.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
/**
 * Default Constructor
 */
Pond :: Pond() : World(){
	//allows Pond to populate world without knowing World grid sizes
	row = 10;//(sizeof grid )/ (grid[0]);
	col = 10;//(sizeof grid[0])/ (sizeof (char));
	vector <Fish> fishpop;
	
	int numfish = (row * col)/3; //fill 1/3 of pond with fish
	cout << "Numfish " << numfish << endl;
	for(int i = 0; i< numfish;i++){
		int randCol = rand() %col;
		int randRow = rand()%row;
		fishpop.push_back(Fish(randRow,randCol));
		cout << "add fish to vector at row, col" << randRow<<","<<randCol<<endl;
	}
	cout << "fish vector size "<< fishpop.size()<<endl;
}

void Pond :: PrintGrid(){
	for(int i = 0; i<row; i++){
		for(int j = 0; j< col; j++){
			cout << "++";
		}
		cout << endl;
		for (int j =0;j<col;j++){
			cout << "+"<<grid[i][j];
		}
		cout << "+\n";
	}
}
void Pond :: UpdateGrid(){
	//clear out fish grid 
	cout<< "update grid whitespace\n";
	for (int i=0;i<row; i++){
		for (int j=0; j<col;j++){
			grid[i][j] =' ';
		}
	}
	cout << "update 2d array with fish\n";
/*	for (Fish f : fishpop){
		grid[f.locCol][f.locRow] = f.size;
	}*/
	//repopulate fish grid after they moved
	for(vector<Fish> :: iterator f = fishpop.begin(); f !=  fishpop.end(); ++f){
		
		cout <<"entered vector iterator loop" << "fish Row " << f->locRow << " Col " << f->locCol;
		grid[f->locRow][f->locCol] = f->size;
	}
}

bool Pond :: checkBounds(int row, int col){
	return true;
}

void Pond :: initGrid(){
	
}




