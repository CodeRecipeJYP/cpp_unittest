//
// Created by Jaeyoung on 2018. 10. 12..
//

#ifndef CPP_UNITTEST_DETECTED_PLACEHOLDER_H
#define CPP_UNITTEST_DETECTED_PLACEHOLDER_H


class DetectedPlaceholder {
public:
    DetectedPlaceholder(const char *pRawWord, int type, int positionInSentence);
    virtual ~DetectedPlaceholder(void);
    bool operator == (const DetectedPlaceholder &detectedPlaceholder) const {
        return (m_pRawWord == detectedPlaceholder.m_pRawWord) &&
                (m_type == detectedPlaceholder.m_type) &&
                (m_positionInSentence == detectedPlaceholder.m_positionInSentence);
    }

    bool operator == (const DetectedPlaceholder *detectedPlaceholder) const {
        return (m_pRawWord == detectedPlaceholder->m_pRawWord) &&
               (m_type == detectedPlaceholder->m_type) &&
               (m_positionInSentence == detectedPlaceholder->m_positionInSentence);
    }

    const char* getRawWord() {
        return m_pRawWord;
    }
    int getType() {
        return m_type;
    }
    int getPositionInSentence() {
        return m_positionInSentence;
    }

private:
    const char* m_pRawWord;
    int m_type;
    int m_positionInSentence;
};


#endif //CPP_UNITTEST_DETECTED_PLACEHOLDER_H
