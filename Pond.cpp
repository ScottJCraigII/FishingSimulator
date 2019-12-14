//  Written By Scott J. Craig and Carrie E. Adkins
//  Finished 12/13/2019 11:30 pm
//  This is a fish simulation  rules listed in read me

#include "Pond.h"
#include "World.h"
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
	int temp = sizeof grid[0];
	row = sizeof grid / temp;
	col = (sizeof grid[0])/ (sizeof (char));
	day = 1;
	int numfish = row*col/4; 	//25% filled with
	for(int i = 0; i< numfish;i++){
		fishpop.push_back(Fish(rand()%row,rand()%col));
	}
	//randomize weights 
	for(Fish& f : fishpop){
		f.weight = rand()%21 +10; //initial f wieghts from 10-30oz
		f.setSize();
	}	
	// put the boat on the pond
	man.move(rand()%row,rand()%col);
}

// This prints the pond with the appropriate characters for the fish and man
// man is our fisherman on a boat

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
	//This repopulates the pon to update pond with fish locations, this is needed to prevent an empty space where the boat was in the previous iteration
	for (Fish &f : fishpop){
		grid[f.locRow][f.locCol] = f.size;
	}
	//place the fisherman in the pond
	grid[man.locRow][man.locCol] = man.person;
}

// This has the fish swim and updates their location for the next day
void Pond :: endDay(){
	for(Fish &f : fishpop){
		f.swim();
		fixLocation(f);
	}	
	day++;
}

// this method Breeds and grows fish during the time between seasons
// this is what happens when all characters are off stage
// we then grow the fish and change their weight accordingly
// determines how many male/female pairs of fish are available to decide breeding
// resets the ay to 1 for the new season.
void Pond :: endSeason(){
	int numMales = 0;
	int numFemales = 0;
	
	//this loop grows fish and counts breeding sized males in the offseason
	for (Fish& f: fishpop){
		f.grow(); 			//grow each of the fish
		f.setSize();

		if(f.sex == 1 && f.weight >= 24){ //count breeding size males
			numMales++;
		}
		if(f.sex == 1 && f.weight >= 24){ //count breeding size females
			numFemales++;
		}
	}

	//this loop breeds new fish
	for (int i = numFemales; i>0;i--){	//doesn't need to be by refernce, since we only need to acces where mom is, not modify the mom object
		if(numMales >0){

			//fishpop++ overload ++, move push_back to overload
			fishpop.push_back(Fish(rand()%row,rand()%col)); // add fish to mothers block  //this is where my error is?
			numMales--;									//remove breeding male
		}
	}
	day = 1;
}

// this makes sure nothing goes out of bounds of the grid
bool Pond :: checkBounds(int r, int c){
	if(r < 0 || r>=row){
		if(c <0 || c >=col){
			return false;
		}
	}
	return true;
}

//Pond 3 
//this interdependence means that both fish and man objects should inherit from a super class that normalizes their location variables.
void Pond :: fixLocation(auto& obj){
	if(obj.locRow < 0){
		obj.locRow = 0;
	}else if (obj.locRow >= row){
		obj.locRow = row-1; 
	}
			
	if (obj.locCol < 0){
		obj.locCol = 0;
	}else if (obj.locCol>=col){
		obj.locCol = col-1;
	}	
	
	return;
}

//
void Pond :: initGrid(){
	
}

// This returns the day in the season
int Pond :: getDay(){
	return day;
}

// This moves the location of the man on the pond
// This also ensures the man does not move out of the pond
void Pond :: sail(){
	man.move();
	fixLocation(man);	
}

//  This casts the fishing pole a random distance from the man location
//  this casts the line and uses a random function to determine where
void Pond :: cast(){
	int baitRow = man.locRow + (rand()%(2* man.castDistance +1)-man.castDistance);
	int baitCol = man.locCol + (rand()%(2* man.castDistance +1)-man.castDistance);

  // this returns if the cast is out of bounds preventing the line from going out of the pond
	if (!checkBounds(baitRow, baitCol)){return;}
	
	//This method iterates through the vector from head, it is designed to remove the older fish first
	// this prevents checking for fish if nothing is located in that position
	if (grid[baitRow][baitCol]!=' '){
		for(vector<Fish>::iterator f = fishpop.begin(); f!= fishpop.end(); f++){ //need an iterator for vect.erase
			
			if(baitRow == f->locRow && baitCol ==f->locCol && f->hunger >= man.bait){
				cout << "You landed a "<< f->weight<<" oz Fish!\n";
				if (f->weight > 20){
					cout << "Put the fish in your livewell\n"; 
					// no container or livewell created
					fishpop.erase(f);
					return;
				}else {
					cout << "You release the fish that was too small\n";
					return; //catch one fish per worm and keeps only if it is not a small fish
				}
			}
		}
	}
	return;
}

// This casts the fishing pole a random distance from the man location
// This casts the line and uses the input as the location.
void Pond :: cast(int row, int col){
	int baitRow = row;
	int baitCol = col;
	
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




