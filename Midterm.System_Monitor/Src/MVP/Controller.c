#include "Model.h" 

void Controller_Update_System(Model_Infor* model)
{
    if (!model) return;

    Model_Process(model);
}