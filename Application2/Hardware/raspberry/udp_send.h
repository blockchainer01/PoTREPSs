#ifndef UDP_SEND_H
#define UDP_SEND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXSENDSIZE 1000
#define PORT 8080 //端口地址
#define SERVER_IP "10.64.117.168" // 替换为你的目标地址

//#define SERVER_IP "192.168.211.148"
void sendData(const double *data , size_t size);

#endif