
Here are the hardware requirements, experimental instructions and simulation codes for Application3 in the manuscript.

## Files


├─Hardware  
│  │  README.md  
│  │    
│  ├─Codes for DSP in plant side  
│  │  ├─cmd  
│  │  ├─Debug  
│  │  ├─include  
│  │  ├─lib  
│  │  └─source  
│  ├─Codes for PFC  
│  │      &emsp;CtlNode.py  
│  │      &emsp;PltPhyNode.py  
│  │      &emsp;RlyAttNode.py  
│  │        
│  └─Parameters  
│   &emsp;   │  Parameters_LFC.m  
│   &emsp;   │    
│   &emsp;   └─Cal_cons    
│   &emsp;        &emsp;  &emsp; conRegularization.m  
│   &emsp;        &emsp;  &emsp; cons.mat  
│   &emsp;        &emsp;  &emsp; constraintTrans.m  
│   &emsp;        &emsp;  &emsp; constraintTransT.m  
│   &emsp;        &emsp;  &emsp; constraintVisualization.m  
│   &emsp;        &emsp;  &emsp; Initialize.m  
│   &emsp;        &emsp;  &emsp; lcon2vert.m  
│   &emsp;        &emsp;  &emsp; Main.m  
│   &emsp;        &emsp;  &emsp; MinkowskiSum.m  
│   &emsp;        &emsp;  &emsp; mRPIs.m  
│   &emsp;        &emsp;  &emsp; PontryaginDif.m  
│   &emsp;        &emsp;  &emsp; removeRedundantConstraints.m  
│   &emsp;        &emsp;  &emsp; setScalar.m  
│   &emsp;        &emsp;  &emsp; setScalarVertex.m  
│   &emsp;        &emsp;  &emsp; vert2lcon.m  
│              
├─SemiHardware    
│   &emsp;   CtlNode.py  
│   &emsp;   PltSimNode.py  
│   &emsp;   README.md  
│   &emsp;   RlyAttNode.py  
│   
└─Simulation  
&emsp;    │  README.md  
&emsp;    │    
&emsp;    └─Main System    
&emsp; &emsp;       │  A_all.mat  
&emsp; &emsp;       │  B_all.mat  
&emsp; &emsp;       │  Initialize.m  
&emsp; &emsp;       │  MainSystem.m  
&emsp; &emsp;       │  MicrogridOutput.gif  
&emsp; &emsp;       │    
&emsp;        └─SystemMatrices  
&emsp; &emsp;  &emsp;             A_all.mat  
&emsp; &emsp;  &emsp;             B_all.mat 

