// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:25 $
//###########################################################################
//
// FILE:	DSP2833x_Gpio.c
//
// TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
   // Each GPIO pin can be: 
   // a) a GPIO input/output
   // b) peripheral function 1
   // c) peripheral function 2
   // d) peripheral function 3
   // By default, all are GPIO Inputs 
   GpioCtrlRegs.GPAMUX1.all = 0x0000;     // GPIO functionality GPIO0-GPIO15
   GpioCtrlRegs.GPAMUX2.all = 0x0000;     // GPIO functionality GPIO16-GPIO31
   GpioCtrlRegs.GPBMUX1.all = 0x0000;     // GPIO functionality GPIO32-GPIO39
   GpioCtrlRegs.GPBMUX2.all = 0x0000;     // GPIO functionality GPIO48-GPIO63
   GpioCtrlRegs.GPCMUX1.all = 0x0000;     // GPIO functionality GPIO64-GPIO79
   GpioCtrlRegs.GPCMUX2.all = 0x0000;     // GPIO functionality GPIO80-GPIO95

   GpioCtrlRegs.GPADIR.all = 0x0000;      // GPIO0-GPIO31 are inputs
   GpioCtrlRegs.GPBDIR.all = 0x0000;      // GPIO32-GPIO63 are inputs   
   GpioCtrlRegs.GPCDIR.all = 0x0000;      // GPI064-GPIO95 are inputs

   // Each input can have different qualification
   // a) input synchronized to SYSCLKOUT
   // b) input qualified by a sampling window
   // c) input sent asynchronously (valid for peripheral inputs only)
   GpioCtrlRegs.GPAQSEL1.all = 0x0000;    // GPIO0-GPIO15 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPAQSEL2.all = 0x0000;    // GPIO16-GPIO31 Synch to SYSCLKOUT
   GpioCtrlRegs.GPBQSEL1.all = 0x0000;    // GPIO32-GPIO39 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPBQSEL2.all = 0x0002;    // GPIO48-GPIO63 Synch to SYSCLKOUT //temp_input

   // Pull-ups can be enabled or disabled. 
   GpioCtrlRegs.GPAPUD.all = 0x0000;      // Pullup's enabled GPIO0-GPIO31
   GpioCtrlRegs.GPBPUD.all = 0x0000;      // Pullup's enabled GPIO32-GPIO63
   GpioCtrlRegs.GPCPUD.all = 0x0000;      // Pullup's enabled GPIO64-GPIO79

   GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;     //w5300 rst

   GpioDataRegs.GPBSET.bit.GPIO61 = 1;     //PWM
   GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;     //PWM EN DIR
   GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;     //93c46 CS
   GpioCtrlRegs.GPCDIR.bit.GPIO86 = 1;     //93c46 DI
   GpioCtrlRegs.GPCDIR.bit.GPIO87 = 1;     //93c46 CLK
   GpioDataRegs.GPBCLEAR.bit.GPIO39 = 1;
   GpioDataRegs.GPCCLEAR.bit.GPIO86 = 1;
   GpioDataRegs.GPCCLEAR.bit.GPIO87 = 1;

//   GpioCtrlRegs.GPCDIR.bit.GPIO83 = 0;     //输入  DO

   GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;     //输出D1
   GpioCtrlRegs.GPCDIR.bit.GPIO82 = 1;     //输出D2
   GpioCtrlRegs.GPBDIR.bit.GPIO55 = 1;      //输出D3
   GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;      //输出D4
   GpioCtrlRegs.GPBDIR.bit.GPIO59 = 1;     //输出D5
   GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;     //输出 D6
   GpioDataRegs.GPACLEAR.bit.GPIO29 = 1;
   GpioDataRegs.GPBCLEAR.bit.GPIO59 = 1;
   GpioDataRegs.GPBCLEAR.bit.GPIO55 = 1;
   GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;
   GpioDataRegs.GPBCLEAR.bit.GPIO58 = 1;
   GpioDataRegs.GPCCLEAR.bit.GPIO82 = 1;

   GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;//SPI CS

   GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;//485ch1  方向脚
   GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;//485ch2  方向脚
   GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;//默认为接收状态
   GpioDataRegs.GPACLEAR.bit.GPIO14 = 1;//默认为接收状态

   GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;//PCS 风机
   GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;

   GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;//245使能脚

    EDIS;
}	
	
//===========================================================================
// End of file.
//===========================================================================
