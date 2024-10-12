#include "TestHelper.h"
#include <fstream>
#include <boost/test/unit_test.hpp>

void TestHelper::checkFileExists(const string& filePath) {
    ifstream file(filePath);
    BOOST_REQUIRE_MESSAGE(file.is_open(), "File not found: " << filePath);
    file.close();
}

bool TestHelper::compareFiles(const string& filePath1, const string& filePath2) {
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    string line1, line2;
    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            return false;
        }
    }

    return file1.eof() && file2.eof();
}