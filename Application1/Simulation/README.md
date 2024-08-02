


# Simulation Code and Simulation Instructions

This is the simulation code for **Application 1** and the corresponding instructions to run it.

## Files

│  └─Simulation
│      │  Running instructions.txt
│      │  
│      ├─Cal_cons
│      │      conRegularization.m
│      │      cons.mat
│      │      constraintTrans.m
│      │      constraintTransT.m
│      │      constraintVisualization.m
│      │      Initialize.m
│      │      lcon2vert.m
│      │      Main.m
│      │      MinkowskiSum.m
│      │      mRPIs.m
│      │      PontryaginDif.m
│      │      removeRedundantConstraints.m
│      │      setScalar.m
│      │      setScalarVertex.m
│      │      vert2lcon.m
│      │      
│      └─Main System
│              cons.mat
│              Game.m
│              GetState.m
│              Initialize.m
│              MainSystem.m
│              MicrogridOutput.gif
│              MM4.m
│              PlotAll.m
│              result_strategy.mat

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
