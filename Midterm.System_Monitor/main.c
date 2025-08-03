#include "System_Infor.h"
#include "Controller.h"
#include "View.h"
#include <unistd.h> 
int main() {
    // Khởi tạo model
    Model_Infor model = {0};
    while(1)
    {
    // Controller cập nhật dữ liệu hệ thống
    Controller_Update_System(&model);

    // View hiển thị dữ liệu ra dashboard
    Display_Dashboard(&model);

    sleep(3);
    }
     return 0;
}
