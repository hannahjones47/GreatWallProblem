#define BOOST_TEST_MODULE GreatWallTests
#include <boost/test/included/unit_test.hpp>
#include "../include/GreatWall.h"
#include "TestHelper.h"
#include <fstream>
#include <cstdlib>
using namespace std;

BOOST_AUTO_TEST_SUITE(IntegrationTests)

BOOST_AUTO_TEST_CASE(Test_20) {
    TestHelper::runIntegrationTest("20", "20/input-pairs-20.txt", "20/result-sequence-20.txt");
}

BOOST_AUTO_TEST_CASE(Test_50) {
    TestHelper::runIntegrationTest("50", "50/input-pairs-50.txt", "50/result-sequence-50.txt");
}

BOOST_AUTO_TEST_CASE(Test_100) {
    TestHelper::runIntegrationTest("100", "100/input-pairs-100.txt", "100/result-sequence-100.txt");
}

BOOST_AUTO_TEST_CASE(Test_200) {
    TestHelper::runIntegrationTest("200", "200/input-pairs-200.txt", "200/result-sequence-200.txt");
}

BOOST_AUTO_TEST_CASE(Test_500) {
    TestHelper::runIntegrationTest("500", "500/input-pairs-500.txt", "500/result-sequence-500.txt");
}

BOOST_AUTO_TEST_CASE(Test_1K) {
    TestHelper::runIntegrationTest("1K", "1K/input-pairs-1K.txt", "1K/result-sequence-1K.txt");
}

BOOST_AUTO_TEST_CASE(Test_2K) {
    TestHelper::runIntegrationTest("2K", "2K/input-pairs-2K.txt", "2K/result-sequence-2K.txt");
}

BOOST_AUTO_TEST_CASE(Test_5K) {
    TestHelper::runIntegrationTest("5K", "5K/input-pairs-5K.txt", "5K/result-sequence-5K.txt");
}

BOOST_AUTO_TEST_CASE(Test_10K) {
    TestHelper::runIntegrationTest("10K", "10K/input-pairs-10K.txt", "10K/result-sequence-10K.txt");
}

BOOST_AUTO_TEST_CASE(Test_20K) {
    TestHelper::runIntegrationTest("20K", "20K/input-pairs-20K.txt", "20K/result-sequence-20K.txt");
}

BOOST_AUTO_TEST_CASE(Test_50K) {
    TestHelper::runIntegrationTest("50K", "50K/input-pairs-50K.txt", "50K/result-sequence-50K.txt");
}

BOOST_AUTO_TEST_CASE(Test_100K) {
    TestHelper::runIntegrationTest("100K", "100K/input-pairs-100K.txt", "100K/result-sequence-100K.txt");
}

BOOST_AUTO_TEST_CASE(Test_200K) {
    TestHelper::runIntegrationTest("200K", "200K/input-pairs-200K.txt", "200K/result-sequence-200K.txt");
}

BOOST_AUTO_TEST_CASE(Test_500K) {
    TestHelper::runIntegrationTest("500K", "500K/input-pairs-500K.txt", "500K/result-sequence-500K.txt");
}

BOOST_AUTO_TEST_CASE(Test_1M) {
    TestHelper::runIntegrationTest("1M", "1M/input-pairs-1M.txt", "1M/result-sequence-1M.txt");
}

BOOST_AUTO_TEST_CASE(Test_2M) {
    TestHelper::runIntegrationTest("2M", "2M/input-pairs-2M.txt", "2M/result-sequence-2M.txt");
}

BOOST_AUTO_TEST_CASE(Test_3M) {
    TestHelper::runIntegrationTest("3M", "3M/input-pairs-3M.txt", "3M/result-sequence-3M.txt");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(UnitTests)

BOOST_AUTO_TEST_CASE(ReadDataTest) {
    const string inputFilePath = TestHelper::testDataFilePath + "20/input-pairs-20.txt";
    TestHelper::requireFileExists(inputFilePath);

    GreatWall wall(inputFilePath);

    BOOST_CHECK_EQUAL(wall.getUnsortedBricks().size(), 19);
    BOOST_CHECK_EQUAL(wall.getUnsortedBricks().size(), 19);

    const string* firstValue = wall.getUnsortedBricks().lookupEast("mgR");
    BOOST_CHECK(firstValue != nullptr);
    BOOST_CHECK_EQUAL(*firstValue, "fYI");

    const string* middleValue = wall.getUnsortedBricks().lookupWest("SXW");
    BOOST_CHECK(middleValue != nullptr);
    BOOST_CHECK_EQUAL(*middleValue, "LYd");

    const string* lastValue = wall.getUnsortedBricks().lookupEast("BSC");
    BOOST_CHECK(lastValue != nullptr);
    BOOST_CHECK_EQUAL(*lastValue, "yxv");

    const string* nonExistentValue = wall.getUnsortedBricks().lookupEast("nonexistent");
    BOOST_CHECK(nonExistentValue == nullptr);
}

BOOST_AUTO_TEST_CASE(SortBricksTest) {
    const string inputFilePath = TestHelper::testDataFilePath + "20/input-pairs-20.txt";
    TestHelper::requireFileExists(inputFilePath);

    GreatWall wall(inputFilePath);
    wall.sortBricks();

    BOOST_CHECK_EQUAL(wall.getSortedBricks().getSize(), 20);

    BOOST_CHECK_EQUAL(wall.getSortedBricks().getHead()->data, "XLM");
    BOOST_CHECK_EQUAL(wall.getSortedBricks().getTail()->data, "Ohe");
}

BOOST_AUTO_TEST_CASE(DisplaySortedBricksTest) {
    const string inputFilePath = TestHelper::testDataFilePath + "1K/input-pairs-1K.txt";
    const string expectedOutputFilePath = TestHelper::testDataFilePath + "1K/result-sequence-1K.txt";

    TestHelper::requireFileExists(inputFilePath);
    TestHelper::requireFileExists(expectedOutputFilePath);

    GreatWall wall(inputFilePath);
    wall.sortBricks();

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    wall.displaySortedBricks(cout);
    cout.rdbuf(oldCout);

    ifstream expectedFile(expectedOutputFilePath);
    stringstream expectedOutputStream;
    expectedOutputStream << expectedFile.rdbuf();
    expectedFile.close();

    BOOST_CHECK_EQUAL(buffer.str(), expectedOutputStream.str());
}

BOOST_AUTO_TEST_SUITE_END()