#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "../GreatWall.h"
#include "TestHelper.h"
#include <fstream>
#include <cstdlib>

//todo check now for more test data files?
using namespace std;
const string testDataFilePath = std::filesystem::path(__FILE__).parent_path().parent_path().string() + "/tests/TestData/";

BOOST_AUTO_TEST_SUITE( TestDataSuite )

BOOST_AUTO_TEST_CASE( Test1KBricks ) {

    const string inputFilePath = testDataFilePath + "1K/input-pairs-1K.txt";
    const string expectedOutputFilePath = testDataFilePath + "1K/result-sequence-1K.txt";

    TestHelper::checkFileExists(inputFilePath); 
    TestHelper::checkFileExists(expectedOutputFilePath);

    GreatWall wall(inputFilePath);
    wall.readData();
    wall.sortBricks();
    string actualOutputFilePath = wall.writeSortedBricksToFile();

    BOOST_REQUIRE_MESSAGE(
        TestHelper::compareFiles(expectedOutputFilePath, actualOutputFilePath),
        "The contents of the files do not match"
    );
}

BOOST_AUTO_TEST_SUITE_END()