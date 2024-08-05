#!/usr/bin/env python
# coding: utf-8

"""
Secondary Controller Layer(SCL) code

SCL connects to PoA Ethereum, sends control signal u, 
receives, merges, generates consensus status signal, 
and forms loop iteration.

by Yuzhong Li 
cslyz@hzu.edu.cn
"""

import socket  
import numpy as np  
import threading
import time
import struct 
import matplotlib.pyplot as plt
import sys
import time
import pprint
from web3.providers.eth_tester import EthereumTesterProvider

from web3 import Web3
from web3 import Web3, HTTPProvider
from web3.eth import Eth
from web3.middleware import geth_poa_middleware
np.set_printoptions(threshold=np.sys.maxsize)


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





'''
The setup of PoA Ethereum blockchain
'''
w3 = Web3(HTTPProvider('http://192.168.1.70:8509'))
w3.middleware_onion.inject(geth_poa_middleware, layer=0)
eth = Eth(w3)
accounts = w3.eth.accounts
option={'from':accounts[0], "gasLimit": "0xff2fefd8"} 
#set ethereum transact() parameter 

#Check if the connection is successful
if w3.eth.get_block(0) is None:
	print("Blockchain connect failed！")   
elif w3.is_connected():
	print("Blockchain connected successfully！")

#Read account balance
balance = w3.eth.get_balance(accounts[0],'latest')
print('balance before tx => {0}'.format(balance))

#Unlock Account
w3.geth.personal.unlock_account(eth.accounts[0],'a',0)
w3.geth.personal.unlock_account(eth.accounts[1],'a',0)

'''
Initialization of network IP and related parameters
'''
FIRST_LAYER_IP = '192.168.1.70'
FIRST_LAYER_PORT = 30011 
SECOND_LAYER_IPS = [('192.168.1.71', 30021), ('192.168.1.72', 30022), ('192.168.1.73', 30023), ('192.168.1.74', 30024), ('192.168.1.75', 30025),  ('192.168.1.76', 30026),  ('192.168.1.77', 30027)]  # 假设的IP地址和端口  
len2 = len(SECOND_LAYER_IPS)
len3=5
message="Hello from first layer!!!"
responses = [] 
e1_event=threading.Event()
event = threading.Event()
R=np.zeros([len2,len3*dim])
fl=np.zeros(len2)
recv_data = np.zeros((len3+1))
len2m=int(len2/2)+1


#Define a hexadecimal string formatted output function
def bytesToHexString(bs):
   return ''.join(['%02x' % b for b in bs])

#Define methods for receiving, combining, and consensus
def Combin(data, addr, ts):
    global R
    global fl
    if addr[0] ==SECOND_LAYER_IPS[0][0] and fl[0] == 0:
        R[0] = struct.unpack('!20f',data[4:84])
        fl[0] = 1
    elif addr[0] ==SECOND_LAYER_IPS[1][0] and fl[1] == 0:
        R[1] = struct.unpack('!20f',data[4:84])
        fl[1] = 1
    elif addr[0] ==SECOND_LAYER_IPS[2][0] and fl[2] == 0:
        R[2] = struct.unpack('!20f',data[4:84])
        fl[2] = 1
    elif addr[0] ==SECOND_LAYER_IPS[3][0] and fl[3] == 0:
        R[3] = struct.unpack('!20f',data[4:84])
        fl[3] = 1
    elif addr[0] ==SECOND_LAYER_IPS[4][0] and fl[4] == 0:
        R[4] = struct.unpack('!20f',data[4:84])
        fl[4] = 1
    elif addr[0] ==SECOND_LAYER_IPS[5][0] and fl[5] == 0:
        R[5] = struct.unpack('!20f',data[4:84])
        fl[5] = 1
    elif addr[0] ==SECOND_LAYER_IPS[6][0] and fl[6] == 0:
        R[6] = struct.unpack('!20f',data[4:84])
        fl[6] = 1
    else:
        pass
    if np.sum(fl) >= 1:
        R1=R[np.any(R!=0, axis=1)]
        R2=modezz(R1)#Consensus
        R=np.zeros([len2,len3*dim])
        fl=np.zeros(len2)
        print("T_Out")
        return 1, R2
    else:
        return 0, R2

#Consensus Method
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

#Send method
def send(message):  
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # sock.bind(('localhost', 30010))  
    for ip, port in SECOND_LAYER_IPS: 
        sock.sendto(message, (ip, port))
        # print(f"First layer send to {(ip, port)}")
        time.sleep(0.02)
    sock.close() 
    
#Recv method - Used for receiving threads
def recv(): 
    # global recv_data
    global R,t_count
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
    sock.bind((FIRST_LAYER_IP, FIRST_LAYER_PORT)) 
    sock.settimeout(60)
    while not e1_event.is_set():
        try:      
            data, addr = sock.recvfrom(1024)
            ts1 = int(struct.unpack('!1f',data[0:4])[0])  
#             print(f" ts1 = {ts1}, addr = {addr}")
            if data:
                #if recv an empty package ???
                if ts1 == ts+1:
                    if t_count==0:
                        t_count = t_count + 1
                        r_flag, RX = Combin(data, addr, ts)
                        x[:,ts+1]=RX           
                        V[:,ts+1] = x[[0,4,8,12,16],ts+1]
                        I[:,ts+1] = x[[1,5,9,13,17],ts+1]
                        print(f"V={V[:,ts+1]},I={I[:,ts+1]}")
                        #sendtoPoA(RX)
                        event.set()
                    else:
                        pass
                else:
                    print(f"ts1 != ts+1, ts1 = {ts1}, ts = {ts} EEEEEEEEEEEE")
                    pass
        except socket.timeout:
            print(f"No data received!!!")
            e1_event.set()
            sock.close()
            break


#Data upload Ethereum PoA blockchain method-personal.unlockAccount Agian Agian Agian !!!
def sendtoPoA(R1):
    R2=[f"{x:.2f}" for x in R1]
    R3=' '.join(R2)
    data_into_block=w3.to_hex(text=R3) 
    tx_hash = w3.eth.send_transaction({
    'from': w3.eth.coinbase,
    'to': w3.eth.accounts[1],
    'value': 1,
    'gas': 50000,
    'gasPrice':w3.to_wei('10','gwei'),
    'data':data_into_block})
    print('tx hash => {0}'.format(Web3.to_hex(tx_hash)))
    print(f"block number={w3.eth.block_number}")


#Storage space initialization
I_max = np.array([1,1,1.8,1.8,1.8])
##
A = A_all
B = B_all

d_SC=1000
d_CA=1000

t_droop = int(5/Ts)
t_max = int(10/Ts)


global x,u,V,I,ts,t_count
ts=0
t_count = 0
x = np.zeros((Ns*dim,t_max + 1))
x_pred = np.zeros((Ns*dim,t_max + 1))

u = np.zeros((Ns,t_max+d_CA))
u_pred = np.zeros((Ns,t_max+d_CA))
Vref = 48



V = np.zeros((Ns,t_max + 1))
I = np.zeros((Ns,t_max + 1))

V_pred = np.zeros((Ns,t_max + 1))
I_pred = np.zeros((Ns,t_max + 1))

G_I = 0.1
G_V = 0.04 * np.array([1,1,1,1,1])
##
'''
Droop Part
'''
for t in np.arange(0,t_droop).reshape(-1):
    x[:,t+1]=A @ x[:,t]+ B @ u[:,t] + B @ np.kron(np.ones(Ns),Vref)
    for i in np.arange(0,Ns).reshape(-1):
        V[i,t+1]=x[dim*i,t+1]
        I[i,t+1]=x[dim*i+1,t+1]


'''
System evolution follows the Ts time cycle
'''
T_sc=int(Tc/Ts)
start_time = time.time()
#Create receiving thread
recv_thread=threading.Thread(target=recv, daemon=True)
#Start mining
w3.geth.miner.start()
#Open the receiving thread
recv_thread.start()
for t in np.arange(t_droop,t_max-d_CA).reshape(-1):

    ts = t
    if np.mod(t,T_sc) == 1:
        if t>=t_droop+d_SC+1:
            xxd=x[:,t-d_SC]
            for k in np.arange(0,d_SC+d_CA):
                xxd=A @ xxd + B @ u[:,t-d_SC+k] + B @ np.kron(np.ones(Ns),Vref)
            x_pred[:,t+d_CA]=xxd

            for i in np.arange(0,Ns).reshape(-1):
                V_pred[i,t+d_CA] = x_pred[dim*i,t+d_CA] 
                I_pred[i,t+d_CA] = x_pred[dim*i+1,t+d_CA]
                
            u_pred[:,t+d_CA]=G_I*(-L_comm @ (I_pred[:,t+d_CA]/I_max)) + \
                    G_V*(np.kron(np.ones(Ns),Vref-sum(V_pred[:,t+d_CA]/Ns))) + \
                    u[:,t+d_CA-1]

        for l in np.arange(0,T_sc).reshape(-1):
            u[:,t+d_CA+l]=u_pred[:,t+d_CA]
    
    

    print(f"**************************************")
    print(f"u[:,{t}]={u[:,t]}")
    uk=np.append(np.array([t]), u[:,t], axis=0)
    u_pack = struct.pack('!6f', *uk)    
    send(u_pack)
    event.wait()#Waiting for the system to return the status value x
    event.clear()
    end_time = time.time()
    t_count = 0
    print(f"x[:,{t}]={x[:,t]}")
    print("Elapse time {:.4f} s".format(end_time - start_time))  
recv_thread.join()#Waiting for thread to stop
w3.geth.miner.stop()#Mining has stop


'''
Draw graphics
'''
import matplotlib.pyplot as plt  
import numpy as np  
t = np.arange(0,t_max-T_sc)
# Create a graphic window and subplot 
fig, axs = plt.subplots(nrows=2, ncols=1, figsize=(8, 6))  # 创建2行1列的子图  
# Draw on the first subplot 
axs[0].plot(t,V[0,t],t,V[1,t],t,V[2,t],t,V[3,t],t,V[4,t])
# Draw on the second subplot
axs[1].plot(t,I[0,t],t,I[1,t],t,I[2,t],t,I[3,t],t,I[4,t])
# Adjust the distance between subplots  
plt.tight_layout()  
# show the graphic
plt.show()





