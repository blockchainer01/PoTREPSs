
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
│  │      CtlNode.py
│  │      PltPhyNode.py
│  │      RlyAttNode.py
│  │      
│  └─Parameters
│      │  Parameters_LFC.m
│      │  
│      └─Cal_cons
│              conRegularization.m
│              cons.mat
│              constraintTrans.m
│              constraintTransT.m
│              constraintVisualization.m
│              Initialize.m
│              lcon2vert.m
│              Main.m
│              MinkowskiSum.m
│              mRPIs.m
│              PontryaginDif.m
│              removeRedundantConstraints.m
│              setScalar.m
│              setScalarVertex.m
│              vert2lcon.m
│              
├─SemiHardware
│      CtlNode.py
│      PltSimNode.py
│      README.md
│      RlyAttNode.py
│      
└─Simulation
    │  README.md
    │  
    └─Main System
        │  A_all.mat
        │  B_all.mat
        │  Initialize.m
        │  MainSystem.m
        │  MicrogridOutput.gif
        │  
        └─SystemMatrices
                A_all.mat
                B_all.mat
                

