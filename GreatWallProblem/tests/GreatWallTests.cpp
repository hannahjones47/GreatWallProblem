#define BOOST_TEST_MODULE GreatWallIntegrationTests
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "../GreatWall.h"
#include "TestHelper.h"
#include <fstream>
#include <cstdlib>

using namespace std;
const string testDataFilePath = std::filesystem::path(__FILE__).parent_path().parent_path().string() + "/tests/TestData/";

void runTest(const string testCaseName, const string inputFilePath, const string expectedOutputFilePath) {
    cout << "Running test case: " << testCaseName << endl;

    TestHelper::checkFileExists(testDataFilePath + inputFilePath);
    TestHelper::checkFileExists(testDataFilePath + expectedOutputFilePath);

    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();
    string actualOutputFilePath = wall.writeSortedBricksToFile();

    BOOST_REQUIRE_MESSAGE(
        TestHelper::compareFiles(expectedOutputFilePath, actualOutputFilePath),
        "The contents of the files do not match for test case: " << testCaseName
    );
}

BOOST_AUTO_TEST_SUITE(InputOutputTests)

BOOST_AUTO_TEST_CASE(Test_20) {
    runTest("20", "20/input-pairs-20.txt", "20/result-sequence-20.txt");
}

BOOST_AUTO_TEST_CASE(Test_50) {
    runTest("50", "50/input-pairs-50.txt", "50/result-sequence-50.txt");
}

BOOST_AUTO_TEST_CASE(Test_100) {
    runTest("100", "100/input-pairs-100.txt", "100/result-sequence-100.txt");
}

BOOST_AUTO_TEST_CASE(Test_200) {
    runTest("200", "200/input-pairs-200.txt", "200/result-sequence-200.txt");
}

BOOST_AUTO_TEST_CASE(Test_500) {
    runTest("500", "500/input-pairs-500.txt", "500/result-sequence-500.txt");
}

BOOST_AUTO_TEST_CASE(Test_1K) {
    runTest("1K", "1K/input-pairs-1K.txt", "1K/result-sequence-1K.txt");
}

BOOST_AUTO_TEST_CASE(Test_2K) {
    runTest("2K", "2K/input-pairs-2K.txt", "2K/result-sequence-2K.txt");
}

BOOST_AUTO_TEST_CASE(Test_5K) {
    runTest("5K", "5K/input-pairs-5K.txt", "5K/result-sequence-5K.txt");
}

BOOST_AUTO_TEST_CASE(Test_10K) {
    runTest("10K", "10K/input-pairs-10K.txt", "10K/result-sequence-10K.txt");
}

BOOST_AUTO_TEST_CASE(Test_20K) {
    runTest("20K", "20K/input-pairs-20K.txt", "20K/result-sequence-20K.txt");
}

BOOST_AUTO_TEST_CASE(Test_50K) {
    runTest("50K", "50K/input-pairs-50K.txt", "50K/result-sequence-50K.txt");
}

BOOST_AUTO_TEST_CASE(Test_100K) {
    runTest("100K", "100K/input-pairs-100K.txt", "100K/result-sequence-100K.txt");
}

BOOST_AUTO_TEST_CASE(Test_200K) {
    runTest("200K", "200K/input-pairs-200K.txt", "200K/result-sequence-200K.txt");
}

BOOST_AUTO_TEST_CASE(Test_500K) {
    runTest("500K", "500K/input-pairs-500K.txt", "500K/result-sequence-500K.txt");
}

BOOST_AUTO_TEST_CASE(Test_1M) {
    runTest("1M", "1M/input-pairs-1M.txt", "1M/result-sequence-1M.txt");
}

BOOST_AUTO_TEST_CASE(Test_2M) {
    runTest("2M", "2M/input-pairs-2M.txt", "2M/result-sequence-2M.txt");
}

BOOST_AUTO_TEST_CASE(Test_3M) {
    runTest("3M", "3M/input-pairs-3M.txt", "3M/result-sequence-3M.txt");
}

BOOST_AUTO_TEST_SUITE_END()