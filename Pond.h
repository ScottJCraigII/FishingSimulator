#include <cstdlib>
#include <vector>
#include "Fish.h"
#include "World.h"
#include "Man.h"

using namespace std; 

 class Pond : public World {
	 public:
		Pond();
//		~Pond();
		vector<Fish> fishpop;
		Man man;
		
		void PrintGrid();
		void UpdateGrid();
		
		void endDay();
		void endSeason();
		
		void sail();
		void cast();
		void cast (int,int);
		
		int getDay();
		
		void fixLocation(auto&);
		
	 private:
		void initGrid();
		bool checkBounds(int,int);
		int row;
		int col;
//		vector<Fish> fishpop;
 };
