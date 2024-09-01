set(target tests)

add_executable(${target}
        tests.cc
)

target_link_libraries(${target}
        PRIVATE
        model
        controller
        utils
        GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${target})
