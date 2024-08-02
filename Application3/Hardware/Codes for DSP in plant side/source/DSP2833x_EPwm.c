// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:19 $
//###########################################################################
//
// FILE:   DSP2833x_EPwm.c
//
// TITLE:  DSP2833x ePWM Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitEPwm: 
//---------------------------------------------------------------------------
// This function initializes the ePWM(s) to a known state.
//
void TZCLR(void)
{
	EALLOW;
	EPwm1Regs.TZCLR.bit.OST	= 1;
	EPwm2Regs.TZCLR.bit.OST	= 1;
	EPwm3Regs.TZCLR.bit.OST	= 1;
	EDIS;
}

void InitEPwm(void)
{
	EPwm1Regs.TBPRD 			= EPWM_TBPRD;
	EPwm1Regs.TBCTR 			= 0x0000;
	EPwm1Regs.TBPHS.half.TBPHS 	= 0;
	EPwm1Regs.CMPA.half.CMPA	= 0;

//	EPwm1Regs.TBCTL.bit.FREE_SOFT 	= 0x2;
	EPwm1Regs.TBCTL.bit.CLKDIV		= TB_DIV1;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV	= TB_DIV2;	//TBCLK=SYSCLK/(CLKDIV*HSPCLKDIV)
	EPwm1Regs.TBCTL.bit.SYNCOSEL	= TB_CTR_ZERO;
	EPwm1Regs.TBCTL.bit.PRDLD		= 1;
	EPwm1Regs.TBCTL.bit.CTRMODE		= 0x2;	//=2,up-down count mode	
	EPwm1Regs.TBCTL.bit.PHSEN		= TB_DISABLE;

	EPwm1Regs.CMPCTL.bit.SHDWAMODE 	= TB_SHADOW;		//0,shadow mode
	EPwm1Regs.CMPCTL.bit.LOADAMODE 	= CC_CTR_ZERO;  

	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;	//active high mode,
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;
	
	EPwm1Regs.DBCTL.bit.IN_MODE		= DBA_ALL;		//EPWM1A IN
	EPwm1Regs.DBCTL.bit.POLSEL		= DB_ACTV_LOC;		//AHC mode,b invert
	EPwm1Regs.DBCTL.bit.OUT_MODE	= DB_FULL_ENABLE;		//full enable
	
	EPwm1Regs.DBRED = 75;
	EPwm1Regs.DBFED = 75;

	EPwm2Regs.TBPRD 			= EPWM_TBPRD;
	EPwm2Regs.TBCTR 			= 0x0000;
	EPwm2Regs.TBPHS.half.TBPHS 	= 0;
	EPwm2Regs.CMPA.half.CMPA	= 0;

//	EPwm2Regs.TBCTL.bit.FREE_SOFT 	= 0x2;
	EPwm2Regs.TBCTL.bit.CLKDIV		= TB_DIV1;
	EPwm2Regs.TBCTL.bit.HSPCLKDIV	= TB_DIV2;	//TBCLK=SYSCLK/(CLKDIV*HSPCLKDIV)
	EPwm2Regs.TBCTL.bit.SYNCOSEL	= TB_SYNC_IN;
	EPwm2Regs.TBCTL.bit.PRDLD		= 1;
	EPwm2Regs.TBCTL.bit.CTRMODE		= 0x2;	//=2,up-down count mode	
	EPwm2Regs.TBCTL.bit.PHSEN		= TB_ENABLE;

	EPwm2Regs.CMPCTL.bit.SHDWAMODE 	= TB_SHADOW;		//0,shadow mode
	EPwm2Regs.CMPCTL.bit.LOADAMODE 	= CC_CTR_ZERO;  

	EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;	//
	EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;
	
	EPwm2Regs.DBCTL.bit.IN_MODE		= DBA_ALL;		//EPWM1A IN
	EPwm2Regs.DBCTL.bit.POLSEL		= DB_ACTV_LOC;		//AHC mode,b invert
	EPwm2Regs.DBCTL.bit.OUT_MODE	= DB_FULL_ENABLE;		//full enable
	
	EPwm2Regs.DBRED = 75;
	EPwm2Regs.DBFED = 75;


	EPwm3Regs.TBPRD 			= EPWM_TBPRD;
	EPwm3Regs.TBCTR 			= 0x0000;
	EPwm3Regs.TBPHS.half.TBPHS 	= 0;
	EPwm3Regs.CMPA.half.CMPA	= 0;

//	EPwm3Regs.TBCTL.bit.FREE_SOFT 	= 0x2;
	EPwm3Regs.TBCTL.bit.CLKDIV		= TB_DIV1;
	EPwm3Regs.TBCTL.bit.HSPCLKDIV	= TB_DIV2;	//TBCLK=SYSCLK/(CLKDIV*HSPCLKDIV)
	EPwm3Regs.TBCTL.bit.SYNCOSEL	= TB_SYNC_IN;
	EPwm3Regs.TBCTL.bit.PRDLD		= 1;
	EPwm3Regs.TBCTL.bit.CTRMODE		= 0x2;	//=2,up-down count mode	
	EPwm3Regs.TBCTL.bit.PHSEN		= TB_ENABLE;

	EPwm3Regs.CMPCTL.bit.SHDWAMODE 	= TB_SHADOW;		//0,shadow mode
	EPwm3Regs.CMPCTL.bit.LOADAMODE 	= CC_CTR_ZERO;  

	EPwm3Regs.AQCTLA.bit.CAU = AQ_SET;
	EPwm3Regs.AQCTLA.bit.CAD = AQ_CLEAR;
	
	EPwm3Regs.DBCTL.bit.IN_MODE		= DBA_ALL;		//EPWM1A IN
	EPwm3Regs.DBCTL.bit.POLSEL		= DB_ACTV_LOC;		//AHC mode,b invert
	EPwm3Regs.DBCTL.bit.OUT_MODE	= DB_FULL_ENABLE;		//full enable
	
	EPwm3Regs.DBRED = 75;
	EPwm3Regs.DBFED = 75;

	EALLOW;
	EPwm1Regs.TZSEL.bit.OSHT1	= TZ_ENABLE;
	EPwm1Regs.TZCTL.bit.TZA		= TZ_FORCE_HI;
	EPwm1Regs.TZCTL.bit.TZB		= TZ_FORCE_HI;

	EPwm2Regs.TZSEL.bit.OSHT1	= TZ_ENABLE;
	EPwm2Regs.TZCTL.bit.TZA		= TZ_FORCE_HI;
	EPwm2Regs.TZCTL.bit.TZB		= TZ_FORCE_HI;

	EPwm3Regs.TZSEL.bit.OSHT1	= TZ_ENABLE;
	EPwm3Regs.TZCTL.bit.TZA		= TZ_FORCE_HI;
	EPwm3Regs.TZCTL.bit.TZB		= TZ_FORCE_HI;
	EDIS;

    EPwm1Regs.ETSEL.bit.INTEN = 1;
    EPwm1Regs.ETSEL.bit.INTSEL= ET_CTR_PRD;
    EPwm1Regs.ETPS.bit.INTCNT = ET_1ST;
    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;

    EPwm1Regs.ETSEL.bit.SOCAEN=1;//  enable soc TO START ADC
    EPwm1Regs.ETSEL.bit.SOCASEL=ET_CTR_PRD;//soc at prd
    EPwm1Regs.ETPS.bit.SOCAPRD= 1;
}

//---------------------------------------------------------------------------
// Example: InitEPwmGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 

void InitEPwmGpio(void)
{
   InitEPwm1Gpio();
   InitEPwm2Gpio();
   InitEPwm3Gpio();
   InitEPwm4Gpio();
   InitEPwm5Gpio();
   InitEPwm6Gpio();

}

void InitEPwm1Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // Enable pull-up on GPIO1 (EPWM1B)   
   
/* Configure ePWM-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM1 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
   
    EDIS;
}

void InitEPwm2Gpio(void)
{
   EALLOW;
	
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Enable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;    // Enable pull-up on GPIO3 (EPWM3B)

/* Configure ePWM-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM2 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
   
    EDIS;
}

void InitEPwm3Gpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    // Enable pull-up on GPIO5 (EPWM3B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM3 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
	
    EDIS;
}

void InitEPwm4Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;    // Enable pull-up on GPIO7 (EPWM4B)

/* Configure ePWM-4 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM4 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
	
    EDIS;
}

void InitEPwm5Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;    // Enable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;    // Enable pull-up on GPIO9 (EPWM5B)

/* Configure ePWM-5 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
	
    EDIS;
}

void InitEPwm6Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;    // Enable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up on GPIO11 (EPWM6B)

/* Configure ePWM-6 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B
	
    EDIS;
} 

//---------------------------------------------------------------------------
// Example: InitEPwmSyncGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM Synch pins
//

void InitEPwmSyncGpio(void)
{

   EALLOW;

/* Configure EPWMSYNCI  */
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pull-up on GPIO32 (EPWMSYNCI)    

/* Set qualification for selected pins to asynch only */
// This will select synch to SYSCLKOUT for the selected pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;   // Synch to SYSCLKOUT GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0;  // Synch to SYSCLKOUT GPIO32 (EPWMSYNCI)    

/* Configure EPwmSync pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be EPwmSync functional pins.
// Comment out other unwanted lines.   

   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 2;    // Enable pull-up on GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 2;   // Enable pull-up on GPIO32 (EPWMSYNCI)    



/* Configure EPWMSYNC0  */

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

// GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;   // Enable pull-up on GPIO33 (EPWMSYNC0)    

// GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 3;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2;   // Enable pull-up on GPIO33 (EPWMSYNC0)    

}



//---------------------------------------------------------------------------
// Example: InitTzGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as Trip Zone (TZ) pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 

void InitTzGpio(void)
{
   EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Enable pull-up on GPIO12 (TZ1)
//   GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;    // Enable pull-up on GPIO13 (TZ2)
//   GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up on GPIO14 (TZ3)
//   GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up on GPIO15 (TZ4)

//  GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;    // Enable pull-up on GPIO16 (TZ5)
// GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up on GPIO28 (TZ5)

   GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;    // Enable pull-up on GPIO17 (TZ6) 
// GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;    // Enable pull-up on GPIO29 (TZ6)  
   
/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 1;  // Asynch input GPIO12 (TZ1)
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3;  // Asynch input GPIO13 (TZ2)
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;  // Asynch input GPIO14 (TZ3)
//   GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;  // Asynch input GPIO15 (TZ4)

//   GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;  // Asynch input GPIO16 (TZ5)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (TZ5)

//   GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;  // Asynch input GPIO17 (TZ6) 
// GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3;  // Asynch input GPIO29 (TZ6)  
	GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0x32;
   
/* Configure TZ pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be TZ functional pins.
// Comment out other unwanted lines.   
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // Configure GPIO12 as TZ1
//   GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;  // Configure GPIO13 as TZ2
//   GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;  // Configure GPIO14 as TZ3
//   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;  // Configure GPIO15 as TZ4

//   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3;  // Configure GPIO16 as TZ5
// GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // Configure GPIO28 as TZ5

//   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;  // Configure GPIO17 as TZ6               
// GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // Configure GPIO29 as TZ6  

   EDIS;
}



//===========================================================================
// End of file.
//===========================================================================
