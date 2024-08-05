#!/usr/bin/env python
# coding: utf-8
'''
Sampling Actuator Layer (SAL) Physical node code 

SAL receives the control signal u (ts) from SRL and sends it to the device. 
After collecting the status signal x (ts), the device sends it to other SAL 
nodes and also receives x (ts) signals from other nodes. After running, it 
obtains x (ts+1) signals and sends them to each node of SRL.

Physics experiments require sending u (ts) to DGU via serial port, obtaining 
x(ts), and then DGU returning x (ts+1) via serial port

by Yuzhong Li 
cslyz@hzu.edu.cn
'''
import socket  
import threading
import numpy as np  
from scipy.stats import mode  
import struct
import matplotlib.pyplot as plt
import serial
import time

'''
Initialize parameters
'''

A_all=np.array([[0.3325,0.05,0,0,                  0.1,      0,     0,0,                    0,      0,     0,0,                  0.5,      0,     0, 0,               0.0625,       0,      0,0],
[  -0.1422775,   0.95,  0.05,5,               0.0133,      0,     0,0,                    0,      0,     0,0,               0.0665,      0,     0, 0,            0.0083125,       0,      0,0],
[  -0.0026365,      0,     1,0,              0.00038,      0,     0,0,                    0,      0,     0,0,               0.0019,      0,     0, 0,            0.0002375,       0,      0,0],
[-0.000184555,-0.0001,0.0001,1,             2.66e-05,      0,     0,0,                    0,      0,     0,0,             0.000133,      0,     0, 0,           1.6625e-05,       0,      0,0],
[         0.1,      0,     0,0,    0.578333333333333,   0.05,     0,0,                 0.05,      0,     0,0,                  0.1,      0,     0, 0,    0.166666666666667,       0,      0,0],
[     0.01064,      0,     0,0,  -0.0976653333333333,   0.96,  0.04,4,              0.00532,      0,     0,0,              0.01064,      0,     0, 0,   0.0177333333333333,       0,      0,0],
[     0.00038,      0,     0,0, -0.00170233333333333,      0,     1,0,              0.00019,      0,     0,0,              0.00038,      0,     0, 0, 0.000633333333333333,       0,      0,0],
[    2.66e-05,      0,     0,0,-0.000119163333333333,-0.0001,0.0001,1,             1.33e-05,      0,     0,0,             2.66e-05,      0,     0, 0, 4.43333333333333e-05,       0,      0,0],
[           0,      0,     0,0,                 0.05,      0,     0,0,    0.696153846153846,   0.05,     0,0,                 0.25,      0,     0, 0,                    0,       0,      0,0],
[           0,      0,     0,0,              0.00252,      0,     0,0,  -0.0681138461538462,   0.96,  0.04,4,               0.0126,      0,     0, 0,                    0,       0,      0,0],
[           0,      0,     0,0,                9e-05,      0,     0,0,-0.000646923076923077,      0,     1,0,              0.00045,      0,     0, 0,                    0,       0,      0,0],
[           0,      0,     0,0,              6.3e-06,      0,     0,0,-4.52846153846154e-05,-0.0001,0.0001,1,             3.15e-05,      0,     0, 0,                    0,       0,      0,0],
[         0.5,      0,     0,0,                  0.1,      0,     0,0,                 0.25,      0,     0,0,   0.0616666666666665,   0.05,     0, 0,   0.0833333333333333,       0,      0,0],
[       0.035,      0,     0,0,                0.007,      0,     0,0,               0.0175,      0,     0,0,   -0.119183333333333,   0.95,  0.05, 5,  0.00583333333333333,       0,      0,0],
[       0.001,      0,     0,0,               0.0002,      0,     0,0,               0.0005,      0,     0,0, -0.00197666666666667,      0,     1, 0, 0.000166666666666667,       0,      0,0],
[       7e-05,      0,     0,0,              1.4e-05,      0,     0,0,              3.5e-05,      0,     0,0,-0.000138366666666667,-0.0001,0.0001, 1, 1.16666666666667e-05,       0,      0,0],
[      0.0625,      0,     0,0,    0.166666666666667,      0,     0,0,                    0,      0,     0,0,   0.0833333333333333,      0,     0, 0,               0.6825,    0.05,      0,0],
[    0.005355,      0,     0,0,              0.01428,      0,     0,0,                    0,      0,     0,0,              0.00714,      0,     0, 0,           -0.0814034,    0.94,   0.06,6],
[   0.0001275,      0,     0,0,              0.00034,      0,     0,0,                    0,      0,     0,0,              0.00017,      0,     0, 0,           -0.0007477,       0,      1,0],
[   8.925e-06,      0,     0,0,             2.38e-05,      0,     0,0,                    0,      0,     0,0,             1.19e-05,      0,     0, 0,          -5.2339e-05, -0.0001, 0.0001,1]])





B_all=np.array([[     0,     0,     0,     0,     0],
[0.0035,     0,     0,     0,     0],
[0.0001,     0,     0,     0,     0],
[ 7e-06,     0,     0,     0,     0],
[     0,     0,     0,     0,     0],
[     0,0.0028,     0,     0,     0],
[     0,0.0001,     0,     0,     0],
[     0, 7e-06,     0,     0,     0],
[     0,     0,     0,     0,     0],
[     0,     0,0.0028,     0,     0],
[     0,     0,0.0001,     0,     0],
[     0,     0, 7e-06,     0,     0],
[     0,     0,     0,     0,     0],
[     0,     0,     0,0.0035,     0],
[     0,     0,     0,0.0001,     0],
[     0,     0,     0, 7e-06,     0],
[     0,     0,     0,     0,     0],
[     0,     0,     0,     0,0.0042],
[     0,     0,     0,     0,0.0001],
[     0,     0,     0,     0, 7e-06]])


Ts = 0.0001
Tc= 0.01;
Ns = 5
dim = 4
##
A_comm= np.array([[0,1,0,0,1],[1,0,1,0,0],[0,1,0,1,0],[0,0,1,0,1],[1,0,0,1,0]])
##
D_comm = np.zeros((Ns,Ns))
##

for i in np.arange(0,Ns).reshape(-1):
    for j in np.arange(0,Ns).reshape(-1):
        if A_comm[i,j]!=0:
            D_comm[i,i]=D_comm[i,i]+A_comm[i,j]
##
L_comm = D_comm - A_comm
L_eig,_= np.linalg.eigh(-L_comm)

I_max = np.array([1,1,1.8,1.8,1.8])
##
A = A_all
B = B_all

d_SC=1000
d_CA=1000

t_droop = int(5/Ts)
t_max = int(10/Ts)


'''
Allocate memory space
'''
global x,u,V,I
x = np.zeros((Ns*dim,t_max + 1))
x_pred = np.zeros((Ns*dim,t_max + 1))

u = np.zeros((Ns,t_max+d_CA))
u_pred = np.zeros((Ns,t_max+d_CA))
Vref = 48

V = np.zeros((Ns,t_max + 1))
I = np.zeros((Ns,t_max + 1))

V_pred = np.zeros((Ns,t_max + 1))
I_pred = np.zeros((Ns,t_max + 1))
##

#Set initial parameters for droop control
x[:,t_droop] = np.array([42.87826291,2.69655487,2.69667973,0.42878255,
 42.82522564,2.72444162,2.72456338,0.53531523,
 43.31185569,5.20713902,5.20702914,0.54139813,
 43.03409047,4.96487384,4.96480751,0.43034086,
 42.98951989,4.91138763,4.91133203,0.35824596])

data6 = x[:,t_droop]

global ts
ts=0

#Set the serial port for communication with DGU
ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=115200,
    parity=serial.PARTIY_NONE,
    stopbits=serials.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
    )


#DGU serial communication method
def dsp_com(ts, x_dsp):
    datad = np.concatenate(([ts], [round(num,2) for num in x_dsp]))
    comm = ' '.join(map(str, datad))
    ser.write(comm)
    res = ser.readline().decode('utf-8').rstrip()
    tss = int(res[0:5])
    if ts = tss:
        return res
    else:
        return None

#Method to obtain local port, and ID
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
            i=None
        elif ip == "192.168.1.72":
            port = 30022
            i=None
        elif ip == "192.168.1.73":
            port = 30023
            i=None
        elif ip == "192.168.1.74":
            port = 30024
            i=None
        elif ip == "192.168.1.75":
            port = 30025
            i=None
        elif ip == "192.168.1.76":
            port = 30026
            i=None
        elif ip == "192.168.1.77":
            port = 30027
            i=None
        else:
            i=None
            pass
        
    finally:
        s.close()
    return ip,port,i
local_ip,local_port,i=get_local_ip()
print(f"local_ip={local_ip},local_port={local_port},i={i}")


#Set IP and other parameters
SECOND_LAYER_IPS = [('192.168.1.71', 30021), ('192.168.1.72', 30022), ('192.168.1.73', 30023), ('192.168.1.74', 30024), ('192.168.1.75', 30025),  ('192.168.1.76', 30026),  ('192.168.1.77', 30027)]  # 假设的IP地址和端口
THIRD_LAYER_IPS = [('192.168.1.25', 30031), ('192.168.1.23', 30032), ('192.168.1.22', 30033), ('192.168.1.26', 30034), ('192.168.1.29', 30035)]
LAYER_IPS = SECOND_LAYER_IPS + THIRD_LAYER_IPS
THIRD_LAYER_IP = local_ip  # set local ip  
THIRD_LAYER_PORT = local_port # set local port  
e1_event=threading.Event()

len2=len(SECOND_LAYER_IPS)
len3=len(THIRD_LAYER_IPS)
R=np.zeros([len2,len3])
fl=np.zeros(len2)
fl3=np.zeros(len3)
global u_flag,x_flag
u_flag=0
x_flag=1
len2m=int(len2/2)+1
len3dim=len3*dim
len3m=int(len3/2)+1
R3=np.zeros([len3,len3dim])

#Simulating Plant operation method
def Plant_op(t, Ns, dim, V, I, u, x, A, B, Vref, i):
    x[:,t+1]=A @ x[:,t]+ B @ u[:,t] + B @ np.kron(np.ones(Ns),Vref)
    V[i,t+1]=x[0,t+1]
    I[i,t+1]=x[1,t+1]
    return x[:,t+1]

#Combinate and consensus PLM other nodes to obtain x(ts+1) method
def Combin3(data, len3, addr, ts):
    ts1 = struct.unpack('!1f',data[0:4])[0]
    global R3
    global fl3
    if ts==ts1:
        if addr[0] ==THIRD_LAYER_IPS[0][0] and fl[0] == 0:
            R3[0] = struct.unpack('!20f',data[4:84])
            fl3[0] = 1
        elif addr[0] ==THIRD_LAYER_IPS[1][0] and fl[1] == 0:
            R3[1] = struct.unpack('!20f',data[4:84])
            fl3[1] = 1
        elif addr[0] ==THIRD_LAYER_IPS[2][0] and fl[2] == 0:
            R3[2] = struct.unpack('!20f',data[4:84])
            fl3[2] = 1
        elif addr[0] ==THIRD_LAYER_IPS[3][0] and fl[3] == 0:
            R3[3] = struct.unpack('!20f',data[4:84])
            fl3[3] = 1
        elif addr[0] ==THIRD_LAYER_IPS[4][0] and fl[4] == 0:
            R3[4] = struct.unpack('!20f',data[4:84])
            fl3[4] = 1
        else:
            pass
        if np.sum(fl3)>= len3m:
            R1=R3[np.any(R3!=0, axis=1)]
            #print(f"R1={R1}")
            data1=modezz(R1)
            #print(f"data={data1}")
            R3 = np.zeros([len3,len3dim])
            fl3 = np.zeros(len3)
            #print("x_Out")
            return 1, data1
        else:
            return 0, None
    else:
        return 0, None


#Combinate and consensus DRL other nodes to obtain u(ts) method
def Combin2(data, len2, addr, ts):
    ts1 = int(struct.unpack('!1f',data[0:4])[0])
    global R
    global fl
#     if np.sum(fl) == 0:
    if ts==ts1:
        if addr[0] ==SECOND_LAYER_IPS[0][0] and fl[0] == 0:
            R[0] = struct.unpack('!5f',data[4:24])
            fl[0] = 1
        elif addr[0] ==SECOND_LAYER_IPS[1][0] and fl[1] == 0:
            R[1] = struct.unpack('!5f',data[4:24])
            fl[1] = 1
        elif addr[0] ==SECOND_LAYER_IPS[2][0] and fl[2] == 0:
            R[2] = struct.unpack('!5f',data[4:24])
            fl[2] = 1
        elif addr[0] ==SECOND_LAYER_IPS[3][0] and fl[3] == 0:
            R[3] = struct.unpack('!5f',data[4:24])
            fl[3] = 1
        elif addr[0] ==SECOND_LAYER_IPS[4][0] and fl[4] == 0:
            R[4] = struct.unpack('!5f',data[4:24])
            fl[4] = 1
        elif addr[0] ==SECOND_LAYER_IPS[5][0] and fl[5] == 0:
            R[5] = struct.unpack('!5f',data[4:24])
            fl[5] = 1
        elif addr[0] ==SECOND_LAYER_IPS[6][0] and fl[6] == 0:
            R[6] = struct.unpack('!5f',data[4:24])
            fl[6] = 1
        else:
            pass
        #print(f"fl={fl}")
        if np.sum(fl) >= len2m:
            #R1=R[np.any(R!=0, axis=1)]
            data1=modezz(R)
            R=np.zeros([len2,len3])
            fl=np.zeros(len2)
            #print("u_Out")
            return 1, data1
        else:
            return 0, None          
    else:
        return 0, None

#Consensus method
def modezz(arr):  
    arr_view = arr.view([('', arr.dtype)] * arr.shape[1])    
    unique_rows, counts = np.unique(arr_view, return_counts=True, axis=0)   
    max_count = np.max(counts)  
    most_common_rows = arr[np.where(counts == max_count)[0][0]]  
    #Only the first row with the most occurrences will be taken here. 
    #If there are multiple rows, additional processing is required 
    return most_common_rows


'''
Main program iteration, receiving control signal u (ts), 
sending it to the device to obtain status signal x (ts+1)
'''
#Set socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
sock.bind((THIRD_LAYER_IP, THIRD_LAYER_PORT))
sock.settimeout(600)
while not e1_event.is_set():
    try:
        data, addr = sock.recvfrom(4096)    
        if data:
            if ts==0:
                ts = int(struct.unpack('!1f',data[0:4])[0])
            if addr[0][10] == '7':
                if u_flag == 0:
                    u_flag, data5 = Combin2(data, len2, addr, ts)
            elif addr[0][10] == '2':
                if x_flag == 0:
                    x_flag, data6 = Combin3(data, len3, addr, ts)                   
            else:
                pass
            if u_flag == 1 and x_flag == 1:
                u[:,ts] = data5
                print(f"u[:,{ts}]={u[:,ts]}")
                x[:,ts] = data6
                print("Plant process")
                #data7 = Plant_op(ts, Ns, dim, V, I, u, x, A, B, Vref, i)
                data7 = dsp_com(ts, x[:,ts])#RS485 serial communication with DGU
                if data7 != None: 
                    print(f"x[:,{ts+1}]={data7}")
                    ts=ts+1
                    data8 = np.concatenate(([ts], data7))
                    data9 = struct.pack('!21f', *data8)
                    u_flag = 0
                    x_flag = 0      
                    for ip, port in LAYER_IPS: 
                        sock.sendto(data9, (ip, port)) 
                        #print(f"{ts+1} Send to :{(ip,port)}")
                else:
                    pass
                print(f"**************************************")
    except socket.timeout:
            print(f"No data received!!!")
            e1_event.set()
            sock.close()
            break

