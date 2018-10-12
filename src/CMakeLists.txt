project(cpp_unittest_src)

set(SOURCE_FILES
        validators/validator.cpp)
set(HEADER_FILES
        validators/validator.h detector/url_detector.cpp detector/url_detector.h detector/detected_placeholder.cpp detector/detected_placeholder.h)

add_library(cpp_unittest_src STATIC ${SOURCE_FILES} ${HEADER_FILES})
