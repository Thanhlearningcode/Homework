#include "System_Infor.h"
#include "Controller.h"
#include "View.h"
#include <unistd.h> 
int main() 
{
    /* Init model */
    Model_Infor model = {0};

    while(1)
    {
    Controller_Update_System(&model);

    /*Display information*/
    Display_Dashboard(&model);

    sleep(3);
    }
     return 0;
}
