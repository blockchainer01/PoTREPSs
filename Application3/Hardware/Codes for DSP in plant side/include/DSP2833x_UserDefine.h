#ifndef DSP2833x_USER_DEFINE_H
#define DSP2833x_USER_DEFINE_H

#ifdef __cplusplus
extern "C" {
#endif

#define RS485_TX1 GpioDataRegs.GPASET.bit.GPIO13 = 1;
#define RS485_RX1 GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
#define RS485_TX2 GpioDataRegs.GPASET.bit.GPIO14 = 1;
#define RS485_RX2 GpioDataRegs.GPACLEAR.bit.GPIO14 = 1;

#define CS1H        GpioDataRegs.GPBSET.bit.GPIO39=1
#define CS1L        GpioDataRegs.GPBCLEAR.bit.GPIO39=1
#define CLK1H       GpioDataRegs.GPCSET.bit.GPIO87=1
#define CLK1L       GpioDataRegs.GPCCLEAR.bit.GPIO87=1
#define DI1H        GpioDataRegs.GPCSET.bit.GPIO86=1
#define DI1L        GpioDataRegs.GPCCLEAR.bit.GPIO86=1

#define FAULTLED GpioDataRegs.GPCDAT.bit.GPIO82
#define GRIDLED GpioDataRegs.GPADAT.bit.GPIO29

#define AC_POWER_ON GpioDataRegs.GPBSET.bit.GPIO58 = 1;
#define AUX_ON GpioDataRegs.GPBSET.bit.GPIO59 = 1;
#define DC_ON GpioDataRegs.GPBSET.bit.GPIO52 = 1;
//GPIO59 FOR AUX  AND GPIO58 FOR MAIN CONTECTOR
#define AC_POWER_OFF GpioDataRegs.GPBCLEAR.bit.GPIO58 = 1;GpioDataRegs.GPBCLEAR.bit.GPIO59 = 1;GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;

//#define BRAKE_ON GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;
//#define BRAKE_OFF GpioDataRegs.GPBSET.bit.GPIO52 = 1;

#define FAN_OFF GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;
#define FAN_ON GpioDataRegs.GPBSET.bit.GPIO52 = 1;

//#define FAN_OFF GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;/*ONLY FOR PCS*/
//#define FAN_ON GpioDataRegs.GPASET.bit.GPIO31 = 1;/*ONLY FOR PCS*/

#define EnablePWM   GpioDataRegs.GPBCLEAR.bit.GPIO61=1;     //mfsrb低
#define DisablePWM  GpioDataRegs.GPBSET.bit.GPIO61=1;AC_POWER_OFF;
#define DisablePWM1  GpioDataRegs.GPBSET.bit.GPIO61=1;

#define  w5300SET_RST       GpioDataRegs.GPBSET.bit.GPIO60=1
#define  w5300CLEAR_RST     GpioDataRegs.GPBCLEAR.bit.GPIO60=1

#define SYNC_L  GpioDataRegs.GPBCLEAR.bit.GPIO57=1
#define SYNC_H  GpioDataRegs.GPBSET.bit.GPIO57=1
#define SCLK_L  GpioDataRegs.GPBCLEAR.bit.GPIO56=1
#define SCLK_H  GpioDataRegs.GPBSET.bit.GPIO56=1
#define SDA_L  GpioDataRegs.GPBCLEAR.bit.GPIO54=1
#define SDA_H  GpioDataRegs.GPBSET.bit.GPIO54=1

#define LoadPWM    {EPwm1Regs.CMPA.half.CMPA = svgen.Ta * EPWM_TBPRD;\
                    EPwm2Regs.CMPA.half.CMPA = svgen.Tb * EPWM_TBPRD;\
	                EPwm3Regs.CMPA.half.CMPA = svgen.Tc * EPWM_TBPRD;}


#define EPWM_TBPRD 3750

// TBCTL (Time-Base Control)
//==========================
// CTRMODE bits
#define	TB_COUNT_UP		0x0
#define	TB_COUNT_DOWN	0x1
#define	TB_COUNT_UPDOWN	0x2
#define	TB_FREEZE		0x3
// PHSEN bit
#define	TB_DISABLE		0x0
#define	TB_ENABLE		0x1
// PRDLD bit
#define	TB_SHADOW		0x0
#define	TB_IMMEDIATE	0x1
// SYNCOSEL bits
#define	TB_SYNC_IN		0x0
#define	TB_CTR_ZERO		0x1
#define	TB_CTR_CMPB		0x2
#define	TB_SYNC_DISABLE	0x3
// HSPCLKDIV and CLKDIV bits
#define	TB_DIV1			0x0
#define	TB_DIV2			0x1
#define	TB_DIV4			0x2
// PHSDIR bit
#define	TB_DOWN			0x0
#define	TB_UP			0x1

// CMPCTL (Compare Control)
//==========================
// LOADAMODE and LOADBMODE bits
#define	CC_CTR_ZERO		0x0
#define	CC_CTR_PRD		0x1
#define	CC_CTR_ZERO_PRD	0x2
#define	CC_LD_DISABLE	0x3
// SHDWAMODE and SHDWBMODE bits
#define	CC_SHADOW		0x0
#define	CC_IMMEDIATE	0x1

// AQCTLA and AQCTLB (Action Qualifier Control)
//=============================================
// ZRO, PRD, CAU, CAD, CBU, CBD bits
#define	AQ_NO_ACTION	0x0
#define	AQ_CLEAR		0x1
#define	AQ_SET			0x2
#define	AQ_TOGGLE		0x3

// DBCTL (Dead-Band Control)
//==========================
// OUT MODE bits
#define	DB_DISABLE		0x0
#define	DBA_ENABLE		0x1
#define	DBB_ENABLE		0x2
#define	DB_FULL_ENABLE	0x3
// POLSEL bits
#define	DB_ACTV_HI		0x0
#define	DB_ACTV_LOC		0x1
#define	DB_ACTV_HIC		0x2
#define	DB_ACTV_LO		0x3
// IN MODE
#define DBA_ALL         0x0
#define DBB_RED_DBA_FED 0x1
#define DBA_RED_DBB_FED 0x2
#define DBB_ALL         0x3

// CHPCTL (chopper control)
//==========================
// CHPEN bit
#define	CHP_DISABLE		0x0
#define	CHP_ENABLE		0x1
// CHPFREQ bits
#define	CHP_DIV1		0x0
#define	CHP_DIV2		0x1
#define	CHP_DIV3		0x2
#define	CHP_DIV4		0x3
#define	CHP_DIV5		0x4
#define	CHP_DIV6		0x5
#define	CHP_DIV7		0x6
#define	CHP_DIV8		0x7
// CHPDUTY bits
#define	CHP1_8TH		0x0
#define	CHP2_8TH		0x1
#define	CHP3_8TH		0x2
#define	CHP4_8TH		0x3
#define	CHP5_8TH		0x4
#define	CHP6_8TH		0x5
#define	CHP7_8TH		0x6

// TZSEL (Trip Zone Select)
//==========================
// CBCn and OSHTn bits
#define	TZ_DISABLE		0x0
#define	TZ_ENABLE		0x1

// TZCTL (Trip Zone Control)
//==========================
// TZA and TZB bits
#define	TZ_HIZ			0x0
#define	TZ_FORCE_HI		0x1
#define	TZ_FORCE_LO		0x2
#define	TZ_NO_CHANGE	0x3

// ETSEL (Event Trigger Select)
//=============================
#define	ET_CTR_ZERO		0x1
#define	ET_CTR_PRD		0x2
#define	ET_CTRU_CMPA	0x4
#define	ET_CTRD_CMPA	0x5
#define	ET_CTRU_CMPB	0x6
#define	ET_CTRD_CMPB	0x7

// ETPS (Event Trigger Pre-scale)
//===============================
// INTPRD, SOCAPRD, SOCBPRD bits
#define	ET_DISABLE		0x0
#define	ET_1ST			0x1
#define	ET_2ND			0x2
#define	ET_3RD			0x3


//--------------------------------
// HRPWM (High Resolution PWM)
//================================
// HRCNFG
#define	HR_Disable		0x0
#define	HR_REP			0x1
#define	HR_FEP			0x2
#define	HR_BEP			0x3

#define	HR_CMP			0x0
#define	HR_PHS			0x1

#define	HR_CTR_ZERO		0x0
#define	HR_CTR_PRD		0x1

typedef struct {  
				  float  AS;
				  float  BS;
				  float  CS;
				  float  Valpha;		    // Output: stationary d-axis stator variable 
				  float  Vbeta;		    // Output: stationary q-axis stator variable
		 	 	} CLARKE;	            

typedef CLARKE *CLARKE_handle;

typedef struct {  
                  float  PAlpha;
				  float  PBeta;
                  float  PDs;     		// Input: stationary d-axis stator variable 
				  float  PQs;    	    // Input: stationary q-axis stator variable 
				  float  PSine;  
				  float  PCosine; 
				  char   sel;   
		 	 	} PARK;	            

typedef PARK *PARK_handle;

typedef struct {  float  Ref;   		// Input: Reference input 
				  float  Fdb;   		// Input: Feedback input 
				  float  Err;			// Variable: Error 
				  float  Kp;			// Parameter: Proportional gain
				  float  Up;			// Variable: Proportional output 
				  float  Ui;			// Variable: Integral output 	
				  float  OutPreSat;	    // Variable: Pre-saturated output
				  float  OutMax;		// Parameter: Maximum output 
				  float  OutMin;		// Parameter: Minimum output
				  float  Out;   		// Output: PID output 
				  float  Ki;			// Parameter: Integral gain
				  float  ErrMax;
				  float  ErrMin;
				 }PIDREG;	            

typedef PIDREG *PIDREG_handle;

typedef struct {  float  IPAlpha;  		// Output: stationary d-axis stator variable
				  float  IPBeta;		   // Output: stationary q-axis stator variable
				  float  IPDs;			// Input: rotating d-axis stator variable
				  float  IPQs;			// Input: rotating q-axis stator variable
				  float  IPSine;      
				  float  IPCosine;   
		 	 	} IPARK;	            

typedef IPARK *IPARK_handle;
            
typedef struct {
                float           V_pv;
                float           I_pv;
				float           V_ds;
				float           V_ds2;
				float           Power[16];
				float			MP_Vdc[16];
				float			OutVdc;
				float           Power_m[2];
				int             ex_status;
				int             nth;
				int             peak_lock;
				float           ori_cur;
				int				repeat;
				int				rep_num;
				float           Duty_max;
				char            trace;
				char            ov_cur_flg;
				char            ov_vol_flg;
			   }MPPT;
typedef MPPT * mppt_handle; 

typedef struct {
                int				V_pos;
				int				Angle_pos;
				int             F_sum;
				long            V_sum;
                long            V_grid[32];
				float           V_sin[16];
				int            	Err_V;
				int           	Err_norm;
				int             Err_Fre[16];
				int             Err_F_sum;
				int             Err_pos;
				int             Err_F; 
			   }ISLAND;
typedef ISLAND * ISLAND_handle;
typedef struct {
				float    wL;	  //角频率乘电感(pu),也就是电感的标幺
				float    Vfdbd;	  //网侧电压回馈Vd
				float    Ifdbd;	  //网侧电流回馈值Id
				float    Ifdbq;	  //网侧电流回馈值Iq
				float    Vd;      //控制模块输出：
				float    Vq;      //电压d q分量；对Valpha,Vbeta的控制实现软起动,在SVPWM模块实现
		        float    Vd_Pidout;
				float    Vq_Pidout;
			   }CURR_ADJ;
typedef CURR_ADJ * Curr_handle;
typedef struct 	{ float  Ualpha; 			// Input: reference alpha-axis phase voltage 
				  float  Ubeta;			    // Input: reference beta-axis phase voltage 
				  float  Ta;				// Output: reference phase-a switching function		
				  float  Tb;				// Output: reference phase-b switching function 
				  float  Tc;				// Output: reference phase-c switching function
				} SVGENDQ;

typedef SVGENDQ *SVGENDQ_handle ;
     
typedef struct{
             unsigned long  cmd;
			 unsigned long  sign;
			 unsigned long lenth;
			   char   str[800];
               } TCPIPDATA;
typedef struct{
               unsigned long  cmdd;
			   unsigned long  signn;
			   unsigned long lenthh;
			   unsigned long runsign; 
			   unsigned long faultsign; 
               char strr[40];            
              } TCPIPDATA1;
typedef struct{
               unsigned long cmd1;
               unsigned long sign1;
               unsigned long lenth1;
               float         value1[27];
               } TCPIPDATA2;

typedef struct {
				float         Ua;        
				float         Ua_sum;
				float         Ua_sum_t;
				float         Ub;
				float         Ub_sum;
				float         Ub_sum_t;
				float         Uc;
				float         Uc_sum;
				float         Uc_sum_t;
				float         Udc;
				float         Udc_sum;
				float         Udc_sum_t;
				float         Pa;
				float         Pa_sum;
				float         Pa_sum_t;
				float         Pb;
				float         Pb_sum;
				float         Pb_sum_t;
                float         Pc;
				float         Pc_sum;
				float         Pc_sum_t;
				float         Ia0;
				float         Ia0_sum;
				float         Ia0_sum_t;
				float         Ib0;
				float         Ib0_sum;
				float         Ib0_sum_t;
				float         Ic0;
				float         Ic0_sum;
				float         Ic0_sum_t;
				float         Ia;
				float         Ia_sum;
				float         Ia_sum_t;
				float         Ib;
				float         Ib_sum;
				float         Ib_sum_t;
				float         Ic;
				float         Ic_sum;
				float         Ic_sum_t;
				float         Idc;
				float         Idc_sum;
				float         Idc_sum_t;
				float         P;
				float         P_sum;
				float         P_sum_t;
				float         Pq;
				float         Pq_sum;
				float         Pq_sum_t;
				float         PL;
				float         Pfdb;
				float         Tem;
				float         Tem_sum;
				float         Tem_sum_t;

				float         vdc_inverse;
				float         PF;

				u16		      N;
				float         Count_Ratio;
				u16           Count;
				
				int			  status;
				u16			  Tx_int[30];

				float         IA0;
                float         IA0_sum;
                float         IA0_sum_t;
                float         IB0;
                float         IB0_sum;
                float         IB0_sum_t;
                float         IC0;
                float         IC0_sum;
                float         IC0_sum_t;
		 	   } Display;
typedef Display *Display_handle;

typedef struct {  
				int    uac_Min1;
				int    uac_Min2;
				int    uac_Min3;
				int    uac_Max1;
				int    uac_Max2;
				int    uac_Max3;

				int    Udc_Min1;
				int    Udc_Min2;
				int    Udc_Min3;
				int    Udc_Max1;
				int    Udc_Max2;
				int    Udc_Max3;

				int    iac_Min1;
				int    iac_Min2;
				int    iac_Min3;
				int    iac_Max1;
				int    iac_Max2;
				int    iac_Max3;

				int    Idc_Max1;
				int    Idc_Max2;
				int    Idc_Max3;

				int    Temp_max1;
				int    Temp_max2;
				int    Temp_max3;
		 	   } Extremum;	
typedef Extremum *Extre_handle;

typedef struct {
				Uint16          Year;
				int64		    Enrg_Y;
				Uint16          Month;
				int64		    Enrg_M;
				Uint16          Date;
				int64		    Enrg_D;
				int64         	Enrg;
	            int64         	Enrg_Pre;

				Uint16          Y_Update;
				Uint16          M_Update;
				Uint16          D_Update;
				Uint16          Mdfy_en;

				int32	        E_Total_Dis;
				int16         	E_date_Dis;
				int32         	E_Month_Dis;
				int32         	E_Year_Dis;

	            int64         	Enrg_Total;
	            int64         	Enrg_Total_Half;
	            float           Enrg_k;
               } Energy;
typedef Energy * Energy_handle;

typedef struct
{
	u16 Tx_Data1[64];
	u16 Rx_Data1[16];
	u16 Tx_Data2[16];
	u16 Rx_Data2[16];
	u16 Rx_Disp[64];
	u16 Tx_Num1;
	u16 Rx_Num1;
	u16 Tx_Num2;
	u16 Rx_Num2;
	u16 *p_Disp;
	u16 Tx_Cnt;
	u16 Rx_Cnt;
	u16 Rx_Flag;
	u16 Tx_Flag;
	u16 Modbus_add;
	u16 Time;
	u16 Tx_delay;
} Uart;
typedef Uart *Uart_handle;

typedef struct {
                    float32  Ipv;
                    float32  Vpv;
                    float32  DeltaPmin;
                    float32  MaxVolt;
                    float32  MinVolt;
                    float32  Stepsize;
                    float32  VmppOut;
                    float32  DeltaP;
                    float32  Power;
                    float32  Power_Prev;
                    int16 mppt_enable;
                    int16 mppt_first;
                    int16 Status;
                } MPPT_PNO_F;
typedef MPPT_PNO_F *mppt_pno_handle;

typedef struct
{
    float   Valpha[8];
    float   Freq;
    int    Valpha_buf[16];
    int    Valpha_sum;
    int    V_POS;
    int    Vz_POS;
    int    Sequence;
    int    Samples;
    int    SampleSum;
    int    Sample_n;
    u16    Sample_Freq;
} THREE_ANALYZ;
typedef THREE_ANALYZ *Analyzer_handle;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_USER_DEFINED_TYPE_H definition
