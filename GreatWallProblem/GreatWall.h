#include <string>
#include <vector>
using namespace std;

class GreatWall {
    private:
		string inputDataPath;
		// container for unsorted bricks
        // container for sortedBricks;

    public:
        GreatWall(const std::string& filePath);
		void readData();
		void sortBricks();
		string writeSortedBricksToFile() const;
        void displaySortedBricks() const;
};