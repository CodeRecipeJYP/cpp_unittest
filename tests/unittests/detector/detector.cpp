//
// Created by Jaeyoung on 2018. 10. 11..
//
#include <detector/url_detector.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;


void printVector(vector<int>* vct) {
    for (auto i = vct->begin(); i != vct->end(); ++i) {
        cout << (*i) << ", ";
    }
}

TEST(detector, sanity_test) {
    EXPECT_EQ(1, 1);
}
//
//TEST(detector, test_url) {
//    Detector* detectorInstance = new Detector();
//    const char *query = "abc http://www.naver.com/ ";
//
//    std::vector<int>* actual = detectorInstance->detectFromQuery(query);
////
////    cout << endl;
////    printVector(actual);
////    cout << endl;
//
//    ASSERT_THAT(*actual, ElementsAre(4));
//}

TEST(detector, test_url2) {
    Detector* detectorInstance = new Detector();
    const char *query = "abc http://www.naver.com/ ";

    std::vector<DetectedPlaceholder*>* actual = detectorInstance->detectFromQueryAndReturnDetectedPlaceholder(query);
//
//    cout << endl;
//    printVector(actual);
//    cout << endl;


    DetectedPlaceholder* expected = new DetectedPlaceholder("http://www.naver.com/", 0, 4);
    cout << "expected: " << expected->getRawWord() << endl;
    cout << "actual: " << (*actual)[0]->getRawWord() << endl;
    cout << "expected: " << expected->getType() << endl;
    cout << "actual: " << (*actual)[0]->getType() << endl;
    cout << "expected: " << expected->getPositionInSentence() << endl;
    cout << "actual: " << (*actual)[0]->getPositionInSentence() << endl;

    DetectedPlaceholder* a = (*actual)[0];
    ASSERT_THAT(*a, Eq(*expected));
}

//TEST(detector, test_url_and_pn) {
//    Detector* detectorInstance = new Detector();
//    const char *query = "abc http://www.naver.com/50-50 50-50";
//
//    std::vector<int>* actual = detectorInstance->detectFromQuery(query);
//
//    ASSERT_THAT(*actual, ElementsAre(0, 1));
//}

//TEST(detector, test_korean_charactor) {
//    Detector* detectorInstance = new Detector();
//    const char *query = "ㅎㅏㄴ글 도 되니 http://www.naver.com/50-50 50-50 https://www.naver.com/";
//
//    std::vector<int>* actual = detectorInstance->detectFromQuery(query);
////
////    cout << endl;
////    printVector(actual);
////    cout << endl;
//
//    ASSERT_THAT(*actual, ElementsAre(0, 1));
//}
