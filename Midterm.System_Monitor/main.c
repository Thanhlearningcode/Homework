#include "System_Infor.h"
#include "Controller.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "Logger.h"

int main(void)
{
    /* Initialize model  */
    Model_Infor* model_monitor = (Model_Infor*)calloc(1, sizeof(Model_Infor));
    if (!model_monitor)
    {
        Log_Message(LOG_ERROR,"Failed to allocate memory for model_monitor\n");       
        return 1;
    }

    Logger_Init(LOG_INFO,"Log/log.txt");
    
    while (1)
    {   
        if (Controller_Update_System(model_monitor)!= MODEL_SUCCESS)
        {
            Log_Message(LOG_ERROR, "[Controller]- update failed\n\n");       
        }
        sleep(3); 
    }

    /* Clean up memory  */
    if (model_monitor)
    {
        free(model_monitor);
        model_monitor = NULL;
    }
    Logger_Close();

    return 0;
}
