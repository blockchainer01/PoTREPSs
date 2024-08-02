// TI File $Revision: /main/5 $
// Checkin $Date: October 23, 2007   13:34:09 $
//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define ADC_usDELAY  5000L

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void)
{
    extern void DSP28x_usDelay(Uint32 Count);
    
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
	ADC_cal();
	EDIS;


    AdcRegs.ADCTRL1.bit.ACQ_PS = 2;  
	AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1=1;//enable  Epwm SOC
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0; //at every finishing convition interruput
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1; //enable interruput fuction 
    AdcRegs.ADCTRL3.bit.ADCCLKPS = 0;
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;        // 1  double mode
    AdcRegs.ADCTRL1.bit.CONT_RUN = 0; 
	AdcRegs.ADCMAXCONV.bit.MAX_CONV1=0x0A;//11通道采集数据
	AdcRegs.ADCTRL3.bit.SMODE_SEL=0;// 同步采样
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 15;       //ia
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 1;        //ic
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 8;        //uab
    AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 12;       //ubc
    AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 5;        //udc
    AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 0;        //idc
    AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 6;        //temp
    AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 4;        //IA
    AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 11;       //IB
    AdcRegs.ADCCHSELSEQ3.bit.CONV09 = 13;       //IC

	AdcRegs.ADCTRL3.bit.ADCBGRFDN = 3;	//bandgap/reference/ADC circuits is POWER ON
	DELAY_US(1);
	AdcRegs.ADCTRL3.bit.ADCPWDN = 1;	//others is POWER ON
//	AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits
    DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels
 
}

//===========================================================================
// End of file.
//===========================================================================
