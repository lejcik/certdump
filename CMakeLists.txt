cmake_minimum_required(VERSION 3.14)
project(CertDump VERSION 1.4.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# dependencies
include(GNUInstallDirs)
find_package(OpenSSL 3.0 REQUIRED)

# sources
add_subdirectory(src)

# unit tests
option(BUILD_TESTING "Build tests" OFF)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

# Install targets
install(TARGETS certdump
    EXPORT CertDumpTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install headers
install(DIRECTORY include/certdump
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
