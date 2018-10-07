//
// Created by Jaeyoung on 2018. 10. 7..
//

#include <validators/validator.h>
#include <gtest/gtest.h>


TEST(validator, testeq) {
    EXPECT_EQ(1, 1);
}

TEST(validator, nameofthetest1) {
    std::string rawEmailRegex = std::string("[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*")
                           + "@"
                           + "[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}";

    Validator emailValidator(rawEmailRegex);

    EXPECT_TRUE(emailValidator.isValid("swe@gmail.com"));
}

TEST(validator, nameofthetest2) {
    std::string rawEmailRegex = std::string("[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*")
                                + "@"
                                + "[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}";

    Validator emailValidator(rawEmailRegex);
    EXPECT_FALSE(emailValidator.isValid("swegmail.com"));
}
