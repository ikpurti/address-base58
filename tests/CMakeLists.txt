add_executable(address-base58_tests test_core.cpp)
target_link_libraries(address-base58_tests PRIVATE engine)
target_include_directories(address-base58_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND address-base58_tests)
