#include "World.h"
#include "Pond.h"
//  #include "Fish.h"
#include <cstdlib>
#include <iostream>

#include <time.h>
using namespace std;

int main (int argc, char **argv){
	srand(time(NULL)); //seed for randomizer

	Pond pond;
	cout <<"Main.cpp pond.fish vector size " <<pond.fishpop.size()<<endl;
	pond.UpdateGrid();
	pond.PrintGrid();
	return 0;
}
