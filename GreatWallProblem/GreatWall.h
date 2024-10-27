#include <string>
#include <vector>
#include "HashTable.h"
using namespace std;

class GreatWall {
    private:
		string inputDataPath;
        // HashTable unsortedBricks; // container for unsorted bricks // todo uncomment after testing
        // container for sorted bricks;

    public:
        HashTable unsortedBricks; // container for unsorted bricks // todo make private after testing
        GreatWall(const std::string& filePath);
		void readData(); // reads data from the input file into unsorted bricks list
		void sortBricks(); // sorts the data in the unsorted bricks list and stores it in the sorted bricks list
		string writeSortedBricksToFile() const; // writes the sorted bricks list to a file and returns the file path
        void displaySortedBricks() const; // displays the sorted bricks list to the console
};