//  Written By Scott J. Craig and Carrie E. Adkins
//  Finished 12/13/2019 11:30 pm
//  This is a fish simulation  rules listed in read me

#include <cstdlib>
#include <vector>
#include "Fish.h"
#include "World.h"
#include "Man.h"
#include <iostream>

using namespace std; 

 class Pond : public World {
		friend ostream& operator <<(ostream&, Pond&);
	 
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
		
		int getDay() const;
		
		void fixLocation(auto&);
//		void operator <<(ostream os);
		
	 private:
		void initGrid();
		bool checkBounds(int,int);
		int row;
		int col;
//		vector<Fish> fishpop;
 };
