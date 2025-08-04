#ifndef _VIEW_H_
#define _VIEW_H_

#include "System_Infor.h"
//#include "Logger.h"

typedef enum 
{   
    VIEW_ERROR,
    VIEW_SUCCESS,
} View_Status;

View_Status View_Display_Dashboard(Model_Infor* model);

#endif /* _VIEW_H_*/