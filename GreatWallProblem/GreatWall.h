#include <string>
#include <vector>
#include "DualHashTable.h"
#include "SLLDeque.h"
using namespace std;

class GreatWall {
    private:
		string inputDataPath;
        DualHashTable unsortedBricks; // container for unsorted bricks 
        SLLDeque sortedBricks;        // container for sorted bricks;

    public:
        GreatWall(const std::string& filePath);
		void readData(); // reads data from the input file into unsorted bricks list
		void sortBricks(); // sorts the data in the unsorted bricks list and stores it in the sorted bricks list
        void displaySortedBricks(ostream&) const; // displays the sorted bricks list to the console
        const DualHashTable& getUnsortedBricks() const { return unsortedBricks; }
        const SLLDeque& getSortedBricks() const { return sortedBricks; }
};