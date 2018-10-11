//
// Created by Jaeyoung on 2018. 10. 11..
//
#include <detector/url_detector.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::ElementsAre;
using namespace std;


void printVector(vector<int>* vct) {
    for (auto i = vct->begin(); i != vct->end(); ++i) {
        cout << (*i) << ", ";
    }
}

TEST(detector, sanity_test) {
    EXPECT_EQ(1, 1);
}

TEST(detector, test_url) {
    Detector* detectorInstance = new Detector();
    const char *query = "abc http://www.naver.com/ ";

    std::vector<int>* actual = detectorInstance->detectFromQuery(query);
//
//    cout << endl;
//    printVector(actual);
//    cout << endl;

    ASSERT_THAT(*actual, ElementsAre(4));
}

//TEST(detector, test_url_and_pn) {
//    Detector* detectorInstance = new Detector();
//    const char *query = "abc http://www.naver.com/50-50 50-50";
//
//    std::vector<int>* actual = detectorInstance->detectFromQuery(query);
//
//    ASSERT_THAT(*actual, ElementsAre(0, 1));
//}

TEST(detector, test_korean_charactor) {
    Detector* detectorInstance = new Detector();
    const char *query = "ㅎㅏㄴ글 도 되니 http://www.naver.com/50-50 50-50 https://www.naver.com/";

    std::vector<int>* actual = detectorInstance->detectFromQuery(query);
//
//    cout << endl;
//    printVector(actual);
//    cout << endl;

    ASSERT_THAT(*actual, ElementsAre(0, 1));
}
