#include "World.h"
#include "Pond.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main (int argc, char **argv){
	srand(time(NULL)); //seed for randomizer
	int dailyCasts = 10;
	int casts=0;
	int seasonLength=10;
	int maxyears =10;
	int year=1;
	
	Pond pond;
	cout <<" Pond built and ready to fish!\n";
	
	while(year<=maxyears){
		cout << "Year "<< year<< " Fish in Pond "<< pond.fishpop.size()<<endl;
		while(pond.getDay() <= seasonLength){
			cout << "Day "<<pond.getDay()<<" of fishing!\n";
			casts = 0;
			while(casts<dailyCasts){
				pond.sail(); 	//Rule Man1, Main interacts with pond so pond initiates man move
				pond.UpdateGrid();
				pond.PrintGrid();
				pond.cast();
				casts++;
			}
			cout<<"Press Enter to end the Day\n";
			cin.ignore();
			pond.endDay();
		}
		pond.endSeason();
		year++;
	}
	cout << "Thanks for playing\n";
	return 0;
}
