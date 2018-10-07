include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(cpp_unittest_unittests_run
        validators/validator.cpp
        validators/validator_fixture.cpp)

target_link_libraries(cpp_unittest_unittests_run gtest gtest_main)
target_link_libraries(cpp_unittest_unittests_run cpp_unittest_src)
