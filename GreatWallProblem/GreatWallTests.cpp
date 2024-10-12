#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "GreatWall.h"
#include <fstream>
using namespace std;

const string testDataFilePath = "../TestData/";

void readExpectedOutput(const string& filePath, vector<string>& expectedOutput) {
    ifstream inFile(filePath);
    string line;
    while (getline(inFile, line)) {
        expectedOutput.push_back(line);
    }
}

void checkFileExists(const string& filePath) {
    ifstream file(filePath);
    BOOST_REQUIRE_MESSAGE(file.is_open(), "File not found: " << filePath);
    file.close();
}

BOOST_AUTO_TEST_SUITE( TestDataSuite )

BOOST_AUTO_TEST_CASE( Test1KBricks ) {
    // arrange
    const string inputFilePath = testDataFilePath + "1K/input-pairs-1K.txt";
    const string expectedOutputFilePath = testDataFilePath + "1K/result-sequence-1K.txt";

    checkFileExists(inputFilePath); 
    checkFileExists(expectedOutputFilePath);

    // act
    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();
    vector<string> actualOutput = wall.getSortedBricks();

    // assert
    vector<string> expectedOutput;
    readExpectedOutput(expectedOutputFilePath, expectedOutput);

    BOOST_CHECK_EQUAL_COLLECTIONS(
        expectedOutput.begin(), expectedOutput.end(),
        actualOutput.begin(), actualOutput.end()
    );
}

BOOST_AUTO_TEST_SUITE_END()