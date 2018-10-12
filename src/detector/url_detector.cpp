//
// Created by Jaeyoung on 2018. 10. 11..
//

#include <iostream>
#include <validators/validator.h>
#include "url_detector.h"
#include "detected_placeholder.h"

using namespace std;


Detector::Detector() {

}

Detector::~Detector() {
}

vector<int>* Detector::detectFromQuery(const char *query) {
    auto * ret = new vector<int>();
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

vector<DetectedPlaceholder *> *Detector::detectFromQueryAndReturnDetectedPlaceholder(const char *query) {
    auto * ret = new vector<DetectedPlaceholder*>();

    regex urlRegex("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w_\\.-]*)*\\/?");

    for (int i = 0; i < strlen(query); ) {
        const char* eachSubstring = (query + i);
        cout << "[idx: " << i << "]: " << eachSubstring << endl;

        std::smatch m;

        string eachSubstringAsString(eachSubstring);

        if (regex_search(eachSubstringAsString, m, urlRegex)) {
            cout << "isValid" << endl;
            ret->push_back(new DetectedPlaceholder(eachSubstringAsString.substr(0, m.length()).c_str(), 0, i));
            i += m.length();
        }
        i++;
    }

    return ret;
}
