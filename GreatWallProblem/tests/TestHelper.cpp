#include "TestHelper.h"
#include "../include/GreatWall.h"
#include <fstream>
#include <boost/test/unit_test.hpp>
using namespace std;

const string TestHelper::testDataFilePath = filesystem::path(__FILE__).parent_path().parent_path().string() + "/tests/TestData/";

void TestHelper::requireFileExists(const string& filePath) {
    ifstream file(filePath);
    BOOST_REQUIRE_MESSAGE(file.is_open(), "File not found: " << filePath);
    file.close();
}

void TestHelper::runIntegrationTest(const string testCaseName, const string inputFilePath, const string expectedOutputFilePath) {
    cout << "Running test case: " << testCaseName << endl;

    TestHelper::requireFileExists(testDataFilePath + inputFilePath);
    TestHelper::requireFileExists(testDataFilePath + expectedOutputFilePath);

    GreatWall wall(testDataFilePath + inputFilePath);
    wall.sortBricks();

    stringstream actualOutputStream;
    wall.displaySortedBricks(actualOutputStream);

    ifstream expectedFile(testDataFilePath + expectedOutputFilePath);
    stringstream expectedOutputStream;
    expectedOutputStream << expectedFile.rdbuf();
    expectedFile.close();

    BOOST_REQUIRE_MESSAGE(
        actualOutputStream.str() == expectedOutputStream.str(),
        "The contents of the output do not match for test case: " << testCaseName
    );
}