


# Hardware Requirements and Experimental Instructions


This is the hardware requirements and experimental instructions of for **Application 3**. The system architecture corresponding to Application 3 is shown below.
> Note: In this application, onboard controller is used, which is different from previous two applications.



## Description

This application has implemented the PFC-based secondary control strategy for renewable energy power systems on Ethereum. The architecture of the closed-loop system is shown below. 

<div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig3/Fig2_PFC_logic.png?raw=true" div align=center > </div>
<p align="center">Fig. 1 Architecture of a REPS with the PFC-based regulation strategy.</p>

 
During the system process, the data transmission between the generator unit and the PFC controller is performed on Ethereum. This system adopts VNC access to the local area network. Therefore, the whole system can be divided into three layers.
* The first layer is the Secondary Controller Layer (SCL). One Raspberry Pi is deployed to accomplish this function.
* The second layer is the Signal Relay Layer (SRL). It contains seven Raspberry Pi as seven nodes forming the P2P network.
* The third layer is the Sampling and Actuator Layer (SAL). Five DSP in this layer are respectively connected to five DGUs.

Fig.2 shows the data flow between these three layers.

 <div align=center><img src="https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/Fig3/logic_Ethereum-DPoT-DSP.jpg?raw=true" width="400" div align=center > </div>
<center> Fig. 2 Data flow of the PFC-assisted microgrid system based on the Ethereum platform. </center>

The procedure for conducting the experiment is as follows.

1. Initialize hardware specifications and control parameters for the controller.
2. Each local DSP in SAL receives the sampled system measurement $y­_{p,i}$ where $i=1, \cdots, N$, and the same below.
3. If secondary control is not activated, i.e., when it is at the droop control phase, each DSP generates the control signal $u­_{p,i}$ using the local measurement, and turn to step 8.
4. If secondary control is activated, each DSP communicates with Ethereum through the **RS-485** serial port, and sends $y­_{p,i}$ to Ethereum on all seven nodes in SRL. Ethereum further communicates with the SCL and sends their received sequence $[y­_{p,1}, y­_{p,2}, \cdots, y­_{p,N}]$ to it.
5. Since attacks, the measurement sequences arrived at SCL are not the same. So SCL executes MRP, and uses the trustworthy result to calculate control signals $u=[u_{c,1}, u_{c,2}, \cdots, u_{c,N}]$ for all DGUs by the secondary control law.
6. SCL also communicates with Ethereum and sends back these control signals to Ethereum on all nodes in SRL. Ethereum further sends the received signal $u_{c,i}$ to the corresponding DSP of DGU $i$ through the **RS-485** serial port.
7. Since attacks, the control signals arrived at DSP are not the same. So DSP executes MRP, and obtains the trustworthy $u_{p,i}$.
8. After obtaining the control signal, DSP sends it to IGBT in the DGU. Then return to step 2.

More details: 
* The control algorithm is programmed in Python to be implemented on the Raspberry Pi as the DPoT-based secondary controller. Other Raspberry Pi  deployed in the Ethereum-based cyber layer interact with Ethereum through the geth client and Web3.py. Data is transmitted through the wireless router. Smart contract corresponding to PFC is programmed using Solidity. Five DGUs form the physical system of the microgrid connected by power lines. The DSP embedded in each DGU is connected to the Raspberry Pi in SRL.

## Getting Started

### Dependencies

#### Hardware
- Raspberry Pi 4B
- Wireless router
- DSP 28335

#### Software

- Geth 1.9.10
- Remix 0.91
- Solidity 8.10.0
- Jupyter notebook 
- Web3.py 5.12.0
- Python 3.92
- CCS version 8.0 or above

### Installing

### Installation (Debian Linux for Raspberry Pi) 
#### Build Ethereum private chain
1. Download geth 1.9.10 from geth.ethereum.org and place it in the Raspberry Pi /home/pi/directory
2. Decompression geth 
```bash  
tar -zxvf geth-1.9.10-XXXXX.tar.gz
```
3. Configure paths and soft links
```bash
ln -s /usr/local/bin/geth /home/pi/geth/geth-1.9.10-XXXXX.tar.gz/geth
ln -s /usr/local/bin/puppeth /home/pi/geth/geth-1.9.10-XXXXX.tar.gz/puppet
```
4. Create nodes and accounts on each raspberry pi
```bash
mkdir devnet
cd devnet
mkdir data
geth --datadir account new
```
Prompt for password input. After successfully creating an account, the account hash will be displayed.

5. Record account and password
```bash
echo account hash >> account.txt
echo password >> password.txt
```
**Note**: Account hash and password should fill in the account hash displayed in the previous step and the password entered respectively.

6. Create Genesis Block
Start Puppeth
```bash
puppeth
```
Set private chain name
Set as devnet

Choose to create a new Genesis block
```
What would you like to do?
1. Show network stats
2. Configure new genesis
3. Track new remote server
4. Deploy network components
>2
```
Choose to create a new Genesis block from the template
```
What would you like to do?
1. Create new genesis from scratch
2. Import alredy existing genesis
>1
```
Select consensus mechanism
```
Which consensus engine to use?
1. Ethash - proof-of-work
2. Clique - proof-of-authority
>2 
```
Set the time to produce a Block to 0
```
How many seconds should blocks take?
>0
```
Specify authorization nodes and input account hashes for all nodes
```
Which accounts should be pre-funded?
> 0x.....(account hash 1)
> 0x.....(account hash 2)
> 0x.....(account hash 3)
...
account hash 1-3是各节点的账户哈希值
```
Specify Ethereum Private Chain Id
```
Specify your chain/network ID if you want an explicit one
>1516
```
Export initial block
```
What would you like to do?
1. Show network stats
2. Manage existing genesis
3. Track new remote components
>2
```
Ctrl+C exit to obtain the initialization Genesis block file for devnet.json

7. Initialize private chain
Copy the devnet.json file to each Raspberry Pi node through scp and initialize the private chain
```
geth --datadir data init devnet.json
```


8. Start the Ethereum geth client and cosole at each node
```bash
    geth --datadir data --networkid 1516 --port 30303 console
```
9. Establish communication between each node
Find the enode value at each node (Raspberry Pi)
```javascript
> admin.nodeInfo()
```
Record the node's enode value

Establishing mutual connections between nodes
```javascript
    admin.nodeAdd("enode://enode_value@IP:Port")
```
**Note**: `enode_value`, `IP` and `Port` are the enode value of the node to be connected, IP address and port number

Check the connections of each node
```javascript
    admin.peers
```
To complete the construction of the Ethereum private chain, you need to see the information of all node connections

#### Installation of Web3.py
1. Install Web3. py on node (Raspberry Pi)
```bash
pip install web3
```
2. Installing Jupyter Notebook
```bash
pip install jupyter
```
3. Enter the node directory and start Jupyter Notebook
```bash
cd devnet
jupyter notebook
```
4. Create a new Python file and test the installation of Web3.py
```python
from web3 import web3
w3.api
```
If the version number is displayed at this time, it indicates successful installation.


#### Building a DPoT new energy system with PFC strategy
1. Control node
Import the control node program ConNode.python

2. Plant node
Import plant side node program PltNode.py

### Executing program

1. Control node
Start the control side program ConNode.py
```bash
python3 ConNode.py
```
2. Relay node
Start the relay nodes program RlyNode.py
```bash
python3 RlyAttNode.py
```
3. Plant node
Start the plant side program PltNode.py
```bash
python3 PltPhyNode.py
```

4. DGUs

Use CCS version 8.0 or above

1) Burn to RAM
        Copy the file 28335_SAM_1nk.cmd to the DSP2833x_Libraries folder
        Excute: Compile - burn - run
 2)  Burn to FLASH
        Step 1: Copy the F28335. cmd file and DSP2833x_SemCopy.c file to DSP2833x_Libraries folder
        Step 2: Add two lines of code to the main function 
 ```c
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);  
    InitFlash();
```
        Step 3: Compile - Burn file DPoT.out
3)  9) Start the distributed generation power supply and set each power supply according to the parameters in the manuscript.

10) Activate the local droop control and check that the operation indicators are reasonable. In particular, check the electrical circuits for short circuits and other safety hazards.
Start DGUs
12) Issue commands to start the control programme using the configuration software of NCSLAB. The programme automatically performs the following three steps: performs a one-minute wait, at which time the duty cycle is 0; then runs the local droop control, at which time there is no communication between the generating units; and activates the secondary controller after 5 s.

13) Observe the operational status of the system. For example, waveforms are observed with oscilloscopes and the operational status of each blockchain node is monitored with VNC.
