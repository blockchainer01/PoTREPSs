#include "DSP2833x_Device.h"                    // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"                  // DSP2833x Examples Include File
#include <math.h>
//三相DCAC IGBT

#define CLARKE_DEFAULTS { 0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
              			} 	         									
                    
#define PARK_DEFAULTS {   0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
                          0,   \
					  }
            			                   
#define PIDIQ_DEFAULTS   { 	0,\
/*  Fdb   */            	0,\
/*  Err   */             	0,\
/*  Kp   */	               	2,\
/*  Up   */                 0,\
/*  Ui   */	               	0,\
/*  OutPreSat   */        	0,\
/*  OutMax   */             600,\
/*  OutMin   */        		-600,\
/*  Out   */                0,\
/*  Ki  */                 	0.00005,\
                            20.0,\
                            -20.0,\
						 }

#define PIDP_DEFAULTS   { 	0,\
/*  Fdb   */            	0,\
/*  Err   */             	0,\
/*  Kp   */	               	-0.2,\
/*  Up   */                 0,\
/*  Ui   */	               	0,\
/*  OutPreSat   */        	0,\
/*  OutMax   */             5,\
/*  OutMin   */        		-52,\
/*  Out   */                0,\
/*  Ki  */                 	0.01,\
						 } 

#define PIDVDC_DEFAULTS   { 0,\
/*  Fdb   */            	0,\
/*  Err   */             	0,\
/*  Kp   */	               	0.1,\
/*  Up   */                 0,\
/*  Ui   */	               	0,\
/*  OutPreSat   */        	0,\
/*  OutMax   */             3,\
/*  OutMin   */        		-5,\
/*  Out   */                0,\
/*  Ki  */                 	0.0002,\
                            20.0,\
                            -20.0,\
						  }
                   
#define IPARK_DEFAULTS {  0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
                          0.0, \
						  0.0, \
              		   }
					   
#define CURR_DEFAULTS {	1.25,\
						0.0,  \
						0.0,  \
						0.0,  \
						0.0,  \
						0.0,  \
						0.0,  \
						0.0,  \
					   }

				   
#define ISLAND_DEFAULTS  {\
/*V_pos*/                    0,\
/*Angle_pos*/				 0,\
/*F_sum*/					 0,\
/*V_sum*/					 0,\
/*V_grid[32]*/				 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
/*V_sin*/                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
/*Err_V*/					 0,\
/*Err_norm*/				 15,\
/*Err_Fre[16]*/              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},\
/*Err_F_sum*/				 0,\
/*Err_pos*/		    		 0,\
/*Err_F*/		    		 0,\
					      } 
#define SVGENDQ_DEFAULTS {	0,\
							0,\
							0,\
							0,\
							0,\
						 }
      

#define TCPIPDATA_DEFAULTS {	0,\
							    0,\
							    0,\
							   {0},\
						 }
#define TCPIPDATA1_DEFAULTS {  0,\
                               0,\
							   0,\
							   0,\
							   0,\
                               0.0,\
                               0.0,\
							   0.0,\
							   0.0,\
							   0.0,\
							   0.0,\
							   0.0,\
							   0.0,\
							   0.0,\
							   0.0,\
                              }
#define TCPIPDATA2_DEFAULTS {  0,\
							   0,\
							   0,\
							   {0.0},\
                            }

#define Dis_Para_DEFAULTS {\
						   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,\
						   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,\
						   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,\
						   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,0,\
						   0.004,1, 	 1199, 0.0008333333,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},\
                          0,    0,    0,    0,    0,    0,    0,    0,    0,\
                            }

#define Extre_DEFAULTS    {\
/*VAC Min & Max*/          -700,  40,  50,  260,   280, 700,\
/*VDC Min & Max*/          200,  240,  250,   750,   820,  850,\
/*iAC Min & Max*/          -80,  -30,  -20,    10,    30,  80,\
/*IDC & TEMP  Max*/        -5,   500,  -0,    85,    100,   71,\
                          } 

#define Energy_DEFAULTS	   {\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
							0,\
	                        3599971200230398157,\
	                        -1700000000000000000,\
	                        2.7778e-10f,\
                           } 

#define Uart1_DEFAULTS  {\
/*Tx_Data1*/             {0x01,0x04,0,0,0,0,0,0},\
/*Rx_Data1*/             {0,0,0,0,0,0,0,0},\
/*Tx_Data2*/             {0x01,0x00,0,0,0,0,0,0},\
/*Rx_Data2*/             {0,0,0,0,0,0,0,0},\
/*Rx_Disp*/              {0,0,0,0,0,0,0,0},\
/*Tx_Num1*/               8,\
/*Rx_Num1*/               32,\
/*Tx_Num2*/               8,\
/*Rx_Num2*/               8,\
                          NULL,\
/*Tx_Cnt*/                0,\
/*Rx_Cnt*/                0,\
/*Rx_Flag*/               0,\
/*Tx_Flag*/               0,\
                          1,\
                          0,\
                          0,\
                        }

#define MPPT_PNO_DEFAULTS {0,0,15,750,400,8,0,0,0,0,0,1,0}
/*-----------------------------------------------------------------------------
the end
-----------------------------------------------------------------------------*/								
CLARKE         V_clarke    = CLARKE_DEFAULTS;
CLARKE         I_clarke    = CLARKE_DEFAULTS;
PARK           V_park      = PARK_DEFAULTS;
PARK           I_park      = PARK_DEFAULTS;
IPARK          I_ipark     = IPARK_DEFAULTS;   
PIDREG         Id_pidreg   = PIDIQ_DEFAULTS;
PIDREG         Iq_pidreg   = PIDIQ_DEFAULTS;   
PIDREG         V_pidreg    = PIDVDC_DEFAULTS;
CURR_ADJ       V_CURR_ADJ  = CURR_DEFAULTS; 

ISLAND         V_ISLAND    = ISLAND_DEFAULTS;
SVGENDQ        svgen       = SVGENDQ_DEFAULTS;	//SVPWM初始化

TCPIPDATA1     Tcpdataaver  = TCPIPDATA1_DEFAULTS;
TCPIPDATA2     Tcpdatatest  = TCPIPDATA2_DEFAULTS;
Display		   Dis_Para		= Dis_Para_DEFAULTS;
Extremum	   Extre		= Extre_DEFAULTS;
Energy		   ENRG_Data	= Energy_DEFAULTS;

PIDREG		   Pset_pidreg	= PIDP_DEFAULTS;

Uart            Uart1       = Uart1_DEFAULTS;

MPPT_PNO_F     mppt_pno_ctrl = MPPT_PNO_DEFAULTS;

THREE_ANALYZ  ThreeAnalyz ={{0},0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,20000};
/*-----------------------------------------------------------------------------

-----------------------------------------------------------------------------*/	
Uint16  ReadAd(void);

interrupt void EPwm1ISR(void);
//void loopback_tcps(SOCKET s, uint16 port, uint16 mode);

void GetCrcCode(Uint16 len,Uint16 * str);
void int_char(Uint16 len, Uint16 * Dest,Uint16 * Source);
Uint16 ModbusCRCHi[];
Uint16 ModbusCRCLo[];

void Paramcalc1(void);
void Paramcalc2(void);

void Reset_status(void);
void Scib_Check(void);
void Scib_Data_Process(void);
void Scib_Data_Tx(void);
void RESET_SCIB(void);
void RESET_SCIC(void); 
void c46_DOL(void);

void Protect(u16 s);

void InitI2C(void);
void InitI2CGpio();
Uint16 WriteData(Uint16	*Wdata, Uint16 RomAddress, Uint16 number);
Uint16 ReadData(Uint16  *RamAddr, Uint16 RomAddress, Uint16 number);
void I2C_Operation(void);
void WR_Flash(Uint16* x);
void Mdfy_Enrg_HMI(Energy_handle E,Uint16 i);
void Mdfy_Time(Energy_handle E,Uint16 Sel);
void ENRG_Compute(Energy_handle E);
Uint16 Mdfy_Enrg(Energy_handle E,Uint16 Sel);

/*-----------------------------------------------------------------------------
the end
-----------------------------------------------------------------------------*/	

volatile float Ia=0,Ib=0,Ic=0,Idc=0,IA,IB,IC;	   // ABC相电流采集值,直流电流采集值							
volatile float Ua=0,Ub=0,Uc=0,Uab=0,Ubc=0,Udc=0;     // ABC相电压采集值,直流电压采集值

volatile float Vdcs[4]={0,0,0,0};
volatile Uint16 Udc_count=0;


float R25_N=0.2,T25_N=0.003354,T0=273.15,Vt=12.05,B5025_N=0.0002962963,Rt=100;//B=3375,T25=298.15,Rt为上端分压电阻
volatile float R1=5;
volatile float Vtemp;

float offset1=60,offset2=60,offset3=60,offset4=75,offset5=75,offset6=60,offset7=60,offset8=60;

//标志位相关
volatile u16 flg1=0,flg2=0,Fault_I;
volatile u16 Fault2=0x1000,Fault1=0x1000,WR_En=0;

volatile Uint32 rs_time = 0;


//变压器相关
float Vpre_rate=1.01;//1\n

//MPP相关
volatile float delta_U=0,U1,U2,Mppt_Pv=600;
volatile unsigned int Mppt_time=0,mpp_pause=0;
Uint16 Mppt_enable=0;
volatile float Plimit_P=10,Plimit_N=-10,P_set=0;
volatile long upwr_count=0;

int P_rated,p_cal_cnt=0;

void main(void)
{
	Uint16 i;float temp;


	InitSysCtrl();

	InitGpio();
	InitEPwm1Gpio();
	InitEPwm2Gpio();
	InitEPwm3Gpio();
	InitTzGpio();
	InitXintf();
	InitScibGpio();	    
	InitScicGpio();
	InitI2CGpio();
    InitI2C(); 

	DINT;
	
	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	I2C_Operation();

	EALLOW; 
	PieVectTable.EPWM1_INT = &EPwm1ISR;
	EDIS;
	
	InitAdc();
	InitSci();
	InitEPwm(); 

		
	IER |= M_INT3;
	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;	// Enable TINT0 in the PIE: Group 3 interrupt 1
	
	EINT;// Enable global Interrupts and higher priority real-time debug events:
	ERTM;
	
	c46_DOL();

	//部分变量初始化
	P_rated		    = 10;
	P_set			= P_rated * 5;

	V_pidreg.Kp    = 1.0;
	V_pidreg.Ki    = 0.0004;
	V_pidreg.OutMax= Plimit_P;
	V_pidreg.OutMin= Plimit_N;
	Id_pidreg.Kp    = 10.0;
	Id_pidreg.Ki    = 0.00006;
	Id_pidreg.OutMax= 600.0;
	Id_pidreg.OutMin= -600.0;
	Iq_pidreg.Kp    = 10.0;
	Iq_pidreg.Ki    = 0.00006;
	Iq_pidreg.OutMax= 600.0;
	Iq_pidreg.OutMin= -600.0;

	Mppt_enable=0;
	

	i=0;
	while(i<20)
	{
		while(!Dis_Para.status);			
		Dis_Para.status=0;
		i++;
	} 
	Dis_Para.status|=0x04;//调零结束
	 
	temp=Dis_Para.Ia0_sum_t * Dis_Para.Count_Ratio; 	
	offset1=offset1-temp;

	temp=Dis_Para.Ic0_sum_t * Dis_Para.Count_Ratio; 	
	offset2=offset2-temp;

	temp=Dis_Para.Idc_sum_t * Dis_Para.Count_Ratio;	
	offset3=offset3+temp;

	temp=Dis_Para.IA0_sum_t * Dis_Para.Count_Ratio;
    offset6=offset6-temp;

    temp=Dis_Para.IB0_sum_t * Dis_Para.Count_Ratio;
    offset7=offset7-temp;

    temp=Dis_Para.IC0_sum_t * Dis_Para.Count_Ratio;
    offset8=offset8-temp;

	while(1)
	{


/************************指示灯*****************************/
		temp=fabs(Dis_Para.P);

        if((Dis_Para.Tem > 65)||(temp>5000))
            FAN_ON
        else if(Dis_Para.Tem < 55)
            FAN_OFF

		if(Dis_Para.status & 0x01)
		{
            Paramcalc2();
            Protect(4);
            Dis_Para.status &=0xfffe;
		}
		
		if(Fault1)	Fault2=Fault1;//更新故障状态

		Fault_I = EPwm1Regs.TZFLG.bit.OST ;	
		if(Fault_I)
		{
			DisablePWM;
			Fault1 |= 0x04; 
			flg1=0;
			flg2=0;
			TZCLR();
			Fault2=Fault1;
		}
		else if(Fault1 & 0x04)
		{
			Fault1 &= 0xfffb;
			c46_DOL();
		}
	 
        if(Uart1.Tx_delay > 100)//485应答10mS延时
        {
            Uart1.Tx_delay=0;
            Scib_Data_Process();
        }

		ENRG_Compute(&ENRG_Data);//发电量计算

		WR_Flash((Uint16* )(&ENRG_Data.Enrg));//发电量保存

	}
}

interrupt void EPwm1ISR(void)
{	
    int temp;

	PieCtrlRegs.PIEACK.all = 0x0004;

    if((ScibRegs.SCICTL2.bit.TXEMPTY)&&(!Uart1.Tx_Flag))//485方向控制 发送完成转为接收
        RS485_RX1;
	Scib_Check();

	ReadAd();
	Protect(1);
	
	//添加用户控制算法

	if(((!Fault1)&&(!flg2)))//无故障，并网启动
	{
		rs_time++;
		if(rs_time==40000)
		{
			AUX_ON;	//辅助接触器开	
		}
		if(rs_time==60000)
		{
			AC_POWER_ON;//主接触器开
			Fault2=Fault1;			
		}
		if(rs_time==70000)
			Reset_status();
	}
	else rs_time=0;

	if(flg2 & 0x01)
	{    
		//SVPWM计算及更新寄存器
		LoadPWM;	
		if(flg1 & 0x01) 
		{
			EnablePWM;
			flg1=0;
			WR_En=3;
		}	 			 
	}

    Paramcalc1();//参数计算函数


    //添加孤岛保护检测


	Scib_Data_Tx();

	EPwm1Regs.ETCLR.bit.INT = 1;//clear ETFLG[INT]	               
}

Uint16  ReadAd(void)
{
	Uint16 i,Ch[10];
	float temp=0.0;
	while (AdcRegs.ADCST.bit.INT_SEQ1== 0);//判断 AD是否读完
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;//清除AD标志	
		
    Ch[0]=((AdcRegs.ADCRESULT0)>>4);//ia
    Ch[1]=((AdcRegs.ADCRESULT1)>>4);//ic
	Ch[2]=((AdcRegs.ADCRESULT2)>>4);//uab
    Ch[3]=((AdcRegs.ADCRESULT3)>>4);//ubc
	Ch[4]=((AdcRegs.ADCRESULT4)>>4);//udc
    Ch[5]=((AdcRegs.ADCRESULT5)>>4);//idc
    Ch[6]=((AdcRegs.ADCRESULT6)>>4);//temp
	Ch[7]=((AdcRegs.ADCRESULT7)>>4);//IA
	Ch[8]=((AdcRegs.ADCRESULT8)>>4);//IB
	Ch[9]=((AdcRegs.ADCRESULT8)>>4);//IC

	Udc_count&=3;

	Ia		 = offset1 - Ch[0] * 0.0293;
	Ic		 = offset2 - Ch[1] * 0.0293;
    Ib       = - Ic - Ia;

    IA       = offset6 - Ch[7] * 0.0293;
    IB       = offset7 - Ch[8] * 0.0293;
    IC       = offset8 - Ch[9] * 0.0293;

	Idc		 = Ch[5] * 0.0293 - offset3;
	Vtemp    = Ch[6]* 0.001465- 3.0;

	Uab		 = Ch[2]* 0.3516 - 720;
	Ubc		 = Ch[3]* 0.3516 - 720;   

	Ua		 = (2* Uab+Ubc)* 0.3333333;
	Ub		 = (Ubc-Uab)* 0.3333333;
	Uc		 = (-Uab-2* Ubc)* 0.3333333;  

	Vdcs[Udc_count++]=Ch[4]* 0.23443;

	for(i=0;i<4;i++)
		temp +=Vdcs[i];
    Udc		 = temp * 0.25;
	
	return(0);  //无故障返回0
}

void Paramcalc1(void)
{
	float temp1,temp2;long temp3;

	temp1 =Uab* Ia - Ubc* Ic;
	if(flg2)//发电量计算
	{

		temp2 = temp1* 10-0.5;
		temp3 =(long)temp2;
		if(temp3<0) temp3=-temp3;
		ENRG_Data.Enrg += temp3;
	}

	if(Dis_Para.Count>Dis_Para.N)
	{
		Dis_Para.Ua_sum_t =Dis_Para.Ua_sum;         Dis_Para.Ua_sum=0;
		Dis_Para.Ub_sum_t =Dis_Para.Ub_sum;         Dis_Para.Ub_sum=0;
		Dis_Para.Uc_sum_t =Dis_Para.Uc_sum;         Dis_Para.Uc_sum=0;

		Dis_Para.Udc_sum_t=Dis_Para.Udc_sum;        Dis_Para.Udc_sum=0;

		Dis_Para.Ia_sum_t =Dis_Para.Ia_sum;         Dis_Para.Ia_sum=0;
		Dis_Para.Ib_sum_t =Dis_Para.Ib_sum;         Dis_Para.Ib_sum=0;
		Dis_Para.Ic_sum_t =Dis_Para.Ic_sum;         Dis_Para.Ic_sum=0;

		Dis_Para.Ia0_sum_t =Dis_Para.Ia0_sum;       Dis_Para.Ia0_sum=0;
		Dis_Para.Ib0_sum_t =Dis_Para.Ib0_sum;       Dis_Para.Ib0_sum=0;
		Dis_Para.Ic0_sum_t =Dis_Para.Ic0_sum;       Dis_Para.Ic0_sum=0;

		Dis_Para.IA0_sum_t =Dis_Para.IA0_sum;       Dis_Para.IA0_sum=0;
        Dis_Para.IB0_sum_t =Dis_Para.IB0_sum;       Dis_Para.IB0_sum=0;
        Dis_Para.IC0_sum_t =Dis_Para.IC0_sum;       Dis_Para.IC0_sum=0;

		Dis_Para.Idc_sum_t=Dis_Para.Idc_sum;    	Dis_Para.Idc_sum=0;

		Dis_Para.P_sum_t =Dis_Para.P_sum;           Dis_Para.P_sum=0;
		Dis_Para.Pq_sum_t =Dis_Para.Pq_sum;         Dis_Para.Pq_sum=0;

		Dis_Para.Tem_sum_t =Dis_Para.Tem_sum;       Dis_Para.Tem_sum=0;

		Dis_Para.Count=0;
		Dis_Para.status |=0x01;
	}
	else
	{
		Dis_Para.Ua_sum +=Ua * Ua;
		Dis_Para.Ub_sum +=Ub * Ub;
		Dis_Para.Uc_sum +=Uc * Uc;

		Dis_Para.Udc_sum+=Udc;
		
		if(Dis_Para.status & 0x04)
		{
			Dis_Para.Ia_sum += Ia * Ia;
			Dis_Para.Ib_sum += Ib * Ib;
			Dis_Para.Ic_sum += Ic * Ic;
		}
		
		Dis_Para.Ia0_sum+=Ia;
		Dis_Para.Ic0_sum+=Ic;

		Dis_Para.IA0_sum+=IA;
        Dis_Para.IB0_sum+=IB;
        Dis_Para.IC0_sum+=IC;

		Dis_Para.Idc_sum+=Idc;

		Dis_Para.P_sum  +=temp1;//修改为线电压,交流功率
		Dis_Para.Pq_sum -= Uab*Ic + Ubc*Ia - (Uab+Ubc)*Ib;//无功功率

		Dis_Para.Tem_sum+=Vtemp;
		
		Dis_Para.Count++;	
	}	

}

void Paramcalc2(void)
{
	Uint16 i;
	float temp1,temp2;
	int32 temp3,temp4;
 
	Dis_Para.Ua=sqrt(Dis_Para.Ua_sum_t * Dis_Para.Count_Ratio);
	Dis_Para.Ub=sqrt(Dis_Para.Ub_sum_t * Dis_Para.Count_Ratio);
	Dis_Para.Uc=sqrt(Dis_Para.Uc_sum_t * Dis_Para.Count_Ratio);

	Dis_Para.Udc=Dis_Para.Udc_sum_t * Dis_Para.Count_Ratio;
    if(Dis_Para.Udc< 0.9)
        Dis_Para.Udc=0.9;
	Dis_Para.vdc_inverse = 1.732/Dis_Para.Udc;

	Dis_Para.Ia=sqrt(Dis_Para.Ia_sum_t * Dis_Para.Count_Ratio);
	Dis_Para.Ib=sqrt(Dis_Para.Ib_sum_t * Dis_Para.Count_Ratio);
	Dis_Para.Ic=sqrt(Dis_Para.Ic_sum_t * Dis_Para.Count_Ratio);

	Dis_Para.Idc=Dis_Para.Idc_sum_t * Dis_Para.Count_Ratio;

	Dis_Para.P=Dis_Para.P_sum_t * Dis_Para.Count_Ratio;
	Dis_Para.Pq=Dis_Para.Pq_sum_t * Dis_Para.Count_Ratio*0.57735f;//除sqrt(3)

	Dis_Para.Tem=Dis_Para.Tem_sum_t * Dis_Para.Count_Ratio;

	R1 = Rt/(Vt-Dis_Para.Tem) * Dis_Para.Tem;  //NTC阻值
	temp2 = R1 * R25_N;
	temp1 = log(temp2) * B5025_N + T25_N;
	temp2 = 1.0f/temp1;
	temp1 = temp2-T0;
	Dis_Para.Tem = temp1;  //温度℃	

	Dis_Para.PL=Dis_Para.Ua* Dis_Para.Ia + Dis_Para.Ub* Dis_Para.Ib + Dis_Para.Uc* Dis_Para.Ic;
	Dis_Para.PF=fabs(Dis_Para.P/Dis_Para.PL);
	if(Dis_Para.PF>0.999)
	    Dis_Para.PF=0.999;

	temp3=ENRG_Data.E_Year_Dis* 0.01 + 0.5;
	temp4=ENRG_Data.E_Total_Dis* 0.01;
	
	temp1=	Dis_Para.P * 0.01;//交流功率

	if(temp1<0)	temp1 = temp1-0.3;//六舍七入
	else	temp1 = temp1 + 0.3;

	i=0;
	Dis_Para.Tx_int[i++] = P_rated;//逆变器额定功率
	Dis_Para.Tx_int[i++] = Dis_Para.Udc * 10; //直流电压[0]
	Dis_Para.Tx_int[i++] = (int)(Dis_Para.Idc * 10); //直流电流     int转换保留符号
	Dis_Para.Tx_int[i++] = 0;
	Dis_Para.Tx_int[i++] = 0;
	Dis_Para.Tx_int[i++] = 0;
	Dis_Para.Tx_int[i++] = ThreeAnalyz.Sequence;
	Dis_Para.Tx_int[i++] = Dis_Para.Ua * 10;//A相电压//[6]
	Dis_Para.Tx_int[i++] = Dis_Para.Ia * 10;//A相电流
	Dis_Para.Tx_int[i++] = Dis_Para.Ub * 10;//B相电压
	Dis_Para.Tx_int[i++] = Dis_Para.Ib * 10;//B相电流
	Dis_Para.Tx_int[i++] = Dis_Para.Uc * 10;//C相电压[10]
	Dis_Para.Tx_int[i++] = Dis_Para.Ic * 10;//C相电流
	Dis_Para.Tx_int[i++] = (int)temp1;//交流功率0.1kw
	Dis_Para.Tx_int[i++] = ThreeAnalyz.Freq*100;//频率
	Dis_Para.Tx_int[i++] = Dis_Para.Tem * 10;//温度[14]
	Dis_Para.Tx_int[i++] = Fault2;//运行状态
	Dis_Para.Tx_int[i++] = P_set;//
	Dis_Para.Tx_int[i++] = 0;//
	Dis_Para.Tx_int[i++] = 0;//
	Dis_Para.Tx_int[i++] = 0;//
	Dis_Para.Tx_int[i++] = 0;//
	Dis_Para.Tx_int[i++] = temp4 & 0x0000ffff;//总发电量 
	Dis_Para.Tx_int[i++] = temp4>>16;//高字//

}


void int_char(Uint16 len, Uint16 * Dest,Uint16 * Source)
{
    Uint16 i, temp1, temp2;
    for (i = 0; i < len; i++)
    {
        temp1 = (i << 1) + 3;
        temp2 = temp1 +1;
        *(Dest+temp1) = *(Source+i) >> 8;      //高字节在前
        *(Dest+temp2) = *(Source+i) & 0x00ff;
    }
} 

void GetCrcCode(Uint16 len,Uint16 * str)
{
	Uint16 hi,lo;
	Uint16 x,j;
	hi=0xff;
	lo=0xff;
	for(x=0;x<len;x++)
	{ 
		j = lo^ (* (str+x));
		lo=hi^ModbusCRCHi[j];
		hi=ModbusCRCLo[j];                  	
	}
	*(str+len)= lo;
	*(str+len+1)= hi;
 
}

void Reset_status(void)
{
	TZCLR();                   //IPM上电清除

	Id_pidreg.Ui = 0;
	Iq_pidreg.Ui = 0;
	V_pidreg.Ui = 0;
	Pset_pidreg.Ui=0;

	flg1=1;flg2=1;

	rs_time=0; 
	mpp_pause=0;
}

void c46_DOL()
{
	int i,DI1;
	int data1=6,data2=1;

	CS1L;
	DELAY_US(5);
	CS1H;
	DELAY_US(5);

	for(i=0;i<3;i++)
	{
		DI1 =(0x04>>i) & data1 ;
		if(DI1) 
			DI1H;
		else 
			DI1L;
		DELAY_US(1);
		CLK1H;
		DELAY_US(4);
		CLK1L;
		DELAY_US(3);
	}

	for(i=0;i<7;i++)
	{
		DI1 =(0x40>>i) & data2 ;
		if(DI1)
			DI1H;
		else
			DI1L;
		DELAY_US(1);
		CLK1H;
		DELAY_US(4);
		CLK1L;
		DELAY_US(3);
	}
}  

void RESET_SCIB(void)
{
	ScibRegs.SCICTL1.bit.SWRESET=0;
	DELAY_US(1);
	ScibRegs.SCICTL1.bit.SWRESET=1;	
} 

void RESET_SCIC(void)
{
	ScicRegs.SCICTL1.bit.SWRESET=0;
	DELAY_US(1);
	ScicRegs.SCICTL1.bit.SWRESET=1;
}

void Protect(u16 s)
{
	switch(s)
	{
		case 1:				
			if((Uab<Extre.uac_Min1)||(Uab>Extre.uac_Max3)||(Ubc<Extre.uac_Min1)||(Ubc>Extre.uac_Max3))
			{
				Fault1|=0x0001;	//交流过压 线电压瞬时值	
			}			
			if(Udc>Extre.Udc_Max3)	
			{
				Fault1|=0x0400;	//母线过压 瞬时值
			}								
			if((Ia<Extre.iac_Min1)||(Ia>Extre.iac_Max3)||(Ic<Extre.iac_Min1)||(Ic>Extre.iac_Max3))
			{
				Fault1|=0x0004;//交流过流 瞬时值
			}
			break;

		case 2: //孤岛
			Fault1|=0x0020; 
			break;
        case 3:
            if((ThreeAnalyz.Freq<50.45)&&(ThreeAnalyz.Freq>49.55))
                Fault1&=0xffdf;
			break;
		case 4:
			if((Dis_Para.Ua>Extre.uac_Max2)||(Dis_Para.Ub>Extre.uac_Max2)||(Dis_Para.Uc>Extre.uac_Max2))
			{
				Fault1|=0x0001;//交流过压 有效值
			}
			else if((Dis_Para.Ua<Extre.uac_Max1)&&(Dis_Para.Ub<Extre.uac_Max1)&&(Dis_Para.Uc<Extre.uac_Max1))
			{
				Fault1&=0xfffe;
			}
			if((Dis_Para.Ua<Extre.uac_Min2)||(Dis_Para.Ub<Extre.uac_Min2)||(Dis_Para.Uc<Extre.uac_Min2))
			{
				Fault1|=0x0020; //交流欠压有效值//和孤岛共用
			}
					
			if(Dis_Para.Udc>Extre.Udc_Max2)
			{
				Fault1|=0x0400;//母线过压 平均值
			}
			else if(Dis_Para.Udc<Extre.Udc_Max1)
			{
				Fault1&=0xfbff;
			}
			
			else if(Dis_Para.Udc>Extre.Udc_Min3)
			{
				Fault1&=0xf7ff;
			};	

			if(Dis_Para.Tem>Extre.Temp_max2)//温度保护
			{
				Fault1|= 0x4000;
			}
			else if(Dis_Para.Tem<Extre.Temp_max1)
			{
				Fault1 &= 0xbfff;
			}
       		break;

		default:
	       	break;
	}
	
	if((flg2)&&(Fault1))//故障处理
	{
		DisablePWM;
		flg1=0;
		flg2=0;
		Fault2=Fault1;
	} 
} 

void WR_Flash(Uint16* x)
{Uint16 *p,data[8],i;
	p=x;
	for(i=0;i<4;i++)
	{
		data[i*2]=*(p+i);
		data[i*2+1]=(*(p+i))>>8;
	}
	if((WR_En==3)&&(Fault1 & 0x7fff))
	{
		WriteData(data,72,8);
		WR_En =0;
	}
} 

Uint16 Mdfy_Enrg(Energy_handle E,Uint16 Sel)
{Uint16 Flg=0,*p,i,data[8];
 
 	p = (Uint16 *)(&E->Enrg);
	for(i=0;i<4;i++)
	{
		data[i*2]=*(p+i);
		data[i*2+1]=(*(p+i))>>8;
	} 

 switch (Sel)
   {
	case 1:
		   if(E->Y_Update!=E->Year)
			 {
			  WriteData(data,80,8);
			  E->Enrg_Y=E->Enrg;
			  Flg=1; E->Mdfy_en|=0x07;
			 }
		   break;
	case 2:
		   if((E->M_Update!=E->Month)||(E->Mdfy_en&0x02))
			 {
			  WriteData(data,88,8);
			  E->Enrg_M=E->Enrg;
			  Flg=1; E->Mdfy_en|=0x03;
			  } 
		   break;
	case 3:
		   if((E->D_Update!=E->Date)||(E->Mdfy_en&0x01))
			 {
			  WriteData(data,96,8);
			  E->Enrg_D=E->Enrg;
			  Flg=1; E->Mdfy_en|=0x01;
			 }
		   break;
	default:
		   break;
   }
 return Flg;
}

void Mdfy_Enrg_HMI(Energy_handle E,Uint16 i)
{Uint16 *p,j,data[8];

 	p = (Uint16 *)(&E->Enrg);
	for(j=0;j<4;j++)
	{
		data[j*2]=*(p+j);
		data[j*2+1]=(*(p+j))>>8;
	} 

 if(E->Mdfy_en & 0x10)
   {
	E->Enrg_D=E->Enrg;//校正总电量
	E->Enrg_M=E->Enrg;
	E->Enrg_Y=E->Enrg;
	WriteData(data,72+i*8,8);
	if(i==3)
	  E->Mdfy_en &= 0xef;
   }
}

void Mdfy_Time(Energy_handle E,Uint16 Sel)
{Uint16 *p;

 switch (Sel)
   {
	case 1:
		   if(E->Mdfy_en&0x04)
             {
		      p = (Uint16 *)(&E->Y_Update);
              WriteData(p,104,1);
		      E->Year=E->Y_Update;
			  E->Mdfy_en&=0xfb;
	         }
		   break;
	case 2:
		   if(E->Mdfy_en&0x02)
             {
		      p = (Uint16 *)(&E->M_Update);
              WriteData(p,108,1);
		      E->Month=E->M_Update;
			  E->Mdfy_en&=0xfd;
	         }
		   break;
	case 3:
		   if(E->Mdfy_en&0x01)
             {
		      p = (Uint16 *)(&E->D_Update);
		      WriteData(p,112,1);
		      E->Date=E->D_Update;
			  E->Mdfy_en&=0xfe;
	         }
		   break;
	default:
		   break;
	 }
}

void ENRG_Compute(Energy_handle E)  
{int64 temp;
	
 temp = E->Enrg * E->Enrg_k;// 单位: 10wh
 if(temp>999999999)
   {
	E->Enrg = 200000000;
	E->Enrg_Pre = 0;
	temp = 0;
   }
 E->E_Total_Dis = temp;
	
 temp = E->Enrg - E->Enrg_D;
 if(temp<0)
   {
	if(temp<E->Enrg_Total_Half)
	  temp += E->Enrg_Total;
	else
	  temp = 0;
   }
 E->E_date_Dis = temp * E->Enrg_k + 0.5f;
 
 temp = E->Enrg - E->Enrg_M;
 if(temp<0)
   {
	if(temp<E->Enrg_Total_Half)
	  temp += E->Enrg_Total;
	else
	  temp = 0;
   }
 E->E_Month_Dis = temp * E->Enrg_k + 0.5f;

 temp = E->Enrg - E->Enrg_Y;
 if(temp<0)
   {
	if(temp<E->Enrg_Total_Half)
	  temp += E->Enrg_Total;
	else
	  temp = 0;
   }
 E->E_Year_Dis = temp * E->Enrg_k + 0.5f;
}

void Scib_Check(void)
{
	if(ScibRegs.SCIRXST.bit.RXRDY)
	{
		Uart1.Rx_Data1[Uart1.Rx_Cnt++]= ScibRegs.SCIRXBUF.bit.RXDT;	  // Read data
		if(Uart1.Rx_Data1[0]==0x01)
		{
		    if(Uart1.Rx_Cnt>1)
		    {
                if((Uart1.Rx_Data1[1]==0x04)||(Uart1.Rx_Data1[1]==0x05)||(Uart1.Rx_Data1[1]==0x06))
                {
                    if(Uart1.Rx_Cnt & 0x08)
                    {
                        Uart1.Rx_Flag=0x1;
                        Uart1.Rx_Cnt=0;
                    }
                }
                else    Uart1.Rx_Cnt=0;
		    }
		}
		else Uart1.Rx_Cnt=0;
	}
    if(Uart1.Rx_Flag & 0x1)//485应答10mS延时
        Uart1.Tx_delay++;
} 

void Scib_Data_Process(void)
{
	u16 temp;

    Uart1.Rx_Flag=0;
    Uart1.Rx_Data1[8]=Uart1.Rx_Data1[6];
    Uart1.Rx_Data1[9]=Uart1.Rx_Data1[7];

    GetCrcCode(6,Uart1.Rx_Data1);

    if((Uart1.Rx_Data1[8] != Uart1.Rx_Data1[6])||(Uart1.Rx_Data1[9] != Uart1.Rx_Data1[7]))
        Uart1.Rx_Data1[1] = 0;

    switch(Uart1.Rx_Data1[1])
    {
        case 0x04:
                temp = (Uart1.Rx_Data1[2]<<8) + Uart1.Rx_Data1[3];
                if(temp<1000) temp=1000;
                if(temp>1023) temp=1023;
                temp=temp-1000; //寄存器起始地址偏移量

                Uart1.Tx_Data1[2]=Uart1.Rx_Data1[5];//发送寄存器数目
                if(Uart1.Tx_Data1[2]>24)
                    Uart1.Tx_Data1[2]=24;

                int_char(Uart1.Tx_Data1[2],Uart1.Tx_Data1,&Dis_Para.Tx_int[temp]);
                Uart1.Tx_Data1[2] = Uart1.Tx_Data1[2]<<1;//发送字节数目

                Uart1.Tx_Num1 = 3 + Uart1.Tx_Data1[2];
                GetCrcCode(Uart1.Tx_Num1, Uart1.Tx_Data1);
                Uart1.Tx_Num1 = 2 + Uart1.Tx_Num1;//加上校验2字节

                Uart1.Tx_Flag=0x02;
                break;
        case 0x05://开关机
				if(Uart1.Rx_Data1[4])
					Fault1 &= 0xefff;
				else
					{Fault1 |= 0x1000;DisablePWM;flg1=0;flg2=0;Fault2=Fault1;}				
                Uart1.Tx_Flag=0x04;
                break;
        case 0x06://电压
				temp = Uart1.Rx_Data1[5] + Uart1.Rx_Data1[4] * 256;
				if(Uart1.Rx_Data1[3]==0xda)//电压控制
				{
                    if(temp>800)
                        temp=800;
                    if(temp<200)
                        temp=200;

                    Mppt_Pv = temp;
				}
				if(Uart1.Rx_Data1[3]==0xdc)//功率 电流控制
				{
                    if(temp<1)
                        temp=1;
                    if(temp>100)
                        temp=100;
                    P_set = temp;

                    V_pidreg.OutMax = 0.22 * temp;
                    V_pidreg.OutMin = -V_pidreg.OutMax;
				}
                Uart1.Tx_Flag=0x04;
                break;
    }
}
	
void Scib_Data_Tx(void)
{
    if(ScibRegs.SCIRXST.bit.RXERROR)//串口错误复位
        RESET_SCIB();
    if(ScibRegs.SCICTL2.bit.TXRDY)
    {
        if(Uart1.Tx_Flag & 0x06)
            RS485_TX1;
        switch(Uart1.Tx_Flag)
        {
            case 0x02:
                    ScibRegs.SCITXBUF = Uart1.Tx_Data1[Uart1.Tx_Cnt++];
                    if(Uart1.Tx_Cnt==Uart1.Tx_Num1)//数据
                    {
                        Uart1.Tx_Cnt=0;
                        Uart1.Tx_Flag=0;
                    }
                    break;
            case 0x04:
                    ScibRegs.SCITXBUF = Uart1.Rx_Data1[Uart1.Tx_Cnt++];
                    if(Uart1.Tx_Cnt & 0x08)
                    {
                        Uart1.Tx_Cnt=0;
                        Uart1.Tx_Flag=0;
                    }
                    break;
            default:
                break;
        }
    }
} 

void InitI2C(void)
{
 I2caRegs.I2CMDR.bit.IRS =0;
 I2caRegs.I2CSAR = 0x0050;		// Slave address - EEPROM control code
 I2caRegs.I2CPSC.all = 9;			// Prescaler - need 7-12 Mhz on module clk
 I2caRegs.I2CCLKL = 15;			// NOTE: must be non zero
 I2caRegs.I2CCLKH = 15;			// NOTE: must be non zero
 I2caRegs.I2CIER.all = 0x00;		// Enable SCD & ARDY interrupts

 I2caRegs.I2CMDR.bit.IRS = 1;	// Take I2C out of reset
}	


void InitI2CGpio()
{
 EALLOW;

 GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;    // Enable pull-up for GPIO32 (SDAA)
 GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;	   // Enable pull-up for GPIO33 (SCLA)

 GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;  // Asynch input GPIO32 (SDAA)
 GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;  // Asynch input GPIO33 (SCLA)

 GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;   // Configure GPIO32 for SDAA operation
 GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;   // Configure GPIO33 for SCLA operation
	
 EDIS;
}

Uint16	I2C_xrdy()
{
 Uint16	t;
 t = I2caRegs.I2CSTR.bit.XRDY;
 return t;
}

Uint16	I2C_rrdy()
{
	Uint16	t;
	t = I2caRegs.I2CSTR.bit.RRDY;
	return t;
}

Uint16 WriteData(Uint16	*Wdata, Uint16 RomAddress, Uint16 number)
{
   Uint16 i;
   if (I2caRegs.I2CSTR.bit.BB == 1)
   {
      return I2C_BUS_BUSY_ERROR;
   }
   while(!I2C_xrdy());
   I2caRegs.I2CSAR = 0x50;
   I2caRegs.I2CCNT = number + 1;
   I2caRegs.I2CDXR = RomAddress;
   I2caRegs.I2CMDR.all = 0x6E20;
   for (i=0; i<number; i++)
   {
      while(!I2C_xrdy());
      I2caRegs.I2CDXR = *Wdata;
      Wdata++;
	  if (I2caRegs.I2CSTR.bit.NACK == 1)
   		  return	I2C_BUS_BUSY_ERROR;
   }   	
   return I2C_SUCCESS;   
}

Uint16 ReadData(Uint16  *RamAddr, Uint16	RomAddress, Uint16 number)
{
   Uint16  i,Temp;

   if (I2caRegs.I2CSTR.bit.BB == 1)
   {
       return I2C_BUS_BUSY_ERROR;
   }
   while(!I2C_xrdy());
   I2caRegs.I2CSAR = 0x50;
   I2caRegs.I2CCNT = 1;
   I2caRegs.I2CDXR = RomAddress;
   I2caRegs.I2CMDR.all = 0x6620; 
   if (I2caRegs.I2CSTR.bit.NACK == 1)
   		return	I2C_BUS_BUSY_ERROR;
   DELAY_US(50);		
   while(!I2C_xrdy());
   I2caRegs.I2CSAR = 0x50;
   I2caRegs.I2CCNT = number;	 
   I2caRegs.I2CMDR.all = 0x6C20; 
   if (I2caRegs.I2CSTR.bit.NACK == 1)
   		return	I2C_BUS_BUSY_ERROR;
   for(i=0;i<number;i++)
   {
      while(!I2C_rrdy());
   	  Temp = I2caRegs.I2CDRR;
	  if (I2caRegs.I2CSTR.bit.NACK == 1)
   		  return	I2C_BUS_BUSY_ERROR;
   	  *RamAddr = Temp;
   	  RamAddr++;
   }
   return I2C_SUCCESS;
}

void I2C_Operation(void)
{Uint16 i,data[128],*p,temp;

    ReadData(data,0,128);
    temp=0;
    for(i=0;i<8;i++)
        temp +=data[i];
    if(temp==2040)//EEPROM空片检测
    {
        for(i=0;i<16;i++)
            data[i]=0;
        for(i=0;i<8;i++)
        {
            WriteData(data,i*16,16);//M24c02  每页大小为16字节   AT24c02每页为8字节  需要修改
            DELAY_US(5000);
        }
    }
    else
    {
        for(i=0;i<64;i++)
        {
            temp=i<<1;
            data[temp] +=data[temp+1]<<8;
        }
        for(i=1;i<64;i++)
        {
            temp=i*2;
            data[i] =data[temp];
        }
        /******电量数据******/
        p=(Uint16 *)(&ENRG_Data.Enrg);//dsp按照16位编址
        for(i=0;i<4;i++)
            *(p+i)= data[i+36];

        p=(Uint16 *)(&ENRG_Data.Enrg_Y);
        for(i=0;i<4;i++)
            *(p+i)= data[i+40];
        p=(Uint16 *)(&ENRG_Data.Enrg_M);
        for(i=0;i<4;i++)
            *(p+i)= data[i+44];
        p=(Uint16 *)(&ENRG_Data.Enrg_D);
        for(i=0;i<4;i++)
            *(p+i)= data[i+48];

        p=(Uint16 *)(&ENRG_Data.Year);
        *p=data[52] &= 0xff;//去掉年月日旳高字节
        ENRG_Data.Y_Update=ENRG_Data.Year;
        p=(Uint16 *)(&ENRG_Data.Month);
        *p=data[54] &= 0xff;//去掉年月日旳高字节
        ENRG_Data.M_Update=ENRG_Data.Month;
        p=(Uint16 *)(&ENRG_Data.Date);
        *p=data[56] &= 0xff;
        ENRG_Data.D_Update=ENRG_Data.Date;
    }
}

Uint16 ModbusCRCHi[]=
{
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,
0x00,0xc1,0x81,0x40,0x00,0xc1,0x81,0x40,0x01,0xc0,
0x80,0x41,0x01,0xc0,0x80,0x41,0x00,0xc1,0x81,0x40,
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x00,0xc1,
0x81,0x40,0x01,0xc0,0x80,0x41,0x01,0xc0,0x80,0x41,
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x00,0xc1,
0x81,0x40,0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40,0x00,0xc1,0x81,0x40,
0x01,0xc0,0x80,0x41,0x01,0xc0,0x80,0x41,0x00,0xc1,
0x81,0x40,0x01,0xc0,0x80,0x41,0x00,0xc1,0x81,0x40,
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40,0x00,0xc1,0x81,0x40,
0x01,0xc0,0x80,0x41,0x00,0xc1,0x81,0x40,0x01,0xc0,
0x80,0x41,0x01,0xc0,0x80,0x41,0x00,0xc1,0x81,0x40,
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,
0x00,0xc1,0x81,0x40,0x00,0xc1,0x81,0x40,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,
0x01,0xc0,0x80,0x41,0x00,0xc1,0x81,0x40,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40,0x00,0xc1,0x81,0x40,
0x01,0xc0,0x80,0x41,0x01,0xc0,0x80,0x41,0x00,0xc1,
0x81,0x40,0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,
0x00,0xc1,0x81,0x40,0x01,0xc0,0x80,0x41,0x01,0xc0,
0x80,0x41,0x00,0xc1,0x81,0x40
};

Uint16 ModbusCRCLo[]=
{
0x00,0xc0,0xc1,0x01,0xc3,0x03,0x02,0xc2,0xc6,0x06,
0x07,0xc7,0x05,0xc5,0xc4,0x04,0xcc,0x0c,0x0d,0xcd,
0x0f,0xcf,0xce,0x0e,0x0a,0xca,0xcb,0x0b,0xc9,0x09,
0x08,0xc8,0xd8,0x18,0x19,0xd9,0x1b,0xdb,0xda,0x1a,
0x1e,0xde,0xdf,0x1f,0xdd,0x1d,0x1c,0xdc,0x14,0xd4,
0xd5,0x15,0xd7,0x17,0x16,0xd6,0xd2,0x12,0x13,0xd3,
0x11,0xd1,0xd0,0x10,0xf0,0x30,0x31,0xf1,0x33,0xf3,
0xf2,0x32,0x36,0xf6,0xf7,0x37,0xf5,0x35,0x34,0xf4,
0x3c,0xfc,0xfd,0x3d,0xff,0x3f,0x3e,0xfe,0xfa,0x3a,
0x3b,0xfb,0x39,0xf9,0xf8,0x38,0x28,0xe8,0xe9,0x29,
0xeb,0x2b,0x2a,0xea,0xee,0x2e,0x2f,0xef,0x2d,0xed,
0xec,0x2c,0xe4,0x24,0x25,0xe5,0x27,0xe7,0xe6,0x26,
0x22,0xe2,0xe3,0x23,0xe1,0x21,0x20,0xe0,0xa0,0x60,
0x61,0xa1,0x63,0xa3,0xa2,0x62,0x66,0xa6,0xa7,0x67,
0xa5,0x65,0x64,0xa4,0x6c,0xac,0xad,0x6d,0xaf,0x6f,
0x6e,0xae,0xaa,0x6a,0x6b,0xab,0x69,0xa9,0xa8,0x68,
0x78,0xb8,0xb9,0x79,0xbb,0x7b,0x7a,0xba,0xbe,0x7e,
0x7f,0xbf,0x7d,0xbd,0xbc,0x7c,0xb4,0x74,0x75,0xb5,
0x77,0xb7,0xb6,0x76,0x72,0xb2,0xb3,0x73,0xb1,0x71,
0x70,0xb0,0x50,0x90,0x91,0x51,0x93,0x53,0x52,0x92,
0x96,0x56,0x57,0x97,0x55,0x95,0x94,0x54,0x9c,0x5c,
0x5d,0x9d,0x5f,0x9f,0x9e,0x5e,0x5a,0x9a,0x9b,0x5b,
0x99,0x59,0x58,0x98,0x88,0x48,0x49,0x89,0x4b,0x8b,
0x8a,0x4a,0x4e,0x8e,0x8f,0x4f,0x8d,0x4d,0x4c,0x8c,
0x44,0x84,0x85,0x45,0x87,0x47,0x46,0x86,0x82,0x42,
0x43,0x83,0x41,0x81,0x80,0x40
};

