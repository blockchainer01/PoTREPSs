


Here are the hardware requirements, experimental instructions and simulation codes for Application2 in the manuscript.

## Files


│    
├─Hardware  
│  │  README.md   
│  │    
│  ├─Area1  
│  │      &emsp;ADSM_Area1.elf  
│  │      &emsp;Node1_Area1.elf  
│  │      &emsp;Node2_Area1.elf  
│  │      &emsp;Node3_Area1.elf  
│  │      &emsp;Node4_Area1.elf  
│  │      &emsp;Node5_Area1.elf  
│  │      &emsp;Node6_Area1.elf  
│  │      &emsp;Node7_Area1.elf  
│  │        
│  ├─Area2  
│  │      &emsp;ADSM_Area2.elf  
│  │      &emsp;Node1_Area2.elf  
│  │      &emsp;Node2_Area2.elf  
│  │      &emsp;Node3_Area2.elf  
│  │      &emsp;Node4_Area2.elf  
│  │      &emsp;Node5_Area2.elf  
│  │      &emsp;Node6_Area2.elf  
│  │      &emsp;Node7_Area2.elf  
│  │        
│  ├─Area3  
│  │      &emsp;ADSM_Area3.elf  
│  │      &emsp;Node1_Area3.elf  
│  │      &emsp;Node2_Area3.elf  
│  │      &emsp;Node3_Area3.elf  
│  │      &emsp;Node4_Area3.elf  
│  │      &emsp;Node5_Area3.elf  
│  │      &emsp;Node6_Area3.elf  
│  │      &emsp;Node7_Area3.elf  
│  │        
│  ├─HIL_LFC_UDP  
│  │  └─models  
│  │      └─AsyncIP_sl  
│  │              &emsp;&emsp;&emsp;AsyncIP.c  
│  │              &emsp;&emsp;&emsp;AsyncIPUtils.h  
│  │              &emsp;&emsp;&emsp;AsyncIP_sl.slx  
│  │              &emsp;&emsp;&emsp;asyncip_sl_2_sc_console.slx  
│  │                
│  ├─Parameters  
│  │  │  &emsp;Parameters_PoTdcMG.m  
│  │  │    
│  │  └─Cal_cons  
│  │          &emsp;&emsp;conRegularization.m  
│  │          &emsp;&emsp;cons.mat  
│  │          &emsp;&emsp;constraintTrans.m  
│  │          &emsp;&emsp;constraintTransT.m  
│  │          &emsp;&emsp;constraintVisualization.m  
│  │          &emsp;&emsp;Initialize.m  
│  │          &emsp;&emsp;lcon2vert.m  
│  │          &emsp;&emsp;Main.m  
│  │          &emsp;&emsp;MinkowskiSum.m  
│  │          &emsp;&emsp;mRPIs.m  
│  │          &emsp;&emsp;PontryaginDif.m  
│  │          &emsp;&emsp;removeRedundantConstraints.m  
│  │          &emsp;&emsp;setScalar.m  
│  │          &emsp;&emsp;setScalarVertex.m  
│  │          &emsp;&emsp;vert2lcon.m  
│  │            
│  └─raspberry  
│          &emsp;&emsp;main  
│          &emsp;&emsp;main.c  
│          &emsp;&emsp;run_pack.sh  
│          &emsp;&emsp;udp_receive.c  
│          &emsp;&emsp;udp_receive.h  
│          &emsp;&emsp;udp_send.c  
│          &emsp;&emsp;udp_send.h  
│            
└─Simulation  
    │  README.md  
    │    
    ├─Cal_cons  
    │      &emsp;conRegularization.m  
    │      &emsp;cons.mat  
    │      &emsp;constraintTrans.m  
    │      &emsp;constraintTransT.m  
    │      &emsp;constraintVisualization.m  
    │      &emsp;Initialize.m  
    │      &emsp;lcon2vert.m  
    │      &emsp;Main.m  
    │      &emsp;MinkowskiSum.m  
    │      &emsp;mRPIs.m  
    │      &emsp;PontryaginDif.m  
    │      &emsp;removeRedundantConstraints.m  
    │      &emsp;setScalar.m  
    │      &emsp;setScalarVertex.m  
    │      &emsp;vert2lcon.m  
    │        
    └─Main System  
            &emsp;&emsp;cons.mat  
            &emsp;&emsp;Game.m  
            &emsp;&emsp;GetState.m  
            &emsp;&emsp;Initialize.m  
            &emsp;&emsp;MainSystem.m  
            &emsp;&emsp;MM4.m  
            &emsp;&emsp;PlotAll.m  
            &emsp;&emsp;result_strategy.mat  
            &emsp;&emsp;StateResponses.gif  
