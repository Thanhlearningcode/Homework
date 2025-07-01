# Tìm GoogleTest
find_package(GTest REQUIRED)

# Tạo file chạy test
add_executable(led_driver_test led_driver_test.cpp)

# Link thư viện driver và GoogleTest
target_link_libraries(led_driver_test PRIVATE led_driver GTest::GTest GTest::Main pthread)
