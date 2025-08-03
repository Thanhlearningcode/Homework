#ifndef _SYSTEM_INFOR_H_
#define _SYSTEM_INFOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CPU_CORE_NUMBERS         8
#define CPU_TOP_PROCESS_NUMBERS  5
#define RAM_TOP_PROCESS_NUMBERS  5
#define IP_ADDRESS               4
#define NUMBER_CHARACTERS        32
#define KERNEL_VERSION           64

typedef struct 
{
    float used;
    float core[CPU_CORE_NUMBERS];
    float hz;
    float temp;
    char  top_process[CPU_TOP_PROCESS_NUMBERS][CPU_CORE_NUMBERS*CPU_TOP_PROCESS_NUMBERS];
} CPU_Infor;

typedef struct 
{
    float ram_used;
    float ram_free;
    float swap;
    char  top_process[RAM_TOP_PROCESS_NUMBERS][CPU_CORE_NUMBERS*RAM_TOP_PROCESS_NUMBERS];
    float cache;
} Memory_Infor;

typedef struct 
{
    float used;
    float free;
    float read_speed;
    float write_speed;
    float input;
    float output;
    float IOPS;
} Storage_Infor;

typedef struct 
{
    float upload_speed;
    float download_speed;
    float bandwidth;
    int   num_connections;
    char  ip_address[IP_ADDRESS][NUMBER_CHARACTERS];
    int   packet_stats;
} Network_Infor;

typedef struct 
{
    int           uptime;
    char          system_time[64];
    char          kernel_version[KERNEL_VERSION];
    char          running_services[10][64];
    float         load_avg[3];
} System_Infor;

typedef struct 
{
    CPU_Infor     cpu;
    Memory_Infor  mem;
    Storage_Infor storage;
    Network_Infor network;
    System_Infor  sytem;
} Model_Infor;

#endif /*_SYSTEM_INFOR_H_*/