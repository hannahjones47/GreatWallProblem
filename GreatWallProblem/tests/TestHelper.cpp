#include "TestHelper.h"
#include "../include/GreatWall.h"
#include <fstream>
#include <boost/test/unit_test.hpp>
using namespace std;
using chrono::steady_clock;
using chrono::nanoseconds;
using chrono::duration_cast;

const string TestHelper::testDataFilePath = filesystem::path(__FILE__).parent_path().parent_path().string() + "/tests/TestData/";

void TestHelper::requireFileExists(const string& filePath) {
    ifstream file(filePath);
    BOOST_REQUIRE_MESSAGE(file.is_open(), "File not found: " << filePath);
    file.close();
}

long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; 
}

void TestHelper::runIntegrationTest(const string testCaseName, const string inputFilePath, const string expectedOutputFilePath) {
    cout << "Running test case: " << testCaseName << endl;
   
    TestHelper::requireFileExists(testDataFilePath + inputFilePath);
    TestHelper::requireFileExists(testDataFilePath + expectedOutputFilePath);

    steady_clock::time_point startTime = steady_clock::now();
    long memoryBefore = getMemoryUsage();

    GreatWall wall(testDataFilePath + inputFilePath);
    wall.sortBricks();

    stringstream actualOutputStream;
    wall.displaySortedBricks(actualOutputStream);

    steady_clock::time_point finishTime = steady_clock::now();
    nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);
    long memoryAfter = getMemoryUsage();
    long memoryUsed = memoryAfter - memoryBefore;
    cout << "> Test case: " << testCaseName << " took " << timeTaken.count() << " nanoseconds." << endl;
    cout << "> Test case: " << testCaseName << " used " << memoryUsed << " kilobytes." << endl;

    ifstream expectedFile(testDataFilePath + expectedOutputFilePath);
    stringstream expectedOutputStream;
    expectedOutputStream << expectedFile.rdbuf();
    expectedFile.close();

    BOOST_REQUIRE_MESSAGE(
        actualOutputStream.str() == expectedOutputStream.str(),
        "The contents of the output do not match for test case: " << testCaseName
    );
}

