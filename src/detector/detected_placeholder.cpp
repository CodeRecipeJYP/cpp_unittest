//
// Created by Jaeyoung on 2018. 10. 12..
//

#include "detected_placeholder.h"
#include <string.h>

const char* _makeCopy(const char* target) {
    size_t rawWordLen = strlen(target);

    char *pTemp = new char[rawWordLen + 1];

    if (rawWordLen > 0) {
        strncpy(pTemp, target, rawWordLen);
    }

    pTemp[rawWordLen] = '\0';

    return pTemp;
}

DetectedPlaceholder::DetectedPlaceholder(const char *pRawWord, int type, int positionInSentence) {
    m_pRawWord = _makeCopy(pRawWord);
    m_type = type;
    m_positionInSentence = positionInSentence;
}

DetectedPlaceholder::~DetectedPlaceholder(void) {

}
