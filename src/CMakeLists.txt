# Create library target
add_library(certdump STATIC)

# Add alias for namespaced access
add_library(CertDump::certdump ALIAS certdump)

target_sources(certdump
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/certdump/certdump.h
    PRIVATE
        certdump.cpp
        openssl_helpers.cpp
        openssl_helpers.h
)

target_link_libraries(certdump
    PRIVATE
        OpenSSL::Crypto
        OpenSSL::SSL
)

# Set include directories
target_include_directories(certdump
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include/certdump
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
