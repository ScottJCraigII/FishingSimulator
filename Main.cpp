#include "World.h"
#include "Pond.h"
#include "Fish.h"
#include <cstdlib>

using namespace std;

int main (int argc, char **argv){
	
	Pond pond();
	pond.updateGrid();
	pond.printGrid();
	return 0;
}
