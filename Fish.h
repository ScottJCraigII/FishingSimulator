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
		
		void swim();
	
	private:
	/*	int locRow;
		int locCol;
		int size; 
	*/	int hunger;
	//	int sex;
		
};
