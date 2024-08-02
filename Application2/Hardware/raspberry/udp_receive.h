#ifndef UDP_RECEIVE_H
#define UDP_RECEIVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAXRECVSIZE 64

struct data_in
{
  short  dev_id;             // (2 bytes) Sender device ID
  int    msg_id;             // (4 bytes) Message ID
  short  msg_len;            // (2 bytes) Message length (data only)
  double data[MAXRECVSIZE];  // Up to MAXRECVSIZE doubles (8 bytes each)
};

extern volatile int exit2_flag;
extern struct data_in received_data; 

void *ucp_receive(void *arg);

#endif  // UCP_RECEIVE_H