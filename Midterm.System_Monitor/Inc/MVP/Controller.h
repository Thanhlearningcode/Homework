#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "System_Infor.h"
#include "View.h"

typedef enum 
{   
    MODEL_ERROR,
    MODEL_SUCCESS,
} Model_Status;

Model_Status Controller_Update_System(Model_Infor* model);

#endif /*_CONTROLLER_H_*/

