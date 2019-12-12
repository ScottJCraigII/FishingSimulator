#include "World.h"
#include "Pond.h"
//  #include "Fish.h"
#include <cstdlib>
#include <iostream>

#include <time.h>
using namespace std;

int main (int argc, char **argv){
	srand(time(NULL)); //seed for randomizer
	
	int seasonLength=5;
	
	Pond pond;
	cout <<"Pond built and ready to fish!\n";
	while(pond.getDay() <= seasonLength){
		cout << "Day "<<pond.getDay()<<" of fishing!\n";
		pond.UpdateGrid();
		pond.PrintGrid();
		cout<<"Press Enter to end the Day";
		cin.ignore();
		pond.endDay();
	}
	return 0;
}
