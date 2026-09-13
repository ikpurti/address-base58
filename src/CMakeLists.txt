add_library(engine STATIC engine.cpp)
target_include_directories(engine PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(address-base58 main.cpp)
target_link_libraries(address-base58 PRIVATE engine)
