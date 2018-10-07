project(cpp_unittest_src)

set(SOURCE_FILES
        validators/validator.cpp)
set(HEADER_FILES
        validators/validator.h)

add_library(cpp_unittest_src STATIC ${SOURCE_FILES} ${HEADER_FILES})
