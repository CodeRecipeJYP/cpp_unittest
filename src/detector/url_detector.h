//
// Created by Jaeyoung on 2018. 10. 11..
//

#ifndef CPP_UNITTEST_DETECTOR_H
#define CPP_UNITTEST_DETECTOR_H
#include <vector>
#include "detected_placeholder.h"

class Detector {
public:
    Detector();
    ~Detector();

    std::vector<int>* detectFromQuery(const char *query);
    std::vector<DetectedPlaceholder*>* detectFromQueryAndReturnDetectedPlaceholder(const char *query);
};


#endif //CPP_UNITTEST_DETECTOR_H
