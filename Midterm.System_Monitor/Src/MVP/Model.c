#include "Model.h"
#include <time.h>
#include <unistd.h> 

void Model_Process(Model_Infor* model)
{
    model->cpu.used = 30.5 + rand() % 50;        
    model->cpu.hz = 3.2;
    model->cpu.temp = 50.0 + rand() % 30;       
    strcpy(model->cpu.top_process[0], "firefox");

    model->mem.ram_used = 1024 + rand() % 4096;
    model->mem.cache = 256 + rand() % 1024;
    model->mem.swap = 128 + rand() % 512;
    strcpy(model->mem.top_process[0], "chrome");

    model->storage.used = 100 + rand() % 300;
    model->storage.free = 500 - model->storage.used;
    model->storage.read_speed = 50 + rand() % 100;
    model->storage.write_speed = 40 + rand() % 100;
    model->storage.IOPS = 1000 + rand() % 1000;

    model->network.upload_speed = rand() % 1000;
    model->network.download_speed = 500 + rand() % 1500;
    model->network.num_connections = rand() % 100;
    strcpy(model->network.ip_address[0], "192.168.1.100");

    model->sytem.uptime += 1;  
    strcpy(model->sytem.kernel_version, "6.5.0-31-generic");
    model->sytem.load_avg[0] = (float)(rand() % 100) / 100.0;
    model->sytem.load_avg[1] = (float)(rand() % 100) / 100.0;
    model->sytem.load_avg[2] = (float)(rand() % 100) / 100.0;
}