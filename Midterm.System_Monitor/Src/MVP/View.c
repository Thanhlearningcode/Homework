#include "View.h"

View_Status View_Display_Dashboard(Model_Infor* model)
{
    if(!model)
    {
       Log_Message(LOG_ERROR,"[View]-Model no exist\n");
       return VIEW_ERROR; 
    }

    printf("------- SYSTEM MONITOR DASHBOARD ------- \n");

                     /*CPU Info*/ 
    printf("CPU Usage: %.2f%%\n", model->cpu.used);
    printf("CPU Freq: %.2f GHz | Temp: %.2f C\n", model->cpu.hz, model->cpu.temp);
    printf("Top CPU Procs:\n");
    for (int i = 0; i < CPU_TOP_PROCESS_NUMBERS; i++)
    {
        printf(" - %s\n", model->cpu.top_process[i]);
    }

                    /*RAM Info*/ 
    printf("RAM Used: %f MB | Cache: %.2f MB | Swap: %f MB\n", model->mem.ram_used, model->mem.cache, model->mem.swap);
    printf("Top RAM Procs:\n");
    for (int i = 0; i < RAM_TOP_PROCESS_NUMBERS; i++)
    {
        printf(" - %s\n", model->mem.top_process[i]);
    }

                   /*Storage Info*/ 
    printf("Disk Used: %.2f GB | Free: %.2f GB | Read: %.2f MB/s | Write: %.2f MB/s\n",
           model->storage.used,
           model->storage.free,
           model->storage.read_speed,
           model->storage.write_speed);

                  /*Network Info*/ 
    printf("Net: Upload %.2f kB/s | Download %.2f kB/s | Connections: %d\n",
           model->network.upload_speed,
           model->network.download_speed,
           model->network.num_connections);

              /*System Info*/ 
    printf("System Uptime: %d s | Kernel: %s\n",
           model->sytem.uptime,
           model->sytem.kernel_version);
    printf("Load Avg (1, 5, 15 min): %.2f, %.2f, %.2f\n",
           model->sytem.load_avg[0],
           model->sytem.load_avg[1],
           model->sytem.load_avg[2]);
           
           return VIEW_SUCCESS;
}


