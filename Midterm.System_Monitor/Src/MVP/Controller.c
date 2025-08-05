#include "Model.h" 
#include "View.h"

Model_Status Controller_Update_System(Model_Infor* model)
{
    if (!model)
    {
        return MODEL_ERROR; 
    } 

    Model_Process(model);

    View_Display_Dashboard(model);

    return MODEL_SUCCESS;
}