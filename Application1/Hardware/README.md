# Hardware Requirements and Experimental Instructions

This is the hardware requirements and experimental instructions for **Application 1**. The system architecture corresponding to Application 1 is shown below.


 <div align=center><img src="https://raw.githubusercontent.com/blockchainer01/Figures_PoT/main/Figures/1-IMG_7883.JPG" width="800" div align=center > </div>
 <p align="center">Fig. 1. Microgrid test system.</p>




## 1. Hardware requirements

1) A computer installed with the NCSLAB environment for compiling and downloading the object-side Raspberry Pi AD sampling algorithms and PWM generation modules, etc. More information about the NCSLAB environment can be found at https://www.powersim.whu.edu.cn/react/?lang=en-US.

2) Five Raspberry Pi acting as sampling modules and actuators, as shown in the Fig. 2.


3) Sampling boards and hardware interfaces, as shown in the Fig. 2.

 <div align=center><img src="https://github.com/blockchainer01/Figures_PoT/blob/main/Figures/2-Interface.png?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 2. Sampling boards and hardware interfaces.</p>

 

4) Five groups of Raspberry Pi as a blockchain network, for a total of 35, as shown in Fig. 3.

 <div align=center><img src="https://raw.githubusercontent.com/blockchainer01/Software_platform_PoT/main/Figures/Raspberry_Pis.jpg" width="700" div align=center > </div>
 <p align="center">Fig. 3. Raspberry Pi-based blockchain network.</p>
 

5) Five bipolar high precision analog-to-digital expansion board (AD1263), as shown in the Fig. 4.

<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/4-AD263.png?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 4. Analog-to-digital expansion board.</p>


6) Router (TP-LINK AX1800) that can host 35 wireless devices, as shown in the Fig. 5.


<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/5-Router.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 5. Router.</p>


7) USB-based power supply for Raspberry Pi, etc., as shown in the Fig. 6.

<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/6-charger.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 6. USB-based power supply for Raspberry Pi.</p>


8) Five sets of distributed generation units (with DSP 28335 as their on-board controller), as shown in the Fig. 7.

<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/7-converters.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 7. Distributed generation units.</p>

> Note:
> It should be noted that in Application 1, Raspberry Pi based controllers are used and no on-board DSP is used.
 

9) Power supplies, including solar panels, photovoltaic simulators, batteries and DC power supplies
- Solar panels, photovoltaic simulators, batteries (shown in the Fig. 8.)
<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/8-IMG_20231114_151932.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 8. Solar panels.</p>
 
- DC power supplies (shown in the Fig. 9.)
<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/9-IMG_20210415_104841.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 9. DC power supplies.</p>
 
10) Tie lines (emulating 9 buses in the microgrid), as shown in the Fig. 10.

<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/10-IMG_20231114_173637.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 10. Tie lines.</p>

11) Five resistive loads, as shown in Fig. 10.

12) High precision oscilloscopes, as shown in the Fig. 11.
<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/11-IMG_20231109_234915.jpg?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 11. High precision oscilloscopes.</p>

## 2. Software requirements

1) Ubuntu virtual machine
> MATLAB and a cross-compilation environment for Ubuntu and Raspberry Pi for compiling control algorithms is built in the Ubuntu virtual machine.

2) Navicat
> Navicat connects to the NCSLAB database in order to use the one-click download feature of the algorithm.

3) VNC
> The VNC is used to remotely control the Raspberry Pi-based controller on the PC, and also to quickly import the experimental data to the PC. In addition, it is also responsible for monitoring the operational status of the blockchain.

4) Recvn file
> The Recvn file is used to receive compiled programs from the computer on the Raspberry Pi, and can also be used to start and run programs, and to connect to the NetContop real-time monitoring software developed by our group.

5) NCSLAB

> The NCSLAB platform is used to compile and implement a one-click download of multi-objective algorithms. The NCSLAB platform is a commercially available software platform developed by the research team, which has not been open-sourced for intellectual property reasons. More information about the NCSLAB environment can be found at https://www.powersim.whu.edu.cn/react/?lang=en-US.
- User interface of NCSLAB
<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/12-NCSLAB_interface.png?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 12. User interface of NCSLAB.</p>
 
## 3. Network configuration 

Network configuration Raspberry Pi. Make sure the Raspberry Pi is on the same network segment as the wireless route.

1) Open a terminal window in the Raspberry Pi's graphical interface

2) Determine the network interface

3) Find the current network configuration

4) Edit the network configuration file

5) Save and close the configuration file

6) Restart network service

7) Verifying the network configuration

> Note: The network configuration table for each node can be found in the Raspberrypi_ip.txt file

## 4. Implementation of the PoT-based secondary control algorithm

#### 4.1 Hardware and control parameters of the system

Hardware parameters and control parameters can be found in the parameter folder xxx.

#### 4.2 Configure the Raspberry Pi
Configure the ASDM and the UDP communication of each blockchain node, and set the URLs and ports of each node as shown below.
``` c
int remote_port = u(0); //23000; //SET_LOCAL IP PORT
addr.sin_family = AF INET;
addr.sin_port = htons(remote_port);
addr.sin_addr.s_addr = inet_addr("192.168.46.27");
```

####  4.3 Algorithm design and implementation

The algorithms used for the Raspberry Pi have been compiled into executable files, please refer to the file with the suffix elf in this folder. The specific algorithm design is available in the MATLAB file at xx. The code can be run directly on a computer with MATLAB software installed.

## 5. Experimental procedure

1) Connect the converters, lines and loads according to the following figure and form a microgrid system.
<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig16.png?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 13. Block diagram of the electrical part of the IEEE 9-bus system with five power generation units.</p>
 
2) Connect the sampling Raspberry Pi to the hardware converter according to the interface relationships shown in the following figure.
<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig17_DataFlow_DCMG.png?raw=true" width="700" div align=center > </div>
 <p align="center">Fig. 14. Data flow of the IEEE 9-bus test bench with PoT-based blockchain.</p>
3) Use VNC to start the Raspberry Pi's on the 5 device side, as well as the Raspberry Pi's in the controllers that make up the blockchain network, making sure that they are on the same network segment as the NCSLAB and the computers with VNS. The NCSLAB is on the LAN at 192.168.1.106. This step is to ensure that NCSLAB can send each executable file to each Raspberry Pi with one click.

4) Each Raspberry Pi starts the receive programme `./recvn` and specify the listening port.

5) Select the Multi-Agent Algorithm One-Click Download feature of NCSLAB. This feature is still in beta and has not yet been updated to the NCSLAB webpage.

6) Test the Raspberry Pi to make sure it works.

7) Test the configuration of NCSLAB to ensure that the commands are issued and working properly.

8) Test the hardware circuits to ensure that the circuits are working properly.

9) Start the distributed generation power supply and set each power supply according to the parameters in the manuscript.

10) Activate the local droop control and check that the operation indicators are reasonable. In particular, check the electrical circuits for short circuits and other safety hazards.

11) Ensure that the configuration software of NCSLAB is successfully connected to the Raspberry Pi. Download each executable file.

12) Issue commands to start the control programme using the configuration software of NCSLAB. The programme automatically performs the following three steps: performs a one-minute wait, at which time the duty cycle is 0; then runs the local droop control, at which time there is no communication between the generating units; and activates the secondary controller after 5 s.

13) Observe the operational status of the system. For example, waveforms are observed with oscilloscopes and the operational status of each blockchain node is monitored with VNC Viewer.
