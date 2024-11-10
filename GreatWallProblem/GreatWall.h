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
        bool sorted;                  // flag to indicate if the bricks have been sorted
        void readData();              // reads data from the input file into unsorted bricks list

    public:
        GreatWall(const string& filePath);
		void sortBricks(); // sorts the data in the unsorted bricks list and stores it in the sorted bricks list
        void displaySortedBricks(ostream&) const; // displays the sorted bricks list to the console
        const DualHashTable& getUnsortedBricks() const { return unsortedBricks; }
        const SLLDeque& getSortedBricks() const { return sortedBricks; }
};