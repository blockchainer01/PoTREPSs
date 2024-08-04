


# Hardware Requirements and Experimental Instructions


## 1. Preparation for the experiment

### 1.1. Hardware requirements

1) OPAL-RT 4512
 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/2-opalrt.jpg?raw=true" width="800" div align=center > </div>
 <p align="center">Fig. 1. OPAL-RT 4512.</p>
 
2) Three Raspberry Pi acting as sampling modules and actuators, as shown in Application 1. Three groups of Raspberry Pi as a blockchain network, for a total of 15, as shown in Application 1.

3) The router, USB power supply, etc. are the same as in Application 1.

### 1.2 Software requirements

1) RTLAB file

2) The rest of the software is the same as in Application 1

### 3. The network configuration of the Raspberry Pi is the same as Application 1

### 4. Implementation of the PoT-based load frequency control algorithm

### 4.1 Hardware and control parameters of the system

Hardware parameters and control parameters can be found in the parameter folder xxx.

### 4.2 Algorithm design and implementation

An executable of the algorithm has been generated, which is the same as Application 1. The specific algorithm design is available in the MATLAB file at xx. The code can be run directly on a computer with MATLAB software installed.

## 2. Experimental procedure

###  4.3.1 Start OPAL-RT

1) Start the RTLAB software and open the project HIL_LFC_UDP.

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/1_Start.png?raw=true" width="800" div align=center > </div>
 <p align="center">Fig. 2. Control desk of RTLAB software.</p>
 
2) Modify module `OpIPSocketCtrl1`, configure the IP address and ports.

3) Parameter description: `Remote Address` is the static ip of the Raspberry Pi.

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/2_rtConfiguration.png?raw=true" width="800" div align=center > </div>
 <p align="center">Fig. 3. Parameter description.</p>

4) Run `build`, `load`, and `execute` in turn, at this point the RTLAB project is already running.

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/3_compile.png?raw=true" width="800" div align=center > </div>
 <p align="center">Fig. 4. RTLAB project.</p>

5) Use the `sc_console` monitoring module in `HIL_LFC_UDP.mlx` to monitor the data received via UDP, i.e. the control command, in real time.
 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/4_monitor.png?raw=true" width="800" div align=center > </div>
 <p align="center">Fig. 5. Monitoring module in the RTLAB project.</p>


###  4.3.2 Static IP configuration for Raspberry Pi

Switch on the Raspberry Pi and connect it to the RTLAB with a network cable so that the Raspberry Pi is on the same network segment as the RTLAB, and configure the static IP.

Enter the file `/etc/dhcpcd.conf`:

```c
sudo vi /etc/dhcpcd.conf
```

The fixed IP address for the RTLAB in our laboratory is `10.64.117.183`. Add the following code to the end of the aforementioned file:

```c
interface eth0 // Specify interface eth0
static ip_address=10.64.117.70/24 // Specify a static IP so that it is on the same network segment as the RTLAB
static routers= 10.64.117.1 // Router IP
static domain_name_servers=8.8.8.8 // DNS server
```

Note: Execute `sudo reboot` after modifying the above files to reboot the Raspberry Pi.

###  4.3.3 2.3 Start the UDP communication server of the Raspberry Pi.

1) Configure the port on the receiving end.
```c
//udp_receive.h
#define PORT 8080 // Port address
```

2) Configure the port and IP address of the sending end

```c
//udp_send.h  
#define PORT 8080 // Port address
#define SERVER_IP "10.64.117.183" // Replace this with the RTLAB address
```

3) Run the script file
```c
sudo chmod +x run_pack.sh
sudo ./run_pack.sh
```

###  4.3.4 Start the Raspberry Pi controller and monitor the operational status of the HIL test system
Similar to the steps in Application 1, start the Raspberry Pi controller, monitor the operational status of the HIL test system, etc.


## 3. Description of communications

### 3.1 RTLAB side

##### 3.1.1 Configuration

Modify module `OpIPSocketCtrl1` to configure its IP address and port, as shown in Figure \ref{xx}.

##### 3.1.2  Send data via UDP

Parameter description: `Data` is the data to be sent, `Data ready` controls the sending period.

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/RTLABceive.png?raw=true" width="700" div align=center > </div>

##### 3.1.3  Receive data via UDP

Parameter description: `set width` sets the number of received data, `message 1 data` is the received data

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/RTLABSEND.png?raw=true" width="700" div align=center > </div>

### 3.2 Raspberry Pi side

General instructions for use: (set the IP address of the Raspberry Pi to the same network segment as that of the RTLAB)
```c
//terminal  run main.c
sudo chmod +x run_pack.sh
```

or run
```c
sudo ./main
```

##### Receive data via UDP

###### Configure the port on the receiving end

```c
//udp_receive.h
#define PORT 8080 // Port address
```

###### Instructions for use

```c
//main.h
pthread_t serverThread;

// Creating a server thread for UDP acceptance of data
if (pthread_create(&serverThread, NULL, ucp_receive, NULL) != 0)
{
    perror("pthread_create");
    exit(EXIT_FAILURE);
}

// Add intermediate logic

// Wait for the UDP server thread to finish
pthread_join(serverThread, NULL);
```

Decode the received HEX data and store it into the buffer variable

```c
//udp_receive.c
recvfrom(sockfd, buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&client_addr, &len) == -1) // Save in buffer
unpackBuffer(buffer, &received_data); // The final received data is deposited into received_data
```

Running result:

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig2/6_outcomes.png?raw=true" width="600" div align=center > </div>

##### Send data via UDP

###### Configure the port and IP address of the transmitter

```c
//udp_send.h  
#define PORT 8080 //Port address
#define SERVER_IP "10.64.117.168" // Replace it with the RTLAB fixed address
```

###### Instructions for use

```c
//main.h
double udpsenddata[2]={1,2,3};
sendData(udpsenddata,3); // The first parameter is data, the second one is data_size
```




