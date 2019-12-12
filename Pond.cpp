#include "Pond.h"
#include "World.h"
//#include "Man.h"
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
	man;
	row = 10;			//(sizeof grid )/ (grid[0]);
	col = 10;			//(sizeof grid[0])/ (sizeof (char));
	day = 1;
	int numfish = 30; 	//(row * col)/3; //fill 1/3 of pond with fish
						//	cout << "Numfish " << numfish << endl;
	for(int i = 0; i< numfish;i++){
		int randCol = rand() %col;
		int randRow = rand()%row;
		fishpop.push_back(Fish(randRow,randCol));
//		cout << "add fish to vector at row, col" << randRow<<","<<randCol<<endl;
	}
	//randomize weights 
	for(Fish& f : fishpop){
		f.weight = rand()%21 +10;
		f.setSize();
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
	for (Fish &f : fishpop){
//		cout << "Updated pond Fish Locations"<<endl;
//		cout << "Pond fish row " << f.locRow<< " col "<< f.locCol<<endl; //same for each as end day, same vector of Fish, different location?
		grid[f.locRow][f.locCol] = f.size;
	}
	//place the fisherman
	grid[man.locRow][man.locCol] = man.person;
}

void Pond :: endDay(){
	int fishTracker=1;
	
	for(Fish &f : fishpop){
//		cout << "fish "<< fishTracker<<" tries to swim\n";
		//fish tries to swim
		f.swim();
		
//		cout << "Pond fish "<<fishTracker<<" row " << f.locRow<< " col "<< f.locCol<<endl;  
		//if fish tries to swim outside of the pond, the pond restricts it

			if(f.locRow < 0){
				f.locRow = 0;
			}else if (f.locRow >= row){
				f.locRow = row-1; //fish bonks into down limit, stupid fish
			}
			
			if (f.locCol < 0){
				f.locCol = 0;
			}else if (f.locCol>=col){
				f.locCol = col-1;
			}		
//			cout << "Pond fish"<<fishTracker<<" corrected row " << f.locRow<< " col "<< f.locCol<<endl;
		
		fishTracker++;
	}	
	day++;
}

void Pond :: endSeason(){
	int numMales = 0;
	
	//this loop grows fish and counts breeding sized males in the offseason
	for (Fish &f: fishpop){
		f.grow(); 			//grow each of the fish
		f.setSize();

		if(f.sex == 1 && f.size >= 24){ //count breeding size males
			numMales++;
		}
	}
	
	//this loop breeds new fish
	for (Fish &f: fishpop){
		if(numMales> 0 && f.sex == 0 && f.size >= 24){
				fishpop.push_back(Fish(f.locRow,f.locCol)); // add fish to mothers block
				numMales--;									//remove breeding male
			}
		}
	
	day = 1;
}

bool Pond :: checkBounds(int r, int c){
	if(r < 0 || r>=row){
		if(c <0 || c >=col){
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

void Pond :: sail(){
	man.move();
	if(man.locRow < 0){
		man.locRow = 0;
	}else if (man.locRow >= row){
		man.locRow = row-1; 
	}
			
	if (man.locCol < 0){
		man.locCol = 0;
	}else if (man.locCol>=col){
		man.locCol = col-1;
	}		
}

void Pond :: cast(){
	int baitRow = man.locRow + (rand()%(2* man.castDistance +1)-man.castDistance);
	int baitCol = man.locCol + (rand()%(2* man.castDistance +1)-man.castDistance);
	
	if (!checkBounds(baitRow, baitCol)){return;} // if cast is out of bounds return
	
	//This method iterates through the vector from head, so has a preference to remove older fish first.
	
	if (grid[baitRow][baitCol]!=' '){		//if  grid whitespace no point in checking the vector, no fish
		for(vector<Fish>::iterator f = fishpop.begin(); f!= fishpop.end(); f++){ //need an iterator for vect.erase
			
			if(baitRow == f->locRow && baitCol ==f->locCol && f->hunger >= man.bait){
				cout << "You landed a "<< f->weight<<" oz Fish!\n";
				if (f->weight > 20){
					cout << "Put the fish in your livewell\n"; 
					//add a copy of the fish to vect<Fish> livewell to keep track of caught fish implement later
					fishpop.erase(f);
					return;
				}else {
					cout << "You release the fish that was too small\n";
					return; //catch one fish per worm..
				}
			}
		}
	}
	return;
}




