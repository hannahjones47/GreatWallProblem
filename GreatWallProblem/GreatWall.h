#include <string>
#include <vector>
using namespace std;

class GreatWall {
    private:
		string inputDataPath;
		std::vector<std::pair<std::string, std::string>> unsortedBricks;
        std::vector<std::pair<std::string, std::string>> sortedBricks;

    public:
        GreatWall(const std::string& filePath);
		void readData();
		void sortBricks();
		const vector<int>& getSortedBricks() const;
        void displaySortedBricks();
		void createOutputFile(const string& outputPath) const;
};