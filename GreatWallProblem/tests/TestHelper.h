#ifndef TESTHELPER_H
#define TESTHELPER_H

#include <string>
#include <vector>
using namespace std;

class TestHelper {
public:
    static void checkFileExists(const string& filePath);
    static bool compareFiles(const string& filePath1, const string& filePath2);
};

#endif // TESTHELPER_H