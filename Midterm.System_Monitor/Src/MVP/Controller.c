#include "Model.h" 
#include "View.h"

Model_Status Controller_Update_System(Model_Infor* model)
{
    if (!model)
    {   
        Log_Message(LOG_ERROR,"[Controllẻ]-Model no exist\n");
        return MODEL_ERROR; 
    } 

    if (Model_Process(model) != MODEL_SUCCESS)
    {
        Log_Message(LOG_WARNING, "Controller_Update_System: Model_Process failed\n");
    }

    View_Display_Dashboard(model);

    return MODEL_SUCCESS;
}