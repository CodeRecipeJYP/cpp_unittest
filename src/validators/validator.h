//
// Created by Jaeyoung on 2018. 10. 7..
//

#ifndef CPP_UNITTEST_VALIDATOR_H
#define CPP_UNITTEST_VALIDATOR_H

#include <string>
#include <regex>

class Validator {
public:
    Validator(const std::string& rawRegex);
    ~Validator();

    bool isValid(const std::string& input);
    bool isValid(const char* input);

private:
    std::regex* validateRegex = nullptr;
};


#endif //CPP_UNITTEST_VALIDATOR_H
