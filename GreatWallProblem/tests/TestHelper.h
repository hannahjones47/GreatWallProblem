#ifndef TESTHELPER_H
#define TESTHELPER_H
#include <string>
#include <vector>
using namespace std;

class TestHelper {
  public:
    static void requireFileExists(const string& filePath);
    static void runIntegrationTest(const string testCaseName, const string inputFilePath, const string expectedOutputFilePath);
    static const string testDataFilePath;
};

#endif // TESTHELPER_H