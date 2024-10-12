#include <string>
#include <vector>
using namespace std;

class GreatWall {
    private:
		string inputDataPath;
		vector<pair<string, string>> unsortedBricks;
        vector<string> sortedBricks;

    public:
        GreatWall(const std::string& filePath);
		void readData();
		void sortBricks();
		const vector<string>& getSortedBricks() const;
        void displaySortedBricks();
};