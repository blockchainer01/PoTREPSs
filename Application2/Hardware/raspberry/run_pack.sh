#!/bin/bash

gcc -o main main.c udp_receive.c udp_send.c -pthread
sudo ./main