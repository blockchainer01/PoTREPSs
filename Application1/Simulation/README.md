


# Simulation Code and Simulation Instructions

This is the simulation code for **Application 1** and the corresponding instructions to run it.

## Files

│  └─Simulation    
│      │    
│      ├─Cal_cons    
│      │    &emsp;  conRegularization.m        
│      │    &emsp;  cons.mat    
│      │    &emsp;  constraintTrans.m     
│      │    &emsp;  constraintTransT.m    
│      │    &emsp;  constraintVisualization.m  
│      │    &emsp;  Initialize.m  
│      │    &emsp;  lcon2vert.m  
│      │    &emsp;  Main.m  
│      │    &emsp;  MinkowskiSum.m  
│      │    &emsp;  mRPIs.m  
│      │    &emsp;  PontryaginDif.m  
│      │    &emsp;  removeRedundantConstraints.m  
│      │    &emsp;  setScalar.m  
│      │    &emsp;  setScalarVertex.m  
│      │    &emsp;  vert2lcon.m  
│      │        
│      └─Main System  
│       &emsp;&emsp;       cons.mat  
│       &emsp; &emsp;      Game.m  
│       &emsp; &emsp;      GetState.m  
│       &emsp;  &emsp;     Initialize.m  
│       &emsp; &emsp;      MainSystem.m  
│       &emsp;  &emsp;     MicrogridOutput.gif  
│       &emsp;  &emsp;     MM4.m  
│       &emsp;  &emsp;     PlotAll.m  
│       &emsp;  &emsp;     result_strategy.mat  

## Requirements
MATLAB software is properly installed and optimization solvers cplex, gurobi, xpress, copt, mosek are added.

## Run procedure
* Step 1. Run the file "Main.m" in the folder "Cal_cons".
* Step 2. Move the generated parameter data "cons.mat" to the folder "Main System".
* Step 3. Run the file "MainSystem.m" in the folder "Main System".

## Simplified procedure
Since the calculation of parameters has been conducted in advance, Step 3 can be performed directly.

##  See the results directly
Since the evolution of the system also has been run in advance, you can view the regulation process directly from the figure below or by clicking on the picture "MicrogridOutput.gif" in the folder "Main System".
> * Output results
![PoTResultsMG](https://github.com/blockchainer01/Software_platform_PoT/blob/main/Figures/MicrogridOutput.gif?raw=true)
