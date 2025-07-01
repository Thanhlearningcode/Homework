#include <gtest/gtest.h>

// Nói với compiler: những hàm này là C, không phải C++:
extern "C" {
#include "../Inc/Led_Driver.h"
}

TEST(LedDriverTest, InitCreatesZeroBuffer) {
    ASSERT_TRUE(Led_Init(10)); // bool
    const uint32_t* buf = Get_Led_Buffer();
    size_t count = Get_Count_Led_Pixel();
    ASSERT_EQ(count, 10u);

    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(buf[i], 0u);
    }

    Led_Shutdown();
}

TEST(LedDriverTest, SetPixelColorCorrectly) {
    Led_Init(10);
    Led_Set_Pixels_Colors(0, 255, 0, 0);     // Red
    Led_Set_Pixels_Colors(9, 0, 0, 255);     // Blue
    Led_Set_Pixels_Colors(4, 255, 255, 255); // White

    const uint32_t* buf = Get_Led_Buffer();
    EXPECT_EQ(buf[0], 0x0000FF00u);    // Red (G-R-B): G=0,R=255,B=0 → 0x00_00FF_00
    EXPECT_EQ(buf[4], 0x00FFFFFFu);    // White
    EXPECT_EQ(buf[9], 0x000000FFu);    // Blue

    Led_Shutdown();
}

TEST(LedDriverTest, FillAllPixelsWithGreen) {
    Led_Init(10);
    Led_Fill(0, 255, 0); // Green
    const uint32_t* buf = Get_Led_Buffer();
    for (size_t i = 0; i < Get_Count_Led_Pixel(); ++i) {
        EXPECT_EQ(buf[i], 0x00FF0000u); // G=255,R=0,B=0 → 0x00FF0000
    }
    Led_Shutdown();
}

TEST(LedDriverTest, OutOfRangeDoesNotCrash) {
    Led_Init(5);
    Led_Set_Pixels_Colors(100, 1, 2, 3); // index lớn
    Led_Set_Pixels_Colors(-1, 1, 2, 3);  // size_t -1 => số rất lớn
    // Chỉ cần không crash, test sẽ pass
    Led_Shutdown();
}
