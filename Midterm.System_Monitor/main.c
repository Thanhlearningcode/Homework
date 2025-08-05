#include "System_Infor.h"
#include "Controller.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    /* Initialize model  */
    Model_Infor* model_monitor = (Model_Infor*)calloc(1, sizeof(Model_Infor));
    if (!model_monitor)
    {
        fprintf(stderr, "Failed to allocate memory for model_monitor\n");
        return 1;
    }

    while (1)
    {
        Controller_Update_System(model_monitor);
        sleep(3);
    }

    /* Clean up memory  */
    if (model_monitor)
    {
        free(model_monitor);
        model_monitor = NULL;
    }

    return 0;
}
