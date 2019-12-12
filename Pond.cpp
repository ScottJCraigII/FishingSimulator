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
	day = 1;
	
	int numfish = 10; //(row * col)/3; //fill 1/3 of pond with fish
//	cout << "Numfish " << numfish << endl;
	for(int i = 0; i< numfish;i++){
		int randCol = rand() %col;
		int randRow = rand()%row;
		fishpop.push_back(Fish(randRow,randCol));
//		cout << "add fish to vector at row, col" << randRow<<","<<randCol<<endl;
	}
//	cout << "fish vector size "<< fishpop.size()<<endl;
}

void Pond :: PrintGrid(){
	for(int j = 0; j<= col; j++){
			cout << "++";
		}
	for(int i = 0; i<row; i++){
		cout << "\n+";
		for (int j =0;j<col;j++){
			cout << " "<<grid[i][j];
		}
		cout <<"+";
	}
	cout<<endl;
	for(int j = 0; j<=col; j++){
			cout << "++";
		}
	cout <<endl;
}
void Pond :: UpdateGrid(){
	//clear out pond 
	for (int i=0;i<row; i++){
		for (int j=0; j<col;j++){
			grid[i][j] =' ';
		}
	}
	//update pond with new fish locations
	for (Fish f : fishpop){
//		cout << "Updated pond Fish Locations"<<endl;
//		cout << "Pond fish row " << f.locRow<< " col "<< f.locCol<<endl; //same for each as end day, same vector of Fish, different location?
		grid[f.locRow][f.locCol] = f.size;
	}
}

void Pond :: endDay(){
	int fishTracker=1;
	
	for(Fish f : fishpop){
//		cout << "fish "<< fishTracker<<" tries to swim\n";
		//fish tries to swim
		f.swim();
		
//		cout << "Pond fish "<<fishTracker<<" row " << f.locRow<< " col "<< f.locCol<<endl;  
		//if fish tries to swim outside of the pond, the pond restricts it
		if (!checkBounds(f.locRow,f.locCol)){
			if(f.locRow < 0){
				f.locRow = 0;
			}else if (f.locRow > row){
				f.locRow = row; //fish bonks into down limit, stupid fish
			}
			
			if (f.locCol < 0){
				f.locCol = 0;
			}else if (f.locCol> col){
				f.locCol = col;
			}		
//			cout << "Pond fish"<<fishTracker<<" corrected row " << f.locRow<< " col "<< f.locCol<<endl;
		}
		fishTracker++;
	}	
	day++;
}

void Pond :: endSeason(){
	int numMales = 0;
	for (Fish f: fishpop){
		if(f.sex ==1){
			numMales++;
		}
	}
	for (Fish f: fishpop){
		while(numMales>0){
			if (f.sex == 0){
				fishpop.push_back(Fish(f.locRow,f.locCol)); // add fish to mothers block
				numMales--;
			}
		}
	}
	day = 0;
}

bool Pond :: checkBounds(int row, int col){
	if(row < 0 || row >10){
		if(col <0 || col >0){
			return false;
		}
	}
	return true;
}

void Pond :: initGrid(){
	
}

int Pond :: getDay(){
	return day;
}




