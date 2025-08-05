#ifndef _MODEL_H_
#define _MODEL_H_

#include "System_Infor.h"
#include "Logger.h"

typedef enum 
{   
    MODEL_ERROR,
    MODEL_SUCCESS,
} Model_Status;

Model_Status Model_Process(Model_Infor* model);

#endif /*_MODEL_H_*/