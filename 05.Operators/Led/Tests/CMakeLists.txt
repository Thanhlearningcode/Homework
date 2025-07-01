find_package(GTest REQUIRED)

add_executable(led_driver_test led_driver_test.cpp)

target_link_libraries(led_driver_test PRIVATE led_driver GTest::GTest GTest::Main pthread)
