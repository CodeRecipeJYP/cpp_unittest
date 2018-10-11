//
// Created by Jaeyoung on 2018. 10. 7..
//

#include <iostream>
#include "validator.h"
using namespace std;

Validator::Validator(const std::string& rawRegex) {
    validateRegex = new std::regex(rawRegex);
}

Validator::~Validator() {
    delete(validateRegex);
}

bool Validator::isValid(const std::string& input) {
    return std::regex_match(input, *validateRegex);
}

bool Validator::isValid(const char *input) {
    std::smatch m;
//    std::regex_match(input, *validateRegex);
    string input_as_string(input);
    bool ret = std::regex_search(input_as_string, m, *validateRegex);

    if (ret) {
        cout << m.length() << endl;
        cout << input_as_string.substr(0, static_cast<unsigned long>(m.length())) << endl;
    }
    return ret;
}
