#include "World.h"
#include "Pond.h"
//  #include "Fish.h"
#include <cstdlib>
#include <iostream>

#include <time.h>
using namespace std;

int main (int argc, char **argv){
	srand(time(NULL)); //seed for randomizer
	
	int seasonLength=3;
	int maxyears =5;
	int year=1;
	
	Pond pond;
	cout <<" Pond built and ready to fish!\n";
	
	while(year<=maxyears){
		cout << "Year "<< year<< " Fish in Pond "<< pond.fishpop.size()<<endl;
		while(pond.getDay() <= seasonLength){
			cout << "Day "<<pond.getDay()<<" of fishing!\n";
			pond.UpdateGrid();
			pond.PrintGrid();
			cout<<"Press Enter to end the Day\n";
			cin.ignore();
//			cout << "cin ignore\n";
			pond.endDay();
			cout << "Pond end day\n";
		}
		cout << "Pond end year\n";
		pond.endSeason();
//		cout << "increment year\n";
		year++;
	}
	cout << "Thanks for playing\n";
	return 0;
}
