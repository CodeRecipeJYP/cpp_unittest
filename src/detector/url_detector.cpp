//
// Created by Jaeyoung on 2018. 10. 11..
//

#include <iostream>
#include <validators/validator.h>
#include "url_detector.h"
using namespace std;


Detector::Detector() {

}

Detector::~Detector() {
}

std::vector<int>* Detector::detectFromQuery(const char *query) {
    auto * ret = new std::vector<int>();
    string query_as_string(query);

    auto* validator = new Validator("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w_\\.-]*)*\\/?");
//    auto* validator = new Validator("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})");
//    auto* validator = new Validator("/((([A-Za-z]{3,9}:(?:\\/\\/)?)(?:[-;:&=\\+\\$,\\w]+@)?[A-Za-z0-9.-]+|(?:www.|[-;:&=\\+\\$,\\w]+@)[A-Za-z0-9.-]+)((?:\\/[\\+~%\\/.\\w-_]*)?\\??(?:[-\\+=&;%@.\\w_]*)#?(?:[\\w]*))?)/");

    for (int i = 0; i < strlen(query); ++i) {
        const char* eachSubstring = (query + i);
        cout << "[idx: " << i << "]: " << eachSubstring << endl;

        if (validator->isValid(eachSubstring)) {
            cout << "isValid" << endl;
            ret->emplace_back(i);
        }
    }

    return ret;
}

