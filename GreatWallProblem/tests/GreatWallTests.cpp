#define BOOST_TEST_MODULE GreatWallTests
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "../GreatWall.h"
#include "TestHelper.h"
#include <fstream>
#include <cstdlib>

using namespace std;
const string testDataFilePath = std::filesystem::path(__FILE__).parent_path().parent_path().string() + "/tests/TestData/";

void runIntegrationTest(const string testCaseName, const string inputFilePath, const string expectedOutputFilePath) {
    cout << "Running test case: " << testCaseName << endl;

    TestHelper::requireFileExists(testDataFilePath + inputFilePath);
    TestHelper::requireFileExists(testDataFilePath + expectedOutputFilePath);

    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();
    string actualOutputFilePath = wall.writeSortedBricksToFile();
    // todo delete file.

    BOOST_REQUIRE_MESSAGE(
        TestHelper::areFileContentsEqual(expectedOutputFilePath, actualOutputFilePath),
        "The contents of the files do not match for test case: " << testCaseName
    );
}

BOOST_AUTO_TEST_SUITE(IntegrationTests)

BOOST_AUTO_TEST_CASE(Test_20) {
    runIntegrationTest("20", "20/input-pairs-20.txt", "20/result-sequence-20.txt");
}

BOOST_AUTO_TEST_CASE(Test_50) {
    runIntegrationTest("50", "50/input-pairs-50.txt", "50/result-sequence-50.txt");
}

BOOST_AUTO_TEST_CASE(Test_100) {
    runIntegrationTest("100", "100/input-pairs-100.txt", "100/result-sequence-100.txt");
}

BOOST_AUTO_TEST_CASE(Test_200) {
    runIntegrationTest("200", "200/input-pairs-200.txt", "200/result-sequence-200.txt");
}

BOOST_AUTO_TEST_CASE(Test_500) {
    runIntegrationTest("500", "500/input-pairs-500.txt", "500/result-sequence-500.txt");
}

BOOST_AUTO_TEST_CASE(Test_1K) {
    runIntegrationTest("1K", "1K/input-pairs-1K.txt", "1K/result-sequence-1K.txt");
}

BOOST_AUTO_TEST_CASE(Test_2K) {
    runIntegrationTest("2K", "2K/input-pairs-2K.txt", "2K/result-sequence-2K.txt");
}

BOOST_AUTO_TEST_CASE(Test_5K) {
    runIntegrationTest("5K", "5K/input-pairs-5K.txt", "5K/result-sequence-5K.txt");
}

BOOST_AUTO_TEST_CASE(Test_10K) {
    runIntegrationTest("10K", "10K/input-pairs-10K.txt", "10K/result-sequence-10K.txt");
}

BOOST_AUTO_TEST_CASE(Test_20K) {
    runIntegrationTest("20K", "20K/input-pairs-20K.txt", "20K/result-sequence-20K.txt");
}

BOOST_AUTO_TEST_CASE(Test_50K) {
    runIntegrationTest("50K", "50K/input-pairs-50K.txt", "50K/result-sequence-50K.txt");
}

BOOST_AUTO_TEST_CASE(Test_100K) {
    runIntegrationTest("100K", "100K/input-pairs-100K.txt", "100K/result-sequence-100K.txt");
}

BOOST_AUTO_TEST_CASE(Test_200K) {
    runIntegrationTest("200K", "200K/input-pairs-200K.txt", "200K/result-sequence-200K.txt");
}

BOOST_AUTO_TEST_CASE(Test_500K) {
    runIntegrationTest("500K", "500K/input-pairs-500K.txt", "500K/result-sequence-500K.txt");
}

BOOST_AUTO_TEST_CASE(Test_1M) {
    runIntegrationTest("1M", "1M/input-pairs-1M.txt", "1M/result-sequence-1M.txt");
}

BOOST_AUTO_TEST_CASE(Test_2M) {
    runIntegrationTest("2M", "2M/input-pairs-2M.txt", "2M/result-sequence-2M.txt");
}

BOOST_AUTO_TEST_CASE(Test_3M) {
    runIntegrationTest("3M", "3M/input-pairs-3M.txt", "3M/result-sequence-3M.txt");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(UnitTests)

BOOST_AUTO_TEST_CASE(ReadDataTest) {
    const string inputFilePath = testDataFilePath + "20/input-pairs-20.txt";
    GreatWall wall(inputFilePath);
    wall.readData();
    // todo assert that list of unsorted bricks has a length of 20
    // todo assert that the the first brick is mgR,fYI
    // todo assert that the the last brick is BSC,yxv
}

BOOST_AUTO_TEST_CASE(SortBricksTest) {
    const string inputFilePath = testDataFilePath + "20/input-pairs-20.txt";
    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();
    // todo assert that the list of sorted bricks has a length of 20
    // todo assert that the first brick is XLM
    // todo assert that the last brick is Ohe
}

BOOST_AUTO_TEST_CASE(DisplaySortedBricksTest) {
    const string inputFilePath = testDataFilePath + "1K/input-pairs-1K.txt";
    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    wall.displaySortedBricks();
    cout.rdbuf(oldCout);
    
    // todo assert that the output is correct
}

BOOST_AUTO_TEST_CASE(WriteSortedBricksToFileTest) {
    const string inputFilePath = testDataFilePath + "1K/input-pairs-1K.txt";
    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();
    string outputFilePath = wall.writeSortedBricksToFile();
    // todo assertions to verify that the file is written correctly
    TestHelper::requireFileExists(outputFilePath);
}

BOOST_AUTO_TEST_SUITE_END()