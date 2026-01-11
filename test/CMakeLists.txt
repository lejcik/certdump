enable_testing()

find_package(GTest REQUIRED)

# unit-test executable

add_executable(certdump-test)

target_sources(certdump-test
    PRIVATE
        certdump-test.cpp
        utils.h
        utils.cpp
        pem-tests.cpp
        der-tests.cpp
)

target_link_libraries(certdump-test
    PRIVATE
        CertDump::certdump
        GTest::gtest
)

# define the test certificate directory full path
target_compile_definitions(certdump-test
    PRIVATE
        TEST_CERT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/certificates"
)

# run the tests

add_test(
    NAME certdump-test
    COMMAND $<TARGET_FILE:certdump-test>
)
