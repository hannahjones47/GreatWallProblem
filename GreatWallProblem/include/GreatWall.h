#include <string>
#include "DoubleHashTable.h"
#include "SLLDeque.h"
using namespace std;

class GreatWall {
  private:
    string inputDataPath_;
    DoubleHashTable unsortedBricks_; // container for unsorted bricks 
    SLLDeque sortedBricks_;          // container for sorted bricks
    bool sorted_;                    // flag to indicate if the bricks have been sorted
    void readData();                 // reads data from the input file into unsorted bricks list

  public:
    GreatWall(const string& filePath);
    void sortBricks();                        // sorts the data in the unsorted bricks list and stores it in the sorted bricks list
    void displaySortedBricks(ostream&) const; // displays the sorted bricks list to the console
    const DoubleHashTable& getUnsortedBricks() const { return unsortedBricks_; }
    const SLLDeque& getSortedBricks() const { return sortedBricks_; }
};