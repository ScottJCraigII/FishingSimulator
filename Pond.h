using namespace std;
 class Pond : public World {
	 public:
		Pond {};
		~Pond {};
		
		void PrintGrid();
		void UpdateGrid();
		
	 private:
		void initGrid();
		bool checkBounds();
		
 };
