#include <cstdlib>
using namespace std;

class Fish{
	
	public:
		Fish();
		Fish(int,int);
		~Fish();
		
	
	private:
		int locRow;
		int locCol;
		int size;
		int hunger;
		int sex;
		
};
