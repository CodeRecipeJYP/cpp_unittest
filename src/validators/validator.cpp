//
// Created by Jaeyoung on 2018. 10. 7..
//

#include "validator.h"


Validator::Validator(const std::string& rawRegex) {
    validateRegex = new std::regex(rawRegex);
}

Validator::~Validator() {
    delete(validateRegex);
}

bool Validator::isValid(const std::string& input) {
    return std::regex_match(input, *validateRegex);
}
