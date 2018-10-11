//
// Created by Jaeyoung on 2018. 10. 7..
//
//
//#include <gtest/gtest.h>
//#include <validators/validator.h>
//
//class ValidatorFixture : public ::testing::Test {
//protected:
//    virtual void TearDown() {
//
//    }
//
//    virtual void SetUp() {
//
//    }
//
//public:
//    ValidatorFixture() : Test() {
//        validator = new Validator(std::string("[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*")
//                                  + "@"
//                                  + "[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}");
//    }
//
//    virtual ~ValidatorFixture() {
//        delete validator;
//    }
//
//    Validator* validator;
//};
//
//TEST_F(ValidatorFixture, check) {
//    EXPECT_TRUE(validator->isValid("abc@gmail.com"));
//}
