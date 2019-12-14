//  Written By Scott J. Craig and Carrie E. Adkins
//  Finished 12/13/2019 11:30 pm
//  This is a fish simulation  rules listed in read me

#include <cstdlib>

using namespace std;

class Fish{
	
	public:
		Fish();
		Fish(int,int);
	//	~Fish();
		int locRow;
		int locCol;
		char size;
		int sex;
		int weight;
		int hunger;
		
		void setSize();
		void swim();
		void grow();
	
	private:
	/*	int locRow;
		int locCol;
		int size; 
		int hunger;
	//	int sex;
	*/
};
