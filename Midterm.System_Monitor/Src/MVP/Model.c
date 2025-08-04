#include "Model.h"
#include <time.h>
#include <unistd.h>
#include <string.h>

Model_Status Model_Process(Model_Infor* model)
{
    if (!model)
    {
        return MODEL_ERROR;
    }

         /*Simulate CPU data*/ 
    model->cpu.used = 30.5 + rand() % 50;
    model->cpu.hz = 3.2;
    model->cpu.temp = 50.0 + rand() % 30;

    const char* cpu_processes[] = {"leagueoflegends", "chrome", "zoom", "terminal", "vscode"};
    for (int i = 0; i < CPU_TOP_PROCESS_NUMBERS; i++)
    {
        strncpy(model->cpu.top_process[i], cpu_processes[i], sizeof(model->cpu.top_process[i]) - 1);
        model->cpu.top_process[i][sizeof(model->cpu.top_process[i]) - 1] = '\0'; // ensure null-termination
    }

          /*Simulate RAM data*/ 
    model->mem.ram_used = 1024 + rand() % 4096;
    model->mem.cache = 256 + rand() % 1024;
    model->mem.swap = 128 + rand() % 512;

    const char* ram_processes[] = {"video", "vlc", "steam", "obs", "editor"};
    for (int i = 0; i < RAM_TOP_PROCESS_NUMBERS; i++)
    {
        strncpy(model->mem.top_process[i], ram_processes[i], sizeof(model->mem.top_process[i]) - 1);
        model->mem.top_process[i][sizeof(model->mem.top_process[i]) - 1] = '\0';
    }

         /*Simulate storage data*/ 
    model->storage.used = 100 + rand() % 300;
    model->storage.free = 500 - model->storage.used;
    model->storage.read_speed = 50 + rand() % 100;
    model->storage.write_speed = 40 + rand() % 100;
    model->storage.IOPS = 1000 + rand() % 1000;

          /*Simulate network data*/ 
    model->network.upload_speed = rand() % 1000;
    model->network.download_speed = 500 + rand() % 1500;
    model->network.num_connections = rand() % 100;

    strncpy(model->network.ip_address[0], "192.168.1.100", sizeof(model->network.ip_address[0]) - 1);
    model->network.ip_address[0][sizeof(model->network.ip_address[0]) - 1] = '\0';

          /*Simulate system data*/ 
    model->sytem.uptime += 1;
    strncpy(model->sytem.kernel_version, "6.5.0-31-generic", sizeof(model->sytem.kernel_version) - 1);
    model->sytem.kernel_version[sizeof(model->sytem.kernel_version) - 1] = '\0';
    
    model->sytem.load_avg[0] = (float)(rand() % 100) / 100.0;
    model->sytem.load_avg[1] = (float)(rand() % 100) / 100.0;
    model->sytem.load_avg[2] = (float)(rand() % 100) / 100.0;

    return MODEL_SUCCESS;
}
