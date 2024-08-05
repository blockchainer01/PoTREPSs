#!/usr/bin/env python
# coding: utf-8

'''
Signal Relay Layer (SRL) Code

There are 7 nodes in this DRL layer, 
which are used to receive control signals u 
from SCL and distribute them to 5 SAL nodes. 
Each SRL node receives signals from 5 SAL nodes, 
consensus them, merge them, and upload them to the SPC node. 
In this layer, each node has a probability of being attacked.

by Yuzhong Li 
cslyz@hzu.edu.cn
'''

import socket  
import threading  
import time
import numpy as np
import struct
import random
import math

#Obtain the port number and ID of the node based on the IP address
def get_local_ip():
    try:
        s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(("8.8.8.8",80))
        ip = s.getsockname()[0]
        if ip == "192.168.1.25":
            port = 30031
            i=0
        elif ip == "192.168.1.23":
            port = 30032
            i=1
        elif ip == "192.168.1.22":
            port = 30033
            i=2
        elif ip == "192.168.1.26":
            port = 30034
            i=3
        elif ip == "192.168.1.29":
            port = 30035
            i=4
        elif ip == "192.168.1.70":
            port = 30011
            i=None
        elif ip == "192.168.1.71":
            port = 30021
            i=71
        elif ip == "192.168.1.72":
            port = 30022
            i=72
        elif ip == "192.168.1.73":
            port = 30023
            i=73
        elif ip == "192.168.1.74":
            port = 30024
            i=74
        elif ip == "192.168.1.75":
            port = 30025
            i=75
        elif ip == "192.168.1.76":
            port = 30026
            i=76
        elif ip == "192.168.1.77":
            port = 30027
            i=77
        else:
            i=None
            pass
        
    finally:
        s.close()
    return ip,port,i
local_ip,local_port,i=get_local_ip()
print(f"local_ip={local_ip},local_port={local_port},i={i}")

#Configure IP and attack related parameters
SECOND_LAYER_IP = local_ip # get local ip
SECOND_LAYER_PORT = local_port  # get local port
THIRD_LAYER_IPS = [('192.168.1.25', 30031), ('192.168.1.23', 30032), ('192.168.1.22', 30033), ('192.168.1.26', 30034), ('192.168.1.29', 30035)]  # 假设的IP地址和端口  
FIRST_LAYER_IP = '192.168.1.70'  
FIRST_LAYER_PORT = 30011  
len3 = len(THIRD_LAYER_IPS)
dim = 4
len3dim=len3*dim
len3m=int(len3/2)+1
e1_event=threading.Event()
R = np.zeros([len3,len3dim])
fl = np.zeros(len3)
global ts
ts=0
#Attack probability
attack_probability_u=np.array([0.25,0.26,0.27,0.23,0.09,0,0])
#Attack amplitude
Au=0.5*np.array([0.5,0.4,0.3,0.6,0.45,0.2,0.3])
Omega=0.1


#Consensus
def modezz(arr):
#Convert a two-dimensional array to a structured array (or if NumPy version is newer, use np. ascontiousarray)
#Note: This method is only applicable to arrays with dtype as the basic data type (such as int, float, etc.)
    arr_view = arr.view([('', arr.dtype)] * arr.shape[1])  

 # Use np. unique to find unique rows and their counts   
    unique_rows, counts = np.unique(arr_view, return_counts=True, axis=0)  

  # Find the row with the most occurrences
    max_count = np.max(counts)  
    most_common_rows = arr[np.where(counts == max_count)[0][0]]
    #Only the first row with the most occurrences will be taken here. 
    #If there are multiple rows, additional processing is required
    
    return most_common_rows

#Method for combining data from 5 SAL nodes and making them consensus
def Combin(data, addr, ts):
    ts1 = struct.unpack('!1f',data[0:4])[0]
    global R
    global fl
    #if np.sum(fl) == 0:
        #ts = ts1
    #print(f"ts={ts},ts1={ts1},addr={addr}")
    if ts1 == ts+1:
        if addr[0] ==THIRD_LAYER_IPS[0][0] and fl[0] == 0:
            R[0] = struct.unpack('!20f',data[4:84])
            fl[0] = 1
        elif addr[0] ==THIRD_LAYER_IPS[1][0] and fl[1] == 0:
            R[1] = struct.unpack('!20f',data[4:84])
            fl[1] = 1
        elif addr[0] ==THIRD_LAYER_IPS[2][0] and fl[2] == 0:
            R[2] = struct.unpack('!20f',data[4:84])
            fl[2] = 1
        elif addr[0] ==THIRD_LAYER_IPS[3][0] and fl[3] == 0:
            R[3] = struct.unpack('!20f',data[4:84])
            fl[3] = 1
        elif addr[0] ==THIRD_LAYER_IPS[4][0] and fl[4] == 0:
            R[4] = struct.unpack('!20f',data[4:84])
            fl[4] = 1
        else:
            pass
        if np.sum(fl)>=1en3m:
            R1=R[np.any(R!=0, axis=1)]
            #print(f"R={R}")
            data3 = modezz(R1)
            #print(f"data3={data3}")
            data1 = np.concatenate(([ts1], data3))
            #print(f"data1={data1}")
            data2 = struct.pack('!21f', *data1) 
            R = np.zeros([len3,len3dim])
            fl = np.zeros(len3)
            print("C_Out")
            return data2 
        else:
            return None
    else:
        return None



#Configure Socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
sock.settimeout(600)
sock.bind((SECOND_LAYER_IP, SECOND_LAYER_PORT))

'''
Relay main program
'''
while not e1_event.is_set():
    try:
        data, addr = sock.recvfrom(4096)
        if data:
            if ts==0:
                ts = struct.unpack('!1f',data[0:4])[0]
            if addr[0] == FIRST_LAYER_IP:
                ts = struct.unpack('!1f',data[0:4])[0]
                #attack probability
                random_number=random.random()
                if random_number >= attack_probability_u[i-71]:#Determine whether it has been attacked
                    data7 = struct.unpack('!5f',data[4:24])+Au[i-71]*Omega*math.sin(ts%100*2*math.pi)
                    print(f"u1={data7}")    
                    data8 = np.concatenate(([ts], data7))
                    data = struct.pack('!6f', *data8)
                #Send to SAL node
                for ip, port in THIRD_LAYER_IPS:  
                    sock.sendto(data, (ip, port))
                    print(f"Recv -- Send to third layer{(ip, port)}")
                # time.sleep(1)
            else:
                data2 = Combin(data, addr, ts)
                if data2 != None:
                    sock.sendto(data2, (FIRST_LAYER_IP, FIRST_LAYER_PORT)) 
                    print(f"Recv -- Send to first layer")
        print(f"**************************************")
    except socket.timeout:
            print(f"No data received!!!")
            e1_event.set()
            sock.close()
            break

