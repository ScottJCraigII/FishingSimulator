#include <cstdlib>

using namespace std;
 
class Man{
	
	public:
		Man();
//		~Man();

		char person ='#';
		int bait;
		int locRow;
		int locCol;
		int castDistance;
		
		void move();
		void move(int,int);
		//void cast();
		void operator()(int, int);
		 
		
		
	private:
	//	char person='#';
	//	int bait;	
};
