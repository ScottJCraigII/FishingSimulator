#include <cstdlib>
#include <vector>
#include "Fish.h"
#include "World.h"
using namespace std; 

 class Pond : public World {
	 public:
		Pond();
//		~Pond();
		
		void PrintGrid();
		void UpdateGrid();
		
	 private:
		void initGrid();
		bool checkBounds(int,int);
		int row;
		int col;
		vector<Fish> fishpop;
 };
