


Here are the hardware requirements, experimental instructions and simulation codes for Application2 in the manuscript.

## Files


│  
├─Hardware  
│  │  README.md  
│  │    
│  ├─Area1  
│  │      ADSM_Area1.elf  
│  │      Node1_Area1.elf  
│  │      Node2_Area1.elf  
│  │      Node3_Area1.elf  
│  │      Node4_Area1.elf  
│  │      Node5_Area1.elf  
│  │      Node6_Area1.elf  
│  │      Node7_Area1.elf  
│  │        
│  ├─Area2  
│  │      ADSM_Area2.elf  
│  │      Node1_Area2.elf  
│  │      Node2_Area2.elf  
│  │      Node3_Area2.elf  
│  │      Node4_Area2.elf  
│  │      Node5_Area2.elf  
│  │      Node6_Area2.elf  
│  │      Node7_Area2.elf  
│  │        
│  ├─Area3  
│  │      ADSM_Area3.elf  
│  │      Node1_Area3.elf  
│  │      Node2_Area3.elf  
│  │      Node3_Area3.elf  
│  │      Node4_Area3.elf  
│  │      Node5_Area3.elf  
│  │      Node6_Area3.elf  
│  │      Node7_Area3.elf  
│  │        
│  ├─HIL_LFC_UDP  
│  │  └─models  
│  │      └─AsyncIP_sl  
│  │              AsyncIP.c  
│  │              AsyncIPUtils.h  
│  │              AsyncIP_sl.slx  
│  │              asyncip_sl_2_sc_console.slx  
│  │                
│  ├─Parameters  
│  │  │  Parameters_PoTdcMG.m  
│  │  │    
│  │  └─Cal_cons  
│  │          conRegularization.m  
│  │          cons.mat  
│  │          constraintTrans.m  
│  │          constraintTransT.m  
│  │          constraintVisualization.m  
│  │          Initialize.m  
│  │          lcon2vert.m  
│  │          Main.m  
│  │          MinkowskiSum.m  
│  │          mRPIs.m  
│  │          PontryaginDif.m  
│  │          removeRedundantConstraints.m  
│  │          setScalar.m  
│  │          setScalarVertex.m  
│  │          vert2lcon.m  
│  │            
│  └─raspberry  
│          main  
│          main.c  
│          run_pack.sh  
│          udp_receive.c  
│          udp_receive.h  
│          udp_send.c  
│          udp_send.h  
│            
└─Simulation  
    │  README.md  
    │    
    ├─Cal_cons  
    │      conRegularization.m  
    │      cons.mat  
    │      constraintTrans.m  
    │      constraintTransT.m  
    │      constraintVisualization.m  
    │      Initialize.m  
    │      lcon2vert.m  
    │      Main.m  
    │      MinkowskiSum.m  
    │      mRPIs.m  
    │      PontryaginDif.m  
    │      removeRedundantConstraints.m  
    │      setScalar.m  
    │      setScalarVertex.m   
    │      vert2lcon.m  
    │        
    └─Main System  
            cons.mat  
            Game.m  
            GetState.m  
            Initialize.m  
            MainSystem.m  
            MM4.m  
            PlotAll.m  
            result_strategy.mat  
            StateResponses.gif  
           
